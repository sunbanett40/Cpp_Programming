/*
Project:    Complex Class
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/

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

    complex operator+(const complex &a) const
    {
        return complex(real + a.real, imaginary + a.imaginary);
    }
    complex operator-(const complex &a) const
    {
        return complex(real - a.real, imaginary - a.imaginary);
    }
    complex operator*(const complex &a) const
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

    void operator+=(const complex &a)
    {
        real += a.real;
        imaginary += a.imaginary;
    }
    void operator-=( const complex &a)
    {
        real -= a.real;
        imaginary -= a.imaginary;
    }
    void operator*=(const complex &a)
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

void print_cartesian(complex a);
void print_polar(complex a);
void print_exponential(complex a);

complex RLC(float resistance, float inductance, float capacitance, float freq);