#!/bin/bash
# chmod +x compile.sh

# ANSI color codes
RED='\033[0;31m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

if [ "$#" -lt 1 ]; then
    echo -e "${RED}Error: You need to provide at least one argument.${NC}"
    echo -e "Usage: $0 <source_file.cpp> [executable_name]"
    exit 1
fi

cpp_file="$1"

if [ "$#" -lt 2 ]; then
    read -p "Enter the desired name for the program (without extension): " program_name
else
    program_name="$2"
fi

while [ ! -e "$cpp_file" ]; do
    echo -e "${RED}Error: File '$cpp_file' not found.${NC}"
    read -p "Please enter the name of the C++ source file: " cpp_file
done

echo -e "${CYAN}Compiling the C++ program...${NC}"
g++ "$cpp_file" -o "$program_name" -lncurses

if [ $? -eq 0 ]; then
    echo -e "${CYAN}Compilation successful.${NC}"
else
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

echo -e "${CYAN}Executing the program...${NC}\n"
./"$program_name"
