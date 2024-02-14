#ifndef STRATEGY_ENEMY_UPDATE_STRATEGY_H
#define STRATEGY_ENEMY_UPDATE_STRATEGY_H


#include <iostream>
#include "enemy.h"

class EnemyUpdateStrategy
{
public:
	explicit EnemyUpdateStrategy() = default;
	void operator()(Enemy& enemy) const { std::cout << "update enemy." << std::endl; }
};

#endif // !STRATEGY_ENEMY_UPDATE_STRATEGY_H