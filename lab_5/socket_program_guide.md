## How to Compile and Run the Client-Server Program

### 1. Compile the Programs

Open a terminal and run the following commands to compile the server and client programs. This will create two executable files: `server` and `client`.

```bash
gcc server.c -o server
gcc client.c -o client
```

### 2. Run the Server

In the same terminal, run the server executable. It will wait for a client to connect.

```bash
./server
```

### 3. Run the Client

Open a **second terminal** and run the client executable. It will connect to the server, send a message, receive a reply, and then exit.

```bash
./client
```

### Expected Output

**In the server terminal, you will see:**

```
Message from client: Hello from client
Hello message sent
```

**In the client terminal, you will see:**

```
Hello message sent
Message from server: Hello from server
```
