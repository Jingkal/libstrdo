#include <cstdio>
#include "strdo.hpp"


void test_trim_left() {
    for(auto &str: {
            std::string("hhahahah"),
            std::string(" hhahahah"),
            std::string("  hhahahah"),
            std::string("   hhahahah"),
            std::string("    hhahahah") }) {
        auto sv = strdo::strip_left(str);
        printf("do [%s]:\n", str.c_str());
        printf("\t[%s]\n", sv.data());
    }
}

void test_trim_right() {
    for(auto &str: {
            std::string("hhahahah"),
            std::string("hhahahah "),
            std::string("hhahahah  "),
            std::string("hhahahah   "),
            std::string("hhahahah    ") }) {
        auto sv = strdo::strip_right(str);
        printf("do [%s]:\n", str.c_str());
        printf("\t[%s]\n", std::string(sv).c_str());
    }
}


void test_strip() {
    for(auto &str: {
            std::string("hhahahah"),
            std::string(" hhahahah"),
            std::string("hhahahah  "),
            std::string("  hhahahah   "),
            std::string(" hhahahah    ") }) {
        auto res = strdo::strip(str);
        printf("do [%s]:\n", str.c_str());
        printf("\t[%s]\n", res.c_str());
    }

}


int main(void) {
    using std::string;
    printf("[%s]\n", strdo::strip("abcdef   ").c_str());
    // test_strip();
    // test_trim_left();
    // test_trim_right();
}
