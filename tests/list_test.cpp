
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <string>

#include "list/singly_linked_list.hpp"

using namespace ais1002;

TEST_CASE("Test list") {

    singly_linked_list<std::string> mylist;

    REQUIRE(mylist.empty());

    REQUIRE_THROWS(mylist.removeFirst());
    REQUIRE_THROWS(mylist.removeLast());

    mylist.addFirst("Per");
    REQUIRE(mylist[0] == "Per");
    REQUIRE(!mylist.empty());

    REQUIRE_NOTHROW(mylist.removeLast());

    REQUIRE(mylist.empty());

    mylist.addLast("Nils");
    mylist.addLast("Conny");
    mylist.addLast("Ole");

    REQUIRE(mylist.size() == 3);
    mylist.clear();
    REQUIRE(mylist.empty());

    mylist.addFirst("Olav");
    REQUIRE(mylist[0] == "Olav");
    mylist.addLast("Victor");
    REQUIRE(mylist[0] == "Olav");
    REQUIRE(mylist[1] == "Victor");
    REQUIRE(mylist.size() == 2);

    REQUIRE(mylist.removeFirst() == "Olav");
    REQUIRE(mylist.size() == 1);


}