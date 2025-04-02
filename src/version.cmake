# src/version.cmake
execute_process(
    COMMAND ${GIT} log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
if(NOT GIT_COMMIT_HASH)
    set(GIT_COMMIT_HASH "unknown")
endif()
configure_file("${CMAKE_SOURCE_DIR}/src/version.h.in" "${TO}" @ONLY)
