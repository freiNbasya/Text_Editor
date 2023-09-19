#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int initial_lines = 20;
    int initial_symbols = 50;
    int current_line = 0;
    char** buffer = (char**)malloc(initial_lines * sizeof(char*));
    for (size_t i = 0; i < initial_lines; i++)
    {
        buffer[i] = (char*)malloc(initial_symbols * sizeof(char));
        buffer[i][0] = '\0';
    }

    int loop = 1;
    int choice;


    while (loop) {

        printf("\nEnter a number (1-8): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
        {


            break;
        }
        case 2:
        {

            break;
        }
        case 3:
        {

            break;
        }
        case 4:
        {

            break;
        }
        case 5:
        {

            break;
        }
        case 6:
        {

            break;

        }
        case 7:
        {

            break;
        }
        case 8:
        {

        }
        default:
            printf("Invalid choice.\n");
            break;
        }

    }
    return 0;
}