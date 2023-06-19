#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "parser.h"

bool stringsMatch(const char* str1, const char* str2, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(str1[i] == str2[i])
            continue;
        return 0;
    }
    return 1;
}

char* subString(const char* str, int start, int length) 
{
    char* substr = (char*)malloc(length + 1); 
    memcpy(substr, str + start, length); 
    substr[length] = '\0'; 
    return substr;
}
