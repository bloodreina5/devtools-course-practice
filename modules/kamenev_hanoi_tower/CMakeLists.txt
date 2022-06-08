# Declare variables for binaries' names
get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MODULE      "${DIRNAME}")
set(LIBRARY     "lib${MODULE}")
set(TESTS       "test${MODULE}")
set(APPLICATION "app${MODULE}")

# Include directory with public headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add all submodules
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(application)

#############################################
##### Testing
#############################################