cmake_minimum_required(VERSION 3.29)
project(R3_02)

set(CMAKE_CXX_STANDARD 20)

# Ajouter les fichiers sources
set(SOURCES
        main.cpp
        node.cpp
        tree.cpp
        treeiterator.cpp
)

# Ajouter les fichiers d'en-tête
set(HEADERS
        node.h
        test.h
        tree.h
        treeiterator.h
)

add_executable(R3_02 ${SOURCES} ${HEADERS})
