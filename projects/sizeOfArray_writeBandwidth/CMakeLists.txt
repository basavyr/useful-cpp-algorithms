add_executable(array_bandwidth main.cc)
add_library(bandwidh_array SHARED main.cc)

target_link_libraries(array_bandwidth LINK_PUBLIC bandwidh_array)

install(TARGETS array_bandwidth RUNTIME DESTINATION bin)
install(TARGETS bandwidh_array LIBRARY DESTINATION lib)
