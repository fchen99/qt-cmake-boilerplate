add_executable(app)
target_sources(
    app
    PRIVATE
    Widget.cpp
    main.cpp
)
target_link_libraries(
    app
    PRIVATE
    Qt::Core Qt::Gui Qt::Widgets Qt::Svg
)

# fix the "qt.qpa.plugin: Could not find the Qt platform plugin 'windows' in ''" issue
add_custom_command(
    TARGET app
    POST_BUILD
    COMMAND Qt6::windeployqt
    ARGS $<TARGET_FILE:app>
)