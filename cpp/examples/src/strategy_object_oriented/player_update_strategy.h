#ifndef STRATEGY_OO_UPDATE_PLAYER_STRATEGY_H
#define STRATEGY_OO_UPDATE_PLAYER_STRATEGY_H

#include <iostream>
#include "player.h"
#include "update_strategy.h"

namespace strategy_object_oriented
{
	class PlayerUpdateStrategy : public UpdateStrategy<Player>
	{
	public:
		explicit PlayerUpdateStrategy() = default;
		void update(Player& player) const override { std::cout << "oo update player." << std::endl; }
	};
}

#endif // !STRATEGY_OO_UPDATE_PLAYER_STRATEGY_H