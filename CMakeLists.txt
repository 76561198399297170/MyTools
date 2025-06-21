cmake_minimum_required(VERSION 3.10)
project(Toolkit)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录到根目录下的bin文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin/Release)

# 收集根目录下的所有.cpp和.h文件
file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/source/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${PROJECT_SOURCE_DIR}/include/*.h)

# 添加可执行文件
add_executable(toolkit ${SOURCE_FILES} ${HEADER_FILES})

# 设置头文件搜索路径
target_include_directories(toolkit PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 后续自行添加链接的 lib 库

# cd build
# cmake ..
# make