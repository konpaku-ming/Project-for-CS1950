#include <iostream>
#include <iomanip>

int n;
double sample_x[105], sample_y[105];
double A, B, C, D, E, F;
double avg_x, avg_y;

void read_sample() {
    // input_samples
    std::cout << "Please input the number of samples. (No more than 100)\n";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cout << "Please input x and y of the sample " << i << '\n';
        std::cin >> sample_x[i] >> sample_y[i];
        avg_x += sample_x[i];
        avg_y += sample_y[i];
    }
    avg_x /= n;
    avg_y /= n;
}

void error_function() {
    // calculate error function like f(a, b) = A * a ^ 2 + B * b ^ 2 + C * a * b + D * a + E * b + F;
    // (y - ax - b) ^ 2;
    A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
    for (int i = 1; i <= n; i++) {
        A += sample_x[i] * sample_x[i];
        B += 1;
        C += sample_x[i] * 2;
        D -= 2 * sample_x[i] * sample_y[i];
        E -= 2 * sample_y[i];
        F -= sample_y[i] * sample_y[i];
    }
}

void gradient_descent() {
    double a, b, partial_a, partial_b, alpha;
    int iteration_cnt;
    std::cout << "Please input the learning_rate: ";
    std::cin >> alpha;
    std::cout << "Please input the initial a and b: ";
    std::cin >> a >> b;
    std::cout << "Please input the number of iterations: ";
    std::cin >> iteration_cnt;
    while (iteration_cnt--) {
        std::cout << std::fixed << std::setprecision(4) << "current_a: " << a << " current_b: " << b << '\n';
        partial_a = 2 * A * a + C * b + D;
        partial_b = 2 * B * b + C * a + E;
        a = a - alpha * partial_a;
        b = b - alpha * partial_b;
    }
    std::cout << "The a and b calculated by gradient descent:\n";
    std::cout << std::fixed << std::setprecision(4) <<  "a = " << a << " b = " << b << '\n';
}

void calculate() {
    double a_0, b_0;
    a_0 = ( - D / 2 - n * avg_x * avg_y) / (A - n * avg_x * avg_x);
    b_0 = avg_y - a_0 * avg_x;
    std::cout << "The a and b calculated by least square method:\n";
    std::cout << std::fixed << std::setprecision(4) <<  "a = " << a_0 << " b = " << b_0 << '\n';
}

int main() {
    // 程序模拟运用梯度下降法确定线性拟合时的系数
    read_sample();
    error_function();
    gradient_descent();
    calculate();
}
