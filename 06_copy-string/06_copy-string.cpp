#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char your_str[255], copied_str[255];
	cout << "Please, enter your string: ";
	cin >> your_str; 

	int i;
	for (i = 0; i <= (strlen(your_str) - 1); i++)
		copied_str[i] = your_str[i];
	copied_str[i] = '\0';
	cout << "There is a result of the copying your string: " << copied_str << "\n";

	system ("pause");
	return 0;
}
