/**
 * Project SimplePhoneBook
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Phonebook.h"

class Controller
{
private:
    Phonebook pb;

public:
    void commandLoop();
};

#endif
