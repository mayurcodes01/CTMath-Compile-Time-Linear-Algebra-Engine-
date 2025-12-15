#include <iostream>
#include "matrix.hpp"
#include "operations.hpp"

template<typename T, size_t R, size_t C>
void print(const Matrix<T, R, C>& m) {
    for (size_t i = 0; i < R; ++i) {
        for (size_t j = 0; j < C; ++j) {
            std::cout << m(i, j) << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    Matrix<int, 2, 2> A{};
    Matrix<int, 2, 2> B{};

    A(0, 0) = 1; A(0, 1) = 2;
    A(1, 0) = 3; A(1, 1) = 4;

    B(0, 0) = 5; B(0, 1) = 6;
    B(1, 0) = 7; B(1, 1) = 8;

    auto C = A * B;

    print(C);

    std::cin.get(); // keeps console open in VS
    return 0;
}
