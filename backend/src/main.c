#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main() {
    PGconn *conn;
    PGresult *res;
    int rows, cols, i, j;

    // Connect to the database
    conn = PQconnectdb("user=postgres dbname=exampledb");

    // Check to see that the connection was successful
    if (PQstatus(conn) != CONNECTION_OK) {
        printf("Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        exit(1);
    }

    // Execute a SELECT query
    res = PQexec(conn, "SELECT * FROM employees");

    // Check to see that the query was successful
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("Query failed: %s", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    // Get the number of rows and columns in the result set
    rows = PQntuples(res);
    cols = PQnfields(res);

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

