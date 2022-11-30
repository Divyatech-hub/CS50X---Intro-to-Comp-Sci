import string
import re
from cs50 import get_string


def main_fn():
    # giving the text string to the program
    
    Text = get_string("Text: ")

    # segregating text into letters, words, and sentences for comparison
    
    letters = len(re.findall('[a-zA-Z]', Text))
    words = len(Text.split())
    sentences = len(re.findall(r'[.!?]+', Text))

    # calling the functions to perform the operations
    r_index = readability_index(letters, words, sentences)

    printGrade(r_index)

# function to calc the readability index and return it


def readability_index(letters, words, sentences):

    words_per_100 = words / 100
    l = letters / words_per_100
    s = sentences / words_per_100

    r_index = round(0.0588 * l - 0.296 * s - 15.8)     # using round() to roudn off thr r_index value as an int for comparison

    return r_index

# function to give conclusive output based on readability index


def printGrade(r_index):
    if r_index < 1:
        print("Before Grade 1")
    elif r_index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {r_index}")


main_fn()
