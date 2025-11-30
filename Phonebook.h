/**
 * Project SimplePhoneBook
 */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Contact.h"
#include <vector>

using namespace std;

class Phonebook
{
private:
    vector<Contact> contacts;
    int currentIndex = 0;

public:
    Phonebook();
    void addContact(const Contact &c);
    void editContact(int index, const Contact &c);
    void deleteContact(int index);
    void viewCurrent() const;
    void nextContact();
    void previousContact();
    void displayAll() const;
    int searchByName(const string &name) const;
    void loadFromFile(const string &fileName);
    void saveToFile(const string &fileName) const;
    int size() const;
};

#endif
