// Controller.cpp

#include "Controller.h"
#include <iostream>
#include <conio.h>
#include "Phonebook.h"
#include "Contact.h"

using namespace std;

void Controller::commandLoop()
{
    Phonebook pb;
    string first, last, number, email;
    int index;
    int choice;

    do
    {
        cout << "\n Select an option:\n";
        cout << "  1. Add contact\n";
        cout << "  2. Edit current contact\n";
        cout << "  3. Delete contact\n";
        cout << "  4. View current contact\n";
        cout << "  5. View next contact\n";
        cout << "  6. View previous contact\n";
        cout << "  7. Search Contact\n";
        cout << "  8. Display all contact\n";
        cout << "  9. Load contact from input file\n";
        cout << " 10. Save all contact to file\n";
        cout << " 0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "First name : ";
            cin >> first;
            cout << "Last name  : ";
            cin >> last;
            cout << "Number     : ";
            cin >> number;
            cout << "Email      : ";
            cin >> email;
            pb.addContact(Contact(first, last, number, email));
            break;

        case 2:
            cout << "Index to Update: ";
            cin >> index;
            if (index >= 0 && index < pb.size())
            {
                cout << "New first name : ";
                cin >> first;
                cout << "New last name  : ";
                cin >> last;
                cout << "New number     : ";
                cin >> number;
                cout << "New email      : ";
                cin >> email;
                pb.editContact(index, Contact(first, last, number, email));
            }
            else
            {
                cout << "Invalid index.\n";
            }
            break;

        case 3:
            cout << "Index to delete: ";
            cin >> index;
            pb.deleteContact(index);
            break;

        case 4:
            pb.viewCurrent();
            break;

        case 5:
            pb.nextContact();
            break;

        case 6:
            pb.previousContact();
            break;

        case 7:
            cout << "Name: ";
            cin >> first;
            index = pb.searchByName(first);
            if (index != -1)
                cout << "Found at index: " << index << "\n";
            else
                cout << "Not found.\n";
            break;

        case 8:
            pb.displayAll();
            break;

        case 9:
            pb.loadFromFile("input.txt");
            cout << "Loaded from file.\n";
            break;

        case 10:
            pb.saveToFile("output.txt");
            cout << "Saved. Exiting...\n";
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}
