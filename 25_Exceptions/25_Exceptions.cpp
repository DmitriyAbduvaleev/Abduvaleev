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
		try{
		  if (value_denominator == 0) 
		        throw 3;
		  denominator = value_denominator;
		}
        catch (int except)
        {
          cout << "Division by zero!\n";
		  system("pause");
		  exit(except);
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
        int num, den;
		try{
		    if (INT_MAX / numerator < otherCRational.denominator || INT_MAX / otherCRational.numerator < denominator ||
				INT_MAX / denominator < otherCRational.denominator)
		        throw 4;
		    den = denominator * otherCRational.denominator;
		}
		catch(int except)
		{
			cout << "Overflow error\n";
			system("pause");
            exit(except);
		}

		try{
		    if (INT_MAX - numerator * otherCRational.denominator < otherCRational.numerator * denominator)
		        throw 4;
		    num = numerator * otherCRational.denominator + otherCRational.numerator * denominator;
		}
		catch(int except)
		{
			cout << "Overflow error\n";
			system("pause");
            exit(except);
		}
		
		return CRational(num, den).Reduce();
	}

	CRational Product(CRational otherCRational)
	{
        int num, den;
		try{
		    if (INT_MAX / numerator < otherCRational.numerator || INT_MAX / otherCRational.denominator < denominator)
		        throw 5;
		    num = numerator * otherCRational.numerator;
			den = denominator * otherCRational.denominator;
		}
		catch(int except)
		{
			cout << "Overflow error\n";
			system("pause");
            exit(except);
		}

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
	float numer1, denom1, numer2, denom2;
	int numer_1, denom_1, numer_2, denom_2;

	cout << "Enter the numerator and denominator of the first number (using 'space')\n";
	cin >> numer1 >> denom1;
	try{
          if ((numer1 - int(numer1)) != 0 || (denom1 - int(denom1)) != 0) 
              throw 2;
    }
    catch (int except)
    {
          cout << "Error! You should enter integer numbers\n";
		  system("pause");
          exit(except);
    }
	numer_1 = int(numer1);
	denom_1 = int(denom1);
	try{
          if (!isdigit(numer_1) || !isdigit(denom_1)) //not numbers
              throw 1;
    }
    catch (int except)
    {
          cout << "Error! You should enter numbers\n";
		  system("pause");
          exit(except);
    }

	
	cout << "Enter the numerator and denominator of the second number (using 'space')\n";
	cin >> numer2 >> denom2;
	try{
          if ((numer2 - int(numer2)) != 0 || (denom2 - int(denom2)) != 0) 
              throw 2;
		  
    }
    catch (int except)
    {
          cout << "Error! You should enter integer numbers\n";
		  system("pause");
          exit(except);
    }
	numer_2 = int(numer2);
	denom_2 = int(denom2);
	try{
          if (!isdigit(numer_2) || !isdigit(denom_2)) //not numbers
              throw 1;
    }
    catch (int except)
    {
          cout << "Error! You should enter numbers\n";
		  system("pause");
          exit(except);
    }

	CRational number1(numer_1, denom_1);
	CRational number2(numer_2, denom_2);
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