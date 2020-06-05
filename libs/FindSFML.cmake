IF (NOT SFML_INCLUDE_DIRS OR NOT SFML_LIBRARIES)
  FIND_PATH(SFML_INCLUDE_DIRS
    NAMES
      SFML/Audio.hpp
    PATHS
      /usr/include/       # Default Fedora28 system include path
      /usr/local/include/  # Default Fedora28 local include path
      ${CMAKE_MODULE_PATH}/include/ # Expected to contain the path to this file for Windows10
      ${SFML_DIR}/../../include/      # SFML root directory (if provided)
  )

  IF (MSVC)     # Windows
    SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
  ELSE (MSVC)   # Linux
    SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
  ENDIF(MSVC)

  FIND_LIBRARY(SFML_LIBRARIES
    NAMES
      sfml-audio
    PATHS
      /usr/lib64/
      /usr/lib/
      /usr/lib/x86_64-linux-gnu/
      /usr/local/lib/
      /usr/local/lib64/
      ${SFML_DIR}/../../lib/
      ${CMAKE_MODULE_PATH}/SFML/lib/
  )
ENDIF (NOT SFML_INCLUDE_DIRS OR NOT SFML_LIBRARIES)

IF (SFML_INCLUDE_DIRS AND SFML_LIBRARIES)
  SET(SFML_FOUND TRUE)
ELSE (SFML_INCLUDE_DIRS AND SFML_LIBRARIES)
  SET(SFML_FOUND FALSE)
ENDIF (SFML_INCLUDE_DIRS AND SFML_LIBRARIES)

IF (SFML_FIND_REQUIRED AND NOT SFML_FOUND)
  MESSAGE(FATAL_ERROR
    "  SFML not found.\n"
    "      Windows: Fill CMake variable CMAKE_MODULE_PATH to the provided directory.\n"
    "      Linux: Install SFML using your package manager ($> sudo dnf install SFML-devel).\n"
  )
ENDIF (SFML_FIND_REQUIRED AND NOT SFML_FOUND)
