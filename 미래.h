#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// �߻� Ŭ����
class futuer {
protected:
    double marketData[6];  // 2020����� 2025������� �����͸� ������ �迭

public:
    futuer() {  //������
        for (int i = 0; i < 6; i++) {
            marketData[i] = 0.0;  // �迭 �ʱ�ȭ
        }
    }

    virtual ~futuer() {}  //�Ҹ���

    // ������ ��� 
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

    // ������ ���� 
    virtual void predict(int year, double growthRate) {
        int index = year - 2020;

        if (index < 1 || index >= 6) {
            cout << "������ ������ϴ�." << endl;
            return;
        }
        //���� ������ �� Ȯ��
        double prevValue = marketData[index - 1];
        if (prevValue == 0.0) {
            cout << "���� ������ ���� �������� �ʽ��ϴ�: " << year << ".\n";
            return;
        }
        marketData[index] = prevValue * (1 + growthRate);
        cout << "������ " << year << "��: " << marketData[index] << "\n";
    }

    // ������ ���� �� ����
    double marketDataAt(int year, double value = -1) {
        int index = year - 2020;
        if (index < 0 || index >= 6) {
            cout << "������ ������ϴ�(" << 2020 << "-" << 2025 << ").\n";
            return 0.0;
        }

        if (value == -1) {  // ��ȸ
            return marketData[index];
        }

        // ����
        marketData[index] = value;
        return marketData[index];
    }

    // ���Ͽ��� ������ �б� (���� ���� �Լ�)
    virtual void loadFromFile(const string& filePath) = 0;
};
