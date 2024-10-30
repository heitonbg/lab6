#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Computer {
    string department;
    string configuration;
    int quantity;
    int year;
};

int main() {
    ifstream inputFile("computers.txt"); 
    
    if (!inputFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string targetDepartment;
    cout << "Введите наименование подразделения: ";
    cin >> targetDepartment;

    int totalComputers = 0;
    int oldestYear = numeric_limits<int>::max();
    Computer oldestComputer;

    while (true) {
        Computer comp;
        if (!(inputFile >> comp.department >> comp.configuration >> comp.quantity >> comp.year)) {
            break; 
        }

        if (comp.department == targetDepartment) {
            totalComputers += comp.quantity;
            cout << comp.department << " " << comp.configuration << " " << comp.quantity << " " << comp.year << endl;
        }

        if (comp.year < oldestYear) {
            oldestYear = comp.year;
            oldestComputer = comp;
        }
    }

    cout << "Общее число компьютеров в подразделении " << targetDepartment << ": " << totalComputers << endl;
    
    cout << "Самый старый компьютер: " << oldestComputer.department << " " << oldestComputer.configuration << " "
         << oldestComputer.quantity << " " << oldestComputer.year << endl;

    inputFile.close();

    return 0;
}
