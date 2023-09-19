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
            printf("You chose append option.\n");
            int add_size = 200;
            char* text_to_append = (char*)malloc(add_size * sizeof(char));
            fgets(text_to_append, add_size, stdin);
            size_t textadd_length = strlen(text_to_append);
            size_t line_length = strlen(buffer[current_line]);
            if (text_to_append[textadd_length - 1] == '\n') text_to_append[textadd_length - 1] = '\0';
            if (line_length + textadd_length + 1 > initial_symbols) {
                initial_symbols *= 2;
                buffer[current_line] = (char*)realloc(buffer[current_line], initial_symbols * sizeof(char));
                line_length = strlen(buffer[current_line]);
            }
            strcat(buffer[current_line], text_to_append);


            break;
        }
        case 2:
        {
            printf("You chose add line option.\n");
            strcat(buffer[current_line], "\n");
            current_line++;
            if (current_line == initial_lines) {
                initial_lines *= 2;
                char** buffer = (char**)malloc(initial_lines * sizeof(char*));
                for (size_t i = 0; i < initial_lines; i++)
                {
                    buffer[i] = (char*)malloc(initial_symbols * sizeof(char));
                    buffer[i][0] = '\0';
                }
            }
            break;
        }
        case 3:
        {
            printf("You chose output option.\n");
            for (size_t i = 0; i < initial_lines; i++)
            {
                if (buffer[i][0] != '\0') {
                    printf("%s", buffer[i]);
                }
            }
            break;
        }
        case 4:
        {
            printf("You chose write in file option.");
            FILE* file;
            file = fopen("myfile.txt", "w");
            if (file != NULL)
            {
                for (size_t i = 0; i < initial_lines; i++)
                {
                    if (buffer[i][0] != '\0') {
                        fputs(buffer[i], file);
                    }
                }
                fclose(file);
            }
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