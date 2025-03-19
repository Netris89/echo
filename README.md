# Echo C++ Project

A simple `echo` program written in C++ that mimics the behavior of the traditional `echo` command in Unix-based systems. This program takes a string input and prints it to the console.

## Features

- Prints a string to the console.
- Handles basic command-line arguments like the `echo` command.

## Requirements

- C++20 compatible compiler (e.g., Clang, GCC)
- CMake (version 3.10 or higher)

## Installation

### Clone the repository

To get started, clone the repository to your local machine using the following command:

```sh
git clone https://github.com/Netris89/Utilities.git
cd Utilities
```

### Build the project

#### Install dependencies
Ensure you have a C++20 compatible compiler (e.g., Clang or GCC) and CMake installed. For example:

- On Ubuntu:

```sh
sudo apt update
sudo apt install clang cmake
```

- On macOS:

```sh
brew install clang cmake
```

### Build using CMake
After cloning the repository, create a build directory and build the project using CMake:

```sh
mkdir bin
cd bin
cmake ..
cmake --build .
```

### Run the program
Once the build is complete, you can find the compiled executable in the bin/ directory. To run it:

```sh
./bin/echo "Hello, World!"
```

### Usage

```sh
./bin/echo [options] <string>
```

Prints the string to the console, just like the echo command.   
The string can contain multiple words and will be printed as it is.   

### Example:

    ./bin/echo "Hello, World!"

This will output:

    Hello, World!
