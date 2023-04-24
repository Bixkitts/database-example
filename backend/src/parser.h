#ifndef NETLIBPARSER
#define NETLIBPARSER

#include <stdbool.h>

extern bool stringsMatch(const char* str1, const char* str2, int len);
extern char* subString(const char* str, int start, int length);

#endif
