#include <catch2/catch.hpp>

#include "Contact_dao.hpp"

#include "Contact.hpp"
#include <shixxy/Sxy_Database.hpp>

#include <algorithm>

TEST_CASE("Contact_dao interacts with Sxy::Database", "[Contact_dao]") {
    Sxy::Database db;
    db.open(":memory:");
    Contact_dao dao {db};
    REQUIRE(db.has_table("contacts") == false);

    dao.init();
    REQUIRE(db.has_table("contacts") == true);

    SECTION("Contact_dao:: CRUD operations work") {

        Contact pam { "Pam", "Beesly", "1974-03-07" };
        Contact jim { "Jim", "Halpert", "1979-10-20" };
        Contact dwight { "Dwight", "Schrute", "1966-01-20" };

        dao.create_contact(pam);
        dao.create_contact(jim);
        dao.create_contact(dwight);

        REQUIRE(pam.id() == 1);
        REQUIRE(jim.id() == 2);
        REQUIRE(dwight.id() == 3);

        auto vcontacts = dao.contacts();
        REQUIRE(vcontacts.size() == 3);

        auto it = std::find_if(std::begin(vcontacts), std::end(vcontacts),
                [](const auto& pc) { return pc->first() == "Jim"; });
        REQUIRE(it != std::end(vcontacts));

        dao.delete_contact((*it)->id());
        vcontacts = dao.contacts();
        REQUIRE(vcontacts.size() == 2);
        
        it = std::find_if(std::begin(vcontacts), std::end(vcontacts),
                [](const auto& pc) { return pc->first() == "Jim"; });
        REQUIRE(it == std::end(vcontacts));

        REQUIRE(vcontacts.front()->last() == "Beesly");
        REQUIRE(vcontacts.front()->email().empty() == true);
        REQUIRE(vcontacts.front()->phone().empty() == true);
        pam.last("Halpert");
        pam.email("pam@dundermifflin.com");
        pam.phone("(999) 555-5678");
        dao.update_contact(pam);
        vcontacts = dao.contacts();
        REQUIRE(vcontacts.front()->last() == "Halpert");
        REQUIRE(vcontacts.front()->email() == "pam@dundermifflin.com");
        REQUIRE(vcontacts.front()->phone() == "(999) 555-5678");
    }
}
