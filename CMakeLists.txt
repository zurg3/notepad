cmake_minimum_required(VERSION 3.20)

project(notepad
  VERSION 0.5.1
  DESCRIPTION "Simple text editor. Based on official Qt5 Notepad example."
  HOMEPAGE_URL "https://github.com/zurg3/notepad"
  LANGUAGES CXX
)

if (UNIX AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8.1)
  set(CMAKE_CXX_STANDARD 17)
else ()
  set(CMAKE_CXX_STANDARD 20)
endif ()
set(CMAKE_CXX_STANDARD_REQUIRED True)

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
endif ()

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
endif ()

target_link_libraries(notepad PUBLIC
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
  Qt5::PrintSupport
)

install(TARGETS notepad RUNTIME DESTINATION /usr/bin)

if (UNIX)
  install(FILES notepad.desktop DESTINATION /usr/share/applications)
endif ()
