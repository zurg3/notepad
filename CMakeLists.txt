cmake_minimum_required(VERSION 3.20)

project(notepad
  VERSION 0.5.1
  DESCRIPTION "Simple text editor. Based on official Qt6 Notepad example."
  HOMEPAGE_URL "https://github.com/zurg3/notepad"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Widgets)
find_package(Qt6 COMPONENTS PrintSupport)

if(UNIX)
  add_executable(notepad
    src/main.cpp
    src/notepad.cpp
    src/notepad.h
    src/notepad.ui
    src/notepad.qrc
    src/config.h
    src/version.h
  )
endif()

if(WIN32)
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
endif()

target_link_libraries(notepad PUBLIC
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  Qt6::PrintSupport
)

install(TARGETS notepad RUNTIME DESTINATION /usr/bin)

if(UNIX)
  install(FILES notepad.desktop DESTINATION /usr/share/applications)
endif()
