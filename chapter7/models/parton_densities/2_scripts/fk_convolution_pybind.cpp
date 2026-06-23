// fk_convolution_pybind.cpp

// g++ -O3 -Wall -shared -std=c++17 -fPIC $(python3 -m pybind11 --includes) -undefined dynamic_lookup 2_scripts/fk_convolution_pybind.cpp -o 2_scripts/fk_convolution$(python3-config --extension-suffix)

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<float>
fk_convolute(py::array_t<float, py::array::c_style | py::array::forcecast> FK, py::array_t<float, py::array::c_style | py::array::forcecast> pdf) {
    auto FK_buf  = FK.request();
    auto pdf_buf = pdf.request();

    if (FK_buf.ndim != 2)
        throw std::runtime_error("FK must be 2D");

    if (pdf_buf.ndim != 1)
        throw std::runtime_error("pdf must be 1D");

    const int N_obs = FK_buf.shape[0];
    const int N_x   = FK_buf.shape[1];

    if (pdf_buf.shape[0] != N_x)
        throw std::runtime_error("Dimension mismatch");

    const float* FK_ptr = static_cast<float*>(FK_buf.ptr);
    const float* pdf_ptr = static_cast<float*>(pdf_buf.ptr);
    py::array_t<float> pred(N_obs);
    auto pred_buf = pred.request();
    float* pred_ptr = static_cast<float*>(pred_buf.ptr);

    for (int n = 0; n < N_obs; ++n) {

        float acc = 0.0f;

        for (int i = 0; i < N_x; ++i)
            acc += FK_ptr[n * N_x + i] * pdf_ptr[i];

        pred_ptr[n] = acc;
    }

    return pred;

}

PYBIND11_MODULE(fk_convolution, m) {

    m.doc() = "FK convolution";
    m.def("fk_convolute", &fk_convolute, py::arg("FK"), py::arg("pdf"));

}