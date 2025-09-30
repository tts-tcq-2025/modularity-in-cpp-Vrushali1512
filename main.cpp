#include "color_code.h"
#include <iostream>
#include <cassert>

using namespace ColorCode;

void testGetColorFromPairNumber() {
    ColorPair pair = GetColorFromPairNumber(4);
    assert(pair.majorColor == "White");
    assert(pair.minorColor == "Brown");

    pair = GetColorFromPairNumber(23);
    assert(pair.majorColor == "Violet");
    assert(pair.minorColor == "Green");

    try {
        GetColorFromPairNumber(0);
        assert(false);  // Should not reach here
    } catch (const std::out_of_range&) {
        // Expected
    }
}

void testGetPairNumberFromColor() {
    int pairNumber = GetPairNumberFromColor({"Black", "Orange"});
    assert(pairNumber == 12);

    pairNumber = GetPairNumberFromColor({"Yellow", "Slate"});
    assert(pairNumber == 20);

    try {
        GetPairNumberFromColor({"Pink", "Blue"});
        assert(false);  // Should not reach here
    } catch (const std::invalid_argument&) {
        // Expected
    }
}

void testGetReferenceManual() {
    std::string manual = GetReferenceManual();
    // Check header presence
    assert(manual.find("Pair Number") != std::string::npos);
    assert(manual.find("White") != std::string::npos);
    assert(manual.find("Violet") != std::string::npos);
}

int main() {
    testGetColorFromPairNumber();
    testGetPairNumberFromColor();
    testGetReferenceManual();

    std::cout << "All tests passed!\n";

    // Optionally print the manual
    std::cout << "\nColor Code Reference Manual:\n";
    std::cout << GetReferenceManual();

    return 0;
}
