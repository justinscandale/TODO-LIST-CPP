#include "event.cpp"
#include <iostream>
#include <string>
#include "TodoList.cpp"

// Function to display menu
void displayMenu()
{
    std::cout << "\n====================== TODO LIST ======================\n";
    std::cout << "Please choose an option:\n";
    std::cout << "1. Add Event\n";
    std::cout << "2. Mark Event Complete/Incomplete\n";
    std::cout << "3. Remove Event\n";
    std::cout << "4. View Events\n";
    std::cout << "5. Exit\n";
    std::cout << "=======================================================\n";
    std::cout << "Enter your choice: ";
}

// Function to clear input buffer
void clearInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    TodoList pq = TodoList();
    int choice;
    std::string eventName, eventDetails, eventDateFromUser, monthStr, dayStr, yearStr;
    int eventDate, eventUniqueID, month, day, year;
    std::vector<std::map<std::string, std::string>> temp;

    while (true)
    {
        displayMenu();
        std::cin >> choice;
        clearInputBuffer();

        std::cout << "\n";

        switch (choice)
        {
        case 1:
            std::cout << "======= ADD NEW EVENT =======\n";
            std::cout << "Enter event name: ";
            std::getline(std::cin, eventName);

            std::cout << "Enter event details: ";
            std::getline(std::cin, eventDetails);

            std::cout << "Enter event date (MM/DD/YYYY): ";
            std::cin >> eventDateFromUser;
            clearInputBuffer();

            // Validate the date format
            if (eventDateFromUser.length() != 10 || eventDateFromUser[2] != '/' || eventDateFromUser[5] != '/')
            {
                std::cout << "Invalid date format. Please enter the date in MM/DD/YYYY format.\n";
                continue;
            }

            // Extract the date components
            monthStr = eventDateFromUser.substr(0, 2);
            dayStr = eventDateFromUser.substr(3, 2);
            yearStr = eventDateFromUser.substr(6, 4);

            // Convert the date components to integers
            month = std::stoi(monthStr);
            day = std::stoi(dayStr);
            year = std::stoi(yearStr);

            // Validate the date values
            if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1900 || year > 2100)
            {
                std::cout << "Invalid date values. Please enter a valid date.\n";
                continue;
            }

            // Combine the date components into a single integer
            eventDate = year * 10000 + month * 100 + day;

            pq.addEvent(eventName, eventDetails, eventDate);
            std::cout << "\nEvent added successfully.\n";

            break;
        case 2:
            std::cout << "======= MARK EVENT COMPLETE/INCOMPLETE =======\n";
            std::cout << "Enter unique ID of event to mark: ";
            std::cin >> eventUniqueID;
            clearInputBuffer();
            pq.toggleEventCompletion(eventUniqueID);
            std::cout << "\nEvent completion toggled successfully.\n";
            break;
        case 3:
            std::cout << "======= REMOVE EVENT =======\n";
            std::cout << "Enter unique ID of event to remove: ";
            std::cin >> eventUniqueID;
            clearInputBuffer();
            pq.removeEvent(eventUniqueID);
            std::cout << "\nEvent removed successfully.\n";
            break;
        case 4:
            std::cout << "======= VIEW EVENTS =======\n";
            temp = pq.viewEvents();
            if (temp.empty())
            {
                std::cout << "No events on the list.\n";
                break;
            }
            for (size_t i = 0; i < temp.size(); i++)
            {
                std::cout << "===== Event " << i + 1 << " =====\n";
                for (auto &t : temp[i])
                {
                    std::cout << t.first << ": " << t.second << "\n";
                }
                std::cout << "\n";
            }
            break;
        case 5:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please choose a valid option.\n";
        }
    }

    return 0;
}
