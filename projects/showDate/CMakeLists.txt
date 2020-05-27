add_executable(show_date main.cc)
add_library(date SHARED main.cc)

target_link_libraries(show_date LINK_PUBLIC date)

install(TARGETS show_date RUNTIME DESTINATION bin)
install(TARGETS date LIBRARY DESTINATION lib)
