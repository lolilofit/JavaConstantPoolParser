Конифигурация проекта:
1. Скачать и запустить готовый .exe файл из репозитория. 
Если нет входных параметров, то программа парсит файл по пути "../Main.class", иначе парсит файл по пути первого параметра программы.
2. Если необходимо самому собрать проект, то это можно сделать, например, через cmake с указанием подключаемых .cpp файлов в файле CmakeList.txt:
add_executable(project_name main.cpp PoolInfo.cpp pool_info/RefPoolInfo.cpp pool_info/NumberPoolInfo.cpp pool_info/OneIndexPoolInfo.cpp pool_info/Utf8PoolInfo.cpp pool_info/FloatPoolInfo.cpp pool_info/MethodHandlePoolInfo.cpp pool_info/LongPoolInfo.cpp pool_info/DoublePoolInfo.cpp)  