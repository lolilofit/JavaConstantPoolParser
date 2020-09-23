//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_POOLINFO_H
#define JAVAOPTLAB1_POOLINFO_H


#include <fstream>
#include <iostream>

class PoolInfo {
public:
    virtual int readPrintInfo(std::ifstream &in, int mark, char* fields) {}
};


#endif //JAVAOPTLAB1_POOLINFO_H
