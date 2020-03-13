cmake_minimum_required(VERSION 3.10)
project(cat)
add_library(Cat SHARED lib.h)
SET_TARGET_PROPERTIES(Cat PROPERTIES LINKER_LANGUAGE CXX)
