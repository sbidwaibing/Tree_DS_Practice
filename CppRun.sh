#!/bin/bash

# Check if "clean" is passed as the argument
if [ "$1" == "clean" ]; then
    echo -e "\n> Cleaning up the Object files directory!"
    rm -rf obj bin
    echo -e "> Object files directory has been deleted!\n"
    exit 0
fi

# Check if a file name is provided
if [ -z "$1" ]; then
    echo "Usage: ./CppRun.sh <filename.cpp>"
    exit 1
fi

# Extract the base name of the file (without extension)
filename=$(basename -- "$1")
name="${filename%.*}"

# Create necessary directories
mkdir -p obj bin

# Compile the C++ file
g++ -c "$1" -o "obj/$name.o"
if [ $? -ne 0 ]; then
    echo -e "\nCompilation failed!\n"
    exit 1
fi

# Link and create the executable
g++ "obj/$name.o" -o "bin/$name"
if [ $? -ne 0 ]; then
    echo -e "\n> Linking failed!\n"
    exit 1
fi

# Run the executable
echo -e "\n> Executing the program! \n"
./bin/"$name"