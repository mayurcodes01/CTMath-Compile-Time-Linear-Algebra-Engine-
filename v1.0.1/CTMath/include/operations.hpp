#pragma once
#include "matrix.hpp"
#include <cstddef>

//Matrix Addition
template<typename T, size_t R, size_t C>
constexpr Matrix<T, R, C>
operator+(const Matrix<T, R, C>& a,
    const Matrix<T, R, C>& b)
{
    Matrix<T, R, C> result{};

    for (size_t i = 0; i < R * C; ++i)
        result.data[i] = a.data[i] + b.data[i];

    return result;
}

//Matrix Multiplication
template<typename T,
    size_t R1, size_t C1,
    size_t R2, size_t C2>
constexpr Matrix<T, R1, C2>
operator*(const Matrix<T, R1, C1>& a,
    const Matrix<T, R2, C2>& b)
{
    static_assert(C1 == R2,
        "Matrix multiplication dimension mismatch");

    Matrix<T, R1, C2> result{};// important

    for (size_t i = 0; i < R1; ++i)
        for (size_t j = 0; j < C2; ++j)
            for (size_t k = 0; k < C1; ++k)
                result(i, j) += a(i, k) * b(k, j);

    return result;
}
