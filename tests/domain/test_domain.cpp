#include <iostream>
#include "domain_dummy.h"

int main() {
    domain::bootstrap();
    std::cout << "[domain] bootstrap passed\n";
    return 0;
}
