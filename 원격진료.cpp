#include "원격진료.h"
#include <iostream>
#include <fstream>
using namespace std;

// 파일에서 데이터 읽기
void RemoteDiagnosis::loadFromFile(const string& filePath) {
    ifstream file(filePath);
    if (!file) {
        cerr << "열리지 않습니다. " << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        size_t comma = line.find(",");
        if (comma != string::npos) {
            try {
                int year = stoi(line.substr(0, comma));  // 연도 추출
                double value = stod(line.substr(comma + 1));  // 값 추출
                marketDataAt(year, value);  // 데이터 저장
            }
            catch (const exception& e) {
                cerr << "Error : " << line << " (" << e.what() << ")\n";
            }
        }
    }
    file.close();
}
