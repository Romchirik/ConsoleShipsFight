cmake_minimum_required(VERSION 3.21)
project(ShipsFight)

set(CMAKE_CXX_STANDARD 14)

add_executable(ships main.cpp ShipsGame.cpp ShipsGame.h GameContext.cpp GameContext.h direction.h game_config.h arg_checker.h players/Player_factory.cpp players/Player_factory.h players/Player.h players/Random_player.cpp players/Random_player.h players/Console_player.cpp players/Console_player.h players/Optimal_player.cpp players/Optimal_player.h playfield/Playfield.cpp playfield/Playfield.h playfield/point.h playfield/ships/Ship.h playfield/ships/Ships_factory.cpp playfield/ships/Ships_factory.h playfield/ships/Ship_type.h playfield/ships/Smol_ship.cpp playfield/ships/Smol_ship.h playfield/ships/Huge_ship.cpp playfield/ships/Huge_ship.h playfield/ships/Big_ship.cpp playfield/ships/Big_ship.h playfield/ships/Incredibly_huge_ship.cpp playfield/ships/Incredibly_huge_ship.h)
