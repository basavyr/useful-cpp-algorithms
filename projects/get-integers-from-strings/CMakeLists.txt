add_executable(getintegers get_integers.cc)
add_library(integers SHARED get_integers.cc)

target_link_libraries(getintegers LINK_PUBLIC integers)

install(TARGETS getintegers RUNTIME DESTINATION bin)
install(TARGETS integers LIBRARY DESTINATION lib)
install(FILES input.dat DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)