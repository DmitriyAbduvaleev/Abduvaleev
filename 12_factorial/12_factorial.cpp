#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

long long int factorial(int number)
{
    long long int n_fact = 1;
    if (number != 0)
    {
        for (int i = 1; i < number + 1; i++)
        {
        n_fact = n_fact * i;
        }
        return n_fact;
    }
    else
        return n_fact;
    
}

int main()
{
    char input[256];
    int number;
    
	cout << "Please, enter your integer number from 0 to 100000: ";
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
    
    if (number < 0 || number > 100000) //проверка на то, что число больше 0 и меньше 100000
    { 
        cout << "Please, enter any integer number greater than -1 and less than 100001. Try again! \n"; 
		system("pause");
        return 0; 
    }
    
    long long int result = factorial(number);
    cout << "The result: Factorial of " << number << " is equal to " << result << '\n';
    
	system("pause");
	return 0;
}