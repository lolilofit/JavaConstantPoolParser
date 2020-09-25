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
    unsigned int class_index;
    unsigned int name_and_type_index;

    RefPoolInfo(std::string s, std::map<int, PoolInfo *> *pool) {
        this->methodName = std::move(s);
        m = 1;
        this->pool = pool;
    }

    void readInfo(std::ifstream &in, char *fields);

    void printInfo(int mark);

    std::string getValue();
};


#endif //JAVAOPTLAB1_REFPOOLINFO_H
