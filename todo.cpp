#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct Task 
{
    string desc;
    bool completed;
};

Task tasks[MAX];
int totalTasks = 0;

//function to add a task, if tasks exceed limit then display a message
void add() 
{
    if (totalTasks >= MAX) 
    {
        cout<<"Task list is full.\n";
        return;
    }
    cin.ignore();
    cout<<"Enter description of new task : ";
    getline(cin, tasks[totalTasks].desc);
    tasks[totalTasks].completed = 0;
    totalTasks++;
    cout<<"Task added successfully.\n";
}

//function to view current tasks 
void view() 
{
    if (totalTasks == 0) 
    {
        cout <<"No tasks currently.\n";
        return;
    }
    cout << "\nTasks:\n";
    for (int i = 0; i < totalTasks; i++) 
    {
        cout<<i+1<< ". "<<tasks[i].desc<<" - "<<(tasks[i].completed?"Completed":"Pending")<<"\n";
    }
}

//function to mark a task as completed and if no tasks then display a message
void mark() 
{
    if (totalTasks == 0) 
    {
        cout <<"No tasks to mark.\n";
        return;
    }
    cout <<"Enter task number to mark as completed: ";
    int num;
    cin >> num;
    if (num<1 || num>totalTasks) 
    {
        cout<<"Invalid task number.\n";
    } 
    else 
    {
        tasks[num-1].completed = true;
        cout<<"Task "<<num<<" marked as completed.\n";
    }
}

//function to remove a task, if no tasks or invalid tasks then display a message
void removeTask() 
{
    if(totalTasks == 0) 
    {
        cout<<"No tasks available to remove.\n";
        return;
    }
    cout<<"Enter task number to remove: ";
    int num;
    cin>>num;
    if (num<1 || num>totalTasks) 
    {
        cout<<"Invalid task number.\n";
    }
    else 
    {
        for (int i = num-1;i < totalTasks-1;i++) 
        {
            tasks[i] =tasks[i+1];
        }
        totalTasks--;
        cout<<"Task "<<num<<" marked as completed.\n";
    }
}

//main to display the menu..Take input and call functions accordingly.
int main() 
{
    int c;
    cout<<"    __________________   __________________\n.-/|                  \\ /                  |\\-.\n";
    cout<<"||||                   |                   ||||\n||||                   |   What - To - Do  ||||\n";
    cout<<"||||    Welcome To     |                   ||||\n||||                   |        List       ||||\n";
    cout<<"||||                   |                   ||||\n||||                   |                   ||||\n";
    cout<<"||||__________________ | __________________||||\n||/===================\\|/===================\\||\n`--------------------~___~-------------------''";
    cout <<"\n1) Add Task\n2) View Tasks\n3) Mark Task as Completed\n4) Remove Task\n5) Exit\n";
    while (true) 
    {
        cout<<"\nEnter your choice: ";
        cin>>c;
        
        if (c == 1) 
        {
            add();
        }
        else if (c == 2) 
        {
            view();
        } 
        else if (c == 3) 
        {
            mark();
        } 
        else if (c == 4)
        {
            removeTask();
        } 
        else if (c == 5) 
        {
            cout<<"Exiting...\n";
            break;
        } 
        else 
        {
            cout<<"Invalid choice.Try again.\n";
        }
    }
    return 0;
}
