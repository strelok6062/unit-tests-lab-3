#include "late_fee.h"

#include <algorithm>
#include <cmath>
#include <stdexcept>

double late_fee(double days, double daily) {
    if (days < 0) {
        throw std::invalid_argument("days must not be negative");
    }
    if (daily < 0) {
        throw std::invalid_argument("daily must not be negative");
    }
    if (days != std::floor(days)) {
        throw std::invalid_argument("days must be a whole number");
    }
    return std::min(days * daily, 100.0);
}