// Solve ODE / PDE with explicit Euler integrator

// Fourier heat equation: dT/dt = -k * (T - T_amb)

// Arrhenius reactivity equation: dC/dt = -A * exp(-Ea/RT) * C

// Navier-Stokes advection equation: dT/dt = -u * dT/dx  (upwind, single spatial grid)



// Import libraries ...............................................................................
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>



// Euler integrator ...............................................................................

// f : RHS function  dT/dt = f(T, t)
// T0 : initial value [K]
// dt : timestep [s]
// Returns vector of (t, T) pairs.

using RHS = double(*)(double T, double t);
std::vector<std::pair<double,double>> euler(RHS f, double T0, double dt, int n_steps, const std::string& path) {

    std::ofstream file(path);
    file << "t,state\n";

    std::vector<std::pair<double,double>> out;
    out.reserve(n_steps);

    double T = T0, t = 0.0;
    for (int i = 0; i < n_steps; ++i) {
        file << t << "," << T << "\n";
        out.push_back({t, T});
        T += dt * f(T, t);   // Euler step: T[n+1] = T[n] + dt * f(T[n], t[n])
        t += dt;
    }

    return out;

}



// RHS functions ...............................................................................

// Fourier: dT/dt = -k * (T - T_amb)
// The full Fourier equation is ∂T/∂t=α∇2T\partial T/\partial t = \alpha \nabla^2 T
// ∂T/∂t=α∇2T. Your equation dT/dt=−k(T−Tamb)dT/dt = -k(T - T_\text{amb})
// dT/dt=−k(T−Tamb​) is the lumped version — you've already integrated the Laplacian over space and replaced it with a single number kk
// k. Physically: instead of tracking how heat diffuses through a rod point by point, you're saying "the whole thing loses heat at rate kk
// k proportional to how far it is from ambient." Newton's law of cooling. The Laplacian is hidden inside kk
// k — it encodes the geometry, conductivity, and surface area all in one fitted constant. 

double fourier_rhs(double T, double /*t*/) {

    const double k = 1e-4; // cooling coefficient [1/s]
    const double T_amb = 20.0; // ambient temperature [deg C]

    return -k * (T - T_amb);

}

// Arrhenius: dC/dt = -k(T) * C,  k(T) = A * exp(-Ea / R*T)
// The ODE dC/dt=−k(T)CdC/dt = -k(T)C
// dC/dt=−k(T)C is just first-order reaction kinetics — that's a separate assumption (reaction rate proportional to concentration). Arrhenius tells you how kk
// k depends on temperature. The two things combined give you the full equation.

double arrhenius_rhs(double C, double /*t*/) {

    const double A_pre = 1.0e7; // pre-exponential [1/h]
    const double Ea = 175.0; // activation energy [kJ/mol]
    const double R = 8.314e-3; // gas constant [kJ/mol/K]
    const double T_rxn = 870.0; // fixed temperature [deg C]
    double k = A_pre * std::exp(-Ea / (R * (T_rxn + 273.15)));

    return -k * C;

}

// Advection (lumped, no spatial grid yet): dT/dt = -alpha * (T - T_cold)
// Simple relaxation standing in for -u*dT/dx until we add the spatial grid (...)
// It's the heat transport equation — it describes how temperature is carried by a fluid that's already moving at velocity uu
// u:
// ∂T∂t+u∂T∂x=α∂2T∂x2\frac{\partial T}{\partial t} + u\frac{\partial T}{\partial x} = \alpha\frac{\partial^2 T}{\partial x^2}∂t∂T​+u∂x∂T​=α∂x2∂2T​
// So to be precise: what we're solving is the advection-diffusion equation for temperature, which is a consequence of N-S energy transport, not the momentum equation itself. The link to N-S is real but indirect — N-S is upstream of it.
double advection_rhs(double T, double /*t*/) {

    const double alpha  = 5e-4; // effective transport rate [1/s]
    const double T_cold = 200.0; // cold inlet temperature [deg C]
    
    return -alpha * (T - T_cold);

}



// Main function ..................................................................................

int main(int argc, char* argv[]) {

    // Declare variables
    std::string outdir = (argc > 1) ? argv[1] : "results/data";
    double dt = 1.0; // timestep [s]
    int n_steps = 10000;

    // Call Euler and integrate
    std::cout << "Solving three ODEs with explicit Euler...\n";

    euler(fourier_rhs, 870.0, dt, n_steps, outdir + "/fourier.csv");
    std::cout << "Fourier heat -> " << outdir << "/fourier.csv\n";

    euler(arrhenius_rhs,  1.0,   dt, n_steps, outdir + "/arrhenius.csv");
    std::cout << "Arrhenius reactivity -> " << outdir << "/arrhenius.csv\n";

    euler(advection_rhs,  800.0, dt, n_steps, outdir + "/advection.csv");
    std::cout << "Navier-Stokes advection -> " << outdir << "/advection.csv\n";

    std::cout << "\nDone. Solutions saved at: " << outdir << "\n";
    
    return 0;

}
