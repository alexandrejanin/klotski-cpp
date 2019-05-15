#include <cassert>
#include <iostream>
#include "klotski.h"

int main() {
    Klotski klotski;

    std::cout << klotski.display() << std::endl;
    std::cout << "Signature: " << klotski.signature() << std::endl;

    assert(klotski.signature() == "01120112344536758..9");

    bool canMove1 = klotski.down(1);
    assert(!canMove1);

    bool canMove6 = klotski.down2(6);
    assert(!canMove6);

    bool canMove7 = klotski.down(7);
    assert(canMove7);

    assert(klotski.signature() == "01120112344536.58.79");

    std::cout << klotski.display() << std::endl;

    return 0;
}