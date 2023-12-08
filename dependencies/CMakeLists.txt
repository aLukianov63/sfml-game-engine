include(FetchContent)

# SFML
FetchContent_Declare(
        sfml
        URL https://github.com/SFML/SFML/archive/refs/tags/2.5.1.zip
        URL_MD5 2c4438b3e5b2d81a6e626ecf72bf75be
)
add_subdirectory(sfml)

# Dear ImGui
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG master
)

FetchContent_MakeAvailable(imgui)

# ImGui-SFML
FetchContent_Declare(
        imgui-sfml
        GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml
        GIT_TAG master
)
add_subdirectory(imgui-sfml)
