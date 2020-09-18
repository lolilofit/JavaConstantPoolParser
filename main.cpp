#include <iostream>
#include <map>
#include "PoolInfo.h"
#include "pool_info/RefPoolInfo.h"
#include "pool_info/StringPoolInfo.h"
#include "pool_info/NumberPoolInfo.h"
#include "pool_info/ClassPoolInfo.h"
#include "pool_info/Utf8PoolInfo.h"

void fill_tags(std::map<int, PoolInfo*> &tags) {
    tags.insert(std::pair<const int, PoolInfo*>(10, new RefPoolInfo("Methodref")));
    tags.insert(std::pair<const int, PoolInfo*>(11, new RefPoolInfo("InterfaceMethodref")));
    tags.insert(std::pair<const int, PoolInfo*>(9, new RefPoolInfo("Fieldref")));
    tags.insert(std::pair<const int, PoolInfo*>(12, new RefPoolInfo("NameAndType")));
    tags.insert(std::pair<const int, PoolInfo*>(8, new StringPoolInfo()));
    tags.insert(std::pair<const int, PoolInfo*>(3, new NumberPoolInfo()));
    tags.insert(std::pair<const int, PoolInfo*>(7, new ClassPoolInfo()));
    tags.insert(std::pair<const int, PoolInfo*>(1, new Utf8PoolInfo()));
}

int main() {
    std::ifstream fileBuffer(R"(C:\Users\User\CLionProjects\javaoptlab1\Main.class)", std::ios::binary);

    if(!fileBuffer.is_open()) {
        return 1;
    }

    std::map<int, PoolInfo*> tags;
    fill_tags(tags);

    char* first_fields = new char[4];
    std::fill(first_fields, first_fields + 4, 0);

    //read magic number
    fileBuffer.read(first_fields, sizeof(char) * 4);

    //read minor and major version
    fileBuffer.read(first_fields, sizeof(char) * 4);
    int minor_version = 16*(int) first_fields[0] + (int) first_fields[1];
    int major_version = 16*(int) first_fields[2] + (int) first_fields[3];

    std::cout << "Minor number is: " << minor_version << "\n Major number is: " << major_version << "\n";

    fileBuffer.read(first_fields, sizeof(char) * 2);
    int constant_pool_count = 16*(int) first_fields[0] + (int) first_fields[1];

    //read constant pool
    int tag;

    for(int i = 1; i < constant_pool_count; i++) {
        fileBuffer.read(first_fields, sizeof(char));

        tag = (int) first_fields[0];
        if(tag < 0)
            return 2;

        if(tags.find(tag) != tags.end())
            tags.at(tag)->readPrintInfo(fileBuffer, i, first_fields);
    }

    fileBuffer.close();
    return 0;
}
