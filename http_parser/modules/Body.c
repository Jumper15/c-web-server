#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Body.h"

struct key_value_pair split_properties(char* prop)
{
    struct key_value_pair key_value_pair;
    char* key = strtok(prop, ":");
    char* value = strtok(NULL, ":");

    key_value_pair.key = key;
    key_value_pair.value = value;
    return key_value_pair;
}

char* parse_body(char* content_body)
{
    struct user_info user;
    char* body = malloc(256);
    strncpy(body, &content_body[1], strlen(content_body) - 2);

    printf("body: %s\n\n", body);

    
    char* pair = strtok(body, ",");
    char* password = strtok(NULL, ",");

    return body;
}

int main()
{
    char content_body[256] = "{username:\"example\",password:\"123\"}";
    // printf("body: %s", content_body);

    parse_body(content_body);
    return 0;
}