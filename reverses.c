#include <stdio.h>
#include <string.h>

void reverse_string( char *string, int end_idx )
{
    int start_idx = 0;

    while (start_idx < end_idx)
    {
        /*
         ** XOR swap two characters
         */
        string[start_idx] ^= string[end_idx];
        string[end_idx] ^= string[start_idx];
        string[start_idx] ^= string[end_idx];

        start_idx++;
        end_idx--;
    }

    return;
}

int main( int argc, char **argv )
{
    char string[] = "This is a string";
    char *word_begin = string;
    char *word_end = NULL;
    int end_idx = strlen(string);

    printf("%s\n", string);

    reverse_string(string, end_idx - 1);

    while (word_begin < string + end_idx)
    {
        word_end = strchr(word_begin, ' ');
        if (word_end == NULL)
        {
            word_end = string + end_idx;
        }

        reverse_string(word_begin, word_end - word_begin - 1);

        word_begin = word_end + 1;
    }
    
    printf("%s\n", string);

    return 0;
}
