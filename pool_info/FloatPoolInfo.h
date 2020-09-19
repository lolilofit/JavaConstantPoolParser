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
        int size = int((unsigned char)(fields[0]) << 24 |
                       (unsigned char)(fields[1]) << 16 |
                       (unsigned char)(fields[2]) << 8 |
                       (unsigned char)(fields[3]));

        int s = ((size >> 31u) == 0) ? 1 : -1;
        int e = ((size >> 23u) & 0xffu);
        int m = (e == 0) ?
                (size & 0x7fffffu) << 1u :
                (size & 0x7fffffu) | 0x800000u;

        float result = (float)s * (float)m * (float)std::pow(2.0f, (float)e - 150.0f);
        std::cout << "#" << mark << " Float " << result << "\n";
    }
};

#endif //JAVAOPTLAB1_FLOATPOOLINFO_H
