#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <map>

class EVENT
{

public:
    EVENT(std::string name, int uniqueID, std::string info = "", int priorityDate = 99999999) // constructor with default values
    {
        this->name = name;
        this->uniqueID = uniqueID;
        this->info = info;
        this->priorityDate = priorityDate;
        this->complete = false;
        this->next = nullptr;
    };

    EVENT *next;                                            // pointer to next todo event (used in priority queue)

<<<<<<< HEAD
    int getUniqueID();                                      // return uniqueID
    std::string getName();                                  // return name attribute
    std::string getInfo();                                  // return info attribute
    int getPriorityLevel();                                 // return priorityLevel attribute
    int getPriorityDate();                                  // return priorityDate attribute
    void toggleComplete();                                  // toggle complete attribute
    bool getComplete();                                     // return complete attribute
    std::map<std::string, std::string> eventToDictionary(); // put event in dictionary to be used in api call

private:
    int uniqueID;     // unique id for event
    std::string name; // name of todo event
    std::string info; // description of todo event
    int priorityDate; // in format (YYYYMMDD)
    bool complete;    // true when todo task is completed
=======
        std::string date_to_string(); //returns string of proper date
        int getUniqueID();  //return uniqueID
        std::string getName();  //return name attribute
        std::string getInfo();  //return info attribute
        int getPriorityDate();  //return priorityDate attribute
        void toggleComplete();  //toggle complete attribute
        bool getComplete();  //return complete attribute
        std::map<std::string,std::string> eventToDictionary();  //put event in dictionary to be used in api call

    private:
        int uniqueID;  //unique id for event
        std::string name;  //name of todo event
        std::string info;  //description of todo event
        int priorityDate; //in format (YYYYMMDD)
        bool complete;  //true when todo task is completed
>>>>>>> refs/remotes/origin/main
};

#endif