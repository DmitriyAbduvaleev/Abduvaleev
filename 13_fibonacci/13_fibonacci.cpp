#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int Fibonacci(int number)
{
    int fib = 1;
    if (number == 1 || number == 2)
    {
        return fib;
    }
    else
    {
        return Fibonacci(number - 1) + Fibonacci(number - 2);
    }
}

int main()
{
    char input[256];
    int number;
    
	cout << "Please, enter your integer number from 1 to 100: ";
    cin >> input;
    
    for (int i = 0; i < strlen(input); i++) //проверка на введение строки
    {
        if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-')
        {
            cout << "Please, don't enter any symbols. Try again! \n";
			system("pause");
            return 0;
        }
        
    }
    
    if (atof(input) != atoi(input)) //проверка на целое число
    {
         cout << "Please, enter any integer number. Try again! \n";
		 system("pause");
         return 0;
    }
    
    number = atoi(input);
    
    if (number < 1 || number > 100) //проверка на то, что число больше 0 и меньше 101
    { 
        cout << "Please, enter any integer number greater than 0 and less than 101. Try again! \n"; 
		system("pause");
        return 0; 
    }
    
    int result;
    cout << "The first " << number << " numbers in the Fibonacci series: \n";
    for (int k = 1; k <= number; k++)
    {
        result = Fibonacci(k);
        cout << result << ' ';
    }
	cout << '\n';

	system("pause");
	return 0;
}