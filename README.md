# Minitalk

## 📌 Description
Minitalk is a project that implements a data exchange program using only UNIX signals. It consists of two executables:  
- `server`: Listens for and displays messages sent by the client.  
- `client`: Sends a string message to the server using UNIX signals.  

## 📜 Project Rules
- Must follow the 42 coding standards.  
- Only allowed functions may be used.  
- Proper error handling and memory management are required.  

## 🛠️ Features
✅ Send messages from a client to a server using UNIX signals.  
✅ The server can receive multiple messages without restarting.  
✅ Uses only `SIGUSR1` and `SIGUSR2` for communication.  

## 💡 Bonus
✨ The server acknowledges received messages by sending a signal back to the client.  
✨ Supports Unicode characters.  

## 🏗️ Compilation & Execution
```sh
# Compile the project
make

# Start the server (prints its PID)
./server

# From another terminal, send a message to the server
./client <SERVER_PID> "Hello, Minitalk!"
```
## ⚙️ Allowed Functions
- `write`, `ft_printf` (or a custom equivalent)
- `signal`, `sigemptyset`, `sigaddset`, `sigaction`
- `kill`, `getpid`
- `malloc`, `free`
- `pause`, `sleep`, `usleep`
- `exit`
## 📂 Project Structure
```sh
.
├── client.c        # Client source code
├── server.c        # Server source code
├── minitalk.h      # Header file
├── Makefile        # Compilation script
└── README.md       # This file
```
