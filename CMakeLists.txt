cmake_minimum_required(VERSION 3.17)
project(game)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:\\dev\\SDL2\\include\\SDL2)
set(SDL2_LIB_DIR C:\\dev\\SDL2\\lib)

set(SDL2IMG_INCLUDE_DIR C:\\dev\\SDL2_image\\include)
set(SDL2IMG_LIB_DIR C:\\dev\\SDL2_image\\lib\\x86)

include_directories(include)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

include_directories(${SDL2IMG_INCLUDE_DIR})
link_directories(${SDL2IMG_LIB_DIR})

add_executable(game
        include/Entities.h
        include/Game.h
        include/Map.h
        include/Player.h
        include/TextureManager.h
        src/Entities.cpp
        src/Game.cpp
        src/Map.cpp
        src/Player.cpp
        src/TextureManager.cpp
        main.cpp include/Slime.h src/Slime.cpp include/Snorlax.h src/Snorlax.cpp)

target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)

