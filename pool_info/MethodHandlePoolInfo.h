//
// Created by User on 18.09.2020.
//

#ifndef JAVAOPTLAB1_METHODHANDLEPOOLINFO_H
#define JAVAOPTLAB1_METHODHANDLEPOOLINFO_H


#include "../PoolInfo.h"

class MethodHandlePoolInfo : public PoolInfo {
public:
    int reference_kind;
    unsigned int reference_index;

    MethodHandlePoolInfo(std::map<int, PoolInfo *> *pool) {
        m = 1;
        this->pool = pool;
    }

    void readInfo(std::ifstream &in, char *fields) {
        in.read(fields, sizeof(char) * 3);
        reference_kind = (int) fields[0];
        reference_index = (unsigned int) ((unsigned char) (fields[1]) << 8u | (unsigned char) (fields[2]));
    }

    void printInfo(int mark) {
        std::cout << "#" << mark << " = MethodHandle " << getValue() << "\n";
    }

    std::string getValue() {
        std::string ref_kind_s = pool->at(reference_kind)->getValue();
        std::string ref_ind_s = pool->at(reference_index)->getValue();

        value = ref_kind_s + ":" + ref_ind_s;
        return value;
    }
};


#endif //JAVAOPTLAB1_METHODHANDLEPOOLINFO_H
