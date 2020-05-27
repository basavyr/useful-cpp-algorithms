add_executable(show_date main.cc)
add_library(show_Date SHARED main.cc)

target_link_libraries(show_date LINK_PUBLIC show_Date)

install(TARGETS show_date RUNTIME DESTINATION bin)
install(TARGETS show_Date LIBRARY DESTINATION lib)
