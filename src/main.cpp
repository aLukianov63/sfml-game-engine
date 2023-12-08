
#include "Game.h"
#include "engine/Configuration.h"

#include <optional>

auto main(int argc, char** argv) -> int
{
	Configuration::init();
	Game game;
	game.run(144);
    return 0;
}

