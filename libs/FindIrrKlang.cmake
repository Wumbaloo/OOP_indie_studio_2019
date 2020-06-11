IF (NOT IrrKlang_INCLUDE_DIRS OR NOT IrrKlang_LIBRARIES)
  FIND_PATH(IrrKlang_INCLUDE_DIRS
    NAMES
      irrKlang.h
      irrKlang/irrKlang.h
    PATHS
      /usr/include/irrKlang/        # Default Fedora28 system include path
      /usr/local/include/irrKlang/  # Default Fedora28 local include path
      ${CMAKE_MODULE_PATH}/include/ # Expected to contain the path to this file for Windows10
      ${IrrKlang_DIR}/      # IrrKlang root directory (if provided)
      ${IrrKlang_DIR}/include/      # IrrKlang root directory (if provided)
  )

  IF (MSVC)     # Windows
    SET(CMAKE_FIND_LIBRARY_PREFIXES "")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
  ELSE (MSVC)   # Linux
    SET(CMAKE_FIND_LIBRARY_PREFIXES "lib")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".so")
  ENDIF(MSVC)

  FIND_LIBRARY(IrrKlang_LIBRARIES
    NAMES
      IrrKlang
    PATHS
      /usr/lib64/                   # Default Fedora28 library path
      /usr/lib/                     # Some more Linux library path
      /usr/lib/x86_64-linux-gnu/    # Some more Linux library path
      /usr/local/lib/               # Some more Linux library path
      /usr/local/lib64/             # Some more Linux library path
      ${CMAKE_MODULE_PATH}/         # Expected to contain the path to this file for Windows10
      ${IrrKlang_DIR}/              # IrrKlang root directory (if provided)
  )
ENDIF (NOT IrrKlang_INCLUDE_DIRS OR NOT IrrKlang_LIBRARIES)

IF (IrrKlang_INCLUDE_DIRS AND IrrKlang_LIBRARIES)
  SET(IrrKlang_FOUND TRUE)
ELSE (IrrKlang_INCLUDE_DIRS AND IrrKlang_LIBRARIES)
  SET(IrrKlang_FOUND FALSE)
ENDIF (IrrKlang_INCLUDE_DIRS AND IrrKlang_LIBRARIES)

IF (IrrKlang_FIND_REQUIRED AND NOT IrrKlang_FOUND)
  MESSAGE(FATAL_ERROR
    "  IrrKlang not found.\n"
    "      Windows: Fill CMake variable CMAKE_MODULE_PATH to the provided directory.\n"
    "      Linux: Install IrrKlang on the official website\n"
  )
ENDIF (IrrKlang_FIND_REQUIRED AND NOT IrrKlang_FOUND)
