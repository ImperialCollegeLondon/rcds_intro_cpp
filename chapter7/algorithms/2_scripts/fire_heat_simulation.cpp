// Solve ODE / PDE with explicit Euler integrator
// Fourier heat equation:    dT/dt = -k * (T - T_amb)
// Arrhenius equation:       dC/dt = -A * exp(-Ea/RT) * C
// Advection equation:       dT/dt = -alpha * (T - T_cold)



// Import libraries ...............................................................................
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include "json.hpp"
using json = nlohmann::json;



// Load runcard ...............................................................................

json load_runcard(const std::string& path) {
    std::ifstream file(path);
    return json::parse(file);
}



// Euler integrator ...............................................................................

// f    : RHS function  dT/dt = f(T, t)
// T0   : initial value
// dt   : timestep [s]
// path : output CSV path
// Returns vector of (t, T) pairs.

using RHS = double(*)(double T, double t, const json& rc);

std::vector<std::pair<double,double>> euler(RHS f, double T0, double dt, int n_steps,
                                            const std::string& path, const json& rc) {
    // Prepare output file
    std::ofstream file(path);
    file << "t,state\n";

    // Prepare output vector
    std::vector<std::pair<double,double>> out;
    out.reserve(n_steps);
    double T = T0, t = 0.0;

    // Fill with Euler solution
    for (int i = 0; i < n_steps; ++i) {
        file << t << "," << T << "\n";
        out.push_back({t, T});
        T += dt * f(T, t, rc);   // Euler step: T[n+1] = T[n] + dt * f(T[n], t[n])
        t += dt;
    }

    return out;
}



// RHS functions ...............................................................................

// Fourier: dT/dt = -k * (T - T_amb)
// Lumped version of full ∂T/∂t = α∇²T — Laplacian integrated out,
// k absorbs geometry, conductivity, surface area. Newton 1701 / Fourier 1822.
double fourier_rhs(double T, double /*t*/, const json& rc) {
    double k     = rc["k_cool"];   // cooling coefficient [1/s]
    double T_amb = rc["T_amb"];    // ambient temperature [deg C]
    return -k * (T - T_amb);
}

// Arrhenius: dC/dt = -k(T) * C,  k(T) = A * exp(-Ea / R*T)
// Arrhenius (1889) gives k(T). First-order kinetics dC/dt = -k*C is a separate assumption.
double arrhenius_rhs(double C, double /*t*/, const json& rc) {
    double A_pre = rc["A_pre"];   // pre-exponential [1/h]
    double Ea    = rc["Ea"];      // activation energy [kJ/mol]
    double R     = rc["R"];       // gas constant [kJ/mol/K]
    double T_rxn = rc["T_rxn"];   // reaction temperature [deg C]
    double k = A_pre * std::exp(-Ea / (R * (T_rxn + 273.15)));
    return -k * C;
}

// Advection: dT/dt = -alpha * (T - T_cold)
// Lumped relaxation standing in for full ∂T/∂t + u∂T/∂x = α∂²T/∂x² (Navier-Stokes 1822-1845)
// until we add the spatial grid.
double advection_rhs(double T, double /*t*/, const json& rc) {
    double alpha  = rc["alpha"];    // effective transport rate [1/s]
    double T_cold = rc["T_cold"];   // cold inlet temperature [deg C]
    return -alpha * (T - T_cold);
}



// Main function ..................................................................................

int main(int argc, char* argv[]) {

    // Read arguments
    std::string outdir       = (argc > 1) ? argv[1] : "results/data";
    std::string runcard_path = (argc > 2) ? argv[2] : "4_runcards/default.json";

    // Load runcard
    json rc = load_runcard(runcard_path);

    // Read parameters
    double dt      = rc["dt"];       // timestep [s]
    int    n_steps = rc["n_steps"];  // number of steps

    double T0_fourier   = rc["T0_fourier"];    // initial temperature [deg C]
    double C0           = rc["C0"];            // initial concentration [-]
    double T0_advection = rc["T0_advection"];  // initial temperature [deg C]

    // Solve and write CSVs
    std::cout << "\nSolving three ODEs with explicit Euler...\n";
    std::cout << "Runcard: " << runcard_path << "\n\n";

    euler(fourier_rhs,   T0_fourier,   dt, n_steps, outdir + "/fourier.csv",   rc);
    std::cout << "Fourier heat         -> " << outdir << "/fourier.csv\n";

    euler(arrhenius_rhs, C0,           dt, n_steps, outdir + "/arrhenius.csv", rc);
    std::cout << "Arrhenius reactivity -> " << outdir << "/arrhenius.csv\n";

    euler(advection_rhs, T0_advection, dt, n_steps, outdir + "/advection.csv", rc);
    std::cout << "Advection transport  -> " << outdir << "/advection.csv\n";

    std::cout << "\nDone. Solutions saved at: " << outdir << "\n";
    return 0;

}