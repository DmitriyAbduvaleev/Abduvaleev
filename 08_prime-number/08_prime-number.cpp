#include <iostream>
#include <cstdlib>
#include <cstring>
#include<math.h> //for sqrt
using namespace std;

int main()
{
    bool stop = true;
    char input[256];
    int number;
    
	cout << "Please, enter your integer number greater than 1: ";
    cin >> input;
    
    for (int i = 0; i < strlen(input); i++) //проверка на введение строки
    {
        if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-')
        {
            cout << "Please, don't enter any symbols. Try again! \n";
			system ("pause");
            return 0;
        }
        
    }
    
    if (atof(input) != atoi(input)) //проверка на целое число
    {
         cout << "Please, enter any integer number. Try again! \n";
		 system ("pause");
         return 0;
    }
    
    number = atoi(input);
    
    if (number < 1) //проверка на то, что число больше 1
    { 
        cout << "Please, enter any integer number greater than 1. Try again! \n"; 
		system ("pause");
        return 0; 
    }
    
    if (number == 1 || number == 2) //если введёное число равно 1 или 2 - по определению они простые
    {
        cout << "Your entered number is a PRIME number \n";
		system ("pause");
        return 0;
    }
    else
    {
        for (int j = 2; j <= sqrt(number); j++) //достаточно проверить до корня из введённого числа, оно является максимальным делителем для любого составного.
        {
            if (number % j == 0)
            {
                cout << "Your entered number is a COMPOSITE number \n";
                cout << "It can be divided by this number (first): " << j << "\n";
				system ("pause");
                return 0;
            }
        }
    }
    cout << "Your entered number is a PRIME number \n";
    
	system ("pause");
	return 0;
}