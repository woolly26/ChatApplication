#include <iostream>
#include <thread>
#include "server.h"
#include "client.h"

int main() {
    // Start server in a new thread
    std::thread server_thread(start_server);

    // Give the server a moment to start
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Start client
    start_client();

    // Join the server thread before exiting
    server_thread.join();

    return 0;
}
