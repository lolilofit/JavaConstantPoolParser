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
    unsigned int name_index;

    OneIndexPoolInfo(std::string method_name, std::map<int, PoolInfo *> *pool) {
        this->method_name = std::move(method_name);
        m = 1;
        this->pool = pool;
    }

    void readInfo(std::ifstream &in, char *fields) {
        in.read(fields, sizeof(char) * 2);
        name_index = (unsigned int) ((unsigned char) (fields[0]) << 8u | (unsigned char) (fields[1]));
    }

    void printInfo(int mark) {
        std::cout << "#" << mark << " " << method_name << " = " << getValue() << "\n";
    }

    std::string getValue() {
        std::string class_index_s = pool->at(name_index)->getValue();
        value = class_index_s;
        return value;
    }
};


#endif //JAVAOPTLAB1_ONEINDEXPOOLINFO_H
