project(Disruptor)
cmake_minimum_required(VERSION 2.6)

set(DISRUPTOR_VERSION_MAJOR "1")
set(DISRUPTOR_VERSION_MINOR "0")
set(DISRUPTOR_VERSION_PATCH "0")
set(DISRUPTOR_VERSION "${DISRUPTOR_VERSION_MAJOR}.${DISRUPTOR_VERSION_MINOR}.${DISRUPTOR_VERSION_PATCH}")


# Set architecture-related string for installation consistent with scons file
set(ARCH ${CMAKE_HOST_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_PROCESSOR})
message(STATUS "ARCH = " ${ARCH})


# Install into $CODA_INSTALL directory
if (DEFINED CODA_INSTALL)
    message(STATUS "CODA_INSTALL = " ${CODA_INSTALL})
    set(INSTALL_DIR_DEFINED 1)
    set(CMAKE_INSTALL_PREFIX ${CODA_INSTALL}/${ARCH})
    set(CMAKE_INSTALL_INCLUDEDIR ${CODA_INSTALL}/common/include)
    message(STATUS "CMAKE_INSTALL_PREFIX reset to " ${CMAKE_INSTALL_PREFIX})
    # Install into $CODA directory
elseif (DEFINED ENV{CODA})
    message(STATUS "CODA = " $ENV{CODA})
    set(INSTALL_DIR_DEFINED 1)
    set(CMAKE_INSTALL_PREFIX $ENV{CODA}/${ARCH})
    set(CMAKE_INSTALL_INCLUDEDIR $ENV{CODA}/common/include)
    message(STATUS "CMAKE_INSTALL_PREFIX reset to " ${CMAKE_INSTALL_PREFIX})
else()
    message(STATUS "Set the \"CODA\" env var or specify -DCODA_INSTALL=... on the command line or it'll be installed in /usr/local")
endif()


enable_testing()

# enable gcc specific stuff
if(CMAKE_COMPILER_IS_GNUCXX)
    set(COMPILER_FLAGS "-std=c++14")
    set(WARNING_FLAGS "-W -Wall")
    
    if(CMAKE_BUILD_TYPE STREQUAL "debug")
        message(STATUS "Enabling debugging symbols")
        set(COMPILER_FLAGS "${COMPILER_FLAGS} -g")
    else()
        set(COMPILER_FLAGS "${COMPILER_FLAGS} -O2")
    endif()

    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
        add_definitions(-fPIC)
    endif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")

elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(COMPILER_FLAGS "-std=c++14")
    set(WARNING_FLAGS "-W -Wall")
    
    if(CMAKE_BUILD_TYPE STREQUAL "debug")
        message(STATUS "Enabling debugging symbols")
        set(COMPILER_FLAGS "${COMPILER_FLAGS} -g")
    else()
        set(COMPILER_FLAGS "${COMPILER_FLAGS} -O2")
    endif()

    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
        add_definitions(-fPIC)
    endif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS} ${WARNING_FLAGS}")

add_subdirectory(Disruptor)

if(DISRUPTOR_BUILD_TESTS)
    add_subdirectory(googletest-release-1.8.0)
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    add_subdirectory(Disruptor.PerfTests)
    add_subdirectory(Disruptor.TestTools)
    add_subdirectory(Disruptor.Tests)
endif()


# uninstall target
##################
#

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY
)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
)


# Packaging stuff
#################
#

set(CPACK_PACKAGE_VERSION_MAJOR "${DISRUPTOR_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${DISRUPTOR_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${DISRUPTOR_VERSION_PATCH}")

set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${DISRUPTOR_VERSION}")

set(CPACK_SOURCE_GENERATOR "TBZ2")
set(CPACK_SOURCE_IGNORE_FILES
    "build/"
    "ipch/"
    "/resources/"
    ".sdf$;.suo$;.tss$"
)

include(CPack)
add_custom_target(distr COMMAND ${CMAKE_MAKE_PROGRAM} package_source)

