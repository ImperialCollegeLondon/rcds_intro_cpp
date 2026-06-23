// fk_convolution_cli.cpp

// g++ -O3 -std=c++17 2_scripts/fk_convolution_cli.cpp -o 2_scripts/fk_convolution_cli

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <stdexcept>

std::vector<float> load_binary(const std::string& path, int n_elements) {

    std::ifstream f(path, std::ios::binary);
    if (!f) throw std::runtime_error("Cannot open: " + path);

    std::vector<float> buf(n_elements);
    f.read(reinterpret_cast<char*>(buf.data()), n_elements * sizeof(float));
    return buf;

}

void save_binary(const std::string& path, const std::vector<float>& data) {
    std::ofstream f(path, std::ios::binary);
    f.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(float));
}

std::vector<float> fk_convolute(const std::vector<float>& FK, const std::vector<float>& pdf, int N_obs, int N_x) {
    std::vector<float> pred(N_obs, 0.0f);

    for (int n = 0; n < N_obs; ++n) {
        float acc = 0.0f;

        for (int i = 0; i < N_x; ++i)
            acc += FK[n * N_x + i] * pdf[i];

        pred[n] = acc;
    }

    return pred;

}

int main(int argc, char* argv[]) {

    const int N_obs = 20;
    const int N_x   = 50;
    const int N_rep = 10000;

    std::string fk_path = (argc > 1) ? argv[1] : "data/fk_tables/FK.bin";
    std::string pdf_path = (argc > 2) ? argv[2] : "data/fk_tables/pdf.bin";
    std::string out_path = (argc > 3) ? argv[3] : "data/fk_tables/pred.bin";

    auto FK  = load_binary(fk_path,  N_obs * N_x);
    auto pdf = load_binary(pdf_path, N_x);
    auto pred = fk_convolute(FK, pdf, N_obs, N_x);

    std::cout << "pred[:5] = ";
    for (int i = 0; i < 5; ++i)
        std::cout << pred[i] << " ";
    std::cout << "\n";

    auto t0 = std::chrono::high_resolution_clock::now();

    for (int r = 0; r < N_rep; ++r)
        pred = fk_convolute(FK, pdf, N_obs, N_x);

    auto t1 = std::chrono::high_resolution_clock::now();
    double elapsed_ms = std::chrono::duration<double, std::milli>(t1 - t0).count();
    std::cout << "Total: " << elapsed_ms << " ms\n";
    std::cout << "Per call: " << elapsed_ms / N_rep * 1000.0 << " us\n";

    save_binary(out_path, pred);

    return 0;

}