#ifndef DBCOMMANDS
#define DBCOMMANDS

#include <libpq-fe.h>

enum DBCommand
{
    GET_NAMES,
    GET_NAMES_AND_SALARIES
};

char* execDBCommand(const enum DBCommand command, const char* data);

char* dbGetNames(const char*);
char* dbGetNamesAndSalaries(const char*);
    





#endif
