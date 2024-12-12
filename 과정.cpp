#include "과정.h"
#include <iostream>
using namespace std;

// 공통 데이터 처리 함수 정의
void processMarketData(futuer* market, const string& filePath, int predictionYear, double growthRate) {
    market->loadFromFile(filePath);  // 객체 포인터를 통해 파일 로드
    cout << "예측하기 전 데이터: " << endl;
    market->global();

    // 2024년 데이터가 없으면 수동 추가
    if (market->marketDataAt(2024) == 0.0) {
        market->marketDataAt(2024, 35.00);  // 2024년 데이터 추가
    }

    // 2025년 데이터 예측
    market->predict(predictionYear, growthRate);
}
