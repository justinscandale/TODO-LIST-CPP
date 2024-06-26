#include "event.hpp"
#include <iostream>

std::string EVENT::date_to_string() // return string of proper date
{
    int date = EVENT::getPriorityDate();

    int year = date / 10000;
    int month = (date / 100) % 100;
    int day = date % 100;
    std::string monthStr;
    switch (month)
    {
    case 1:
        monthStr = "January";
        break;
    case 2:
        monthStr = "February";
        break;
    case 3:
        monthStr = "March";
        break;
    case 4:
        monthStr = "April";
        break;
    case 5:
        monthStr = "May";
        break;
    case 6:
        monthStr = "June";
        break;
    case 7:
        monthStr = "July";
        break;
    case 8:
        monthStr = "August";
        break;
    case 9:
        monthStr = "September";
        break;
    case 10:
        monthStr = "October";
        break;
    case 11:
        monthStr = "November";
        break;
    case 12:
        monthStr = "December";
        break;
    default:
        monthStr = "Invalid";
        break;
    }

    std::string output = std::to_string(day) + " " + monthStr + " " + std::to_string(year);
    return output;
};

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
};

int EVENT::getPriorityLevel()
{
    return priorityLevel;
};

std::map<std::string, std::string> EVENT::eventToDictionary() // put event in dictionary to be used in api call
{
    std::map<std::string, std::string> temp;
    temp["Name"] = name;
    temp["ID"] = std::to_string(uniqueID);
    temp["Description"] = info;
    temp["Date"] = date_to_string();
    temp["Status"] = complete ? "Complete" : "Incomplete";
    switch(priorityLevel)
    {
        case 1: temp["Priority"] = "Very Low"; break;
        case 2: temp["Priority"] = "Low"; break;
        case 3: temp["Priority"] = "Medium"; break;
        case 4: temp["Priority"] = "High"; break;
        case 5: temp["Priority"] = "Very High"; break;
    }
    return temp;
};