cmake_minimum_required(VERSION 3.21)
project(Pokemons)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Pokemons main.cpp source/Pokemon.cpp headers/Pokemon.h source/PokemonUtils.cpp headers/PokemonUtils.h source/Attack.cpp headers/Attack.h source/Game.cpp headers/Game.h source/Player.cpp headers/Player.h source/Help.cpp headers/Help.h)
