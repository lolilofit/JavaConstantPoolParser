//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_FLOATPOOLINFO_H
#define JAVAOPTLAB1_FLOATPOOLINFO_H


#include <cmath>
#include "../PoolInfo.h"

class FloatPoolInfo : public PoolInfo {
    int readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 4);

        unsigned int size = (unsigned int)((unsigned char)(fields[0]) << 24 |
                       (unsigned char)(fields[1]) << 16 |
                       (unsigned char)(fields[2]) << 8 |
                       (unsigned char)(fields[3]));

        int s = ((size >> 31u) == 0) ? 1 : -1;
        int e = ((size >> 23u) & 0xff);
        int m = (e == 0) ?
                (size & 0x7fffff) << 1u :
                (size & 0x7fffff) | 0x800000;

        std::cout << "#" << mark << " Float " << s * m * std::exp2(e - 150) << "\n";
        return 1;
    }
};

#endif //JAVAOPTLAB1_FLOATPOOLINFO_H
