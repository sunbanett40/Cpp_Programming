/*
Project:    Complex Class
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

#include <iostream>
#include <cmath>

class complex
{
public:
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

int main()
{
    complex A = complex(3, 4);

    std::cout << "Your value is: ";
    print_cartesian(A);

    std::cout << "The real part is: " << A.Re() << std::endl;
    std::cout << "The imaginary part is: " << A.Im() << std::endl;
    std::cout << std::endl;

    std::cout << "The modulus is: " << A.mod() << std::endl;
    std::cout << "The argument is: " << A.arg() << std::endl;
    std::cout << std::endl;

    std::cout << "The conjugate of your value is: ";
    print_cartesian(A.conj());
}