#include "strdo.hpp"
#include <cstdio>

inline void printv(std::vector<std::string>& vec) {
    for (const auto& str: vec) {
        printf("%s\n", str.c_str());
    }
}

void test(std::vector<std::string> &vec, std::string delim) {
    for (auto& str: vec) {
        auto res = strdo::split(str, delim);
        printv(res);
    }
}

void test_space_char() {
    auto srcs = std::vector<std::string>{
        "hello world",
        "i'm shit\tjaksljdflj aalksdjf"
        " kadsklfj a d' df' \t sdf" };
    test(srcs, " ");
}

void test_word() {
    auto srcs = std::vector<std::string>{
        "i test you",
        "we test him test her"
    };
    test(srcs, "test");

}

int main(void) {
    // test_space_char();
    test_word();
    return 0;
}
