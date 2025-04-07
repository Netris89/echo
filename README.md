# Echo

> [!NOTE]
> This is a small project created for practicing and improving my C++ skills. It is not intended for production use, but rather as a personal learning tool.

A simple implementation of the `echo` command line utility with support for the `-n` option to prevent a newline. 

## Features

- Outputs command-line arguments.
- Supports the `-n` option to suppress the newline character at the end.

## Prerequisites

- A modern C++ compiler (C++11 or later).
- vcpkg

## Installation

Clone the repository and compile the project with:

```sh
git clone https://github.com/Netris89/echo
mkdir build
cd build
cmake ..
```

## Usage

| Option | Description |
|--------|-------------|
| \a | Prints a Alert  |
| \b | Prints a backspace |
| \n | Prints a newline |
| \t | Prints a tab |
| \r | Prints a carriage return |
| \v | Prints a aertical tab |
| \\ | Prints a Backslash |
| \0num | Prints an 8-bit octal value |

### Exemples :
```sh
./echo Hello World
./echo -n Hello World
```