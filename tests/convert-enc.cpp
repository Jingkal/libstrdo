#include "strdo.hpp"
#include <map>
#include <string>

#if __linux__
#include <catch2/catch.hpp>
#elif __APPLE__
#include <catch2/catch_test_macros.hpp>
#endif

TEST_CASE("Test Convert From GBK to UTF8", "[conv]") {
  auto strings = std::map<std::string, std::string>();
  auto utf8_string = std::string("你好");
  strings.emplace("GB18030", "\xC4\xE3\xBA\xC3");
  strings.emplace("BIG5", "\xA7\x41\xA6\x6E");
  for (auto it = strings.cbegin(); it != strings.cend(); ++it) {
    auto res = strdo::conv_to_utf8(it->second, it->first);
    CHECK(utf8_string == res);
    printf("%s string: %s\n", it->first.c_str(), res.c_str());
  }
}
