#include <iostream>
#include <cstdlib>
#include <cstring>
#include<math.h> //for sqrt
using namespace std;

int main()
{
    char input[256], guess[256], letter[256];
    cout << "Please, enter the word which is necessary to guess: ";
    cin >> input;
    int size_input = strlen(input), i;
    for (i = 0; i < size_input; i++)
    {
        guess[i] = '-';
    }
    input[i] = '\0';
    guess[i] = '\0';
    
    int parameter = 0, k = 0, end = 0, j = 0;
    cout << "Your progress: " << guess << "\n";
    while (end != strlen(input))
    {
        parameter = 0;
        cout << "Please, say any letter: ";
        cin >> letter;
        
        if (strlen(letter) == 1)
        {
            for (j = 0; j <size_input; j++)
            {
                if (letter[0] == guess[j])
                {
                    cout << "This letter has already been said. Please, choose another one. \n";
                    parameter = 2;
                }
            }
        
            if (parameter != 2)
            {
                for (k = 0; k < size_input; k++)
                {
                    if (letter[0] == input[k])
                    {
                        guess[k] = letter[0];
                        parameter = 1;
                        end++;
                    }
                }
            }
        
            if (parameter == 0)
            {
                cout << "There is no this letter in the word. You can try to guess again! \n";
            }
            if (parameter == 1)
            {
                cout << "Your progress: " << guess << "\n";
            }
        }
        else
        {
            cout << "You've decided to guess the word! So, let's try! \n";
            for (i = 0; i < size_input; i++)
            {
                if (letter [i] != input[i] || size_input != strlen(letter))
                {
                    cout << "Unfortunately, you're not right. It's over! \n";
					system("pause");
                    return 0;
                }
            }
            cout << "You're right! The guessed word is: " << input << '\n';
			system("pause");
            return 0;
        }
    }
    
    cout << "You've got it! There is your guessed word: " << guess << '\n';
    
	system("pause");
	return 0;
}