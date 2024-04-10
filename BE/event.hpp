#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <map>

class EVENT{

    public:
        EVENT(std::string name, int uniqueID, std::string info = "", int priorityLevel = 3, int priorityDate = 99999999)  //constructor with default values 
        {
            this->name = name;
            this->uniqueID = uniqueID;
            this->info = info;
            this->priorityLevel = priorityLevel;
            this->priorityDate = priorityDate;
            this->complete = false;
            this->next = nullptr;
        };

        std::string getName();  //return name attribute
        std::string getInfo();  //return info attribute
        int getPriorityLevel();  //return priorityLevel attribute
        int getPriorityDate();  //return priorityDate attribute
        void markComplete();  //change complete attribute to true
        void markIncomplete();  //change complete attribute to false
        std::map<std::string,std::string> eventToDictionary();  //put event in dictionary to be used in api call

    private:
        int uniqueID;  //unique id for event
        std::string name;  //name of todo event
        std::string info;  //description of todo event
        int priorityLevel; //in format (0-High, 1-Medium, 2-Low, 3-None)
        int priorityDate; //in format (DDMMYYYY)
        EVENT *next;  //pointer to next todo event (used in priority queue)
        bool complete;  //true when todo task is completed
};

#endif