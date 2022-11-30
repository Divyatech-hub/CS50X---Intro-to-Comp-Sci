#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string Text);
int count_words(string Text);
int count_sentences(string Text);
int readability_index(int letters, int words, int sentences);

// giving the text string to the program and calling respective function to count words, letters, sentences
// segregating text into letters, words, and sentences for comparison
int main(void)
{
    string Text = get_string("Text: ");
    int letters = count_letters(Text);
    int words = count_words(Text);
    int sentences = count_sentences(Text);
    int r_index = readability_index(letters, words, sentences);
    
    // # giving conclusive output based on readability index - to compare
    if (r_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (r_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", r_index);
    }
}

// function to count letters in text
int count_letters(string Text)
{
    int letters = 0;
    for (int i = 0, n = strlen(Text); i < n; i++)
        if (isalpha(Text[i]))
        {
            letters ++;
        }
    return letters;
}

// function to count words in text
int count_words(string Text)
{
    int words = 0;
    for (int i = 0, n = strlen(Text); i < n; i++)
    {
        if (Text[i] == '-' && isalpha(Text[i - 1])) {}

        else if (Text[i] == 39 && isalpha(Text[i - 1])) {}

        else if (!isalpha(Text[i]) && isalpha(Text[i - 1]))
        {
            words ++;
        }

    }
    return words;
}

// function to sentences letters in text
int count_sentences(string Text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(Text); i < n; i++)
    {
        int character = Text[i];
        if (character == 46 || character == 33 || character == 63)
        {
            sentences ++;
        }
    }
    return sentences;
}

// function to calc the readability index and return it
int readability_index(int letters, int words, int sentences)
{
    float words_per_100 = words / 100.0;
    float L = letters / words_per_100;
    float S = sentences / words_per_100;
    int r_index = round(0.0588 * L - 0.296 * S - 15.8);
    return r_index;
}
