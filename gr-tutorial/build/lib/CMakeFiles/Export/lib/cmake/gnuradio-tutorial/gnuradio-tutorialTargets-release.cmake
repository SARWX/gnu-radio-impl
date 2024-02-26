#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gnuradio::gnuradio-tutorial" for configuration "Release"
set_property(TARGET gnuradio::gnuradio-tutorial APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gnuradio::gnuradio-tutorial PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgnuradio-tutorial.so.1.0.0.0"
  IMPORTED_SONAME_RELEASE "libgnuradio-tutorial.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS gnuradio::gnuradio-tutorial )
list(APPEND _IMPORT_CHECK_FILES_FOR_gnuradio::gnuradio-tutorial "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libgnuradio-tutorial.so.1.0.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
