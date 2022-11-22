# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# cs225_sources at lib/CMakeLists.txt:12 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/WBLR-CS-225-Project/lib/cs225/*.cpp")
set(OLD_GLOB
  "/workspaces/WBLR-CS-225-Project/lib/cs225/HSLAPixel.cpp"
  "/workspaces/WBLR-CS-225-Project/lib/cs225/PNG.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/WBLR-CS-225-Project/build_pc/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/WBLR-CS-225-Project/lib/lodepng/*.cpp")
set(OLD_GLOB
  "/workspaces/WBLR-CS-225-Project/lib/lodepng/lodepng.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/WBLR-CS-225-Project/build_pc/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/WBLR-CS-225-Project/lib/lodepng/*.h")
set(OLD_GLOB
  "/workspaces/WBLR-CS-225-Project/lib/lodepng/lodepng.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/WBLR-CS-225-Project/build_pc/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/WBLR-CS-225-Project/src/*.cpp")
set(OLD_GLOB
  "/workspaces/WBLR-CS-225-Project/src/Algorithms/bet_cent.cpp"
  "/workspaces/WBLR-CS-225-Project/src/Algorithms/bfs.cpp"
  "/workspaces/WBLR-CS-225-Project/src/Algorithms/dijkstra.cpp"
  "/workspaces/WBLR-CS-225-Project/src/Graph.cpp"
  "/workspaces/WBLR-CS-225-Project/src/readdat.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/WBLR-CS-225-Project/build_pc/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:131 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/WBLR-CS-225-Project/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/WBLR-CS-225-Project/tests/test-dijkstra.cpp"
  "/workspaces/WBLR-CS-225-Project/tests/test-graph.cpp"
  "/workspaces/WBLR-CS-225-Project/tests/test-readdat.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/WBLR-CS-225-Project/build_pc/CMakeFiles/cmake.verify_globs")
endif()
