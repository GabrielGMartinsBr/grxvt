# FindLibev.cmake

# Locate Libev library
find_path(Libev_INCLUDE_DIR NAMES ev.h PATH_SUFFIXES libev)

find_library(Libev_LIBRARY NAMES ev)

# Set the Libev_FOUND variable to indicate whether the library was found or not
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Libev DEFAULT_MSG Libev_LIBRARY Libev_INCLUDE_DIR)

# If Libev was found, set the additional variables
if (Libev_FOUND)
    set(LIBEV_LIBRARIES ${Libev_LIBRARY})
    set(LIBEV_INCLUDE_DIRS ${Libev_INCLUDE_DIR})
endif()

# Provide user-friendly information about Libev status
message(STATUS "Libev found: ${Libev_FOUND}")
