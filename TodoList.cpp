#include "TodoList.hpp"

// put each event into map of <string, string> and insert this into a vector
std::vector<std::map<std::string, std::string>> TodoList::viewEvents()
{
    std::vector<std::map<std::string, std::string>> temp;

    for (EVENT *cur = root; cur != nullptr; cur = cur->next)
    {
        temp.push_back(cur->eventToDictionary());
    }

    return temp;
};

// add event to priority queue
void TodoList::addEvent(std::string name, std::string info, int priorityDate, int priorityLevel)
{
    EVENT *newEvent = new EVENT(name, uniqueID++, info, priorityDate, priorityLevel);

    // insert at beginning if empty
    if (isEmpty())
    {
        root = newEvent;
    }
    // insert in sorted order if not empty
    else
    {
        insertEventByDate(newEvent);
    }

    size++;

    return;
};

// remove event from priority queue based on uniqueID
void TodoList::removeEvent(int uniqueID)
{
    if (isEmpty())
    {
        return;
    };

    // search for event
    EVENT *prev = nullptr;
    EVENT *cur = root;

    while (cur != nullptr && cur->getUniqueID() != uniqueID)
    {
        prev = cur;
        cur = cur->next;
    }

    // remove EVENT from beginning of priority queue
    if (prev == nullptr)
    {
        root = root->next;
    }
    // remove EVENT from anywhere else in priority queue
    else if (cur != nullptr)
    {
        prev->next = cur->next;
        delete (cur);
    }
    // EVENT not found
    else
    {
        return;
    }
};

// mark event complete/incomplete from priority queue based on uniqueID
void TodoList::toggleEventCompletion(int uniqueID)
{
    if (isEmpty())
    {
        return;
    };

    // search for event
    EVENT *prev = nullptr;
    EVENT *cur = root;

    while (cur != nullptr && cur->getUniqueID() != uniqueID)
    {
        prev = cur;
        cur = cur->next;
    }

    // remove EVENT from anywhere else in priority queue
    if (cur != nullptr)
    {
        cur->toggleComplete();
    }
    // EVENT not found
    else
    {
        return;
    }
};

// return true if priority queue is empty
bool TodoList::isEmpty()
{
    return size == 0 ? true : false;
};

// insert EVENT in priority queue in order of date then prioirty
void TodoList::insertEventByDate(EVENT *ptr)
{
    EVENT *cur = root;
    EVENT *prev = nullptr;

    while (cur != nullptr && ptr->getPriorityDate() > cur->getPriorityDate())
    {
        prev = cur;
        cur = cur->next;
    }

    if (prev == nullptr)
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

// print priority queue
void TodoList::printTodoList()
{
    for (EVENT *cur = root; cur != nullptr; cur = cur->next)
    {
        std::cout << cur->getName() << "  " << cur->getInfo() << "  "
                  << std::to_string(cur->getPriorityDate()) << "  "
                  << std::to_string(cur->getUniqueID()) << std::endl;
    }
    return;
};
EVENT* TodoList::mergeSortHelper(EVENT* start, std::string attribute)
{
    // Base case: If the list has only one element or is empty, return it
    if (start == nullptr || start->next == nullptr)
        return start;

    // Find the middle of the list
    EVENT* slow = start;
    EVENT* fast = start->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    EVENT* mid = slow->next;
    slow->next = nullptr;

    // Recursively sort the two halves
    EVENT* left = mergeSortHelper(start, attribute);
    EVENT* right = mergeSortHelper(mid, attribute);

    // Merge the sorted halves
    return merge(left, right, attribute);
};

EVENT* TodoList::merge(EVENT* left, EVENT* right, std::string attribute)
{
    EVENT dummy("Dummy", 0); // Dummy node for merging
    EVENT* tail = &dummy;

    while (left != nullptr && right != nullptr)
    {
        // Compare events based on the specified attribute
        if (attribute == "priorityDate")
        {
            if (left->getPriorityDate() <= right->getPriorityDate())
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
        }
        else
        {
            // Handle other attribute
            if (left->getPriorityLevel() <= right->getPriorityLevel())
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
        }

        tail = tail->next;
    }

    // Attach the remaining nodes of left and right halves, if any
    if (left != nullptr)
        tail->next = left;
    else
        tail->next = right;

    return dummy.next;
};

void TodoList::mergeSort(std::string attribute)
    {
        if (isEmpty() || size == 1)
            return; // No need to sort if empty or only one event

        root = mergeSortHelper(root, attribute);
    };