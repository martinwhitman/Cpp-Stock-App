# Automatically generated by boost-vcpkg-helpers/generate-ports.ps1

include(vcpkg_common_functions)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/hof
    REF boost-1.69.0
    SHA512 a49e800a59a3c3733aa647676899bd935c7623d18e6213b949def6ed2aff5cea240a503eb4a1cc2446fd3c7ef01f0d03f546cf4e49b16d9dced3530797670924
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})