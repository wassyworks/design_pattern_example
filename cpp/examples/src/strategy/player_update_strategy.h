#ifndef STRATEGY_PLAYER_UPDATE_STRATEGY_H
#define STRATEGY_PLAYER_UPDATE_STRATEGY_H

#include <iostream>

#include "player.h"
class PlayerUpdateStrategy
{
public:
	explicit PlayerUpdateStrategy() = default;
	void operator()(Player& player) const { std::cout << "update player." << std::endl; }
};
#endif //STRATEGY_PLAYER_UPDATE_STRATEGY_H
