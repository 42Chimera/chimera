@echo off

cmake -E remove_directory Intermediate
cmake -B Intermediate -DBUILD_SHARED_LIBS=ON
cmake --build Intermediate -j4