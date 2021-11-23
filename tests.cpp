#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

    Profile p1("marco", "Marco");    
    Profile p2("polo", "Polo");    
    Profile p3("tarma1", "Tarma Roving");    
    Profile p4("@($*!@$H(OI", "!$#*(!@$*");    
    Profile p5(" ", " ");    

    

TEST_CASE("TASK A") {
    SUBCASE("getUsername()") { 
        CHECK(p1.getUsername() == "marco");
        CHECK(p2.getUsername() == "polo");
        CHECK(p3.getUsername() == "tarma1");
        CHECK(p4.getUsername() == "@($*!@$H(OI");
        CHECK(p5.getUsername() == " ");
    }

    SUBCASE("getFullName()") { 
        CHECK(p1.getFullName() == "Marco (@marco)");
        CHECK(p2.getFullName() == "Polo (@polo)");
        CHECK(p3.getFullName() == "Tarma Roving (@tarma1)");
        CHECK(p4.getFullName() == "!$#*(!@$* (@@($*!@$H(OI)");
        CHECK(p5.getFullName() == "  (@ )");
    }
}

TEST_CASE("TASK B") {
    Network nw; 
    SUBCASE("addUser()") { 
        CHECK(nw.addUser("mario", "Mario") == true); 
        CHECK(nw.addUser("mario", "Mario") == false); 
        CHECK(nw.addUser("mario-2", "Mario2") == false);
        CHECK(nw.addUser("yoshi1", "yoshi") == true); 
        CHECK(nw.addUser("yoshi", "Yoshi") == true);
    }
}

TEST_CASE("TASK C") { 
    Network nw;
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");

    for(int i = 2; i < 20; i++) {
        nw.addUser("mario" + to_string(i), "Mario" + to_string(i))
    }

    SUBCASE("follow(user1, user2)") { 
        
    }
}
    