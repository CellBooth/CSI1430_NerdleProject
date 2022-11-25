cmake_minimum_required(VERSION 3.23)
project(SDL_Nerdle)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR C:/Users/daech/Downloads/Installers/SDL2-devel-2.24.2-VC/SDL2-2.24.2/include)
set(SDL2_LIB_DIR C:/Users/daech/Downloads/Installers/SDL2-devel-2.24.2-VC/SDL2-2.24.2/lib/x64)


include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})



add_executable(SDL_Nerdle main.cpp color.h constants.h DoesItCompute.cpp DoesItCompute.h EquationBuilder.cpp EquationBuilder.h point.cpp point.h Postguesscolorset.cpp Postguesscolorset.h SDL_Plotter.cpp SDL_Plotter.h tile.cpp tile.h txtBox.h txtDraw.cpp txtDraw.h)


target_link_libraries(${PROJECT_NAME} SDL2main SDL2)