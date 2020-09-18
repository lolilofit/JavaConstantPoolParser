//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_UTF8POOLINFO_H
#define JAVAOPTLAB1_UTF8POOLINFO_H


#include "../PoolInfo.h"

class Utf8PoolInfo : public PoolInfo {
    void readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 2);
        int size = 16*(int) fields[0] + (int) fields[1];

        char* bytes = new char[size];
        in.read(bytes, sizeof(char) * size);

        std::cout << "#" << mark << " = Utf8 ";
        for(int i = 0; i < size; i++)
            std::cout << bytes[i];
        std::cout << "\n";
    }
};


#endif //JAVAOPTLAB1_UTF8POOLINFO_H
