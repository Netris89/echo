# Echo

> [!IMPORTANT]
> This is a small project created for practicing and improving my C++ skills. It is not intended for production use, but rather as a personal learning tool.

Simple implementation of a POSIX echo command-line utility in C++, which interprets various escape sequences in input strings. It includes support for escape sequences like \a, \b, \n, \t, \0num (octal), and others.

## Features

- Outputs command-line arguments.
- Supports escape sequences like:
    - \a : Alert (bell)
    - \b : Backspace
    - \f : Form feed
    - \n : Newline
    - \r : Carriage return
    - \t : Tab
    - \v : Vertical tab
    - \\ : Backslash
    - \0num : 8-bit octal value

## Prerequisites

- A modern C++ compiler (C++17 or later).

## Installation

Clone the repository and compile the project with:

```sh
git clone https://github.com/Netris89/echo
mkdir build
cd build
cmake ..
```

## Usage

```
./echo Hello World
```

## Supported Escape Sequences

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
./echo "Hello\\nWorld\\041"
```
In the last example, \\n will be interpreted as a newline and \\041 as the octal value for !.

> [!NOTE]
> Octal escape sequences must begin with \0 and contain up to three octal digits (e.g., \012).
> More details on the echo command and its behavior can be found here:
> [The Open Group - echo utility](https://pubs.opengroup.org/onlinepubs/9799919799/utilities/echo.html)