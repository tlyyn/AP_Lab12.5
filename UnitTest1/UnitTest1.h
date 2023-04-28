#include <cassert>
#include <string>
#include "../AP_Lab12.5/Source.cpp"
#include "pch.h"
using namespace std;

void test_infix_to_postfix() {
    string infix = "a+b*c";
    string expected_postfix = "abc*+";
    assert(infix_to_postfix(infix) == expected_postfix);

    infix = "(a+b)*c";
    expected_postfix = "ab+c*";
    assert(infix_to_postfix(infix) == expected_postfix);

    infix = "a*(b+c)";
    expected_postfix = "abc+*";
    assert(infix_to_postfix(infix) == expected_postfix);
}

int main() {
    test_infix_to_postfix();
    return 0;
}