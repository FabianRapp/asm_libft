# LibASM - 64-bit x86 Assembly Implementation of libft

## Overview

This project is my introduction to x86_64 assembly by implementing the foundational C functions of `libft`, the first project at a [42 School](https://42.fr/) usually to learn C, now to learn assembly. The goal is to replicate some of the basic `libc` functions in 64-bit x86 assembly language, gaining a low-level understanding of computer architecture and assembly programming along the way.

## Goals

- **Learn x86 Assembly**: Develop proficiency in 64-bit x86 Assembly (AT&T syntax) through practical application.
- **Implement Standard C Functions**: Recreate core `libft` functions, originally implemented in C, using assembly.
- **Understand System Calls and Memory Management**: Gain insights into system-level operations, function calls, and memory handling in assembly.
- **Have better understanding of ELF to continue implementing a debugger with ptrace.

### Functions
[ ]: todo \
[x]: implemented

## Ascii char manipulation
- [x] `ft_isalpha`: Check if a character is alphabetic.
- [x] `ft_isdigit`: Check if a character is a digit.
- [x] `ft_isalnum`: Check if a character is alphanumeric.
- [x] `ft_isascii`: Check if a character is an ASCII character.
- [x] `ft_isprint`: Check if a character is printable.
- [ ] `ft_toupper`: Convert a character to uppercase.
- [ ] `ft_tolower`: Convert a character to lowercase.

## Memory and String Manipulation

- [x] `ft_strlen`: Calculate the length of a string.
- [ ] `ft_strcpy`: Copy a string from source to destination.
- [ ] `ft_strcmp`: Compare two strings lexicographically.
- [ ] `ft_strdup`: Duplicate a string by allocating memory for it.
- [ ] `ft_write`: Write data to a file descriptor (using the system call).
- [ ] `ft_read`: Read data from a file descriptor (using the system call).
- [ ] `ft_strlen`: Calculate the length of a string.
- [ ] `ft_memset`: Fill a block of memory with a specific value.
- [ ] `ft_bzero`: Set a block of memory to zero.
- [ ] `ft_memcpy`: Copy memory from one location to another.
- [ ] `ft_memmove`: Copy memory, with handling for overlapping regions.
- [ ] `ft_strlcpy`: Copy a string with a maximum buffer size.
- [ ] `ft_strlcat`: Append a string with a maximum buffer size.
- [ ] `ft_strchr`: Locate the first occurrence of a character in a string.
- [ ] `ft_strrchr`: Locate the last occurrence of a character in a string.
- [ ] `ft_strncmp`: Compare a specific number of characters in two strings.
- [ ] `ft_memchr`: Locate a specific byte in a memory block.
- [ ] `ft_memcmp`: Compare a specific number of bytes in two memory blocks.
- [ ] `ft_strnstr`: Locate a substring within a string, limited by a maximum length.
- [ ] `ft_atoi`: Convert a string to an integer.
- [ ] `ft_calloc`: Allocate memory for an array and initialize it to zero.
- [ ] `ft_strdup`: Duplicate a string by allocating memory for it.
- [ ] `ft_substr`: Allocate and return a substring from a given string.
- [ ] `ft_strjoin`: Concatenate two strings into a new allocated string.
- [ ] `ft_strtrim`: Trim characters from both ends of a string, as specified in a set.
- [ ] `ft_split`: Split a string into an array of strings based on a delimiter.
- [ ] `ft_itoa`: Convert an integer to a string.
- [ ] `ft_strmapi`: Create a new string by applying a function to each character of a string.
- [ ] `ft_striteri`: Apply a function to each character of a string, passing the index and character by address.
- [ ] `ft_putchar_fd`: Output a character to a specific file descriptor.
- [ ] `ft_putstr_fd`: Output a string to a specific file descriptor.
- [ ] `ft_putendl_fd`: Output a string followed by a newline to a file descriptor.
- [ ] `ft_putnbr_fd`: Output an integer to a specific file descriptor.

## Linked List Operations
- [ ] `ft_lstnew`: Create a new list node.
- [ ] `ft_lstadd_front`: Add a new node at the beginning of the list.
- [ ] `ft_lstsize`: Count the number of nodes in a list.
- [ ] `ft_lstlast`: Retrieve the last node of the list.
- [ ] `ft_lstadd_back`: Add a new node at the end of the list.
- [ ] `ft_lstdelone`: Delete a specific node using a deletion function.
- [ ] `ft_lstclear`: Delete and free all nodes in a list.
- [ ] `ft_lstiter`: Apply a function to each node in a list.
- [ ] `ft_lstmap`: Create a new list by applying a function to each node, with a deletion function for error handling.

## Prerequisites
Any C compiler should be fine
