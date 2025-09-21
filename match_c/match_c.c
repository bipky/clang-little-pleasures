#include <stdio.h>

int match(const char* string, const char* pattern)
{
    int i;
    for (;; string++, pattern++) {
        switch (*pattern) {
        case 0:
            return *string == 0;
        case '*':
            for (i = 0;; i++) {
                if (match(string + i, pattern + 1))
                    return 1;
                if (!string[i])
                    return 0;
            }
        case '?':
            if (!*string)
                return 0;
            break;
        default:
            if (*string != *pattern)
                return 0;
        }
    }
}

int main(int argc, char** argv)
{
    char *str, *pat;
    str = argv[1];
    pat = argv[2];
    int result;
    if (argc < 3) {
        fprintf(stderr, "Please provide string and pattern\n");
        return 1;
    }
    result = match(str, pat);
    if (result) {
      printf("Match!\n");
    } else {
      printf("No match.\n");
    }
    return 0;
}