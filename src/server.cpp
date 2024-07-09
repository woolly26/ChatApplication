#include "chat.h"

std::vector<Client> clients;
std::mutex clients_mutex;
std::ofstream log_file("chat_log.txt", std::ios::app);

std::string get_current_time() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S %Z");
    return oss.str();
}

void broadcast_message(const std::string& message, int sender_socket) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (const auto& client : clients) {
        if (client.socket != sender_socket) {
            send(client.socket, message.c_str(), message.length(), 0);
        }
    }
    log_file << message << std::endl;
}

void private_message(const std::string& message, const std::string& recipient) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (const auto& client : clients) {
        if (client.username == recipient) {
            send(client.socket, message.c_str(), message.length(), 0);
            break;
        }
    }
    log_file << message << std::endl;
}

void list_users(int client_socket) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    std::string user_list = "Connected users:\n";
    for (const auto& client : clients) {
        user_list += client.username + "\n";
    }
    send(client_socket, user_list.c_str(), user_list.length(), 0);
}

void remove_client(int client_socket) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    clients.erase(std::remove_if(clients.begin(), clients.end(),
        [client_socket](const Client& client) { return client.socket == client_socket; }),
        clients.end());
    close(client_socket);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Receive username
    bytes_read = read(client_socket, buffer, BUFFER_SIZE);
    buffer[bytes_read] = '\0';
    std::string username(buffer);

    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        clients.push_back({client_socket, username});
    }

    std::string welcome_message = username + " has joined the chat at " + get_current_time() + ".\n";
    broadcast_message(welcome_message, client_socket);

    while ((bytes_read = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0';
        std::string message(buffer);

        if (message == "/quit") {
            remove_client(client_socket);
            std::string quit_message = username + " has left the chat at " + get_current_time() + ".\n";
            broadcast_message(quit_message, client_socket);
            break;
        } else if (message == "/list") {
            list_users(client_socket);
        } else if (message.rfind("/msg ", 0) == 0) {
            size_t space_pos = message.find(' ', 5);
            if (space_pos != std::string::npos) {
                std::string recipient = message.substr(5, space_pos - 5);
                std::string private_message_content = "Private message from " + username + ": " + message.substr(space_pos + 1) + "\n";
                private_message(private_message_content, recipient);
            } else {
                std::string error_message = "Invalid command format. Use /msg <username> <message>\n";
                send(client_socket, error_message.c_str(), error_message.length(), 0);
            }
        } else {
            std::string public_message = username + ": " + message + " (" + get_current_time() + ")\n";
            broadcast_message(public_message, client_socket);
        }
    }

    remove_client(client_socket);
    std::string disconnect_message = username + " has disconnected at " + get_current_time() + ".\n";
    broadcast_message(disconnect_message, client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the network address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    while ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        std::cout << "New connection accepted" << std::endl;
        std::thread client_thread(handle_client, client_socket);
        client_thread.detach();
    }

    if (client_socket < 0) {
        perror("accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    return 0;
}

