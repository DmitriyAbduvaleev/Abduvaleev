#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class CRational {
private:
	int numerator, denominator;

public:
    CRational()
    {
        numerator = 1;
        denominator = 1;
    }
    
    CRational(int value_numerator, int value_denominator)
    {
        numerator = value_numerator;
        if (value_denominator == 0)
        {
            cout << "Division by zero!" << endl;
            exit(0);
        }
        else
        {
            denominator = value_denominator;
        }
    }
    
 	int GreatestCommonDivisor (int n, int d)
	{
		if (d == 0)
			return n;
		else
			return GreatestCommonDivisor (d, n % d);
	}

	CRational Sum(CRational otherCRational)
	{
        int num = numerator * otherCRational.denominator + otherCRational.numerator * denominator;
        int den = denominator * otherCRational.denominator;

		return CRational(num, den).Reduce();
	}

	CRational Product(CRational otherCRational)
	{
        int num = numerator * otherCRational.numerator;
        int den = denominator * otherCRational.denominator;

		return CRational(num, den).Reduce();
  	}

	CRational Reduce()
	{
		int num = numerator / GreatestCommonDivisor (abs(numerator), abs(denominator));
		int den = denominator / GreatestCommonDivisor (abs(numerator), abs(denominator));

		return CRational(num, den);
	}

	void Print()
	{
		int sign;
		if (numerator * denominator >= 0)
			 sign = 1;
		else  sign = -1;

		numerator = abs(numerator);
		denominator = abs(denominator);

		if (denominator == 1)
			cout << sign * numerator << "\n";
		else if (numerator < denominator)
            cout << sign * numerator << "/" << denominator << "\n";
		else if (numerator > denominator)
			cout << sign * numerator / denominator << " " << numerator % denominator << "/" << denominator << "\n";
	}

};

	
int main()
{
	int numer1, denom1, numer2, denom2;
	cout << "Enter the numerator and denominator of the first number (using 'space')\n";
	cin >> numer1 >> denom1;
	cout << "Enter the numerator and denominator of the second number (using 'space')\n";
	cin >> numer2 >> denom2;
	
	CRational number1(numer1, denom1);
	CRational number2(numer2, denom2);
	CRational number3;

	number3 = number1.Sum(number2);
	cout << "The Sum is ";
	number3.Print();
	
	number3 = number1.Product(number2);
	cout << "The Product is ";
	number3.Print();

	system("pause");
	return 0;
}