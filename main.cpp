#include <iostream>
#include <map>
#include "PoolInfo.h"
#include "pool_info/RefPoolInfo.h"
#include "pool_info/NumberPoolInfo.h"
#include "pool_info/OneIndexPoolInfo.h"
#include "pool_info/Utf8PoolInfo.h"
#include "pool_info/FloatPoolInfo.h"
#include "pool_info/MethodHandlePoolInfo.h"
#include "pool_info/LongPoolInfo.h"
#include "pool_info/DoublePoolInfo.h"

void fill_tags(std::map<int, PoolInfo*> &tags) {
    tags.insert(std::pair<const int, PoolInfo*>(10, new RefPoolInfo("Methodref")));
    tags.insert(std::pair<const int, PoolInfo*>(11, new RefPoolInfo("InterfaceMethodref")));
    tags.insert(std::pair<const int, PoolInfo*>(9, new RefPoolInfo("Fieldref")));
    tags.insert(std::pair<const int, PoolInfo*>(12, new RefPoolInfo("NameAndType")));
    tags.insert(std::pair<const int, PoolInfo*>(18, new RefPoolInfo("InvokeDynamic")));

    tags.insert(std::pair<const int, PoolInfo*>(7, new OneIndexPoolInfo("Class")));
    tags.insert(std::pair<const int, PoolInfo*>(16, new OneIndexPoolInfo("MethodType")));
    tags.insert(std::pair<const int, PoolInfo*>(8, new OneIndexPoolInfo("String")));

    tags.insert(std::pair<const int, PoolInfo*>(1, new Utf8PoolInfo()));

    tags.insert(std::pair<const int, PoolInfo*>(4, new FloatPoolInfo()));
    tags.insert(std::pair<const int, PoolInfo*>(3, new NumberPoolInfo()));
    tags.insert(std::pair<const int, PoolInfo*>(5, new LongPoolInfo()));
    tags.insert(std::pair<const int, PoolInfo*>(6, new DoublePoolInfo()));
    tags.insert(std::pair<const int, PoolInfo*>(15, new MethodHandlePoolInfo()));
}

int main(int argc, char* argv[]) {
    std::ifstream fileBuffer(argc == 1 ? "../Main.class" : argv[1], std::ios::binary);

    if(!fileBuffer.is_open()) {
        return 1;
    }

    std::map<int, PoolInfo*> tags;
    fill_tags(tags);

    char* first_fields = new char[4];

    //read magic number
    fileBuffer.read(first_fields, sizeof(char) * 4);

    //read minor and major version
    fileBuffer.read(first_fields, sizeof(char) * 4);
    int minor_version = (unsigned int) ((unsigned char)(first_fields[0]) << 8u | (unsigned char)(first_fields[1]));
    int major_version = (unsigned int) ((unsigned char)(first_fields[2]) << 8u | (unsigned char)(first_fields[3]));

    std::cout << "Minor number is: " << minor_version << "\nMajor number is: " << major_version << "\n";

    fileBuffer.read(first_fields, sizeof(char) * 2);
    unsigned int constant_pool_count = (unsigned int) ((unsigned char)(first_fields[0]) << 8u | (unsigned char)(first_fields[1]));

    //read constant pool
    int tag;
    int mark = 1;

    for(int i = 1; i < constant_pool_count; i++) {
        fileBuffer.read(first_fields, sizeof(char));

        tag = (int) first_fields[0];
        if(tag < 0)
            return 2;

        if(tags.find(tag) != tags.end())
            mark += tags.at(tag)->readPrintInfo(fileBuffer, mark, first_fields);
    }

    fileBuffer.close();
    return 0;
}
