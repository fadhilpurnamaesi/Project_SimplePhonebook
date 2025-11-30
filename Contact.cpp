/**
 * Project SimplePhoneBook
 */

#include "Contact.h"

Contact::Contact()
{
    firstName = "";
    lastName = "";
    phoneNumber = "";
    email = "";
}

Contact::Contact(string first, string last, string number, string mail)
{
    firstName = first;
    lastName = last;
    phoneNumber = number;
    email = mail;
}

string Contact::getFirstName() const { return firstName; }
string Contact::getLastName() const { return lastName; }
string Contact::getPhoneNumber() const { return phoneNumber; }
string Contact::getEmail() const { return email; }

void Contact::setFirstName(string first) { firstName = first; }
void Contact::setLastName(string last) { lastName = last; }
void Contact::setPhoneNumber(string number) { phoneNumber = number; }
void Contact::setEmail(string mail) { email = mail; }
