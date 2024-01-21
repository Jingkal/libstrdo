#include "strdo.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

const auto control_nospace = std::string("hhahahah");
const auto control_space = std::string("hhah ahah");

TEST_CASE("TEST trim left no spaces in the middle", "[trim_left]") {
  std::vector<std::string> strvec = {
      "hhahahah",           " hhahahah",          "    hhahahah",
      "\thhahahah",         " \thhahahah",        "\t hhahahah",
      " \t hhahahah",       "\t\t\t hhahahah",    " \t\t\t hhahahah",
      " \t \t\t hhahahah",  " \t \t \t hhahahah", " \t \t\t hhahahah",
      " \t \t \t hhahahah",
  };
  for (const auto &str : strvec) {
    CHECK(control_nospace == strdo::trim_left(str));
  }
}

TEST_CASE("TEST trim right no spaces in the middle", "[trim_right]") {
  std::vector<std::string> strvec = {
      "hhahahah",           "hhahahah ",          "hhahahah    ",
      "hhahahah\t",         "hhahahah \t",        "hhahahah\t ",
      "hhahahah \t ",       "hhahahah\t\t\t ",    "hhahahah \t\t\t ",
      "hhahahah \t \t\t ",  "hhahahah \t \t \t ", "hhahahah \t \t\t ",
      "hhahahah \t \t \t ",
  };
  for (const auto &str : strvec) {
    CHECK(control_nospace == strdo::trim_right(str));
  }
}

TEST_CASE("TEST trim left with spaces in the middle", "[trim_left]") {
  std::vector<std::string> strvec = {
      "hhah ahah",           " hhah ahah",          "    hhah ahah",
      "\thhah ahah",         " \thhah ahah",        "\t hhah ahah",
      " \t hhah ahah",       "\t\t\t hhah ahah",    " \t\t\t hhah ahah",
      " \t \t\t hhah ahah",  " \t \t \t hhah ahah", " \t \t\t hhah ahah",
      " \t \t \t hhah ahah",
  };
  for (const auto &str : strvec) {
    CHECK(control_space == strdo::trim_left(str));
  }
}

TEST_CASE("TEST trim right with spaces in the middle", "[trim_right]") {
  std::vector<std::string> strvec = {
      "hhah ahah",           "hhah ahah ",          "hhah ahah    ",
      "hhah ahah\t",         "hhah ahah \t",        "hhah ahah\t ",
      "hhah ahah \t ",       "hhah ahah\t\t\t ",    "hhah ahah \t\t\t ",
      "hhah ahah \t \t\t ",  "hhah ahah \t \t \t ", "hhah ahah \t \t\t ",
      "hhah ahah \t \t \t ",
  };
  for (const auto &str : strvec) {
    CHECK(control_space == strdo::trim_right(str));
  }
}

TEST_CASE("TEST trim spaces on both ends of a string", "[trim]") {
  std::vector<std::string> strvec = {
      "hhah ahah",
      " hhah ahah ",
      "    hhah ahah    ",
      "\thhah ahah\t",
      " \thhah ahah \t",
      "\t hhah ahah\t ",
      " \t hhah ahah \t ",
      "\t\t\t hhah ahah\t\t\t ",
      " \t\t\t hhah ahah \t\t\t ",
      " \t \t\t hhah ahah \t \t\t ",
      " \t \t \t hhah ahah \t \t \t ",
      " \t \t\t hhah ahah \t \t\t ",
      " \t \t \t hhah ahah \t \t \t ",
  };
  for (const auto &str : strvec) {
    CHECK(control_space == strdo::trim(str));
  }
}
