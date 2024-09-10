#include <stdio.h>
#include "caesar.h"
#include "cipher.h"

int main() 
{
    welcome();

    int choice = get_choice("Enter your choice: ");

    if(choice > 3 || choice < 1) 
    {
        printf("Invalid choice\n");
        return 0;
    }

    while(choice != 3) 
    {
        int shift_value = get_choice("Enter shift value: ");
        char text[255];
        get_string(text, choice == 1);
        printf("Text: %s\n", text);
        switch (choice)
        {
        case 1:
            encrypt(text, shift_value);
            break;
        case 2:
            decrypt(text, shift_value);
            break;
        default:
            break;
        }
        printf("Result: %s\n", text);
        printf("-----------------------------\n");
        menu();
        choice = get_choice("Enter your choice: ");
    }

    printf("You chose to exit. Goodbye!\n");
    return 0;
}

void welcome() 
{
    printf("============================\n");
    printf("Welcome to Caesar Cipher!\n");
    printf("============================\n");
    menu();
}

void menu() 
{
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("-----------------------------\n");
}

int get_choice(char* message) 
{
    int choice;
    printf("%s", message);
    scanf(" %d", &choice);
    return choice;
}

void get_string(char text[255], int is_encrypt) 
{
    printf("Enter text to %s: ", is_encrypt ? "encrypt" : "decrypt");
    scanf("%c", (char *) stdin);
    fgets(text, 255, stdin);
}

