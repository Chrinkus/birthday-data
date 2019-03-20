#include <catch2/catch.hpp>
#include "Contact.hpp"

TEST_CASE("Contacts construct as expected", "[Constructor]") {
    Contact c1;

    REQUIRE(c1.first().empty() == true);
    REQUIRE(c1.last().empty() == true);
    REQUIRE(c1.birth().empty() == true);
    REQUIRE(c1.email().empty() == true);
    REQUIRE(c1.phone().empty() == true);

    Contact c2 {"Chris", "Schick", "1979-Feb-27"};

    REQUIRE(c2.first() == "Chris");
    REQUIRE(c2.last() == "Schick");
    REQUIRE(c2.birth() == "1979-Feb-27");
    REQUIRE(c2.email().empty() == true);
    REQUIRE(c2.phone().empty() == true);
}

TEST_CASE("Getters and setters work", "[Getter/Setter]") {
    Contact c1;

    c1.first("Troy");
    c1.last("Baker");
    c1.birth("1976-Apr-01");
    c1.email("troy@lastofus.com");
    c1.phone("555-1234");

    CHECK(c1.first() == "Troy");
    CHECK(c1.last() == "Baker");
    CHECK(c1.birth() == "1976-Apr-01");
    CHECK(c1.email() == "troy@lastofus.com");
    CHECK(c1.phone() == "555-1234");
}
