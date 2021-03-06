cmake_minimum_required(VERSION 2.8)
project(CarNN)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++17")

find_package(SFML 2 COMPONENTS graphics REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
find_package(unofficial-box2d CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(cereal CONFIG REQUIRED)
find_package(TBB CONFIG REQUIRED)
find_package(Microsoft.GSL CONFIG REQUIRED)

add_executable(${PROJECT_NAME}
	src/neural/activationmethod.cpp
	src/neural/network.cpp
	src/neural/neuron.cpp
	src/neural/visualizer.cpp
	src/sim/entities/car.cpp
	src/sim/entities/checkpoint.cpp
	src/sim/entities/wheel.cpp
	src/sim/entities/body.cpp
	src/sim/simulationunit.cpp
	src/sim/world.cpp
	src/training/mutator.cpp
	src/training/settings.cpp
	src/util/random.cpp
	src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include/)

target_link_libraries(${PROJECT_NAME}
	jsoncpp_static
	sfml-graphics
	imgui::imgui
	ImGui-SFML::ImGui-SFML
	GL # required because of sfml/vcpkg being dumbasses
	unofficial::box2d::box2d
	fmt
	spdlog::spdlog
	cereal
	TBB::tbb
	Microsoft.GSL::GSL
)
