CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-lpthread

all: chat_server chat_client

chat_server: chat_server.o
	$(CC) $(CFLAGS) -o chat_server chat_server.o

chat_client: chat_client.o
	$(CC) $(CFLAGS) -o chat_client chat_client.o $(LDFLAGS)

chat_server.o: chat_server.c
	$(CC) $(CFLAGS) -c chat_server.c

chat_client.o: chat_client.c
	$(CC) $(CFLAGS) -c chat_client.c

clean:
	rm -f chat_server chat_client *.o
