#include "event.hpp"
#include <iostream>

std::string EVENT::getName()  //return name attribute
{
    return name;
};

std::string EVENT::getInfo(){return "";};  //return info attribute
int EVENT::getPriorityLevel(){return 0;};  //return priorityLevel attribute
int EVENT::getPriorityDate(){return 0;};  //return priorityDate attribute
void EVENT::markComplete(){return;};  //change complete attribute to true
void EVENT::markIncomplete(){return;};  //change complete attribute to false
std::map<std::string,std::string> EVENT::eventToDictionary(){return std::map<std::string, std::string>();};  //put event in dictionary to be used in api call