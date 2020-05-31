add_library(asyncxx SHARED async.cc)
add_executable(async_main main.cc)

target_link_libraries(async_main LINK_PUBLIC asyncxx)

install(TARGETS async_main RUNTIME DESTINATION bin)
install(TARGETS asyncxx LIBRARY DESTINATION lib)

