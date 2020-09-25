//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_UTF8POOLINFO_H
#define JAVAOPTLAB1_UTF8POOLINFO_H


#include "../PoolInfo.h"

class Utf8PoolInfo : public PoolInfo {
public:
    Utf8PoolInfo(std::map<int, PoolInfo *> *pool) {
        m = 1;
        this->pool = pool;
        this->value = "";
    }

    void readInfo(std::ifstream &in, char *fields) {
        in.read(fields, sizeof(char) * 2);
        int size = (int) ((unsigned char) (fields[0]) << 8u | (unsigned char) (fields[1]));

        char *bytes = new char[size + 1];
        in.read(bytes, sizeof(char) * size);
        bytes[size] = '\0';

        value = std::string(bytes);
    }

    void printInfo(int mark) {
        std::cout << "#" << mark << " = Utf8 " << value << "\n";
    }

    std::string getValue() { return value;}
};


#endif //JAVAOPTLAB1_UTF8POOLINFO_H
