#include "event.cpp"
#include "priorityQueue.cpp"

//main used for testing 
int main()
{
    EVENT myEvent = EVENT("MY EVENT",100);
    std::cout<< myEvent.getName();

    return 0;
}