cmake_minimum_required(VERSION 3.16)

# Settings for Apple Silicon with x86_64 compatibility
if(APPLE)
# Force x86_64 architecture (must be before project declaration)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
    set(CMAKE_OSX_ARCHITECTURES "x86_64" CACHE STRING "Build architectures for macOS" FORCE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.15" CACHE STRING "Minimum macOS version")
endif()

# Enable Qt automoc, autorcc, and autouic
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

project(CovidProject VERSION 1.0.0 LANGUAGES CXX)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set position-independent code
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Debug build options
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
endif()

# Set your Qt path - update this to your actual Qt 5.12 installation path
set(Qt5_DIR "/Users/vojtadeconinck/MyQtApp/Qt5.12.0/5.12.0/clang_64/lib/cmake/Qt5")
set(CMAKE_PREFIX_PATH "/Users/vojtadeconinck/MyQtApp/Qt5.12.0/5.12.0/clang_64")

# Find Qt5 components
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# Find OpenCV - adjust path as needed
set(OpenCV_DIR "/usr/local/Cellar/opencv/4.11.0_1/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(THIRDPARTY_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/includes")
include_directories(${THIRDPARTY_INCLUDE_DIR})


# Source files
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/person.cpp
    src/doctor.cpp
    src/patient.cpp
    src/loginscreen.cpp
    src/csvloader.cpp
    src/doctormenu.cpp
    src/addpatient.cpp
    src/regex_validation.cpp
    src/patientlist.cpp
    src/patientmenu.cpp
    src/patientfiltermodel.cpp
    src/patientdetails.cpp
    src/sessionutils.cpp
    src/covidtest.cpp
)

# Header files
set(HEADERS
    src/mainwindow.h
    src/person.h
    src/doctor.h
    src/patient.h
    src/loginscreen.h
    src/csvloader.h
    src/data_types.h
    src/doctormenu.h
    src/addpatient.h
    src/regex_validation.h
    src/patientlist.h
    src/patientmenu.h
    src/patientfiltermodel.h
    src/patientdetails.h
    src/sessionutils.h
    src/covidtest.h
)

# UI files
set(UI_FILES
    ui/mainwindow.ui
    ui/loginscreen.ui
    ui/doctormenu.ui
    ui/addpatient.ui
    ui/patientlist.ui
    ui/patientmenu.ui
    ui/patientdetails.ui
    ui/patientaccount.ui
    ui/covidtest.ui
)

# Resource files
set(RESOURCES
    resources/mainwindow.qrc
)

# Configure RPATH settings for macOS
if(APPLE)
    set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_SOURCE_DIR}/ui")
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    set(CMAKE_INSTALL_RPATH "${CMAKE_PREFIX_PATH}/lib;${CMAKE_PREFIX_PATH}/plugins")
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)
endif()

# Add the executable target
add_executable(CovidProject
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RESOURCES}
)

# Write qt.conf for macOS to locate plugins
if(APPLE)
    file(WRITE "${CMAKE_BINARY_DIR}/qt.conf"
"[Paths]\n"
"Prefix = ${CMAKE_PREFIX_PATH}\n"
"Plugins = ${CMAKE_PREFIX_PATH}/plugins\n"
    )
endif()

# Link Qt libraries and other dependencies
target_link_libraries(CovidProject PRIVATE
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    ${OpenCV_LIBS}
)

# Compile options
target_compile_options(CovidProject PRIVATE 
    -Wall
    -Wextra
    -Wpedantic
    -Wno-deprecated-declarations
)