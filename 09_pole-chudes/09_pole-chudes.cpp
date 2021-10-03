#include <iostream>
#include <cstdlib>
#include <cstring>
#include<math.h> //for sqrt
using namespace std;

int main()
{
    char input[256], guess[256], letter;
    cout << "Please, enter the word which is necessary to guess: ";
    cin >> input;
    int size_input = strlen(input), i;
    for (i = 0; i < size_input; i++)
    {
        guess[i] = '-';
    }
    input[i] = '\0';
    guess[i] = '\0';
    
    int parameter = 0, k = 0, end = 0;
    cout << "Your progress: " << guess << "\n";
    while (end != strlen(input))
    {
        parameter = 0;
        cout << "Please, say any letter: ";
        cin >> letter;
        for (k = 0; k < size_input; k++)
        {
            if (letter == input[k])
            {
                guess[k] = letter;
                parameter = 1;
                end++;
            }
        }
        
        if (parameter == 0)
        {
            cout << "There is no this letter in the word. You can try to guess again! \n";
        }
        else
        {
            cout << "Your progress: " << guess << "\n";
        }
    }
    
    cout << "You've got it! There is your guessed word: " << guess << '\n';
    
	system ("pause");
	return 0;
}


