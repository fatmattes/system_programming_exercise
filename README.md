# server-client – Stock Example

This repository contains a simple system programming example written in C
using UNIX domain sockets.

## Files

### server.c
A basic server that listens on `/tmp/stock` and maintains a stock value.
It accepts single-character commands from clients:
- `+` increment stock
- `-` decrement stock
- `=` return current stock

The server sends the current stock value back to the client.

### client.c
A client that connects to the server socket and sends a command given as
a command-line argument, then prints the returned stock value.

## Compile
```bash
gcc server.c -o server
gcc client.c -o client
 ./server
./client +

