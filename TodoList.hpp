#ifndef TODOLIST_H
#define TODOLIST_H
#include <string>
#include <vector>
#include "event.hpp"
#include "TodoList.hpp"

class TodoList{

    public:
        TodoList(){};  //constructor

        std::vector<std::map<std::string,std::string>> viewEvents();  //put each event into map of <string, string> and insert this into a vector
        void addEvent(std::string name, std::string info = "", int priorityLevel = 3, int priorityDate = 99999999);  //add event to priority queue
        void removeEvent(int uniqueID);  //remove event from priority queue based on uniqueID
        void sortByPriority();  //sort priority queue based on priority level attribute then priority date attribute

        //possible helper functions?
        bool isEmpty();  //return true if priority queue is empty
        void insertEventByDate(EVENT *ptr);  //insert EVENT in prioirty queue in order of date then prioirty 
        void printPriorityQueue();  //print priority queue
    
    private:
        int uniqueID = 0;  //unique id assigned to each todo event
        EVENT *root = nullptr;  //holds root of priority queue
        int size = 0;  //size of priority queue

};

#endif