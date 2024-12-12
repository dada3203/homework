#include "�����.h"
#include <fstream>
#include <iostream>
using namespace std;

// ���Ͽ��� ������ �б�
void wearablemarket::loadFromFile(const string& filePath) {
    ifstream file(filePath);
    if (!file) {
        cerr << "������ �ʽ��ϴ�. " << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        size_t comma = line.find(",");
        size_t dollar = line.find("$");
        if (comma != string::npos && dollar != string::npos) {
            try {
                int year = stoi(line.substr(0, comma));
                double value = stod(line.substr(comma + 1, dollar- comma- 1));
                marketDataAt(year, value);
            }
            catch (const exception& e) {
                cerr << "Error: " << line << " (" << e.what() << ")\n";
            }
        }
    }
    file.close();
}
