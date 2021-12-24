#include <iostream>
#include <cstdlib>

using namespace std;

class FIFO {
private:
	int *array;
	int lenght;
	int element;

public: 
	FIFO(int N)
	{
		if (N <= 0)
		{
			cout << "Error\n";
			system ("pause");
			exit(0);
		}

		lenght = N;
		array = new int[lenght];
		element = 0;
	}

	~FIFO()
	{
		delete[] array;
	}

	void push(int q)
	{
		array[element] = q;
		element ++; 
	}

	void pop(int a)
	{
		cout << a + 1 << ')' << " will be retrieved "<< array[0] << endl; 
		Deleting_Element(array, lenght);

	}
	void Deleting_Element(int *&array, int &lenght) {
		int *new_array = new int[lenght-1];

		cout << "Queue elements (after extracting top element): ";
		for(int i = 0; i < lenght-1; i++) {
			new_array[i] = array[i+1];
			cout << new_array[i] << " ";
		}
		cout << endl << endl;
		lenght--;
		delete[] array;
		array = new_array;
	}

};

int main()
{
	cout << "Enter the lenght of the array\n";
	int N, q;
	cin >> N;

	FIFO array(N);

	cout << "Enter integer numbers: \n";
	int i = 0;
	while (i < N)
	{
		cin >> q;
		array.push(q);
		i++;
	}

	for (i = 0; i < N; i++)
		array.pop(i);

	system("pause");
	return 0;
}