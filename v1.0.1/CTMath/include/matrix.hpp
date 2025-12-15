#pragma once
#include <array>
#include <cstddef>

template<typename T, size_t Rows, size_t Cols>
class Matrix {
public:
    std::array<T, Rows* Cols> data{};   // value-initialized

    constexpr T& operator()(size_t r, size_t c) {
        return data[r * Cols + c];
    }

    constexpr const T& operator()(size_t r, size_t c) const {
        return data[r * Cols + c];
    }

    static constexpr size_t rows() { return Rows; }
    static constexpr size_t cols() { return Cols; }
};
