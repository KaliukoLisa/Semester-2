#include<iostream>
#include<cmath>

using namespace std;


class Complex
{
public:
	Complex()
	{
		real = 0; imaginary = 1;
	}
	Complex(double re, double im)
	{
		SetComplex(re, im);
	}
	void SetComplex(double re, double im)
	{
		real = re; imaginary = im;
	}
	Complex Add(Complex z1)
	{
		Complex z2;
		z2.real = real + z1.real;
		z2.imaginary = imaginary + z1.imaginary;
		return z2;
	}
	Complex Subtract(Complex z1)
	{
		Complex z2;
		z2.real = real - z1.real;
		z2.imaginary = imaginary - z1.imaginary;
		return z2;
	}
	double Radius()
	{
		return sqrt(real*real + imaginary*imaginary);
	}
	void Display()
	{

		if (imaginary < 0)
			cout << real << imaginary << "i" << endl;
		if (imaginary == -1)
			cout << real << "-i"<< endl;
		if (imaginary == 0)
			cout << real <<  endl;
		if (imaginary == 1)
			cout << real << "+i" << endl;
		else
		cout << real << "+" << imaginary << "i" << endl;
	}

private:
	double real, imaginary;
};

int main()
{
	Complex z1, z2, z3;
	z1.SetComplex(2, -1);
	z2.SetComplex(3, 1);
	z1.Display();
	z2.Display();
	z3 = z1.Add(z2);
	z3.Display();
	Complex zArray[5];
	for (int i = 0; i < 5; i++)
		cout << zArray[i].Radius() << endl;
	Complex *zPointer = &z1;
	zPointer->SetComplex(3, 5);
	Complex*zA = new Complex[10];
	zA[4].SetComplex(5, -2);
	return 0;


}
