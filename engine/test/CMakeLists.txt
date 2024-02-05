# Set project source file
set(INC_TEST )
set(SRC_TEST TestMain.cpp)
add_executable( Test ${SRC_TEST} )

set_target_properties( Test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/binary )
cm_printf_important(WARN "Executable output path : ${CMAKE_SOURCE_DIR}/binary")
# INC 변수는 ChimeraEngineCore의 cmakelist에서 사용중.
target_include_directories( Test PUBLIC ${INC_TEST} ${INC} )
set(CHIMERA_LIB_PATH "${CMAKE_SOURCE_DIR}/binary/${CHIMERA_LIBRARY_NAME}")
target_link_libraries(Test PRIVATE ${CHIMERA_LIB_PATH})