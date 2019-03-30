#include <catch2/catch.hpp>

#include "Contact_dao.hpp"

#include <shixxy/Sxy_Database.hpp>

TEST_CASE("Contact_dao interacts with Sxy::Database", "[Contact_dao]") {
    Sxy::Database db;
    db.open(":memory:");
    Contact_dao dao {db};
    REQUIRE(db.has_table("contacts") == false);

    dao.init();
    REQUIRE(db.has_table("contacts") == true);
}
