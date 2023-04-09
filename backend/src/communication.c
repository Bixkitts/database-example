#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <libpq-fe.h>

#include "dbConnection.h"
#include "defines.h"
#include "communication.h"
#include "dbCommands.h"

// We connect to the DB and check it
int connectDB(const char* connectString)
{
    // Connect to the database "user=postgres dbname=exampledb"
    connection = PQconnectdb(connectString);

    // Check to see that the connection was successful
    if (PQstatus(connection) != CONNECTION_OK) {
        printf("Connection to database failed: %s", PQerrorMessage(connection));
        PQfinish(connection);
        exit(1);
    }
    return SUCCESS;
}




