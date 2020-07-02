include(FindPackageHandleStandardArgs)

if(WIN32)

    # Search for Cairo in extern/cairo-windows-1.15.12
    find_path(Cairo_ROOT "include/cairo.h" PATHS "${CMAKE_CURRENT_LIST_DIR}/../lib/cairo" NO_DEFAULT_PATH)
    
    # choose correct dlls for windows 64Bit
    if(Cairo_ROOT)
        set(Cairo_INCLUDE_DIRS "${Cairo_ROOT}/include")
        set(Cairo_LIBS "${Cairo_ROOT}/lib/x64/cairo.lib")
        set(Cairo_DLLS "${Cairo_ROOT}/lib/x64/cairo.dll")
    endif()

    mark_as_advanced(Cairo_ROOT)
    find_package_handle_standard_args(Cairo DEFAULT_MSG Cairo_INCLUDE_DIRS Cairo_LIBS Cairo_DLLS)

else()
    # On MacOS, should be installed via Macports
    # On Ubuntu, install with: apt-get install libcairo2-dev
    find_path(Cairo_INCLUDE_DIRS cairo.h PATH_SUFFIXES cairo)
    find_library(_Cairo_LIB cairo)
    set(Cairo_LIBS ${_Cairo_LIB})
    
    mark_as_advanced(Cairo_INCLUDE_DIRS _Cairo_LIB)
    find_package_handle_standard_args(Cairo DEFAULT_MSG Cairo_INCLUDE_DIRS Cairo_LIBS)
endif()