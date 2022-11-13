#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


string encrypt(string word, int key);

int main(int argc, string argv[])
{
    // Get input words from both players
    int key = atoi(argv[1]);
    string word1 = get_string("Player 1: ");
    string cryptWord = encrypt(word1, key);


    printf("%s \n", word1);
    printf("%s \n", cryptWord);

}


string encrypt(string word, int key)
{
    //ci = (pi + k) % 26
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = word[i] + key;

        if(isaplha(word[i]))
        {
            word[i] = word[i] + key % 26;
        }

    }

    return 0;
}