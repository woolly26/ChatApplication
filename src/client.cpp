#include "chat.h"

void handle_server(int server_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = read(server_socket, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0';
        std::cout << buffer << std::endl;
    }
    close(server_socket);
}

int main() {
    int client_socket;
    struct sockaddr_in serv_addr;

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address / Address not supported" << std::endl;
        return -1;
    }

    if (connect(client_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        return -1;
    }

    std::string username;
    do {
        std::cout << "Enter your username: ";
        std::getline(std::cin, username);
    } while (username.empty());
    send(client_socket, username.c_str(), username.length(), 0);

    std::thread server_thread(handle_server, client_socket);
    server_thread.detach();

    while (true) {
        std::string message;
        std::getline(std::cin, message);

        if (message.empty()) {
            continue;
        }

        send(client_socket, message.c_str(), message.length(), 0);

        if (message == "/quit") {
            break;
        } else if (message == "/list") {
            // Additional client-side logic for commands can be added here if needed
        } else if (message.rfind("/msg ", 0) == 0) {
            // Private message handling
            size_t space_pos = message.find(' ', 5);
            if (space_pos == std::string::npos) {
                std::cerr << "Invalid private message format. Use /msg <username> <message>" << std::endl;
                continue;
            }
        }
    }

    close(client_socket);
    return 0;
}




