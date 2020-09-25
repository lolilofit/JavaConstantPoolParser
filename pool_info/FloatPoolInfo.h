//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_FLOATPOOLINFO_H
#define JAVAOPTLAB1_FLOATPOOLINFO_H


#include <cmath>
#include "../PoolInfo.h"

class FloatPoolInfo : public PoolInfo {
public:
    float float_val;

    FloatPoolInfo(std::map<int, PoolInfo*>* pool) {
        m = 1;
        this->pool = pool;
    }

    void readInfo(std::ifstream &in, char* fields) {
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

        float_val = s * m * std::exp2(e - 150);
    }

    void printInfo(int mark) {
        std::cout << "#" << mark << " Float " << float_val << "\n";
    }
};

#endif //JAVAOPTLAB1_FLOATPOOLINFO_H
