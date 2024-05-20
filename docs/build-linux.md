# Build instructions for Linux
## Requirements
- 64-bit GNU/Linux distro
- Qt6 (Minimum: 6.7 / Recommended: 6.7)
- GCC (Minimum: 12 / Recommended: 14)
- CMake (Minimum: 3.20)

## Get the source code
### Via Git Clone
```
$ git clone https://github.com/zurg3/notepad.git
```

### Or download the source code of the latest version from GitHub
- [Releases/Tags](https://github.com/zurg3/notepad/tags)

## Build the project
### Open the source code directory in terminal

### Run
```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```

## If build was successful, Notepad executable will be in the current directory

## Install the project
```
$ sudo make install
```
