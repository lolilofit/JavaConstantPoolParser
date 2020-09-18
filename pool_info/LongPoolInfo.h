//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_LONGPOOLINFO_H
#define JAVAOPTLAB1_LONGPOOLINFO_H


#include "../PoolInfo.h"

class LongPoolInfo : public PoolInfo {
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

        long result = (long)high_bytes << 32 | low_bytes & 0xFFFFFFFFL;

        std::cout << "#" << mark << " Long = " << result << "\n";
    }
};


#endif //JAVAOPTLAB1_LONGPOOLINFO_H