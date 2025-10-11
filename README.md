CLI Chat Application for Linux
A simple, lightweight, and easy-to-use Command Line Interface (CLI) chat application built in C++ and optimized for Linux. This project allows users to connect to a central server and communicate with each other in a real-time terminal-based environment.

Features
Real-time Communication: Instantly send and receive messages.

Client-Server Architecture: A robust model with a central server managing connections.

Linux Optimized: Built and tested for Linux environments, specifically Ubuntu.

Lightweight: Minimal resource footprint, runs smoothly in any standard terminal.

Getting Started
Follow these instructions to get a copy of the project up and running on your local machine for development and testing purposes.

Prerequisites
You will need a C++ compiler (g++) and the make build tool.

For Ubuntu/Debian-based systems:
You can install the necessary tools by running the following command in your terminal:

sudo apt update && sudo apt install build-essential

This will install g++, make, and other essential development libraries. You can then verify the installation:

g++ --version
make --version

Installation & Running
Clone the repository:

git clone [https://github.com/your-username/ChatApplication.git](https://github.com/your-username/ChatApplication.git)
cd ChatApplication

Compile the source code:
Use the provided Makefile to compile the server and client executables. The binaries will be placed in the ./build/ directory.

make

Run the Server:
Open a terminal window and start the server application.

./build/server

The server will start listening for incoming client connections.

Run the Client:
Open one or more new terminal windows to run the client application(s).

./build/client

Each client will connect to the server, and you can start sending messages.

Usage
Server: The server's primary role is to listen for new clients and relay messages between them. It should be started first and remain running for clients to connect. By default, it will listen on a predefined port.

Client: Once connected, you can type your message and press Enter to send it to all other connected clients. Messages you receive will appear in your terminal.

Contributing
Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

Fork the Project

Create your Feature Branch (git checkout -b feature/AmazingFeature)

Commit your Changes (git commit -m 'Add some AmazingFeature')

Push to the Branch (git push origin feature/AmazingFeature)

Open a Pull Request

License
This project is distributed under the MIT License. See LICENSE for more information.