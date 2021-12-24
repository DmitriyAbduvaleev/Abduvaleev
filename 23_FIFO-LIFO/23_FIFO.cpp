#include <iostream>
#include <cstdlib>

using namespace std;

class Container
{
protected: 
	int *array;
	int length;
	int element;

public:
	Container(int length_a)
	{
		length = length_a;
		array = new int[length];
		element = 0;
	}
	virtual void push(int q) = 0;
	virtual void pop(int &i) = 0;
	virtual void Deleting_Element(int *&array, int &length) = 0;

	~Container()
	{
		delete[] array;
	};

};

class FIFO: public Container
{
public:
	FIFO(int lenght_a): Container(lenght_a) {}

	virtual void push(int q)
	{
		array[element] = q;
		element ++;
	}
	virtual void pop(int &i)
	{
		cout << i + 1 << ')' << " will be retrieved "<< array[0] << endl; 
		Deleting_Element(array, length);
	}
	virtual void Deleting_Element(int *&array, int &length) 
	{
		int *new_array = new int[length-1];

		cout << "Queue elements (after extracting top element): ";
		for(int i = 0; i < length-1; i++) {
			new_array[i] = array[i+1];
			cout << new_array[i] << " ";
		}
		cout << endl << endl;
		length --;
		delete[] array;
		array = new_array;
	}
};


int main()
{
	cout << "Enter the lenght of the queue: ";
	int N, q;
	cin >> N;

	FIFO Queue(N);

	cout << "Enter integer elements of the queue: ";
	int i = 0;
	while (i < N)
	{
		cin >> q;
		Queue.push(q);
		i++;
	}

	for (i = 0; i < N; i++)
		Queue.pop(i);

	system("pause");
	return 0;
}