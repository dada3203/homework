#include "�����.h"
#include "��������.h"
#include "����.h"
#include <iostream>
using namespace std;

int main() {
    // ��ü ������ ����
    futuer* wearable = new wearablemarket();
    futuer* remoteDiagnosis = new RemoteDiagnosis();

    // Wearable ������ ó��
    cout << "Wearable Market Data:\n";
    processMarketData(wearable, "C:/Users/owner/Desktop/wearable.txt", 2025, 0.7);

    // Remote Diagnosis ������ ó��
    cout << "\nRemote Diagnosis Data:\n";
    processMarketData(remoteDiagnosis, "C:/Users/owner/Desktop/Diagnosis.txt", 2025, 0.05);

    // �޸� ����
    delete wearable;
    delete remoteDiagnosis;

    return 0;
}
