
FILE(GLOB ENGINE_SRC "engine/*.cc")

set(ALL_SRC
        ${ENGINE_SRC})


add_library(raptor_static STATIC ${ALL_SRC})
add_library(raptor_shared SHARED ${ALL_SRC})

target_link_libraries(raptor_static pthread)
if (APPLE)
    find_library(CoreFoundation CoreFoundation)
    target_link_libraries(raptor_static ${CoreFoundation} abel pthread)
    target_link_libraries(raptor_shared ${CoreFoundation} abel pthread)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(raptor_static abel pthread)
    target_link_libraries(raptor_shared abel pthread rt)
endif ()

set_target_properties(raptor_shared PROPERTIES
        OUTPUT_NAME raptor
        VERSION ${CMAKE_PROJECT_VERSION}
        SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR}
        )

set_target_properties(raptor_static PROPERTIES
        OUTPUT_NAME raptor
        VERSION ${CMAKE_PROJECT_VERSION}
        SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR}
        )

install(TARGETS raptor_static raptor_shared
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )

file(COPY ${PROJECT_SOURCE_DIR}/raptor
        DESTINATION ${PROJECT_BINARY_DIR}/include
        FILES_MATCHING
        PATTERN "*.h"
        )

install(DIRECTORY ${PROJECT_BINARY_DIR}/include/raptor
        DESTINATION include
        FILES_MATCHING
        PATTERN "*.h"
        )