#ifndef EVENT_H
#define EVENT_H
#include <string>

class TODO_EVENT{

    public:
        TODO_EVENT(std::string name, std::string info, int priorityLevel, int priorityDate, int uniqueID)
        {
            this->name = name;
            this->info = info;
            this->priorityLevel = priorityLevel;
            this->priorityDate = priorityDate;
            this->complete = false;
            this->next = nullptr;
            this->uniqueID = uniqueID;
        }

        TODO_EVENT(std::string name)
        {
            this->name = name;
            this->info = "";
            this->priorityLevel = 3;
            this->priorityDate = 99999999;
            this->complete = false;
            this->next = nullptr;
            this->uniqueID = uniqueID;
        }

        std::string getName();  //return name attribute
        std::string getInfo();  //return info attribute
        int getPriorityLevel();  //return priorityLevel attribute
        int getPriorityDate();  //return priorityDate attribute
        void markComplete();  //change complete attribute to true
        void markIncomplete();  //change complete attribute to false

    private:
        int uniqueID;  //unique id for event
        std::string name;  //name of todo event
        std::string info;  //description of todo event
        int priorityLevel; //in format (0-High, 1-Medium, 2-Low, 3-None)
        int priorityDate; //in format (DDMMYYYY)
        TODO_EVENT *next;  //pointer to next todo event (used in priority queue)
        bool complete;  //true when todo task is completed
};

#endif