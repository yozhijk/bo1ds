add_library(math INTERFACE)

target_sources(math INTERFACE vec2.h)

target_include_directories(math INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(math INTERFACE project_options project_warnings)
