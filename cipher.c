#include <stdio.h>
#include <ctype.h>
#include "cipher.h"

const char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int alphabet_size = sizeof(alphabet);

int letter_to_number(char letter) 
{
    for (int i = 0; i < alphabet_size; i++) {
        if (letter == alphabet[i] || letter == tolower(alphabet[i])) {
            return i;
        }
    }
    return -1;
    
}

char number_to_letter(int number, int is_lowercase) {
    if (number < 0 || number >= alphabet_size) {
        printf("invalid number");
        return '\0';
    }
    if (is_lowercase) {
        return tolower(alphabet[number]);
    }

    return alphabet[number];
}

int shift(int number, int shift_value) 
{
    int shifted_number = (number + shift_value) % alphabet_size;
    if (shifted_number < 0) {
        shifted_number += alphabet_size;
    }
    return shifted_number;
}


void encrypt(char* text, int shift_value) 
{
    for (int i = 0; text[i] != '\0'; i++) {
        int is_lowercase = islower(text[i]);
        int number = letter_to_number(text[i]);
        if (number == -1) {
            continue;
        }
        int shifted_number = shift(number, shift_value);
        text[i] = number_to_letter(shifted_number, is_lowercase);
    }
}

void decrypt(char* text, int shift_value) 
{
    encrypt(text, -shift_value);
}