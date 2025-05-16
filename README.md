# Echo

> [!IMPORTANT]
> This is a small project created for practicing and improving my C++ skills. It is not intended for production use, but rather as a personal learning tool.

Simple implementation of the echo command-line utility in C++ with support for various escape sequences such as \a, \b, \n, \t, \0num (octal), and more. This implementation aims to be POSIX-compliant.

## Features

- Outputs command-line arguments.
- Supports common escape sequences, including:
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

- A modern C++ compiler (C++20 or later).

## Build

Clone the repository and compile the project with:

```sh
git clone https://github.com/Netris89/echo
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

Run the compiled binary with arguments to print to stdout:
```
./echo Hello World
```

## Supported Escape Sequences

| Option | Description |
|--------|-------------|
| \a | Emits an alert  |
| \b | Backspace |
| \c | Suppresses further output  |
| \f | Form feed |
| \n | New line |
| \t | Tab |
| \r | Carriage return |
| \v | Vertical tab |
| \\ | Backslash |
| \0num | 8-bit octal value |

> **Note**  
> Octal escape sequences must begin with `\0` and contain up to three octal digits (e.g., `\041`).
>  
> For more details on the behavior of the `echo` command, refer to the  
> [POSIX specification on echo](https://pubs.opengroup.org/onlinepubs/9799919799/utilities/echo.html).

### Examples :
```sh
./echo Hello World
./echo "Hello\\nWorld\\041"
```
In the last example, \\n will be interpreted as a new line and \\041 as the octal value for !.
