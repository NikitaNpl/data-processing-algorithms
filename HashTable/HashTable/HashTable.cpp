#include <iostream>
#include <string>

#include "HashTableLinearProbing.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    HashTableLinearProbing dict;
    dict.insertNode("sort", "Сортировать");
    dict.insertNode("left", "Осталось");
    dict.display();
    cout << dict.sizeOf() << endl;
    cout << dict.findNode("sort")->value << endl;
    return 0;
}