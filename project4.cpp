#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task {
    int index;
    string details;
    bool completed;
};

class Tasks {
    vector<Task> t;  
public:
    void addTask(string new_task) {
        Task newTask;            
        newTask.details = new_task; 
        newTask.completed = false;   
        newTask.index = t.size(); 
        t.push_back(newTask);       
    }

    void deleteTask(int i) {
        if (i >= 0 && i < t.size()) {  
            t.erase(t.begin() + i);

            for (int j = i; j < t.size(); ++j) {
                t[j].index = j;
            }
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void displayTasks() {
        cout << "Tasks:" << endl;
        for (const auto& task : t) {
            string status = task.completed ? "✔️" : "❌"; 
            cout << task.index << " : " << task.details << "   " << status << endl;
        }
    }

    void markAsComplete(int i) {
        if (i >= 0 && i < t.size()) {
            t[i].completed = true;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void editTask(int i) {
        if (i < 0 || i >= t.size()) {
            cout << "Invalid task index." << endl;
            return;
        }

        int a;
        cout << "What do you want to change in the task? " << endl;
        cout << "Press 1 for changing details and 2 for changing completion status: " << endl;
        cin >> a;

        if (a == 1) {
            cin.ignore(); 
            string task_detail;
            cout << "Enter new details for task " << i << ": ";
            getline(cin, task_detail);
            t[i].details = task_detail;

        } else if (a == 2) {
            int check;
            cout << "Change the completion status of your task " << i << endl;
            cout << "If the task is completed, press 1 else 0: " << endl;
            cin >> check;
            t[i].completed = (check == 1); 
        } else {
            cout << "Invalid option." << endl;
        }
    }
};

int main() {
    Tasks taskManager; 

    cout << "Welcome to Task Tracker ... " << endl;

    while (true) {
        cout << "Enter the number according to the task you want to do in the TaskTracker" << endl;
        cout << "1. Add a Task" << endl;
        cout << "2. Edit any task" << endl;
        cout << "3. Delete any task" << endl;
        cout << "4. Mark the tasks you have completed as checked" << endl;
        cout << "5. Display all the tasks" << endl;
        cout << "6. Quit from the app" << endl;
        int c;
        cout << "Enter your choice: ";
        cin >> c;

        switch (c) {
            case 1: {
                string new_task;
                cin.ignore();
                cout << "Enter the details of the new task: ";
                getline(cin, new_task);
                taskManager.addTask(new_task);
                break;
            }

            case 2: {
                int index;
                cout << "Enter the index of the task you want to edit: ";
                cin >> index;
                taskManager.editTask(index);
                break;
            }

            case 3: {
                int index;
                cout << "Enter the index of the task you want to delete: ";
                cin >> index;
                taskManager.deleteTask(index);
                break;
            }

            case 4: {
                int index;
                cout << "Enter the index of the task you want to mark as completed: ";
                cin >> index;
                taskManager.markAsComplete(index);
                break;
            }

            case 5:
                taskManager.displayTasks();
                break;

            case 6:
                cout << "Quitting the app..." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
