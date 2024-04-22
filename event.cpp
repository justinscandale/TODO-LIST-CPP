#include "event.hpp"
#include <iostream>

std::string EVENT::getName() // return name attribute
{
    return name;
};

int EVENT::getUniqueID() // return uniqueID
{
    return uniqueID;
};

std::string EVENT::getInfo() // return info attribute
{
    return info;
};

int EVENT::getPriorityDate() // return priorityDate attribute
{
    return priorityDate;
};

void EVENT::toggleComplete() // toggle complete attribute
{
    complete = complete ? false : true;
    return;
};

bool EVENT::getComplete() // return completr attribute
{
    return complete;
}

std::map<std::string, std::string> EVENT::eventToDictionary() // put event in dictionary to be used in api call
{
    std::map<std::string, std::string> temp;
    temp["Name"] = name;
    temp["ID"] = std::to_string(uniqueID);
    temp["Description"] = info;
    temp["Date"] = std::to_string(priorityDate);
    temp["Status"] = complete ? "Complete" : "Incomplete";

    return temp;
};