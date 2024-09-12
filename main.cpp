#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// Task structure with attributes
struct Task {
    string name;
    string dueDate;
    string priority;
    string category;
    string notes;
};

// List of tasks
vector<Task> tasks;

// Helper function to color the output
void printColored(const string& text, const string& color) {
    if (color == "red")
        cout << "\033[1;31m" << text << "\033[0m";
    else if (color == "green")
        cout << "\033[1;32m" << text << "\033[0m";
    else
        cout << text;
}

// Function to add a task
void addTask() {
    Task task;
    cout << "Enter task name: ";
    getline(cin, task.name);
    cout << "Enter due date (YYYY-MM-DD): ";
    getline(cin, task.dueDate);
    cout << "Enter priority (High/Medium/Low): ";
    getline(cin, task.priority);
    cout << "Enter category (Work/Personal/Urgent): ";
    getline(cin, task.category);
    cout << "Enter additional notes: ";
    getline(cin, task.notes);

    tasks.push_back(task);
    cout << "Task added successfully!\n";
}

// Function to display all tasks in a table
void displayTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << left << setw(15) << "Name" << setw(15) << "Due Date" << setw(15) << "Priority" << setw(15) << "Category" << "Notes" << endl;
    cout << "------------------------------------------------------------------------------\n";
    
    for (const auto& task : tasks) {
        cout << left << setw(15) << task.name
             << setw(15) << task.dueDate
             << setw(15) << task.priority
             << setw(15) << task.category
             << task.notes << endl;
    }
}

// Function to sort tasks by priority or due date
// Function to sort tasks by priority in a custom order based on user selection (1 for High, 2 for Medium, 3 for Low)
void sortTasks() {
    int priorityChoice;
    cout << "Sort by priority:\n";
    cout << "1. High first\n";
    cout << "2. Medium first\n";
    cout << "3. Low first\n";
    cout << "Enter your choice: ";
    cin >> priorityChoice;
    cin.ignore(); // Ignore the newline character left in the input buffer

    // Lambda function to compare tasks based on the selected priority order
    auto comparePriority = [priorityChoice](const Task& a, const Task& b) {
        vector<string> order;

        if (priorityChoice == 1) {
            order = {"High", "Medium", "Low"};
        } else if (priorityChoice == 2) {
            order = {"Medium", "High", "Low"};
        } else if (priorityChoice == 3) {
            order = {"Low", "High", "Medium"};
        } else {
            cout << "Invalid choice! Defaulting to High first.\n";
            order = {"High", "Medium", "Low"};
        }

        int indexA = find(order.begin(), order.end(), a.priority) - order.begin();
        int indexB = find(order.begin(), order.end(), b.priority) - order.begin();
        return indexA < indexB;
    };

    // Sort the tasks based on the selected order
    sort(tasks.begin(), tasks.end(), comparePriority);
    cout << "Tasks sorted by selected priority order.\n";
}


// Function to display task categories
void displayTasksByCategory() {
    string category;
    cout << "Enter category to filter tasks by (Work/Personal/Urgent): ";
    getline(cin, category);

    cout << left << setw(15) << "Name" << setw(15) << "Due Date" << setw(15) << "Priority" << setw(15) << "Category" << "Notes" << endl;
    cout << "------------------------------------------------------------------------------\n";

    for (const auto& task : tasks) {
        if (task.category == category) {
            cout << left << setw(15) << task.name
                 << setw(15) << task.dueDate
                 << setw(15) << task.priority
                 << setw(15) << task.category
                 << task.notes << endl;
        }
    }
}

// Function to delete a task by name
void deleteTask() {
    string name;
    cout << "Enter the name of the task to delete: ";
    getline(cin, name);

    auto it = remove_if(tasks.begin(), tasks.end(), [&](const Task& task) {
        return task.name == name;
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Task not found.\n";
    }
}

// Function to save tasks to a text file
void saveTasksToTextFile() {
    ofstream file("tasks.txt");
    if (file) {
        for (const auto& task : tasks) {
            file << "Task Name: " << task.name << endl;
            file << "Due Date: " << task.dueDate << endl;
            file << "Priority: " << task.priority << endl;
            file << "Category: " << task.category << endl;
            file << "Notes: " << task.notes << endl;
            file << "---------------------------------------" << endl;
        }
        file.close();
        cout << "Tasks saved to tasks.txt\n";
    } else {
        cout << "Unable to open file for saving.\n";
    }
}

// Function to load tasks from a text file
void loadTasksFromTextFile() {
    ifstream file("tasks.txt");
    if (file) {
        tasks.clear();
        Task task;
        string line;

        while (getline(file, line)) {
            if (line.find("Task Name: ") == 0) {
                task.name = line.substr(11);
            } else if (line.find("Due Date: ") == 0) {
                task.dueDate = line.substr(10);
            } else if (line.find("Priority: ") == 0) {
                task.priority = line.substr(10);
            } else if (line.find("Category: ") == 0) {
                task.category = line.substr(10);
            } else if (line.find("Notes: ") == 0) {
                task.notes = line.substr(7);
            } else if (line.find("-----") == 0) {
                tasks.push_back(task);
                task = Task();
            }
        }
        if (!task.name.empty()) {
            tasks.push_back(task); // Add the last task if not empty
        }
        file.close();
        cout << "Tasks loaded from tasks.txt\n";
    } else {
        cout << "No saved tasks found.\n";
    }
}

// Main function to display menu
int main() {
    int choice;

    loadTasksFromTextFile(); // Load tasks when the program starts

    do {
        cout << "\n=== Command-Line Task Manager ===\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Sort Tasks\n";
        cout << "4. Display Tasks by Category\n";
        cout << "5. Delete Task\n";
        cout << "6. Save Tasks to File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the newline from input buffer

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                sortTasks();
                break;
            case 4:
                displayTasksByCategory();
                break;
            case 5:
                deleteTask();
                break;
            case 6:
                saveTasksToTextFile(); // Save tasks on demand
                break;
            case 7:
                saveTasksToTextFile(); // Save tasks when exiting
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
