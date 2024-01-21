#include "strdo.hpp"
#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

bool is_vec_same(const std::vector<std::string> &v1,
                 const std::vector<std::string> &v2) {
  if (v1.size() != v2.size())
    return false;
  for (size_t i = 0; i < v1.size(); i++) {
    if (v1[i] != v2[i])
      return false;
  }
  return true;
}

TEST_CASE("Test split spaces", "[spaces]") {
  std::map<std::string, std::vector<std::string>> space_test_grp = {
      {"hello world", {"hello", "world"}},
      {"i'm shit\tjaksljdflj aalksdjf",
       {"i'm", "shit", "jaksljdflj", "aalksdjf"}},
      {" kadsklfj a d' df' \t sdf", {"kadsklfj", "a", "d'", "df'", "sdf"}},
  };
  for (const auto &[src, control] : space_test_grp) {
    auto res = strdo::split(src);
    CHECK(is_vec_same(res, control));
  }
}

TEST_CASE("Test split space and symbols", "[mixed]") {
  auto control =
      std::vector<std::string>{"a", "b", "c", "d", "ef", "gh", "xyz"};
  auto sample = std::string("a, b, c, d, ef, gh, -xyz");
  auto delim = std::string("- ,");
  auto res = strdo::split(sample, delim);
  CHECK(is_vec_same(control, res));
}
