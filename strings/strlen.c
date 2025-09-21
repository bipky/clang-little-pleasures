#include <stdio.h>

int string_length(const char* str)
{
    const char* p;
    for (p = str; *p; p++) { }
    return p - str;
}

int main(int argc, char** argv)
{
    char* input_string;
    if (argc != 2) {
        printf("Invalid arguments\n");
        return 1;
    }
    input_string = argv[1];
    printf("The length of string is %d\n", string_length(input_string));
    return 0;
}
