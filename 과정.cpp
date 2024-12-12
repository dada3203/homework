#include "����.h"
#include <iostream>
using namespace std;

// ���� ������ ó�� �Լ� ����
void processMarketData(futuer* market, const string& filePath, int predictionYear, double growthRate) {
    market->loadFromFile(filePath);  // ��ü �����͸� ���� ���� �ε�
    cout << "�����ϱ� �� ������: " << endl;
    market->global();

    // 2024�� �����Ͱ� ������ ���� �߰�
    if (market->marketDataAt(2024) == 0.0) {
        market->marketDataAt(2024, 35.00);  // 2024�� ������ �߰�
    }

    // 2025�� ������ ����
    market->predict(predictionYear, growthRate);
}
