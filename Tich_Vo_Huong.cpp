// File: main_dot.cpp
#include <iostream>
#include <vector>
#include <omp.h>
#include <iomanip>

using namespace std;

const long long N = 100000000;

int main() {
    omp_set_num_threads(8); 

    cout << "=== BAI TOAN 1: TICH VO HUONG ===\n";
    cout << "Kich thuoc Vector: " << N << " phan tu\n";

    // 1. Khởi tạo dữ liệu
    vector<double> A(N, 1.0);
    vector<double> B(N, 2.0);

    double dot_product = 0.0;

    // Lấy số luồng tối đa của máy
    int num_threads = omp_get_max_threads();
    cout << "So luong Threads dang chay: " << num_threads << "\n\n";

    double start = omp_get_wtime();

    // 2. Tính toán song song
#pragma omp parallel for reduction(+:dot_product)
    for (long long i = 0; i < N; i++) {
        dot_product += A[i] * B[i];
    }

    double end = omp_get_wtime();

    // 3. Kết quả
    cout << fixed << setprecision(2);
    cout << "Ket qua tinh duoc: " << dot_product << "\n";
    cout << "Thoi gian chay:    " << (end - start) << " giay\n";

    return 0;
}