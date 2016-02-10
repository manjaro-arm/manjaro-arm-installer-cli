cmake_minimum_required(VERSION 3.2)

# Creates source groups for a target
function(create_source_groups TARGET)
  get_property(SOURCES TARGET ${TARGET} PROPERTY SOURCES)
  foreach(FILE ${SOURCES})
    get_filename_component(PARENT_DIR "${FILE}" PATH)

    # skip src or include and changes /'s to \\'s
    string(REGEX REPLACE "(\\./)?(src|include)/?" "" GROUP "${PARENT_DIR}")
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    # group into "Source Files" and "Header Files"
    if ("${FILE}" MATCHES "\\.c(pp)?$")
      set(GROUP "Source Files\\${GROUP}")
    elseif("${FILE}" MATCHES "\\.h(pp)?$")
      set(GROUP "Header Files\\${GROUP}")
    endif()

    source_group("${GROUP}" FILES "${FILE}")
  endforeach()

  # Create a solution folder for the target based on the directory this
  # function was called from

  # There doesn't seem to be a function to convert an absolute path to a
  # relative one, so hack around it by getting the length of the root directory
  # and chopping it off of the beginning of the target's directory
  string(LENGTH "${CMAKE_SOURCE_DIR}" SOURCE_DIR_LENGTH)
  string(SUBSTRING "${CMAKE_CURRENT_SOURCE_DIR}" ${SOURCE_DIR_LENGTH} -1 FOLDER_NAME)
  set_target_properties(${TARGET} PROPERTIES FOLDER "${FOLDER_NAME}")
endfunction()

# Project name is manjaro-arm-installer-cli
project(manjaro-arm-installer-cli)

# Add CXX flags
if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

# Enable solution folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Create main target
add_executable(manjaro-arm-installer-cli
  src/main.cpp)

create_source_groups(manjaro-arm-installer-cli)