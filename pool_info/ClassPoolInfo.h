//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_CLASSPOOLINFO_H
#define JAVAOPTLAB1_CLASSPOOLINFO_H


#include "../PoolInfo.h"

class ClassPoolInfo : public PoolInfo {
    void readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 2);
        int name_index = 16*(int) fields[0] + (int) fields[1];

        std::cout << "#" << mark << " = Class #" << name_index  << "\n";

    }
};


#endif //JAVAOPTLAB1_CLASSPOOLINFO_H
