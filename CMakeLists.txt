cmake_minimum_required(VERSION 3.15)

# Переменные
set(CMAKE_CXX_STANDARD 17)

# Расположение файлов библиотеки
FILE(GLOB_RECURSE INCLUDES ${ENGINE_SOURCE}/*.h)
FILE(GLOB_RECURSE SOURCES ${ENGINE_SOURCE}/*.cpp)
source_group(TREE ${ENGINE_SOURCE} TREE PREFIX "" FILES ${INCLUDES} ${SOURCES})

# Расположение заголовочных файлов
include_directories(${GAME_SOURCE})

# Создание статической библиотеки
add_library(${ENGINE_NAME} STATIC ${INCLUDES} ${SOURCES})

