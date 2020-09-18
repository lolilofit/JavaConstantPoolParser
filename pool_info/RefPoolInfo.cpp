//
// Created by User on 18.09.2020.
//

#include "RefPoolInfo.h"

void RefPoolInfo::readPrintInfo(std::ifstream &in, int mark, char *fields) {
    in.read(fields, sizeof(char) * 4);
    int class_index = 16*(int) fields[0] + (int) fields[1];
    int name_and_type_index = 16*(int) fields[2] + (int) fields[3];

    std::cout << "#" << mark << " = " << methodName << " #" << class_index << ".#" << name_and_type_index << "\n";
}
