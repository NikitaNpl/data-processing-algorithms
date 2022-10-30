#include <iostream>
#include <string>

#include "HashTableLinearProbing.h"
#include "Windows.h"

using namespace std;

int main() {
    system("chcp 1251 > nul");

    HashTableLinearProbing dict;
    dict.autoFill();
    dict.insertNode("09.05.01", "test2");
    dict.deleteNode("09.03.02", "РТУ МИРЭА");
    dict.insertNode("09.05.01", "test3");
    dict.insertNode("09.05.01", "test3");

    string key;
    string value;
    string command;
    bool isInfinity = true;
    while (isInfinity) {
        cout << "Введите команду (insert, delete, find, close): ";
        cin >> command;
       
        if (command == "close") {
            isInfinity = false;
            break;
        }

        if (command != "insert" && command != "delete" && command != "find") {
            cout << endl;
            continue;
        }

        cout << endl << "Введите ключ записи: ";
        cin >> key;
        cout << endl << "Введите значение записи: ";
        cin >> value;

        if (command == "insert") {
            const bool isInserted = dict.insertNode(key, value);
            if (isInserted) {
                cout << "Запись успешно добавлена" << endl;
            }
            else {
                cout << "Указанная запись уже существует в таблице" << endl;
            }
        }

        if (command == "delete") {
            const bool isDeleted = dict.deleteNode(key, value);
            if (isDeleted) {
                cout << "Запись успешно удалена" << endl;
            } else {
                cout << "Указанная запись существует в хеш-таблице" << endl;
            }
        }

        if (command == "find") {
            const HashNode* findedNode = dict.findNode(key, value);
            if (findedNode) {
                cout << "Найденный узел: key = " << findedNode->key << ";  value = " << findedNode->value << endl;
            } else {
                cout << "Такого узла не существует" << endl;
            }
        }

        key = "";
        value = "";
        command = "";
    }

    cout << "Значения хеш-таблицы:" << endl;
    dict.display();
    cout << "Кол-во элементов: " << dict.sizeOf() << endl;
    return 0;
}