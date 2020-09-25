//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_LONGPOOLINFO_H
#define JAVAOPTLAB1_LONGPOOLINFO_H


#include "../PoolInfo.h"

class LongPoolInfo : public PoolInfo {
public:
    __int64 result;

    LongPoolInfo(std::map<int, PoolInfo*>* pool) {
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

        result = (__int64)high_bytes << 32 | low_bytes & 0xFFFFFFFFL;
    }

    void printInfo(int mark) {
        std::cout << "#" << mark << " Long = " << result << "\n";
    }
};

#endif //JAVAOPTLAB1_LONGPOOLINFO_H
