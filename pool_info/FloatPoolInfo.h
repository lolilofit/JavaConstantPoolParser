//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_FLOATPOOLINFO_H
#define JAVAOPTLAB1_FLOATPOOLINFO_H


#include <cmath>
#include "../PoolInfo.h"

class FloatPoolInfo : public PoolInfo{
    void readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 4);
        unsigned int size = 4096*(int) fields[0] + 256*(int) fields[1] + 16*(int) fields[2] + (int) fields[3];

        unsigned int s = ((size >> 31u) == 0) ? 1 : -1;
        unsigned int e = ((size >> 23u) & 0xffu);
        unsigned int m = (e == 0) ?
                (size & 0x7fffffu) << 1u :
                (size & 0x7fffffu) | 0x800000u;

        float result = (float)s * (float)m * (float)std::pow(2.0f, (float)e - 150.0f);
        std::cout << "#" << mark << " Float " << s << "\n";
    }
};


#endif //JAVAOPTLAB1_FLOATPOOLINFO_H
