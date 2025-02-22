cmake_minimum_required(VERSION 3.16)

project(BarcodeReader3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TARGET_NAME appBarcodeReader3)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Multimedia)

qt_standard_project_setup(REQUIRES 6.4)

qt_add_executable(appBarcodeReader3
    main.cpp
)

qt_add_qml_module(appBarcodeReader3
    URI BarcodeReader3
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES include/DynamsoftBarcodeReader.h include/DynamsoftCommon.h
    SOURCES frameprocessor.h frameprocessor.cpp
    SOURCES imageprocessor.h imageprocessor.cpp
)

set_target_properties(appBarcodeReader3 PROPERTIES
    WIN32_EXECUTABLE TRUE
)

include_directories("${PROJECT_SOURCE_DIR}/include/")

target_link_libraries(${TARGET_NAME} PRIVATE Qt6::Quick Qt::Multimedia)

# Platform-specific configurations
if(WIN32)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_libraries(${TARGET_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/Lib/Windows/x64/DynamsoftBarcodeReaderx64.dll")
    else() # Assuming MSVC or other non-GNU compilers
        target_link_libraries(${TARGET_NAME} PRIVATE "DBRx64")
    endif()

    # Copy DLLs to build directory after build
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/Lib/Windows/"
        $<TARGET_FILE_DIR:${TARGET_NAME}>)
endif()

include(GNUInstallDirs)
install(TARGETS appBarcodeReader3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
