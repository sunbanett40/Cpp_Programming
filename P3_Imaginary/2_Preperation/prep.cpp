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

    complex add(complex a)
    {
        return complex((real + a.Re()), (imaginary + a.Im()));
    }
    complex sub(complex a)
    {
        return complex((real - a.Re()), (imaginary - a.Im()));
    }
    complex mult(complex a)
    {
        float re = (real * a.Re()) - (imaginary * a.Im());
        float im = (real * a.Im()) + (imaginary * a.Re());

        return complex(re, im);
    }
    complex div(complex a, complex b)
    {
        complex conjb = b.conj();
        float denominator = b.mult(conjb).Re();

        float re = mult(conjb).Re()/denominator;
        float im = mult(conjb).Im()/denominator;

        return complex(re, im);
    }

    complex conj(void)
    {  
        return complex(real, -imaginary);
    }
    float mod(void)
    {
        return sqrt(pow(real, 2), pow(imaginary, 2));
    }
    float arg(void)
    {
        return tan(real/imaginary);
    }

private:
    float real;
    float imaginary;
}

int
main()
{
}