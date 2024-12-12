#include "��������.h"
#include <iostream>
#include <fstream>
using namespace std;

// ���Ͽ��� ������ �б�
void RemoteDiagnosis::loadFromFile(const string& filePath) {
    ifstream file(filePath);
    if (!file) {
        cerr << "������ �ʽ��ϴ�. " << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        size_t comma = line.find(",");
        if (comma != string::npos) {
            try {
                int year = stoi(line.substr(0, comma));  // ���� ����
                double value = stod(line.substr(comma + 1));  // �� ����
                marketDataAt(year, value);  // ������ ����
            }
            catch (const exception& e) {
                cerr << "Error : " << line << " (" << e.what() << ")\n";
            }
        }
    }
    file.close();
}
