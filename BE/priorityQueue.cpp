#include "priorityQueue.hpp"

std::vector<std::map<std::string,std::string>> PriorityQueue::viewEvents(){return std::vector<std::map<std::string,std::string>>();};  //put each event into map of <string, string> and insert this into a vector
void PriorityQueue::addEvent(std::string name, int uniqueID, std::string info, int priorityLevel, int priorityDate){};  //add event to priority queue
void PriorityQueue::removeEvent(int uniqueID){};  //remove event from priority queue based on uniqueID
void PriorityQueue::sortByPriorityThenDate(){};  //sort priority queue based on priority level attribute then priority date attribute
