*This project has been created as part of the 42 curriculum by tkhamis.*

# get_next_line

## Description

**get_next_line** is a foundational project from the 42 curriculum that focuses on **file descriptor handling and buffered input**.  
The goal is to implement a function that reads from a file descriptor **one line at a time**, returning each line on successive calls.

The function must correctly handle:
- Arbitrary line lengths
- Multiple file descriptors simultaneously
- Efficient and safe memory management

This project reinforces a solid understanding of **static variables, dynamic memory allocation, and low-level I/O in C**.

---

## Instructions

### Compilation

Compile the project using:
```bash
make
then use the function as follows:
char *line = get_next_line(fd);
```
Each call returns:

- The next line read from the file descriptor (including the trailing \n, if present)
- NULL when the end of file is reached or an error occurs
The function supports:
- Reading from files
- Reading from standard input
- Handling multiple file descriptors concurrently

## Resources

- 42 Subject PDF – get_next_line
- read() system call:
https://man7.org/linux/man-pages/man2/read.2.html
- Static variables in C:
https://en.cppreference.com/w/c/language/storage_duration
- Memory management in C:
https://en.cppreference.com/w/c/memory

## Use of AI

AI tools were used only for conceptual clarification and documentation assistance, such as understanding buffer management, static storage duration, and improving README clarity.
