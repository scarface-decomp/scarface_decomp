cmake_minimum_required(VERSION 3.16)
project(scarface_decomp LANGUAGES CXX)

# Verification does not go through CMake: portal/scripts/reverify_all.py, portal/verify.py and the portal compile
# each function with cl.exe 13.10.3052 or 13.10.3077 and compare it with the game. This target only lets an IDE index
# the hand-written translation units. The generated files (Original_Binary_Order_*.cpp, pc/, xbox/) are
# collections of separately compiled blocks, and imported/ holds one-line sweep stubs, so neither is
# part of it.

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SCARFACE_RECON_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(FILTER SCARFACE_RECON_SOURCES EXCLUDE REGEX "/(Original_Binary_Order_.*|Partial_Proven_Checkpoints|verify_.*)\\.cpp$")
file(GLOB SCARFACE_RECON_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

add_library(scarface_reconstructed STATIC EXCLUDE_FROM_ALL ${SCARFACE_RECON_SOURCES} ${SCARFACE_RECON_HEADERS})
