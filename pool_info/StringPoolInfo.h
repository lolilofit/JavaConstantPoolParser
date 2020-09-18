//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_STRINGPOOLINFO_H
#define JAVAOPTLAB1_STRINGPOOLINFO_H


#include "../PoolInfo.h"

class StringPoolInfo : public PoolInfo {
public:
    void readPrintInfo(std::ifstream &in, int mark, char *fields) {
        in.read(fields, sizeof(char) * 2);
        int string_index = 16*(int) fields[0] + (int) fields[1];

        std::cout << "#" << mark << " = String #" << string_index << "\n";
    }


};


#endif //JAVAOPTLAB1_STRINGPOOLINFO_H
