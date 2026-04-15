#include "User.h"
#include <iostream>

using namespace std;

//cc
User::User(string userName) {
    name = userName;
}

string User::getName() {
    return name;
}

void User::displayProfile() {
    cout << "User: " << name << endl;
}
