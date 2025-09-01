#include <stdio.h>
#include <stdlib.h>

char* readFile(char* fileName) 
{
    char* buffer = malloc(256);
    FILE* fp;
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        perror("Error when opening file");
        exit(1);
    }

    fgets(buffer, 256, fp);
    fclose(fp);
    printf("%s\n", buffer);
    return buffer;
}
