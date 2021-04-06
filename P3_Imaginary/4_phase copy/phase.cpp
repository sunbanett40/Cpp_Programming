/*
Project:    Complex Class
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <cmath>
#include "phase.h"

class complex
{
public:
    complex() = default;
    complex(float re, float im)
    {
        real = re;
        imaginary = im;
    }

    float Re(void)
    {
        return real;
    }
    float Im(void)
    {
        return imaginary;
    }

    complex conj(void)
    {
        return complex(real, -1 * imaginary);
    }
    float mod(void)
    {
        return sqrt(pow(real, 2) + pow(imaginary, 2));
    }
    float arg(void)
    {
        return atan2(imaginary, real);
    }

    complex operator+(complex &a) const
    {
        return complex(real + a.real, imaginary + a.imaginary);
    }
    complex operator-(complex &a) const
    {
        return complex(real - a.real, imaginary - a.imaginary);
    }
    complex operator*(complex &a) const
    {
        float re = (real * a.real) - (imaginary * a.imaginary);
        float im = (real * a.imaginary) + (imaginary * a.real);

        return complex(re, im);
    }
    complex operator/(complex &a) const
    {
        complex b = complex(real, imaginary);

        complex c = complex(a.real, a.imaginary);

        complex conja = c.conj();
        float denominator = (a * conja).Re();

        float re = (b * conja).Re() / denominator;
        float im = (b * conja).Im() / denominator;

        return complex(re, im);
    }

    void operator+=(complex &a)
    {
        real += a.real;
        imaginary += a.imaginary;
    }
    void operator-=(complex &a)
    {
        real -= a.real;
        imaginary -= a.imaginary;
    }
    void operator*=(complex &a)
    {
        real = (real * a.real) - (imaginary * a.imaginary);
        imaginary = (real * a.imaginary) + (imaginary * a.real);
    }
    void operator/=(complex &a)
    {
        complex b = complex(real, imaginary);
        complex conja = a.conj();
        float denominator = (a * conja).Re();

        real = (b * conja).Re() / denominator;
        imaginary = (b * conja).Im() / denominator;
    }

    bool operator==(complex &a) const
    {
        if ((real == a.real) && (imaginary == a.imaginary))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool operator!=(complex &a) const
    {
        if ((real == a.real) && (imaginary == a.imaginary))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

private:
    float real;
    float imaginary;
};

class RLC
{
public:
    RLC(float resistance, float inductance, float capacitance, float volt, float freq, float phase)
    {
        voltage = complex(volt * asin(phase), volt * acos(phase));
        omega = 2 * M_PI * freq;

        float XL = omega * inductance;
        float XC = 1 / (omega * capacitance);

        impedance = complex(resistance, XL - XC);
        current = voltage / impedance;
    }

    complex imp(void)
    {
        return impedance;
    }

    complex cur()
    {
        return current;
    }

private:
    complex voltage;
    float omega;

    complex impedance;
    complex current;
};

int main()
{
    float res, ind, cap;
    float volt, freq, phase;

    std::cout << "Your resistance is? ";
    std::cin >> res;
    std::cout << "Your inductance is? ";
    std::cin >> ind;
    std::cout << "Your capacitance is? ";
    std::cin >> cap;
    std::cout << "Your voltage amplitude is? ";
    std::cin >> volt;
    std::cout << "Your voltage frequency is? ";
    std::cin >> freq;
    std::cout << "Your voltage phase is? ";
    std::cin >> phase;

    RLC circuit = RLC(res, ind, cap, volt, freq, phase);
    std::cout << std::endl
              << "Your current in complex form is: ";
    print_cartesian(circuit.cur());
    std::cout << "The magnitude of your current is: ";
    std::cout << circuit.cur().mod();
    std::cout << std::endl
              << "The phase difference between the voltage and current is: ";
    std::cout << 0 - circuit.cur().arg();
}

void print_cartesian(complex a)
{
    if (a.Im() >= 0)
    {
        std::cout << a.Re() << " + j" << a.Im() << std::endl;
    }
    else
    {
        std::cout << a.Re() << " - j" << a.conj().Im() << std::endl;
    }
}
void print_polar(complex a)
{
    std::cout << a.mod() << " arg " << a.arg() << std::endl;
}
void print_exponential(complex a)
{
    if (a.arg() >= 0)
    {
        std::cout << a.mod() << " exp(j" << a.arg() << ")" << std::endl;
    }
    else
    {
        std::cout << a.mod() << " exp(-j" << a.conj().arg() << ")" << std::endl;
    }
}