#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main()
{
    PriorityQueue pq;

    int choice;
    int value;

    while (true)
    {
        cout << "\n===== EVACUATE - PRIORITY QUEUE =====\n";
        cout << "1. Insert priority\n";
        cout << "2. Remove highest priority\n";
        cout << "3. Display queue\n";
        cout << "4. Check if empty\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter priority value: ";
            cin >> value;

            pq.insert(value);
        }
        else if (choice == 2)
        {
            value = pq.remove();

            if (value != -1)
            {
                cout << "Removed priority: " << value << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Priority Queue: ";
            pq.display();
        }
        else if (choice == 4)
        {
            if (pq.isEmpty())
                cout << "Priority Queue is empty.\n";
            else
                cout << "Priority Queue is not empty.\n";
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
