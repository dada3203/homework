#include "웨어러블.h"
#include "원격진료.h"
#include "과정.h"
#include <iostream>
using namespace std;

int main() {
    // 객체 포인터 생성
    futuer* wearable = new wearablemarket();
    futuer* remoteDiagnosis = new RemoteDiagnosis();

    // Wearable 데이터 처리
    cout << "Wearable Market Data:\n";
    processMarketData(wearable, "C:/Users/owner/Desktop/wearable.txt", 2025, 0.7);

    // Remote Diagnosis 데이터 처리
    cout << "\nRemote Diagnosis Data:\n";
    processMarketData(remoteDiagnosis, "C:/Users/owner/Desktop/Diagnosis.txt", 2025, 0.05);

    // 메모리 해제
    delete wearable;
    delete remoteDiagnosis;

    return 0;
}
