cmake_minimum_required(VERSION "3.18.4")

project("Sensor")

add_executable("${PROJECT_NAME}" "sense.cpp")

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})

install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #${CMAKE_INSTALL_PREFIX}/bin
install(FILES "sense.cpp" DESTINATION src)         #${CMAKE_INSTALL_PREFIX}/src