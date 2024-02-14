#ifndef STRATEGY_ENEMY_H
#define STRATEGY_ENEMY_H

#include <functional>

#include "entity.h"

class Enemy : public Entity {
public:
	using UpdateStrategy = std::function<void(Enemy&)>;

	explicit Enemy(UpdateStrategy updater) : updater_(updater){

	}

	void update() override {
		updater_(*this);
	}

private:
	UpdateStrategy updater_;
};

#endif //STRATEGY_ENEMY_H
