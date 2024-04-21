#include "event.cpp"
#include "priorityQueue.cpp"

//main used for testing 
int main()
{
    //EVENT myEvent = EVENT("NAME_HERE",999,"INFORMATION_HERE",1,02042025);
    
    // //tests for event methods + print out map contents
    // myEvent.toggleComplete();
    // std::map<std::string,std::string> output = myEvent.eventToDictionary();
    // for(auto& t: output)
    // {
    //     std::cout<< t.first << " "
    //         <<t.second << "\n";
    // }

    //test methods for priority queue
    PriorityQueue pq = PriorityQueue();
    pq.addEvent("EXAMPLE1","deets1",1,20000101);
    pq.addEvent("EXAMPLE2","deets2",1,20010101);
    pq.addEvent("EXAMPLE3","deets3",1,20010101);
    pq.addEvent("EXAMPLE4","deets4",1,20000102);
    pq.removeEvent(2);
    pq.printPriorityQueue();

    //print out vector of maps
    std::vector<std::map<std::string,std::string>> temp = pq.viewEvents();
    std::cout<<"\n\n";
    for(size_t i = 0; i<temp.size(); i++)
    {
        std::cout<< i << "th Event in PRIORIRTY QUEUE\n";
        for(auto& t: temp[i])
        {
            std::cout<< t.first << " "
                <<t.second << "\n";
        }
        std::cout<<"\n\n";
    }

    return 0;
}