add_library(deezer-api-cpp utils/curl_utils.cpp)

target_link_libraries(deezer-api-cpp ${LIBS})

install(TARGETS deezer-api-cpp DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/ DESTINATION include/deezer-api-cpp FILES_MATCHING PATTERN "*.h*")