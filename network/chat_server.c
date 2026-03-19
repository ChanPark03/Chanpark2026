#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int server_sock;
    int client_sock;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;

    fd_set reads, cpy_reads;
    int fd_max, fd_num;
    char buffer[BUFFER_SIZE];
    int str_len;

    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        error_handling("socket() error");
    }

    int option = 1;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind() error");
    }

    if (listen(server_sock, 5) == -1) {
        error_handling("listen() error");
    }

    FD_ZERO(&reads);
    FD_SET(server_sock, &reads);
    fd_max = server_sock;

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        cpy_reads = reads;
        if ((fd_num = select(fd_max + 1, &cpy_reads, 0, 0, NULL)) == -1) {
            break;
        }

        if (fd_num == 0) {
            continue;
        }

        for (int i = 0; i < fd_max + 1; i++) {
            if (FD_ISSET(i, &cpy_reads)) {
                if (i == server_sock) { // New client connection
                    client_addr_size = sizeof(client_addr);
                    client_sock = accept(server_sock, (struct sockaddr*) &client_addr, &client_addr_size);
                    if (client_sock == -1) {
                        error_handling("accept() error");
                    } else {
                        FD_SET(client_sock, &reads);
                        if (fd_max < client_sock) {
                            fd_max = client_sock;
                        }
                        printf("New client connected: %d\n", client_sock);
                    }
                } else { // Message from a client
                    str_len = read(i, buffer, BUFFER_SIZE);
                    if (str_len == 0) { // Client disconnected
                        FD_CLR(i, &reads);
                        close(i);
                        printf("Client disconnected: %d\n", i);
                    } else { // Broadcast message
                        for (int j = 0; j < fd_max + 1; j++) {
                            if (FD_ISSET(j, &reads) && j != server_sock && j != i) {
                                write(j, buffer, str_len);
                            }
                        }
                    }
                }
            }
        }
    }

    close(server_sock);
    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}
