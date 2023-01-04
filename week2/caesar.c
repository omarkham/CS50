#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string rotate(string text, int k);

int main(int argc, string argv[])
{
    if(argc == 2 && isdigit(*argv[1]))
    {

        //check if input is valid
        int k = atoi(argv[1]);//the key
        string code = get_string("plaintext: ");

        //rotate function
        string cipher_text = rotate(code, k);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

string rotate(string code, int k)
{
    string text = "";
    //going to iterate through each character in the original string and add
    //that changed letter to the 'cipher text' string (just print it in the end ig)
    //iterate through each letter in the text
    for(int i = 0, n = strlen(code); i<n; i++)
    {
        //do it for lower case letter
        if(code[i] >= 'a' && code[i] <= 'z')
        {
            strcat((((code[i]-'a')+k)%26 + 'a'),text);
        }

        else if(code[i] >= 'A' && code[i] <= 'Z')
        {
            strcat(("%c", ((code[i]-'A')+k)%26 + 'A'),text);
        }

        else
        {
            strcat(code[i], text);//if it's not a letter(example, a comma ',')
        }

    }
    printf("\n");
    return text;
}
