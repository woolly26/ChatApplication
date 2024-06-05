#ifndef CLIENT_H
#define CLIENT_H

void start_client();
void connect_to_server();
void send_message(const std::string& message);
void receive_message();
void disconnect_from_server();


#endif // CLIENT_H
