#include <iostream>

double kelvinToFarenheit(double kelvin);
double kelvin;
double farenheit;

double kelvinToFarenheit(double kelvin) {
    double farenheit = (kelvin - 273.15) * 9/5 + 32;
    return farenheit;
}

int main() {
    
    std::cout << "Input value in KELVIN: ";
    std::cin >> kelvin;
    
    farenheit = kelvinToFarenheit(kelvin);
    std::cout << "Farenheit =" << farenheit;

    return 0;
}


