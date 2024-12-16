cmake_minimum_required(VERSION 3.29)
project(R3_02)

set(CMAKE_CXX_STANDARD 20)

# Ajouter les fichiers sources
set(SOURCES
        main.cpp
        element.cpp
        iteratorlist.cpp
        list.cpp
)

# Ajouter les fichiers d'en-tête
set(HEADERS
        element.h
        ExceptionList.h
        iteratorlist.h
        list.h
        test.h
)

add_executable(R3_02 ${SOURCES} ${HEADERS})
