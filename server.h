#ifndef SERVER_H
#define SERVER_H

void start_server();
void create_socket();
void bind_socket();
void listen_for_connections();
void accept_connection();
void handle_client();
void close_socket();

#endif // SERVER_H
