#pragma once
#include "미래.h"
#include <string>

//공통 데이터 처리 함수 선언
void processMarketData(futuer* market, const string& filePath, int predictionYear, double growthRate);
