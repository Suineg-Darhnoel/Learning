#include <iostream>
#include <complex>

int main()
{
    std::complex<double> c1(10.0, 2.0);
    std::cout << "Real part: " << c1.real() << '\n';
    std::cout << "Imaginary part: " << c1.imag() << '\n';

    std::complex<double> c2(11.0, -1.0);
    std::cout << (c1+c2).real() << '\n';
    std::cout << (c1+c2).imag() << '\n';
    return 0;
}
