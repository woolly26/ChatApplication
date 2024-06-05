#ifndef CHAT_H
#define CHAT_H

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <map>
#include <mutex>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>       // For std::ostringstream
#include <algorithm>     // For std::remove_if
#define PORT 8080
#define BUFFER_SIZE 1024

struct Client {
    int socket;
    std::string username;
};

void handle_client(int client_socket);
void broadcast_message(const std::string& message, int sender_socket);
void private_message(const std::string& message, const std::string& recipient);
void list_users(int client_socket);
void remove_client(int client_socket);

std::string get_current_time();
extern std::vector<Client> clients;
extern std::mutex clients_mutex;
extern std::ofstream log_file;

#endif // CHAT_H

