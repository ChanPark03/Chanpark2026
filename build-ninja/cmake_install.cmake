# Install script for directory: /home/chan/Chanpark2026

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/chan/Chanpark2026/build-ninja/c_example/part3/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/c_example/part4/carSerial/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/c_example/part4/myRandom/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/c_example/part4/baseballGame/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/c_example/part5/date/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/c_example/part5/struct_twoDouble/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/c_example/part6/scoreProcess/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/ds/stack/myStack1/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/ds/stack/myStack2/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/ds/stack/myStack3/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/ds/stack/myStack4/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/ds/queue/myQueue/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/ds/queue/myqueue3/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/network/cmake_install.cmake")
  include("/home/chan/Chanpark2026/build-ninja/bowlingGame/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/chan/Chanpark2026/build-ninja/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
