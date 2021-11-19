#include "network.h"
#include "profile.h"
#include <string>
#include <cctype>

Network::Network() { 
    numUsers = 0; 
}

int Network::findID(std::string user) { 
    for(int i = 0; i < numUsers; i++) { 
        if(profiles[i].getUsername() == user) { 
            return i; 
        }
    }

    return -1;
}

bool Network::addUser(std::string username, std::string display) { 
    if(numUsers == MAX_USERS) { 
        return false; 
    } else if(findID(username) != -1) { 
        return false; 
    }

    for(int i = 0; i < username.size(); i++) { 
        if(!isalnum(username.at(i))) { 
            return false; 
        }
    }

    profiles[numUsers] = { username, display };
    numUsers++;
    return true;
}