//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_METHODHANDLEPOOLINFO_H
#define JAVAOPTLAB1_METHODHANDLEPOOLINFO_H


#include "../PoolInfo.h"

class MethodHandlePoolInfo : public PoolInfo {
    void readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 3);
        int reference_kind = (int) fields[0];
        int reference_index = 16*(int) fields[1] + (int) fields[2];

        std::cout << "#" << mark << " = MethodHandle #" << reference_kind << ".#" << reference_index << "\n";
    }
};


#endif //JAVAOPTLAB1_METHODHANDLEPOOLINFO_H
