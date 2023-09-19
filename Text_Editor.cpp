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
            printf("You chose write in file option.\n");
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
            printf("You chose read from file option.\n");
            FILE* file;
            char mystring[1000];
            file = fopen("MyFile.txt", "r");
            if (file == NULL)
            {
                printf("Error opening file");
            }
            else
            {
                while (fgets(mystring, sizeof(mystring), file)) {

                    printf("%s", mystring);
                }
                fclose(file);
            }
            break;

        }
        case 6:
        {
            printf("You chose find text in file option.\n");
            FILE* file;

            char substring[100];
            char text_line[1000];
            int line_pos = 0;
            int symbol_pos = 0;

            printf("Enter the substring to search for: ");
            fgets(substring, sizeof(substring), stdin);
            size_t substring_length = strlen(substring);
            if (substring[substring_length - 1] == '\n') substring[substring_length - 1] = '\0';
            file = fopen("myfile.txt", "r");
            if (file == NULL) {
                printf("Error opening file");
            }
            while (fgets(text_line, sizeof(text_line), file)) {
                char* symbol_pos = text_line;
                while ((symbol_pos = strstr(symbol_pos, substring))) {
                    printf("Found at position: %d %d\n", line_pos, symbol_pos - text_line);
                    symbol_pos++;
                }
                line_pos++;
            }

            fclose(file);
            break;

        }
        case 7:
        {

            break;
        }
        case 8:
        {
            system("cls");
            printf("You chose clear console option.\n");
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
        }

    }
    return 0;
}