# rhythmplayer

## Setup
- `git clone https://github.com/defaultexception/rhythmplayer.git`
- Download CMake: https://cmake.org/download/

## Run

### Linux
```bash
./build.sh $asset_path # Insert asset path here
./run.sh
```

### Windows
```
set ASSETS_PATH={ASSETS_PATH}
cmake -B build && cmake --build build
.\build\bin\Debug\main.exe
```

## Test

### Linux
```bash
./build.sh $asset_path # Insert asset path here
./test.sh
```

### Windows
```
set ASSETS_PATH={ASSETS_PATH}
cmake -B build && cmake --build build
.\build\bin\Debug\tests.exe
```

## TODO

1. Long-term
    - [x] Testing
    - [ ] Documentation
    - [ ] Benchmarking
2. Parsing
    - [x] Correctly parse test file
    - [ ] Parse 100 test files correctly
3. Graphics
    - [ ] Create scene manager
    - [ ] Main menu
    - [ ] Options menu w/ json
    - [ ] Gameplay screen
    - [ ] Score screen
