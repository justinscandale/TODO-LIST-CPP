// #include "event.cpp"
// #include "priorityQueue.cpp"
// #include <iostream>
// #include <string>

// // main used for testing
// int main()
// {
//     // EVENT myEvent = EVENT("NAME_HERE",999,"INFORMATION_HERE",1,02042025);

//     // //tests for event methods + print out map contents
//     // myEvent.toggleComplete();
//     // std::map<std::string,std::string> output = myEvent.eventToDictionary();
//     // for(auto& t: output)
//     // {
//     //     std::cout<< t.first << " "
//     //         <<t.second << "\n";
//     // }

//     // test methods for priority queue
//     // PriorityQueue pq = PriorityQueue();
//     // pq.addEvent("EXAMPLE1", "deets1", 1, 20000101);
//     // pq.addEvent("EXAMPLE2", "deets2", 1, 20010101);
//     // pq.addEvent("EXAMPLE3", "deets3", 1, 20010101);
//     // pq.addEvent("EXAMPLE4", "deets4", 1, 20000102);
//     // pq.removeEvent(2);
//     // pq.printPriorityQueue();

//     // // print out vector of maps
//     // std::vector<std::map<std::string, std::string>> temp = pq.viewEvents();
//     // std::cout << "\n\n";
//     // for (size_t i = 0; i < temp.size(); i++)
//     // {
//     //     std::cout << i << "th Event in PRIORIRTY QUEUE\n";
//     //     for (auto &t : temp[i])
//     //     {
//     //         std::cout << t.first << " "
//     //                   << t.second << "\n";
//     //     }
//     //     std::cout << "\n\n";
//     // }
//     PriorityQueue pq;
//     int choice;
//     std::string eventName, eventDetails;
//     int eventPriority, eventDate;

//     while (true)
//     {
//         std::cout << "\nPlease choose an option:\n";
//         std::cout << "1. Add event\n";
//         std::cout << "2. Remove event\n";
//         std::cout << "3. View events\n";
//         std::cout << "4. Exit\n";
//         std::cout << "Enter your choice: ";
//         std::cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             std::cout << "Enter event name: ";
//             std::cin >> eventName;
//             std::cout << "Enter event details: ";
//             std::cin >> eventDetails;
//             std::cout << "Enter event priority: ";
//             std::cin >> eventPriority;
//             std::cout << "Enter event date (YYYYMMDD): ";
//             std::cin >> eventDate;
//             pq.addEvent(eventName, eventDetails, eventPriority, eventDate);
//             break;
//         case 2:
//             std::cout << "Enter event priority to remove: ";
//             std::cin >> eventPriority;
//             pq.removeEvent(eventPriority);
//             break;
//         case 3:
//             std::vector<std::map<std::string, std::string>> temp = pq.viewEvents();
//             for (size_t i = 0; i < temp.size(); i++)
//             {
//                 std::cout << i << "th Event in PRIORITY QUEUE\n";
//                 for (auto &t : temp[i])
//                 {
//                     std::cout << t.first << " " << t.second << "\n";
//                 }
//                 std::cout << "\n\n";
//             }
//             break;
//         case 4:
//             std::cout << "Exiting...\n";
//             return 0;
//         default:
//             std::cout << "Invalid choice. Please choose a valid option.\n";
//         }
//     }

//     return 0;
// }

#include "event.cpp"
#include <iostream>
#include <string>
#include "priorityQueue.cpp"

int main()
{
    PriorityQueue pq = PriorityQueue();
    int choice;
    std::string eventName, eventDetails;
    int eventPriority, eventDate, eventUniqueID;
    std::vector<std::map<std::string, std::string>> temp;

    while (true)
    {
        std::cout << "\nPlease choose an option:\n";
        std::cout << "1. Add event\n";
        std::cout << "2. Remove event\n";
        std::cout << "3. View events\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Clear the newline character left in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\n";

        switch (choice)
        {
        case 1:
            std::cout << "Enter event name: ";
            std::getline(std::cin, eventName);
            std::cout << std::endl;

            std::cout << "Enter event details: ";
            std::getline(std::cin, eventDetails);
            std::cout << std::endl;

            std::cout << "Enter event priority: ";
            std::cin >> eventPriority;
            std::cout << std::endl;

            std::cout << "Enter event date (YYYYMMDD): ";
            std::cin >> eventDate;
            std::cout << std::endl;

            pq.addEvent(eventName, eventDetails, eventPriority, eventDate);
            std::cout << "Event added successfully.\n";
            break;
        case 2:
            std::cout << "Enter unique ID of event to remove: ";
            std::cin >> eventUniqueID;
            pq.removeEvent(eventUniqueID);
            break;
        case 3:
            temp = pq.viewEvents();
            if (temp.size() == 0)
            {
                std::cout << "No events on the list.\n";
                break;
            }
            for (size_t i = 0; i < temp.size(); i++)
            {
                std::cout << i + 1 << "th Event on the TODO list\n";
                for (auto &t : temp[i])
                {
                    std::cout << t.first << " " << t.second << "\n";
                }
                std::cout << "\n\n";
            }
            break;
        case 4:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please choose a valid option.\n";
        }
    }

    return 0;
}
