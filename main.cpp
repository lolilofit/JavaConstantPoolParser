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


PoolInfo* getPoolInfo(int tag, std::map<int, PoolInfo*> *pool) {
    if(tag == 10)
        return new RefPoolInfo("Methodref", pool);
    if(tag == 11)
        return new RefPoolInfo("InterfaceMethodref", pool);
    if(tag == 9)
        return new RefPoolInfo("Fieldref", pool);
    if(tag == 12)
        return new RefPoolInfo("NameAndType", pool);
    if(tag == 18)
        return new RefPoolInfo("InvokeDynamic", pool);
    if(tag == 7)
        return new OneIndexPoolInfo("Class", pool);
    if(tag == 16)
        return new OneIndexPoolInfo("MethodType", pool);
    if(tag == 8)
        return new OneIndexPoolInfo("String", pool);
    if(tag == 1)
        return new Utf8PoolInfo(pool);
    if(tag == 4)
        return new FloatPoolInfo(pool);
    if(tag == 3)
        return new NumberPoolInfo(pool);
    if(tag == 5)
        return new LongPoolInfo(pool);
    if(tag == 6)
        return new DoublePoolInfo(pool);
    if(tag == 15)
        return new MethodHandlePoolInfo(pool);
    return nullptr;
        /*
    tags.insert(std::pair<const int, PoolInfo*>(10, new RefPoolInfo("Methodref", pool)));
    tags.insert(std::pair<const int, PoolInfo*>(11, new RefPoolInfo("InterfaceMethodref", pool)));
    tags.insert(std::pair<const int, PoolInfo*>(9, new RefPoolInfo("Fieldref", pool)));
    tags.insert(std::pair<const int, PoolInfo*>(12, new RefPoolInfo("NameAndType", pool)));
    tags.insert(std::pair<const int, PoolInfo*>(18, new RefPoolInfo("InvokeDynamic", pool)));

    tags.insert(std::pair<const int, PoolInfo*>(7, new OneIndexPoolInfo("Class", pool)));
    tags.insert(std::pair<const int, PoolInfo*>(16, new OneIndexPoolInfo("MethodType", pool)));
    tags.insert(std::pair<const int, PoolInfo*>(8, new OneIndexPoolInfo("String", pool)));

    tags.insert(std::pair<const int, PoolInfo*>(1, new Utf8PoolInfo(pool)));

    tags.insert(std::pair<const int, PoolInfo*>(4, new FloatPoolInfo(pool)));
    tags.insert(std::pair<const int, PoolInfo*>(3, new NumberPoolInfo(pool)));
    tags.insert(std::pair<const int, PoolInfo*>(5, new LongPoolInfo(pool)));
    tags.insert(std::pair<const int, PoolInfo*>(6, new DoublePoolInfo(pool)));
    tags.insert(std::pair<const int, PoolInfo*>(15, new MethodHandlePoolInfo(pool)));
         */
}

int main(int argc, char* argv[]) {
    std::ifstream fileBuffer(argc == 1 ? "../Main.class" : argv[1], std::ios::binary);

    if(!fileBuffer.is_open()) {
        return 1;
    }

    std::map<int, PoolInfo*> pool;

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
    PoolInfo* poolInfo;

    while(mark < constant_pool_count) {
        fileBuffer.read(first_fields, sizeof(char));

        tag = (int) first_fields[0];
        if(tag < 0)
            return 2;

        poolInfo = getPoolInfo(tag, &pool);
        poolInfo->readInfo(fileBuffer, first_fields);
        pool.insert(std::pair<int, PoolInfo*>(mark, poolInfo));

        mark += poolInfo->m;
    }

    for (auto& entry : pool) {
        entry.second->printInfo(entry.first);
    }
    fileBuffer.close();
    return 0;
}
