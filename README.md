# To-Do Application

This project is a simple command-line To-Do List application written in C++. It allows users to manage tasks by adding, removing, and marking them as completed. The tasks are saved to a file, so they persist between program executions.

## Features

1. **Add Task**: Add a new task with a description.
2. **Remove Task**: Remove a task by specifying its ID.
3. **Mark Task as Completed**: Mark a task as completed by ID.
4. **Persistent Storage**: All tasks are stored in a file (`ToDo.txt`) so that they persist between sessions.

## How It Works

- The application stores tasks in a `TaskList` object, which uses an `std::map` to associate task IDs with `Task` objects.
- Each `Task` has a description and a completion status.
- The application reads from `ToDo.txt` at startup to load saved tasks and writes back to this file upon exiting, ensuring all changes are saved.
- Task status is indicated with `[X]` for completed and `[ ]` for incomplete tasks.

## Classes and Functions

### Task Class
Represents individual tasks with:
- **Description**: A short string describing the task.
- **Completion Status**: Tracks whether a task is complete (`X` for completed, space for incomplete).
  
#### Public Methods:
- `setDescription`: Sets the task's description.
- `displayTask`: Returns the task's description.
- `markAsCompleted`: Marks the task as completed.

#### Friend Functions:
- `operator>>`: Reads task data from a file.
- `operator<<`: Writes task data to a file.

### TaskList Class
Manages a collection of tasks, handling file operations and task management commands.
  
#### Public Methods:
- `addTask`: Adds a new task to the list.
- `removeTask`: Removes a task by its ID.
- `displayTasks`: Displays all tasks with their IDs and statuses.
- `markCompleted`: Marks a task as completed by ID.

### Main Function
The main program loop displays a menu and allows users to interact with tasks:
- **Add Task**: Prompts for a description and adds a new task.
- **Remove Task**: Removes a task by its ID.
- **Mark as Completed**: Marks a task as completed by its ID.
- **Exit**: Exits the program and saves all tasks to the file.

## Installation and Usage

1. **Compile the Program**: 
   ```bash
   g++ -o todo main.cpp
   ```

2. **Run the Program**:
   ```bash
   ./todo
   ```

3. **Commands**:
   - **1**: Add a new task.
   - **2**: Remove an existing task by its ID.
   - **3**: Mark a task as completed by its ID.
   - **4**: Exit the program and save tasks to `ToDo.txt`.

## File Structure

- **ToDo.txt**: This file stores tasks with their descriptions and statuses. It is automatically created and updated by the program.

## Dependencies

- Standard C++ libraries (`<iostream>`, `<map>`, `<fstream>`)

## Limitations

- The program does not validate user input rigorously, so ensure task IDs are correct to avoid errors.
- Task IDs are simple integers that are not reused, so deleting tasks may leave gaps in the numbering.

## Future Improvements

- Add input validation to improve robustness.
- Enable task editing to modify descriptions after creation.
- Implement sorting by task completion status.

## License

This project is open-source and available for modification and distribution.
