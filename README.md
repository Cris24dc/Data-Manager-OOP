# Data Manager OOP

<img src="./img/wallpaper.jpg" width="95%"/>

## Overview

This project is a C++ application that demonstrates the principles of Object-Oriented Programming (OOP). The application allows users to manage data entries efficiently using a terminal-based user interface. Users can create, read, update, and delete data entries stored in CSV files.

## Features

- **Data Management**: Users can add, delete, find, and search for data entries.
- **User Interface**: A simple terminal-based UI that guides the user through various options.
- **Data Persistence**: Automatically creates and manages CSV files for data storage.
- **Random Data Generation**: A separate script for generating fake data using the Faker library.

## Project Structure

Data-Manager-OOP/
<br>
├── main.cpp # Main application code
<br>
├── classes.hpp # Class implementations and definitions
<br>
├── ui.hpp # User interface implementation
<br>
├── state.hpp # Enum definitions for program states
<br>
│
<br>
├── generator/ # Folder for data generation scripts
<br>
│ └── create_data.py # Script to generate random fake data
<br>
│
<br>
└── database/ # Folder for CSV files created by users

## Setup

1. Clone the repository:

   ```bash
   git clone git@github.com:Cris24dc/Data-Manager-OOP.git
   cd Data-Manager-OOP
   ```

2. Install the Faker library:

   ```bash
   pip install faker
   ```

3. Generate fake data:

   ```bash
   python3 ./generator/create_data.py
   ```

4. Install ncurses

   ```bash
   sudo apt install libncurses5-dev libncursesw5-dev
   ```

5. Build and run the program
   ```bash
   g++ main.cpp -o main.o -lncurses && ./main.o
   ```

## Usage

### 1. Data Generator:

Upon running the script, the console will ask for name of the CSV file and the number of entries generated.

### 2. File Management:

Upon launching, the main program will prompt you to enter the filename you want to use. If the specified file already exists in the database folder, the program will open it. If it does not exist, the program will create a new file with the provided name.

### 3.User Interface Options:

After the file is opened, the user interface will display the following options:

**Add Data**: Allows you to add new data entries.

**Delete Data**: Enables you to remove data entries either by their ID or by name.

**Find Data**: Lets you locate specific data entries using either their ID or name.

**Search Data**: Provides functionality to search for specific values within the data.
