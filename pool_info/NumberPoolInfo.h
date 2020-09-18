//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_NUMBERPOOLINFO_H
#define JAVAOPTLAB1_NUMBERPOOLINFO_H


#include "../PoolInfo.h"

class NumberPoolInfo : public PoolInfo {
    void readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 4);
        int bytes = 16*16*16*(int) fields[0] + 16*16*(int) fields[1] +16*(int) fields[2] + (int) fields[3];

        std::cout << "#" << mark << " = Integer #" << bytes << "\n";
    }
};


#endif //JAVAOPTLAB1_NUMBERPOOLINFO_H
