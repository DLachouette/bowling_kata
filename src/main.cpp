#include "bowling.h"

int main(int argc, char ** argv)
{
	bowling::Bowling game(argc, argv);
	game.run();
    return 0;
}
