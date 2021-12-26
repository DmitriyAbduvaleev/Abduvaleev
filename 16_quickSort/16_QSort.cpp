#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;

void swap_with_temp(int *var1, int *var2);
void swap_with_difference(int *var1, int *var2);
void quicksort(int *str, int first, int last);

int main ()
{
	char input[256];
	int number;
	const int k = 1000;
	int randomDigits[k];
	cout << "Please, enter length on an array from 0 to 100: ";
    cin >> input;
    
    for (int i = 0; i < strlen(input); i++) 
    {
        if (isdigit(input[i]) == 0 && input[i] != '.' && input[0] != '-')
        {
            cout << "Please, don't enter any symbols. Try again! \n";
            return 0;
        }
    }
    
        if (atof(input) != atoi(input))
    {
         cout << "The length of your array must be integer. Try again! \n";
         return 0;
    }
    
    number = atoi(input);
    
	 if (number <= 1 || number > 100)
	{
	    if (number == 1)
	    {
	        cout << "The length of your array is 1, it's already sorted. And that's impossible to replace anything, because there is one place.\n";
	        randomDigits[0] = rand() % 201 - 100;
		    cout << randomDigits[0] << ' ';
	        return 0;
	    }
	    else
	    {
            cout << "You must enter positive number (and less than 101). Try again! \n"; 
            return 0;
	    }
    }
	

	srand(time(NULL));
	cout << "An initial array: ";
	for (int i = 0; i < number; i++)
	 {
		randomDigits[i] = rand() % 201 - 100;
		cout << randomDigits[i] << ' ';
	 }
	cout << '\n';
	
    swap_with_temp(&randomDigits[1], &randomDigits[2]);
    //swap_with_difference(&randomDigits[3], &randomDigits[4]);
    //swap(randomDigits[5], randomDigits[6]);
    
    int first = 0, last = number - 1;
	quicksort(randomDigits, first, last); 
	cout << "Sorted array: ";
	for (int j = 0; j < number; j++)
		cout << randomDigits[j] << ' ';
	cout << '\n';
    
	system("pause");
	return 0;
}

void swap_with_temp(int *var1, int *var2)
{
    int temp;
    if (var1 != var2)
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

void swap_with_difference(int *var1, int *var2)
{
    if (var1 != var2)
    {
        *var1 = *var1 + *var2;
	    *var2 = *var1 - *var2;
	    *var1 = *var1 - *var2;
    }
}

void quicksort(int *str, int first, int last)
{
	int pivot, var;
	int f = first, l = last;
	pivot = str[(f + l) / 2];
	do
	{
		while (str[f] < pivot) 
			f++;
		while (str[l] > pivot)
			l--;
		if (f <= l)
		{
			swap_with_difference(&str[l], &str[f]); 
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(str, first, l); 
	if (f < last) quicksort(str, f, last);
}