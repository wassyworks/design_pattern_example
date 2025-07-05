#ifndef STRATEGY_PLAYER_H
#define STRATEGY_PLAYER_H

#include <functional>

#include "entity.h"

// std::functionを使ってStrategyパターンを実装する
class Player : public Entity {
public:
	using UpdateStrategy = std::function<void(Player&)>;

	explicit Player(UpdateStrategy updater) : updater_(updater){

	}

	void update() override {
		updater_(*this);
	}

private:
	UpdateStrategy updater_;
};

#endif //STRATEGY_PLAYER_H
