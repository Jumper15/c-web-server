#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    char parse_string[32] = "skibidi\ntoilet\n\npineapple\npizza";
    printf("%s", parse_string);

    // cant find seperator
    for (int i = 0; i < strlen(parse_string) - 1; i++) 
    {
        // printf("%d\n", i);
        if (parse_string[i] == '\n' && parse_string[i + 1] == '\n') 
        {
            printf("Found body");
            parse_string[i + 1] = '|';
        }
    }

    printf("%s", parse_string);

    return 0;
}