#include "list/singly_linked_list.hpp"

#include <iostream>

int main() {

    auto list = ais1002::singly_linked_list<std::string>();

    list.addLast("Tore");
    list.addLast("Per");
    list.addLast("Conny");

    std::cout << "Content of list: " << list << std::endl;

    std::cout << "Result of removeFirst: " << list.removeFirst() << std::endl;

    std::cout << "Content of list: " << list << std::endl;

    list.insert(0, "Olav");

    list.insert(list.size() - 1, "Birgitte");

    list.addFirst("Ole");

    std::cout << "Content of list: " << list << std::endl;

    return 0;
}
