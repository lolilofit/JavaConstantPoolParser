//
// Created by User on 18.09.2020.
//

#include "RefPoolInfo.h"

void RefPoolInfo::readInfo(std::ifstream &in, char *fields) {
    in.read(fields, sizeof(char) * 4);
    class_index = (unsigned int) ((unsigned char) (fields[0]) << 8u | (unsigned char) (fields[1]));
    name_and_type_index = (unsigned int) ((unsigned char) (fields[2]) << 8u | (unsigned char) (fields[3]));
}

void RefPoolInfo::printInfo(int mark) {
    std::cout << "#" << mark << " " << methodName << " = " << getValue() << "\n";

}

std::string RefPoolInfo::getValue() {
    std::string class_index_s = pool->at(class_index)->getValue();
    std::string name_and_type_index_s = pool->at(name_and_type_index)->getValue();

    value = class_index_s + ":" + name_and_type_index_s;
    return value;
}
