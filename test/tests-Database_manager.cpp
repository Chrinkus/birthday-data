#include <catch2/catch.hpp>

#include "Database_manager.hpp"

#include <shixxy/Sxy_Database.hpp>
#include "Contact.hpp"

#include <algorithm>

std::vector<Contact> data {
    { "Shigeru", "Miyamoto", "1952-11-16" },
    { "Yu", "Suzuki", "1958-06-10" },
    { "Hideo", "Kojima", "1963-08-24" },
    { "Shinji", "Mikami", "1965-08-11" }
};

TEST_CASE("Database_manager manages contacts database", "[Database_manager]") {
    Database_manager db {":memory:"};

    auto vcontacts = db.contact_dao.contacts();
    REQUIRE(vcontacts.empty() == true);

    for (auto& c : data) {
        db.contact_dao.create_contact(c);
    }

    vcontacts = db.contact_dao.contacts();
    REQUIRE(vcontacts.size() == 4);

    auto it1 = std::find_if(std::begin(vcontacts), std::end(vcontacts),
            [](const auto& c) { return c->first() == "Shigeru"; });
    REQUIRE(it1 != std::end(vcontacts));

    auto it2 = std::find_if(std::begin(vcontacts), std::end(vcontacts),
            [](const auto& c) { return c->last() == "Kojima"; });
    REQUIRE(it2 != std::end(vcontacts));
}
