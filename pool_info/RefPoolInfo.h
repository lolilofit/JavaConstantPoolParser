//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_REFPOOLINFO_H
#define JAVAOPTLAB1_REFPOOLINFO_H


#include "../PoolInfo.h"

#include <utility>

class RefPoolInfo : public PoolInfo {
public:
    std::string methodName;

    RefPoolInfo(std::string s) {
        this->methodName = std::move(s);
    }
    void readPrintInfo(std::ifstream &in, int mark, char* fields);
};


#endif //JAVAOPTLAB1_REFPOOLINFO_H
