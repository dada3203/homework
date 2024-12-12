#pragma once
#include "¹Ì·¡.h"

class RemoteDiagnosis : public futuer {
public:
    RemoteDiagnosis() {}
    ~RemoteDiagnosis() {}

    void loadFromFile(const string& filePath) override;
};
