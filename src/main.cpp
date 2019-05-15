#include <iostream>
#include "klotski.h"

int main() {
    Klotski klotski;

    std::cout << klotski.display() << std::endl;
    std::cout << "Signature: " << klotski.signature() << std::endl;

    return 0;
}