# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Netflix-Clone_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Netflix-Clone_autogen.dir\\ParseCache.txt"
  "Netflix-Clone_autogen"
  )
endif()
