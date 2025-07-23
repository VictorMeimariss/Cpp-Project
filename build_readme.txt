Project Build Instructions

Step 1
    clone repo
    cd <root directory>

Step 2 
    Every new terminal do:
    source /opt/intel/oneapi/setvars.sh (This sets up icpx compiler, gdb-oneapi, MKL paths)
    code . (opens vscode)

Step 3
    Update/Create CMakeLists.txt for new entries at /sr and /tests etc

Step 4
    Run CMake config -> cmake -S . -B obj
    Build -> cmake --build obj

Step 5
    Create/Config launch.json & tasks.json
