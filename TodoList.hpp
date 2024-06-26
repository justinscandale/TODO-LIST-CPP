#ifndef TODOLIST_H
#define TODOLIST_H
#include <string>
#include <vector>
#include "event.hpp"
#include "TodoList.hpp"

class TodoList
{

public:
    TodoList(){}; // constructor
    ~TodoList()
{
    EVENT *cur = root;
    while (cur != nullptr)
    {
        EVENT *next = cur->next;
        std::cout<<"DELETED EVENT WITH ID: " + std::to_string(cur->getUniqueID());
        delete cur;
        cur = next;
    }
};
    void mergeSort(std::string attribute);
    std::vector<std::map<std::string, std::string>> viewEvents();                        // put each event into map of <string, string> and insert this into a vector
    void addEvent(std::string name, std::string info = "", int priorityDate = 99999999, int priorityLevel = 0); // add event to priority queue
    void removeEvent(int uniqueID);                                                      // remove event from priority queue based on uniqueID                                                             // sort priority queue based on priority level attribute then priority date attribute
    void toggleEventCompletion(int uniqueID);
    bool isEmpty();                     // return true if priority queue is empty
    void insertEventByDate(EVENT *ptr); // insert EVENT in prioirty queue in order of date then prioirty
    void printTodoList();               // print priority queue

private:
    EVENT* mergeSortHelper(EVENT* start, std::string attribute);
    EVENT* merge(EVENT* left, EVENT* right, std::string attribute);
    int uniqueID = 0;      // unique id assigned to each todo event
    EVENT *root = nullptr; // holds root of priority queue
    int size = 0;          // size of priority queue
};

#endif