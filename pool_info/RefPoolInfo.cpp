//
// Created by User on 18.09.2020.
//

#include "RefPoolInfo.h"

int RefPoolInfo::readPrintInfo(std::ifstream &in, int mark, char *fields) {
    in.read(fields, sizeof(char) * 4);
    unsigned int class_index = (unsigned int) ((unsigned char)(fields[0]) << 8u | (unsigned char)(fields[1]));
    unsigned int name_and_type_index = (unsigned int) ((unsigned char)(fields[2]) << 8u | (unsigned char)(fields[3]));

    std::cout << "#" << mark << " = " << methodName << " #" << class_index << ".#" << name_and_type_index << "\n";
    return 1;
}
