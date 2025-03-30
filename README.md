# Echo

> [!NOTE]
> This is a small project created for practicing and improving my C++ skills. It is not intended for production use, but rather as a personal learning tool.

A simple implementation of the `echo` command line utility with support for the `-n` option to prevent a newline. 

## Features

- Outputs command-line arguments.
- Supports the `-n` option to suppress the newline character at the end.

## Prerequisites

- A modern C++ compiler (C++11 or later).

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
| `-n` | Show help messageSuppress the newline at the end of the output |

### Exemples :
```sh
./echo Hello World
./echo -n Hello World
```