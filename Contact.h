/**
 * Project SimplePhoneBook
 */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

using namespace std;

class Contact
{
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string email;

public:
    Contact();
    Contact(string first, string last, string number, string mail);

    string getFirstName() const;
    string getLastName() const;
    string getPhoneNumber() const;
    string getEmail() const;

    void setFirstName(string first);
    void setLastName(string last);
    void setPhoneNumber(string number);
    void setEmail(string mail);
};

#endif
