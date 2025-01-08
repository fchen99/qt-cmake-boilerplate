add_executable(app)

file(GLOB UIs ${CMAKE_SOURCE_DIR}/app/*.ui)
qt_add_translations(
    app
    SOURCES ${UIs}
    TS_FILE_DIR ${CMAKE_SOURCE_DIR}/app/i18n
    TS_FILE_BASE app
)

target_sources(
    app
    PRIVATE
    Widget.cpp
    main.cpp
)
target_include_directories(
    app
    PRIVATE
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(
    app
    PRIVATE
    Qt::Core Qt::Gui Qt::Widgets Qt::Svg
    controls
)

# fix the "qt.qpa.plugin: Could not find the Qt platform plugin 'windows' in ''" issue
add_custom_command(
    TARGET app
    POST_BUILD
    COMMAND Qt6::windeployqt
    ARGS $<TARGET_FILE:app>
)