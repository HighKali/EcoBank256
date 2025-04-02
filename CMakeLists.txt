cmake_minimum_required(VERSION 3.10)

set(VERSION "0.1")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CONFIGURATION_TYPES Debug RelWithDebInfo Release CACHE TYPE INTERNAL)
set(CMAKE_SKIP_INSTALL_RULES ON)
set(CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY ON)
set(CMAKE_SUPPRESS_REGENERATION ON)

project(EcoBank256)

include_directories(src "${CMAKE_CURRENT_BINARY_DIR}/version")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  add_definitions("-D_DEFAULT_SOURCE -D_GNU_SOURCE")
endif()

set(ARCH native CACHE STRING "CPU to build for: -march value or default")
if("${ARCH}" STREQUAL "default")
  set(ARCH_FLAG "")
else()
  set(ARCH_FLAG "-march=${ARCH}")
endif()

set(WARNINGS "-Wall -Wextra -Wpointer-arith -Wundef -Wvla -Wwrite-strings -Wno-error=extra -Wno-error=unused-function -Wno-error=deprecated-declarations -Wno-error=sign-compare -Wno-error=strict-aliasing -Wno-error=type-limits -Wno-unused-parameter -Wno-error=unused-variable -Wno-error=undef -Wno-error=uninitialized -Wno-error=unused-result")
set(C_WARNINGS "-Waggregate-return -Wnested-externs -Wold-style-definition -Wstrict-prototypes")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 ${WARNINGS} ${C_WARNINGS} ${ARCH_FLAG} -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${WARNINGS} ${ARCH_FLAG} -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

set(DEBUG_FLAGS "-g3 -O0 -fno-omit-frame-pointer")
set(RELEASE_FLAGS "-Ofast -DNDEBUG -Wno-unused-variable")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${DEBUG_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${DEBUG_FLAGS}")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${RELEASE_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${RELEASE_FLAGS}")

set(BOOST_ROOT "/data/data/com.termux/files/usr")
find_package(Boost 1.55 REQUIRED COMPONENTS system filesystem date_time chrono regex serialization program_options asio)
if(Boost_FOUND)
  message(STATUS "Boost found: ${Boost_INCLUDE_DIRS}")
else()
  message(FATAL_ERROR "Boost not found! Please install boost with 'pkg install boost'")
endif()
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
set(LIBS ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

set(VERSION "${VERSION}-unknown")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/version")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in" "${CMAKE_CURRENT_BINARY_DIR}/version/version.h" @ONLY)
add_custom_target(version ALL)

add_executable(ecobank256d 
  src/main.c 
  src/blockchain.c 
  src/wallet.c 
  src/mixing.c 
  src/cli.c
  src/network.c  # Nuovo file per la rete P2P
  src/mining.c   # Nuovo file per il mining
)
target_link_libraries(ecobank256d ${LIBS})
