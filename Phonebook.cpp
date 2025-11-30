/**
 * Project SimplePhoneBook
 */

#include "Phonebook.h"
#include <iostream>
#include <fstream>

using namespace std;

Phonebook::Phonebook()
{
    currentIndex = -1;
}

void Phonebook::addContact(const Contact &c)
{
    contacts.push_back(c);
    if (currentIndex == -1)
        currentIndex = 0;
}

void Phonebook::editContact(int index, const Contact &c)
{
    if (index >= 0 && index < contacts.size())
        contacts[index] = c;
}

void Phonebook::deleteContact(int index)
{
    if (index >= 0 && index < contacts.size())
    {
        contacts.erase(contacts.begin() + index);
        if (contacts.empty())
            currentIndex = -1;
        else if (currentIndex >= contacts.size())
            currentIndex = contacts.size() - 1;
    }
}

void Phonebook::viewCurrent() const
{
    if (contacts.empty())
    {
        cout << "No contacts available.\n";
        return;
    }
    cout << "\nCurrent Contact:\n";
    cout << contacts[currentIndex].getFirstName() << " "
         << contacts[currentIndex].getLastName() << "|"
         << " | " << contacts[currentIndex].getPhoneNumber() << "|"
         << " | " << contacts[currentIndex].getEmail() << "\n";
}

void Phonebook::nextContact()
{
    if (!contacts.empty())
        currentIndex = (currentIndex + 1) % contacts.size();
}

void Phonebook::previousContact()
{
    if (!contacts.empty())
        currentIndex = (currentIndex - 1 + contacts.size()) % contacts.size();
}

void Phonebook::displayAll() const
{
    cout << "\nAll Contacts:\n";
    for (int i = 0; i < contacts.size(); i++)
    {
        cout << i << ". "
             << contacts[i].getFirstName() << " "
             << contacts[i].getLastName() << "|"
             << " | " << contacts[i].getPhoneNumber() << ""
             << " | " << contacts[i].getEmail() << "\n";;
    }
}

int Phonebook::searchByName(const string &name) const
{
    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts[i].getFirstName() == name ||
            contacts[i].getLastName() == name)
            return i;
    }
    return -1;
}

void Phonebook::loadFromFile(const string &fileName)
{
    ifstream file(fileName);
    if (!file.is_open())
        return;

    string first, last, number, email;

    contacts.clear();
    while (file >> first >> last >> number >> email)
    {
        contacts.push_back(Contact(first, last, number, email));
    }
    if (!contacts.empty())
        currentIndex = 0;

    file.close();
}

void Phonebook::saveToFile(const string &fileName) const
{
    ofstream file(fileName);
    for (auto &c : contacts)
    {
        file << c.getFirstName() << " "
             << c.getLastName() << " "
             << c.getPhoneNumber() << " "
             << c.getEmail() << "\n";
    }
    file.close();
}

int Phonebook::size() const
{
    return contacts.size();
}
