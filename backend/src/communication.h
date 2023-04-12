#ifndef BBCOMMUNICATION
#define BBCOMMUNICATION

#include <libpq-fe.h>

extern int connectDB(const char* connectString);
extern int runTCPServer();
extern int closeDBConnection(PGconn* connection);


#endif
