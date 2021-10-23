#include <iostream>

#include "game/field/field.h"
#include "utils/containers/vector/vector.h"
#include "utils/containers/matrix/matrix.h"
#include <memory>

int main() {
    std::cout << "----\n";
    field field1(2, 3);
    std::cout << field1 << '\n';
    std::cout << "----\n";
    field field2(std::move(field1));
    std::cout << field1 << '\n' << field2 << '\n';
    std::cout << "----\n";
    field field3 = field2;
    std::cout << field1 << '\n' << field2 << '\n' << field3 << '\n';
    std::cout << "----\n";
}