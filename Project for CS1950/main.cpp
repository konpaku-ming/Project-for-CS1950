#include <iostream>

int n;
double sample_x[105], sample_y[105];
double A, B, C, D, E, F;

void read_sample() {
    // input_samples
    std::cout << "Please input the number of samples. (No more than 100)\n";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cout << "Please input x of the sample:" << i << "\n";
        std::cin >> sample_x[i];
        std::cout << "Please input y of the sample:" << i << "\n";
        std::cin >> sample_y[i];
    }

}

void error_function() {
    // calculate error function like f(a, b) = A * a ^ 2 + B * b ^ 2 + C * x * y + D * x + E * y + F;

    for (int i = 1; i <= n; i++) {
        
    }
}

void gradient_descent() {

}

void print() {

}

int main() {
    // 程序模拟运用梯度下降法确定线性拟合时的系数
    read_sample();
    error_function();
    gradient_descent();
    print();

}