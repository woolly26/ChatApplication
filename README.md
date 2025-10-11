# CLI Chat Application for Linux

A simple, lightweight, and easy-to-use **Command Line Interface (CLI)** chat application built in **C++** and optimized for Linux.  
This project allows users to connect to a central server and communicate with each other in a real-time terminal-based environment.

---

## 🚀 Features
- **Real-time Communication**: Instantly send and receive messages.  
- **Client-Server Architecture**: A robust model with a central server managing connections.  
- **Linux Optimized**: Built and tested for Linux environments, specifically Ubuntu.  
- **Lightweight**: Minimal resource footprint, runs smoothly in any standard terminal.  

---

## 🛠️ Getting Started

Follow these instructions to get a copy of the project up and running on your local machine for development and testing purposes.

### ✅ Prerequisites
You will need:
- A C++ compiler (`g++`)
- The `make` build tool

For **Ubuntu/Debian-based systems**, install with:
```bash
sudo apt update && sudo apt install build-essential
```

Verify the installation:
```bash
g++ --version
make --version
```

---

## ⚙️ Installation & Running

### 1. Clone the repository:
```bash
git clone https://github.com/your-username/ChatApplication.git
cd ChatApplication
```

### 2. Compile the source code:
Use the provided `Makefile` to compile the server and client executables.  
The binaries will be placed in the `./build/` directory.

```bash
make
```

### 3. Run the Server:
Open a terminal window and start the server application:
```bash
./build/server
```
The server will start listening for incoming client connections.

### 4. Run the Client(s):
Open one or more new terminal windows to run the client application(s):
```bash
./build/client
```
Each client will connect to the server, and you can start sending messages.

---

## 💻 Usage

- **Server**:  
  - The server listens for new clients and relays messages between them.  
  - It must be started first and remain running for clients to connect.  
  - By default, it listens on a predefined port.

- **Client**:  
  - Once connected, type your message and press **Enter** to send it to all other connected clients.  
  - Incoming messages will appear in your terminal in real time.

---

## 🤝 Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

1. **Fork the Project**  
2. **Create your Feature Branch**  
   ```bash
   git checkout -b feature/AmazingFeature
   ```
3. **Commit your Changes**  
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```
4. **Push to the Branch**  
   ```bash
   git push origin feature/AmazingFeature
   ```
5. **Open a Pull Request**

---

## 📜 License
This project is distributed under the **MIT License**.  
See [LICENSE](LICENSE) for more information.
