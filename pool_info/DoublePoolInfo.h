//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_DOUBLEPOOLINFO_H
#define JAVAOPTLAB1_DOUBLEPOOLINFO_H


#include <cmath>
#include "../PoolInfo.h"


class DoublePoolInfo : public PoolInfo {
public:
    long double double_val;

    DoublePoolInfo(std::map<int, PoolInfo*> *pool) {
        m = 2;
        this->pool = pool;
    }

    void readInfo(std::ifstream &in, char* fields) {
        in.read(fields, sizeof(char) * 4);
        int high_bytes = int((unsigned char)(fields[0]) << 24 |
                             (unsigned char)(fields[1]) << 16 |
                             (unsigned char)(fields[2]) << 8 |
                             (unsigned char)(fields[3]));

        in.read(fields, sizeof(char) * 4);
        int low_bytes =  int((unsigned char)(fields[0]) << 24 |
                                      (unsigned char)(fields[1]) << 16 |
                                      (unsigned char)(fields[2]) << 8 |
                                      (unsigned char)(fields[3]));

        __int64 long_result = (__int64)high_bytes << 32 | low_bytes & 0xFFFFFFFFL;

        long s = ((long_result >> 63) == 0) ? 1 : -1;
        long e = (long)((long_result >> 52) & 0x7ffL);
        __int64 m = (e == 0) ?
                 (long_result & 0xfffffffffffffL) << 1 :
                 (long_result & 0xfffffffffffffL) | 0x10000000000000L;

        double_val = s * m * std::exp2(e - 1075);
    }

    void printInfo(int mark) {
        std::cout << "#" << mark << " Double = " << double_val << "\n";
    }
};


#endif //JAVAOPTLAB1_DOUBLEPOOLINFO_H
