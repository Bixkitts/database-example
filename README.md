# database-example
Showing how I can use C as a backend to query and edit a database and maybe build a web frontend for it.

## Current Features
- It can accept, parse and respond with a http CORS header
  then aceept the next message
- Makes contact with a Postgresq database and successfully sends SQL

## In Progress
- Multiple simultaneous connections with multithreading

## Planned 
- More HTTP parsing, content delivery, real data processing
- Load balancing connection with nginx
- Integration with interesting systems or technology like ChatGPT

## Building
- git submodule update
- cd Backend
- mkdir build
- cd build
- cmake DCMAKE_BUILD_TYPE=Release/Debug ..
- cmake --build .

## Usage
run ./database-example and it will listen by default on TCP port 1619 for incoming connections.
The included frontend application has an example request that doesn't do anything yet except
elicit an appropriate CORS response
