cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(genetic)

add_compile_options(-std=c++11)

find_package(Eigen3 REQUIRED)
find_package(OpenMP)


aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST )
include_directories(${PROJECT_SOURCE_DIR}/include/genetic )

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
