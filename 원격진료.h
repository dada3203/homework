#pragma once
#include "�̷�.h"

class RemoteDiagnosis : public futuer {
public:
    RemoteDiagnosis() {}
    ~RemoteDiagnosis() {}

    void loadFromFile(const string& filePath) override;
};
