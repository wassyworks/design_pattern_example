#ifndef STRATEGY_OO_UPDATE_ENEMY_STRATEGY_H
#define STRATEGY_OO_UPDATE_ENEMY_STRATEGY_H
#include <iostream>
#include "enemy.h"
#include "update_strategy.h"

namespace strategy_object_oriented
{
	class EnemyUpdateStrategy : public UpdateStrategy<Enemy>
	{
	public:
		explicit EnemyUpdateStrategy() = default;
		void update(Enemy& enemy) const override { std::cout << "oo update enemy." << std::endl; }
	};
}

#endif //STRATEGY_OO_UPDATE_ENEMY_STRATEGY_H