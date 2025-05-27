# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CovidProject_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CovidProject_autogen.dir/ParseCache.txt"
  "CovidProject_autogen"
  )
endif()
