#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include "bbnetlib.h"
#include "defines.h"
#include "communication.h"

int main() {
    if(connectDB("user=postgres dbname=exampledb") == ERROR)
    {
        perror("Could not connect to the database");
        return EXIT_FAILURE;
    }
    runTCPServer();
    closeDBConnection();

    return EXIT_SUCCESS;
}

