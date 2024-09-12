Command-Line Task Manager

Overview
A simple yet powerful Command-Line Task Manager implemented in C++. This application allows users to manage their tasks efficiently through a terminal interface. It supports adding, displaying, sorting, and deleting tasks, along with saving and loading tasks from a text file.

Features
Add Task: Enter task details including name, due date, priority, category, and notes.
Display Tasks: View all tasks in a neatly formatted table.
Sort Tasks: Sort tasks by priority with customizable order (High, Medium, Low).
Filter by Category: Display tasks based on specified categories (Work, Personal, Urgent).
Delete Task: Remove tasks by their name.
Save and Load Tasks: Persist tasks to a text file and load them when the application starts.
Usage
Add a Task:

plaintext
Copy code
Enter task name:
Enter due date (YYYY-MM-DD):
Enter priority (High/Medium/Low):
Enter category (Work/Personal/Urgent):
Enter additional notes:
Display Tasks: View all tasks with details such as name, due date, priority, category, and notes.

Sort Tasks:

1 for High first
2 for Medium first
3 for Low first
Filter by Category: Enter the category to view relevant tasks.

Delete Task: Specify the name of the task to delete.

Save Tasks to File: Save current tasks to tasks.txt.

Load Tasks from File: Automatically loads tasks from tasks.txt at startup.

Installation
Clone the repository:

bash
Copy code
git clone https://github.com/yourusername/command-line-task-manager.git
Navigate to the project directory:

bash
Copy code
cd command-line-task-manager
Compile the project using a C++ compiler:

bash
Copy code
g++ -o task_manager main.cpp
Run the application:

bash
Copy code
./task_manager
Project Structure
main.cpp: Contains the main implementation of the Command-Line Task Manager.
tasks.txt: Data file for saving and loading tasks.
README.md: Project documentation.
Contributing
Feel free to fork the repository, make improvements, and submit pull requests. For issues or feature requests, please open an issue in the GitHub repository.