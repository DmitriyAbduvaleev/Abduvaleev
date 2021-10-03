#include <iostream>

using namespace std;

void hanoi(int n, int i, int k); 

int main()
{
    int height;
    cout << "Please, enter the height of the Hanoi Tower: ";
    cin >> height;
    hanoi(height, 1, 3); //����� ������ height � 1 ������ �� 3 (����� ��������)
	system("pause");
    return 0;
}

void hanoi(int n, int i, int k)
{
    if (n == 1)
    {
         cout << "Move disk " << 1 << " from " << i << " to " << k << '\n';
    }
	else
	{
	    int tmp = 6 - i - k; //��������� �������, ����� ������� ������ ����, ����������!
	    hanoi(n - 1, i, tmp);
	    cout << "Move disk " << n << " from " << i << " to " << k << '\n';
	    hanoi(n - 1, tmp, k);
	}
}