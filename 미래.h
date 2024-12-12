#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 추상 클래스
class futuer {
protected:
    double marketData[6];  // 2020년부터 2025년까지의 데이터를 저장할 배열

public:
    futuer() {  //생성자
        for (int i = 0; i < 6; i++) {
            marketData[i] = 0.0;  // 배열 초기화
        }
    }

    virtual ~futuer() {}  //소멸자

    // 데이터 출력 
    virtual void global() const {
        cout << "Year\tValue\n";
        for (int i = 0; i < 6; i++) {
            int year = 2020 + i;
            if (marketData[i] > 0.0) {
                cout << year << "\t" << marketData[i] << endl;
            }
            else {
                cout << year << "\tNULL\n";
            }
        }
    }

    // 데이터 예측 
    virtual void predict(int year, double growthRate) {
        int index = year - 2020;

        if (index < 1 || index >= 6) {
            cout << "범위를 벗어났습니다." << endl;
            return;
        }
        //이전 연도의 값 확인
        double prevValue = marketData[index - 1];
        if (prevValue == 0.0) {
            cout << "이전 연도의 값이 존재하지 않습니다: " << year << ".\n";
            return;
        }
        marketData[index] = prevValue * (1 + growthRate);
        cout << "예측값 " << year << "년: " << marketData[index] << "\n";
    }

    // 데이터 접근 및 설정
    double marketDataAt(int year, double value = -1) {
        int index = year - 2020;
        if (index < 0 || index >= 6) {
            cout << "범위를 벗어났습니다(" << 2020 << "-" << 2025 << ").\n";
            return 0.0;
        }

        if (value == -1) {  // 조회
            return marketData[index];
        }

        // 설정
        marketData[index] = value;
        return marketData[index];
    }

    // 파일에서 데이터 읽기 (순수 가상 함수)
    virtual void loadFromFile(const string& filePath) = 0;
};
