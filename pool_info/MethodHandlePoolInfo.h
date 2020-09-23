//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_METHODHANDLEPOOLINFO_H
#define JAVAOPTLAB1_METHODHANDLEPOOLINFO_H


#include "../PoolInfo.h"

class MethodHandlePoolInfo : public PoolInfo {
    int readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 3);
        int reference_kind = (int) fields[0];
        unsigned int reference_index = (unsigned int) ((unsigned char)(fields[1]) << 8u | (unsigned char)(fields[2]));

        std::cout << "#" << mark << " = MethodHandle #" << reference_kind << ".#" << reference_index << "\n";
        return 1;
    }
};


#endif //JAVAOPTLAB1_METHODHANDLEPOOLINFO_H
