//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_NUMBERPOOLINFO_H
#define JAVAOPTLAB1_NUMBERPOOLINFO_H


#include "../PoolInfo.h"

class NumberPoolInfo : public PoolInfo {
public:
    int result;

    NumberPoolInfo(std::map<int, PoolInfo *> *pool) {
        m = 1;
        this->pool = pool;
    }

    void readInfo(std::ifstream &in, char *fields) {
        in.read(fields, sizeof(char) * 4);
        result = int((unsigned char) (fields[0]) << 24 |
                     (unsigned char) (fields[1]) << 16 |
                     (unsigned char) (fields[2]) << 8 |
                     (unsigned char) (fields[3]));
    }

    void printInfo(int mark) {
        std::cout << "#" << mark << " = Integer " << result << "\n";
    }
};


#endif //JAVAOPTLAB1_NUMBERPOOLINFO_H
