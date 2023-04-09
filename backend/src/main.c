#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include "bbnetlib.h"

int main() {
    PGconn *conn;
    PGresult *res;
    int rows, cols, i, j;


    // Execute a SELECT query

    // Get the number of rows and columns in the result set

    // Print the column names
    for (i = 0; i < cols; i++) {
        printf("%-15s", PQfname(res, i));
    }

    printf("\n");

    // Print the row data
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%-15s", PQgetvalue(res, i, j));
        }

        printf("\n");
    }

    // Clean up
    PQclear(res);
    PQfinish(conn);

     

    return 0;
}

