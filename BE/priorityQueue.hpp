#ifndef PRIORITY_H
#define PRIORITY_H
#include <string>

class TODO_EVENT{

    public:
        priorityQueue(int prioirty, std::string info)
        {
            this->priority = prioirty;
            this->info = info;
        }

        std::string getInfo();
        int getPriority();

        //addEvent(int priority, std::string info);

    private:
        int priority;
        std::string info;


};

#endif