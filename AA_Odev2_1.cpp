#include <iostream>
#include <vector>
#include <chrono>

const double INF = 1e9;

double find_mean(std::vector<double> v) {
    double sum = 0.0;
    for (double x : v) {
        sum += x;
    }
    return sum / v.size();
}

double find_std_dev(std::vector<double> v, double mean) {
    double sum = 0.0;
    for (double x : v) {
        sum += (x - mean) * (x - mean);
    }
    return sqrt(sum / v.size());
}

void yazdir(std::vector<double> v) {
    double mean = find_mean(v);
    double std_dev = find_std_dev(v, mean);
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Standart sapma: " << std_dev << std::endl;
}

void generate_sayilar(int n) {
    if (n <= 0) {
        throw std::invalid_argument("Boyut pozitif olmalı");
    }
    std::vector<double> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = (double) rand() / RAND_MAX;
    }
    yazdir(v);
}

int main() {
    std::srand(std::time(nullptr));
    int size;
    std::cout << "Vektörün boyutunu girin: ";
    std::cin >> size;
    try {
        generate_sayilar(size);
    }
    catch (std::invalid_argument& e) {
        std::cout << "Hata: " << e.what() << std::endl;
    }
    return 0;
}
