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

    void readPrintInfo(std::ifstream &in, int mark, char* fields) {
        in.read(fields, sizeof(char) * 2);
        int name_index = 16*(int) fields[0] + (int) fields[1];

        std::cout << "#" << mark << " = " << method_name << " #" << name_index  << "\n";
    }
};


#endif //JAVAOPTLAB1_ONEINDEXPOOLINFO_H
