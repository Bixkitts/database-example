#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <libpq-fe.h>
#include "bbnetlib.h"

#include "dbConnection.h"
#include "defines.h"
#include "communication.h"
#include "dbCommands.h"

#define BUFFER_SIZE 2048
#define LISTEN_PORT 1619

static void handleTCPPacket(char* data, uint16_t size, Client* remotehost);

// We connect to the DB and check it
int connectDB(const char* connectString)
{
    // Connect to the database "user=postgres dbname=exampledb"
    connection = PQconnectdb(connectString);

    // Check to see that the connection was successful
    if (PQstatus(connection) != CONNECTION_OK) {
        printf("Connection to database failed: %s", PQerrorMessage(connection));
        PQfinish(connection);
        return ERROR;
    }
    return SUCCESS;
}

// This function will invoke the parser and then call the
// appropriate command that's needed.
static void handleTCPPacket(char* data, uint16_t size, Client* remotehost)
{
   printf("%s\n", data); 

}

int runTCPServer()
{
    Client* localhost = createClient("0.0.0.0", 1619);
    Client* remotehost = createClient("0.0.0.0", 1619);
    char* receivedData = (char *) malloc(sizeof(char)*BUFFER_SIZE);

    printf("\nRunning TCP server....");

    listenForTCP(receivedData, BUFFER_SIZE, localhost, remotehost, handleTCPPacket);

    return SUCCESS;
}

int closeDBConnection()
{
    PQfinish(connection); 
    return SUCCESS;
}
