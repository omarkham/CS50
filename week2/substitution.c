#include <cs50.h>
#include <stdio.h>
#include <string.h>//for strlen()
#include <ctype.h>
//to do: get key, validate key, get plaintext, encipher, print ciphertext

//arc c is # of command line inputs
//argv[] is an array of strings- all of the command line inputs
int main(int argc, string argv[])
{
    const int N = 26;
    const string ALPH = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (argc != 2)
    {
        printf("Only one command line argument.\n");
        return 1;
    }

    //ask for plaintext
    string text = get_string("plaintext: ");
    int length = strlen(text);
    int letters[N];
    char cipher[length+1];//+1 to allow space for the null terminator

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if((argv[1][i] < 'a' && argv[1][i] > 'z') || (argv[1][i] < 'A' && argv[1][i] > 'Z'))
        {
            printf("Nope\n");
            return 1;
        }
        //checking for repeated characters
        else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            argv[1][i] = toupper(argv[1][i]);
            for (int j = 0; j < N; j++)
            {
                if (argv[1][i] == letters[j])
                {
                    printf("Nope\n");
                    return 1;
                }
            }
        letters[i] = argv[1][i];
        }
    }

    //loop through each character
    for (int i = 0; i < length; i++)
    {
        //if it's uppercase
        if(isupper(text[i] !=0))
        {
            for (int j = 0; j < N; j++)
            {
                if (text[i] == ALPH[j])
                {
                    cipher[i] = argv[1][j];
                    break;
                }
            }
        }
        else if (islower(text[i] != 0))
        {
            for(int j = 0; j < strlen(ALPH); j++)
            {
                if(text[i] == tolower(ALPH[j]))
                {
                    cipher[i] = tolower(argv[1][j]);
                    break;
                }
            }
        }
        else
        {
            //it's not a letter
            cipher[i] = text[i];
        }
        cipher[length] = '\0';//null addition so it's a string
        printf("ciphertext: %s\n", cipher);
        return 0;//good
    }
}
