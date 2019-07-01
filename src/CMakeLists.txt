add_library(percolation_simulator
    SHARED
        unionfind.cpp
        percolation.cpp
        )
target_include_directories(percolation_simulator
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    )