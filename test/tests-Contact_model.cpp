#include <catch2/catch.hpp>

#include "Contact_model.hpp"

#include "Contact.hpp"
#include "Database_manager.hpp"
#include <shixxy/Sxy_Database.hpp>

TEST_CASE("Contact_model interacts with database", "[Contact_model]") {
    std::vector<Contact> data {
        { "Mark", "Scheifele", "1993-03-15" },
        { "Blake", "Wheeler", "1986-08-31" },
        { "Patrik", "Laine", "1998-04-19" },
        { "Nikolaj", "Ehlers", "1996-02-14" },
        { "Kyle", "Connor", "1996-12-09" },
        { "Dustin", "Byfuglien", "1985-03-27" }
    };

    Database_manager db {":memory:"};

    for (auto& c : data) {
        db.contact_dao.create_contact(c);
    }

    Contact_model model {db};
    
    SECTION("num_records works") {
        REQUIRE(model.num_records() == 6);
    }

    SECTION("record returns desired Contact") {
        auto laine = model.record(2);
        REQUIRE(laine->first() == "Patrik");
    }

    SECTION("record fails gracefully") {
        auto nobody = model.record(53);
        REQUIRE(nobody == nullptr);
    }

    SECTION("is_valid_index works") {
        REQUIRE(model.is_valid_index(0) == true);
        REQUIRE(model.is_valid_index(2) == true);
        REQUIRE(model.is_valid_index(9) == false);
        REQUIRE(model.is_valid_index(-1) == false);
    }

    SECTION("add_contact works") {
        Contact c { "Connor", "Hellebuyck", "1993-05-19" };
        model.add_contact(c);
        REQUIRE(model.num_records() == 7);
        REQUIRE(model.record(6)->first() == c.first());
        REQUIRE(model.record(6)->id() != -1);
    }
}
