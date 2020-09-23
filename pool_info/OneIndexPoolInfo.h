//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_ONEINDEXPOOLINFO_H
#define JAVAOPTLAB1_ONEINDEXPOOLINFO_H


#include "../PoolInfo.h"

#include <utility>

class OneIndexPoolInfo : public PoolInfo {
public:
    std::string method_name;

    OneIndexPoolInfo(std::string method_name) {
        this->method_name = std::move(method_name);
    }

    int readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 2);
        unsigned int name_index = (unsigned int) ((unsigned char)(fields[0]) << 8u | (unsigned char)(fields[1]));

        std::cout << "#" << mark << " = " << method_name << " #" << name_index  << "\n";
        return 1;
    }
};


#endif //JAVAOPTLAB1_ONEINDEXPOOLINFO_H
