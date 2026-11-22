# Operating Systems: IPC Practicals in C

Hands-on practice for **Interprocess Communication (IPC)** from Chapter 3 (Processes). Each lab has C programs that I wrote and tested on Linux.

## Topics Covered

| Lab | Topic | Key APIs |
|-----|-------|----------|
| 1 | Models & Producer–Consumer | `pthread`, mutex, semaphores |
| 2 | POSIX Shared Memory | `shm_open`, `ftruncate`, `mmap` |
| 3 | Message Passing (Message Queues) | `mq_open`, `mq_send`, `mq_receive` |
| 4 | Pipes (Ordinary & Named) | `pipe`, `fork`, `dup2`, `mkfifo` |
| 5 | Sockets (TCP/UDP) | `socket`, `bind`, `listen`, `accept`, `connect` |
| 6 | RPC Concepts | marshalling, `htonl`/`ntohl`, matchmaker |

## Repository Structure

```
os/
├── README.md
├── lab1-producer-consumer/
├── lab2-shared-memory/
├── lab3-message-queues/
│   ├── sender.c
│   ├── receiver.c
│   └── blocking_test.c
├── lab4-pipes/
├── lab5-sockets/
├── lab6-rpc/
└── final-project/
```

## Requirements

- Linux (or WSL on Windows)
- GCC

## How to Compile & Run

```bash
# General
gcc file.c -o file

# Labs using threads (Lab 1)
gcc file.c -o file -pthread

# Labs using POSIX shm / message queues (Lab 2, 3)
gcc file.c -o file -lrt
```

Example (Lab 3):

```bash
cd lab3-message-queues
gcc sender.c -o sender -lrt
gcc receiver.c -o receiver -lrt
./sender
./receiver
```

## Progress

- [ ] Lab 1: Producer–Consumer
- [ ] Lab 2: Shared Memory
- [ ] Lab 3: Message Queues
- [ ] Lab 4: Pipes
- [ ] Lab 5: Sockets
- [ ] Lab 6: RPC
- [ ] Final Project

## Final Project

A mini chat/file service combining sockets, message queues, shared memory and pipes. *(In progress)*

## Notes

- Shared memory and message queue names live in the system until `shm_unlink` / `mq_unlink` is called. Clean up after running.
- Always compile with `-Wall` while learning to catch mistakes early.

## Author

**Muhammad Arslan**
