cmake_minimum_required(VERSION 3.10)

project(notepad VERSION 0.5)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core)
find_package(Qt5 COMPONENTS Gui)
find_package(Qt5 COMPONENTS Widgets)
find_package(Qt5 COMPONENTS PrintSupport)

if (UNIX)
  add_executable(notepad
    src/main.cpp
    src/notepad.cpp
    src/notepad.h
    src/notepad.ui
    src/notepad.qrc
    src/config.h
    src/version.h
  )
endif (UNIX)

if (WIN32)
  add_executable(notepad WIN32
    src/main.cpp
    src/notepad.cpp
    src/notepad.h
    src/notepad.ui
    src/notepad.qrc
    src/notepad.rc
    src/config.h
    src/version.h
  )
endif (WIN32)

target_link_libraries(notepad PUBLIC
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
  Qt5::PrintSupport
)

install(TARGETS notepad RUNTIME DESTINATION /usr/bin)

if (UNIX)
  install(FILES notepad.desktop DESTINATION /usr/share/applications)
endif (UNIX)
