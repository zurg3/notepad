TEMPLATE = app
TARGET = notepad

QT += widgets

qtHaveModule(printsupport): QT += printsupport
requires(qtConfig(fontdialog))

SOURCES += \
  main.cpp\
  notepad.cpp

HEADERS += \
  notepad.h\
  config.h\
  version.h

FORMS += notepad.ui

RESOURCES += \
  notepad.qrc

RC_FILE = notepad.rc
