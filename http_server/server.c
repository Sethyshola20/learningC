#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <unistd.h>     
#include <arpa/inet.h> 

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_length = sizeof(client_address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
            perror("socket failed");
            exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));  
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;      
    server_address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(server_fd, 1) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port 8080...\n");

    while(1){
        client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_length);
        if (client_fd < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("Client connected!\n");
        int room_num = 31010;
        char message[64];
        snprintf(message, sizeof(message), "{\"room\": %d}\n", room_num);

        char response[256];
        snprintf(response, sizeof(response),  "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "Connection: keep-alive\r\n"
        "Content-Length: %zu\r\n"
        "\r\n"
        "%s",
        strlen(message), message);
        ssize_t bytes_sent = send(client_fd, response, strlen(response), 0);
        if(bytes_sent < 0 ){
            perror("Couldn't send");
        }
        close(client_fd);
    }
    
    close(server_fd);
    return 0;
}
