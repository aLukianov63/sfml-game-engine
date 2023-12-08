
set(CMAKE_CXX_STANDARD 23)

add_executable(GameTest_exe
        # source files
        main.cpp
        Game.cpp
        Game.h
        Player.cpp
        Player.h
        Object.h
        Cultist.cpp
        Cultist.h
        # engine files
        engine/Action.cpp
        engine/Action.h
        engine/ActionHandler.cpp
        engine/ActionHandler.h
        engine/Entity.cpp
        engine/Entity.h
        engine/ResourceManager.h
        engine/Configuration.cpp
        engine/Configuration.h
        engine/Animation.cpp
        engine/Animation.h
        engine/AnimatedSprite.cpp
        engine/AnimatedSprite.h
        engine/LevelManager.cpp
        engine/LevelManager.h
        engine/Background.cpp
        engine/Background.h
        engine/Camera.cpp
        engine/Camera.h
        engine/Enemy.cpp
        engine/Enemy.h
        # gui files
        gui/Gui.h)

target_link_libraries(GameTest_exe PRIVATE ImGui-SFML::ImGui-SFML)

# Copy DLLs needed for runtime on Windows
if (WIN32)
    if (BUILD_SHARED_LIBS)
        add_custom_command(TARGET GameTest_exe POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:ImGui-SFML::ImGui-SFML>
                $<TARGET_FILE:sfml-graphics>
                $<TARGET_FILE:sfml-window>
                $<TARGET_FILE:sfml-system>
                $<TARGET_FILE:sfml-audio>
                $<TARGET_FILE:sfml-network>
                $<TARGET_FILE_DIR:GameTest_exe>)
    endif ()
endif ()