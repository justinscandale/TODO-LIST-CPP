#include "priorityQueue.hpp"

//put each event into map of <string, string> and insert this into a vector
std::vector<std::map<std::string,std::string>> PriorityQueue::viewEvents()  
{
    std::vector<std::map<std::string,std::string>> temp;
    
    for(EVENT* cur = root; cur!= nullptr; cur=cur->next)
    {
        temp.push_back(cur->eventToDictionary());
    }

    return temp;
};  

//add event to priority queue
void PriorityQueue::addEvent(std::string name, std::string info, int priorityLevel, int priorityDate)
{
    EVENT *newEvent = new EVENT(name,uniqueID++,info,priorityLevel,priorityDate);

    //insert at beginning if empty
    if(isEmpty())
    {
        root = newEvent;
    }
    //insert in sorted order if not empty
    else
    {
        insertEventByDate(newEvent);
    }

    size++;

    return;
};  

//remove event from priority queue based on uniqueID
void PriorityQueue::removeEvent(int uniqueID)
{
    if(isEmpty()) {return;};

    //search for event
    EVENT* prev = nullptr;
    EVENT* cur = root;

    while(cur != nullptr && cur->getUniqueID() != uniqueID)
    {
        prev = cur;
        cur = cur->next;
    }

    //remove EVENT from beginning of priority queue
    if(prev==nullptr)
    {
        root = root->next;
    }
    //remove EVENT from anywhere else in priority queue
    else if(cur!=nullptr)
    {
        prev->next = cur->next;
        delete(cur);
    }
    //EVENT not found
    else
    {
        return;
    }

}; 

//sort priority queue based on priority level attribute then priority date attribute
void PriorityQueue::sortByPriority()
{
    return;
}; 

//return true if priority queue is empty
bool PriorityQueue::isEmpty()
{
    return size == 0 ? true : false;
};

//insert EVENT in prioirty queue in order of date then prioirty 
void PriorityQueue::insertEventByDate(EVENT *ptr)
{   
    EVENT *cur = root;
    EVENT *prev = nullptr;

    while(cur!=nullptr && ptr->getPriorityDate()>cur->getPriorityDate())
    {
        prev = cur;
        cur = cur->next;
    }

    if(prev == nullptr)
    {
        ptr->next = root;
        root = ptr;
    }
    else
    {
        ptr->next = cur;
        prev->next = ptr;
    }
};

//print prioirity queue
void PriorityQueue::printPriorityQueue()
{
    for(EVENT *cur = root; cur!=nullptr; cur=cur->next)
    {   
        std::cout<<cur->getName()<<"  "<<cur->getInfo()<<"  "
        <<std::to_string(cur->getPriorityDate())<<"  "
        <<std::to_string(cur->getUniqueID()) <<std::endl;
    }
    return;
};