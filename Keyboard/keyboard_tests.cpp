#include "doctest.h"
#include "window.cpp"

TEST_CASE("tst_class_keyboard"){
    Keyboard test;
    test.set_value();
    REQUIRE(test.x == 0);
    REQUIRE(test.y == 0);
    REQUIRE(test.n_x == 0);
    REQUIRE(test.n_y == 0);

    test.set_value(2, 0, 35);
    REQUIRE(test.x == 35);
    REQUIRE(test.y == 0);
    REQUIRE(test.n_x == 2);
    REQUIRE(test.n_y == 0);
}

TEST_CASE("test_file"){
    char text[70] = "";
    std::string test = "llow miles wound place the leave had. to sitting subject no improve st";
    get_from_file(text);
    std::string t = std::string(text);
    REQUIRE(text == test);
}

TEST_CASE("test_change"){
    sf::Text t1, t2;
    t1.setString("app");
    t2.setString("le");
    change(t1, t2);
    REQUIRE(t1.getString() == "appl");
    REQUIRE(t2.getString() == "e");
}

TEST_CASE("test_random"){
    int number;
    number = get_random(0, 4031);
    REQUIRE(number <= 4031);
    REQUIRE(number >= 0);
}
