# DSA_Third_smester_event

## Project Description
This project is an Event Management System implemented in C++. It allows users to manage events and their attendees through a console-based menu interface.

## Features
- Add, update, and delete events.
- Display events in forward or reverse order.
- Add and delete attendees for specific events.
- Display attendees of a specific event.

## Data Structures Used
- Events are managed using a doubly linked list, allowing efficient insertion, deletion, and traversal in both directions.
- Attendees for each event are managed using a circular linked list, enabling easy addition and deletion of attendees.

## How to Compile and Run
To compile the project, use a C++ compiler such as g++:

```
g++ mian_dsa.cpp -o event_management
```

To run the compiled program:

```
./event_management
```

## Usage
Upon running the program, a menu will be displayed with options to manage events and attendees. Enter the number corresponding to the desired action and follow the prompts.

Menu options include:
1. Add Event
2. Delete Event
3. Display Events (Forward)
4. Display Events (Reverse)
5. Add Attendee to Event
6. Display Attendees of an Event
7. Update Event
8. Delete Attendee
9. Exit

Follow the on-screen instructions to perform each operation.

## Author
This project was developed as part of the DSA Third Semester Lab.

## Cloning and Running the Project

### Cloning the Repository
To clone the repository, use the following command:

```
git clone https://github.com/sulmanfarooqq/DSA_Third_smester_event.git
```
cd DSA_Third_smester_event

code . 

run the cpp file 
### Running the Project in Dev C++
1. Open Dev C++.
2. Open the cloned project folder.
3. Open the `mian_dsa.cpp` file.
4. Compile and run the project using Dev C++'s build and run options.

### Running the Project in VS Code
1. Open VS Code.
2. Open the cloned project folder.
3. Open a terminal in VS Code.
4. Compile the project using the following command:

```
g++ mian_dsa.cpp -o event_management
```

5. Run the compiled executable:

```
./event_management
```

Make sure you have a C++ compiler like g++ installed and added to your system PATH.
