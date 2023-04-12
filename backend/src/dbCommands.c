#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <libpq-fe.h>

#include "defines.h"
#include "dbConnection.h"
#include "dbCommands.h"

static int execSQL(const char* query, PGresult* result);

static char* (*dbCommands[2])(const char*) = 
{
    dbGetNames, 
    dbGetNamesAndSalaries
};

char* dbGetNames(const char* data)
{
    PGresult* result;
    execSQL("SELECT name FROM employees", result);
    int rows = PQntuples(result);
    int cols = PQnfields(result);
    char* ret = (char *) malloc(sizeof(char));
    for(int i = 0; i < rows; i++)
    {
        strcat(ret,PQgetvalue(result, i, 0));
    }
    PQclear(result);
    return ret;
}

// Placeholder!!!!!
char* dbGetNamesAndSalaries(const char* data)
{
    PGresult* result;
    execSQL("SELECT name FROM employees", result);
    int rows = PQntuples(result);
    int cols = PQnfields(result);
    char* ret = (char *) malloc(sizeof(char));
    for(int i = 0; i < rows; i++)
    {
        strcat(ret,PQgetvalue(result, i, 0));
    }
    PQclear(result);
    return ret;

}


char* execDBCommand(const enum DBCommand command, const char* data)
{ 
   return (*dbCommands[command])(data); 
}
// Low level: execute and check SQL query
static int execSQL(const char* query, PGresult* result)
{
    result = PQexec(connection, query);

    // Check to see that the query was successful
    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        printf("Query failed: %s", PQerrorMessage(connection));
        PQclear(result);
        PQfinish(connection);
        return ERROR;
    }
    return SUCCESS;
}
