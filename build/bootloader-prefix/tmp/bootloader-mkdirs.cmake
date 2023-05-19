# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/volkerritzka/esp/esp-idf/components/bootloader/subproject"
  "/Users/volkerritzka/esp/TomatoTent/build/bootloader"
  "/Users/volkerritzka/esp/TomatoTent/build/bootloader-prefix"
  "/Users/volkerritzka/esp/TomatoTent/build/bootloader-prefix/tmp"
  "/Users/volkerritzka/esp/TomatoTent/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/volkerritzka/esp/TomatoTent/build/bootloader-prefix/src"
  "/Users/volkerritzka/esp/TomatoTent/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/volkerritzka/esp/TomatoTent/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/volkerritzka/esp/TomatoTent/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
