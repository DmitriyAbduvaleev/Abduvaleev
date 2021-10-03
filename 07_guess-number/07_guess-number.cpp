#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "Please, enter your integer number from 1 to 100: ";
	int number, parameter, cycle = 0, start = 0, end = 100, middle;
	
	cin >> number;

	while (cycle == 0)
	{
		middle = (start + end) / 2;
		cout << "Is your number greater than " << middle << "? 1 - yes, 2 - no, 3 - equal to your number \n";
		cin >> parameter;

		if (parameter == 1)
		{
			start = middle;
		}

		if (parameter == 2)
		{
			end = middle;
		}

		if (parameter == 3)
		{
			cout << "Your entered number is: " << middle << "\n";
			cycle = 1;
		}
		else 
		{
		    cout << "Please, choose the correct number: 1, 2 or 3 \n";
		}
	}

	system ("pause");
	return 0;
}