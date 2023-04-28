#include <iostream>
#include <cassert>
#include "../AP_Lab12.5/Source.cpp"
#include "pch.h"

void test_infix_to_postfix() {
    assert(infix_to_postfix("3+4") == "34+");
    assert(infix_to_postfix("(2+3)*4") == "23+4*");
}

int main() {
    test_infix_to_postfix();
    return 0;
}
