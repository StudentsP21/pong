#include "game_loop.h"


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	std::ios_base::sync_with_stdio(false);

	game_loop();

	return 0;
}
