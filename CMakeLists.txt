cmake_minimum_required(VERSION 3.0.0)
project(grxvt-unicode VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set the C standard version (replace C11 with the desired version)
set(CMAKE_C_STANDARD 11)

# Set the C++ compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -fno-rtti -fvisibility-inlines-hidden -fno-threadsafe-statics -fno-enforce-eh-specs -w")

# Set the C preprocessor flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DHAVE_CONFIG_H")


# Find the gdk-pixbuf package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GDK_PIXBUF REQUIRED gdk-pixbuf-2.0)
include_directories(${GDK_PIXBUF_INCLUDE_DIRS})
link_libraries(${GDK_PIXBUF_LIBRARIES})


# CPack 
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Find FreeType
find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})
link_libraries(${FREETYPE_LIBRARIES})

# XLib
find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

# Xrender
find_library(XRENDER_LIBRARIES NAMES Xrender)
link_libraries(${XRENDER_LIBRARIES})
include_directories(${XRENDER_INCLUDE_DIRS})

# Find libev package
# find_package(Libev REQUIRED)
# link_libraries(${LIBEV_LIBRARIES})
# include_directories(${LIBEV_INCLUDE_DIRS})

include_directories(./)
include_directories(./libev)
include_directories(./src)
include_directories(./src/common)


# Set the additional include directories
include_directories(
    /usr/include/uuid
    /usr/include/libpng16
    /usr/include/harfbuzz
    /usr/include/glib-2.0
    /usr/lib/glib-2.0/include
    /usr/include/sysprof-4
    /usr/include/startup-notification-1.0
)

set(LIBS
    supc++
    m
    ptytty
    fontconfig
    Xft
    Xmu
    Xt
    gobject-2.0
    glib-2.0
    startup-notification-1
)

# Source Files
file(GLOB_RECURSE COMMON src/common/*.cpp)
set(COMMON_DAEMON src/rxvtdaemon.cpp)

# Add the grxvt executable target
add_executable(grxvt src/rxvt.cpp ${COMMON})

# Add the daemon executable target
add_executable(grxvtd src/rxvtd.cpp ${COMMON} ${COMMON_DAEMON})

# Add the clien executable target
add_executable(grxvtc src/rxvtc.cpp ${COMMON} ${COMMON_DAEMON})

# Set the target output names
set_target_properties(grxvt PROPERTIES OUTPUT_NAME "grxvt")
set_target_properties(grxvtc PROPERTIES OUTPUT_NAME "grxvtc")
set_target_properties(grxvtd PROPERTIES OUTPUT_NAME "grxvtd")

# Link Libraries
target_link_libraries(grxvt ${LIBS})
target_link_libraries(grxvtc ${LIBS})
target_link_libraries(grxvtd ${LIBS})