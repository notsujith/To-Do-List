#include <iostream>
#include <map>
#include <fstream>
using namespace std;

class Task{
protected:
    string description;
    bool isCompleted = false;
public:
    Task() : description(""), isCompleted(false) {}
    
    void setDescription(string s) { description = s; }
    string displayTask() { return description; }
    
    char Status() {
        if (isCompleted) {
            return 'X';
        }
        return ' ';
    }
    
    void markAsCompleted() { isCompleted = true; }
    
    friend ifstream &operator>>(ifstream &ifs, Task &task);
    friend ofstream &operator<<(ofstream &ofs, Task &task);
};

ifstream &operator>>(ifstream &ifs, Task &task){
    getline(ifs, task.description);
    ifs >> task.isCompleted;
    ifs.ignore();
    return ifs;
}

ofstream &operator<<(ofstream &ofs, Task &task){
    ofs << task.description << endl;
    ofs << task.isCompleted << endl;
    return ofs;
}

class TaskList{
private:
    map <int, Task> tasks;
    int index = 0;
public:
    TaskList(){
        ifstream ifs("ToDo.txt");
        if (!ifs){
            cout << "File not found" << endl;
            return;
        }
        Task task;
        while (ifs >> task){
            tasks[index++] = task;
        }
        ifs.close();
    }
    
    void addTask(Task &task);
    void removeTask(int index);
    void displayTasks();
    void markCompleted(int index) {
        if (tasks.find(index) != tasks.end()) {
            tasks[index].markAsCompleted();
        } else {
            cout << "Task ID not found.\n";
        }
    }
    
    ~TaskList(){
        ofstream ofs("ToDo.txt");
        for (auto &task : tasks){
            ofs << task.second;
        }
        ofs.close();
    }
};

void TaskList::addTask(Task &task){
    tasks[index++] = task;
}

void TaskList::removeTask(int index){
    if (tasks.find(index) == tasks.end()){
        cout << "Task ID not found.\n";
    }
    else{
        tasks.erase(index);
    }
}

void TaskList::displayTasks(){
    if (!tasks.empty()){
        for(auto &task : tasks){
            cout << task.first <<". " << "[" << task.second.Status() << "] " << task.second.displayTask() << endl;
        }
        cout << endl;
    }
    else{
        cout << "| No tasks to display |\n" << endl;
    }
}

int main(){
    Task task;
    TaskList tasks;
    int choice = 0;
    int ID;
    string description;
    do{
        system("clear");
        cout << "To-Do Application\n" << endl;
        tasks.displayTasks();
        cout << "1. Add Task\n2. Remove Task\n3. Mark Task as Completed\n4. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "Enter the description: ";
                cin.ignore();
                getline(cin, description);
                task.setDescription(description);
                tasks.addTask(task);
                cout << "Task added\n" << endl;
                break;
            case 2:
                cout << "Enter the task ID: ";
                cin >> ID;
                tasks.removeTask(ID);
                cout << "Task removed\n" << endl;
                break;
            case 3:
                cout << "Enter the ID of the task: ";
                cin >> ID;
                tasks.markCompleted(ID);
                cout << "Task marked as completed\n" << endl;
                break;
            case 4:
                cout << "Exiting the application..." << endl;
                break;
            default:
                cout << "Invalid input. Try again." << endl;
        }
    } while(choice != 4);

    return 0;
}
