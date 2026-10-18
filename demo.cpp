#include <iostream>
#include <stdexcept>

#include "late_fee.h"

void try_call(double days, double daily) {
    std::cout << "late_fee(" << days << ", " << daily << ") = ";
    try {
        std::cout << late_fee(days, daily) << "\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "ERROR: " << e.what() << "\n";
    }
}

int main() {
    try_call(0, 10);
    try_call(3, 10);
    try_call(10, 10);
    try_call(20, 10);
    try_call(-1, 10);
    try_call(1.5, 10);
    return 0;
}