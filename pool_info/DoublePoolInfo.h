//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_DOUBLEPOOLINFO_H
#define JAVAOPTLAB1_DOUBLEPOOLINFO_H


#include <cmath>
#include "../PoolInfo.h"

class DoublePoolInfo : public PoolInfo {
    //??
    void readPrintInfo(std::ifstream &in, int mark, char* fields) {
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

        long long_result = (long)high_bytes << 32 | low_bytes & 0xFFFFFFFFL;

        int s = ((long_result >> 63) == 0) ? 1 : -1;
        int e = (int)((long_result >> 52) & 0x7ffL);
        long m = (e == 0) ?
                 (long_result & 0xfffffffffffffL) << 1 :
                 (long_result & 0xfffffffffffffL) | 0x10000000000000L;

        double result = (double)s * (double)m * std::pow(2.0, (double)e - 1075.0);

        std::cout << "#" << mark << " Double = " << result << "\n";
    }
};


#endif //JAVAOPTLAB1_DOUBLEPOOLINFO_H
