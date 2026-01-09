cmake_minimum_required(VERSION 3.18)

project(VoidNovelEngine LANGUAGES C CXX)

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Desable GNU compile extensions
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB ${PROJECT_NAME}_SOURCE RaycastEngine/*.cpp)

# Add thrid-party source files
set(${PROJECT_NAME}_SOURCE
    Thirdparty/ImGUI/src/crude_json.cpp
    Thirdparty/ImGUI/src/drawing.cpp
    Thirdparty/ImGUI/src/imgui.cpp
    Thirdparty/ImGUI/src/imgui_canvas.cpp
    Thirdparty/ImGUI/src/imgui_demo.cpp
    Thirdparty/ImGUI/src/imgui_draw.cpp
    Thirdparty/ImGUI/src/imgui_impl_sdl2.cpp
    Thirdparty/ImGUI/src/imgui_impl_sdlrenderer2.cpp
    Thirdparty/ImGUI/src/imgui_node_editor.cpp
    Thirdparty/ImGUI/src/imgui_node_editor_api.cpp
    Thirdparty/ImGUI/src/imgui_stdlib.cpp
    Thirdparty/ImGUI/src/imgui_tables.cpp
    Thirdparty/ImGUI/src/imgui_widgets.cpp
    Thirdparty/ImGUI/src/rlImGui.cpp
    Thirdparty/ImGUI/src/widgets.cpp
    ${${PROJECT_NAME}_SOURCE}
)

add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCE}
)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    # Release build
    target_compile_options(${PROJECT_NAME} PRIVATE
        # For GCC, Clang
        $<$<CXX_COMPILER_ID:GNU,Clang>:
          -O2
        >
        # For MSVC
        $<$<CXX_COMPILER_ID:MSVC>:
          /O2
        >
    )
else()
    # Release build
    target_compile_options(${PROJECT_NAME} PRIVATE
        # For GCC, Clang
        $<$<CXX_COMPILER_ID:GNU,Clang>:
          -O0 -g -fno-inline -fno-omit-frame-pointer
        >
        # For MSVC
        $<$<CXX_COMPILER_ID:MSVC>:
          /Od /Zi /Ob0 /Oy-
          /link /DEBUG
        >
    )
endif()

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    Thirdparty/ImGUI/include
    Thirdparty/Lua/include
    Thirdparty/LuaBridge/include
    Thirdparty/MicroPather/include
    Thirdparty/Raylib/include
    Thirdparty/SDL2/include
    Thirdparty/cpp-base64/include
    Thirdparty/cJSON/include
)

# TODO: Link libraries
