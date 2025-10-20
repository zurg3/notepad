# Notepad

Simple text editor. Based on [official Qt6 Notepad example](https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/tutorials/notepad?h=6.10).

[![Build Status](https://github.com/zurg3/notepad/actions/workflows/win.yml/badge.svg?branch=master&event=push)](https://github.com/zurg3/notepad/actions)
[![Build Status](https://github.com/zurg3/notepad/actions/workflows/linux.yml/badge.svg?branch=master&event=push)](https://github.com/zurg3/notepad/actions)

## Install Notepad
### Windows - [download portable build](https://github.com/zurg3/notepad/releases/latest)

### Linux
#### Arch Linux
Install via PKGBUILD
```
$ git clone https://github.com/zurg3/notepad.git
$ cd notepad
$ makepkg -si
$ cd ..
$ rm -rf notepad
```

#### Other Linux distros
- Get the source code
- Build the project
- Install via `sudo make install`

## Some notes
- **Currently I don't provide Notepad binaries for Linux!**
- You need install the latest [Microsoft Visual C++ Redistributable](https://learn.microsoft.com/cpp/windows/latest-supported-vc-redist) to run Notepad on Windows.
- [Issues](https://github.com/zurg3/notepad/issues) and [Pull Requests](https://github.com/zurg3/notepad/pulls) are welcome.

## Screenshots
### Windows build
![Screenshot of Windows build](https://raw.githubusercontent.com/zurg3/notepad/master/docs/img/screenshot_windows.png)

### Linux build
![Screenshot of Linux build](https://raw.githubusercontent.com/zurg3/notepad/master/docs/img/screenshot_linux.png)

## Build instructions
- [Windows](https://github.com/zurg3/notepad/blob/master/docs/build-win.md)
- [Linux](https://github.com/zurg3/notepad/blob/master/docs/build-linux.md)
