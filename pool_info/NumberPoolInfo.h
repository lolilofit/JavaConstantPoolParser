//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_NUMBERPOOLINFO_H
#define JAVAOPTLAB1_NUMBERPOOLINFO_H


#include "../PoolInfo.h"

class NumberPoolInfo : public PoolInfo {
    void readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 4);
        int result = int((unsigned char)(fields[0]) << 24 |
                        (unsigned char)(fields[1]) << 16 |
                        (unsigned char)(fields[2]) << 8 |
                        (unsigned char)(fields[3]));

        std::cout << "#" << mark << " = Integer #" << result << "\n";
    }
};


#endif //JAVAOPTLAB1_NUMBERPOOLINFO_H
