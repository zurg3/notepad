# Build instructions for Windows
## Requirements
- 64-bit Windows (Minimum: 10 / Recommended: 11)
- Qt6 (Minimum: 6.7 / Recommended: 6.7)
- Microsoft Visual Studio (Minimum: 2022)
- CMake (Minimum: 3.20)

## Get the source code
### Via Git Clone
```
> git clone https://github.com/zurg3/notepad.git
```

### Or download the source code of the latest version from GitHub
- [Releases/Tags](https://github.com/zurg3/notepad/tags)

## Build the project
### Open the source code directory in CMD

### Run
```
> mkdir build
> cd build
> cmake ..
> cmake --build . --config Release
> windeployqt --no-translations Release
```

## If build was successful, Notepad executable will be in `Release` directory
