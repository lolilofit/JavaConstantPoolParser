//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_POOLINFO_H
#define JAVAOPTLAB1_POOLINFO_H


#include <fstream>
#include <iostream>
#include <map>
#include <utility>


class PoolInfo {
public:
    int m = 0;
    std::string value = "";
    std::map<int, PoolInfo*>* pool;

    virtual void readInfo(std::ifstream &in, char* fields) {}

    virtual void printInfo(int mark) {}

    virtual std::string getValue() {}
};

#endif //JAVAOPTLAB1_POOLINFO_H
