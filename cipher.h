#ifndef CIPHER_H
#define CIPHER_H

int letter_to_number(char letter);
char number_to_letter(int number, int is_lowercase);
int shift(int number, int shift_value);
void encrypt(char* text, int shift_value);
void decrypt(char* text, int shift_value);
int len(char* text);

#endif