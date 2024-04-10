#include "event.hpp"
#include <iostream>

std::string EVENT::getName()  //return name attribute
{
    return name;
};

int EVENT::getUniqueID() //return uniqueID
{
    return uniqueID;
};

std::string EVENT::getInfo()  //return info attribute
{
    return info;
};  

int EVENT::getPriorityLevel()  //return priorityLevel attribute
{
    return priorityLevel;
};

int EVENT::getPriorityDate()  //return priorityDate attribute
{
    return priorityDate;
};  

void EVENT::toggleComplete()  //toggle complete attribute 
{
    complete = complete ? false : true;
    return;
};  

bool EVENT::getComplete()  //return completr attribute
{
    return complete;
}

std::map<std::string,std::string> EVENT::eventToDictionary()  //put event in dictionary to be used in api call
{
    std::map<std::string, std::string> temp;
    temp["name"] = name;
    temp["uniqueID"] = std::to_string(uniqueID);
    temp["info"] = info; 
    temp["priorityLevel"] = std::to_string(priorityLevel);
    temp["priorityDate"] = std::to_string(priorityDate);
    temp["complete"] = complete ? "t": "f";

    return temp;
};  