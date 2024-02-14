#ifndef STRATEGY_OO_ENEMY_H
#define STRATEGY_OO_ENEMY_H
#include <memory>
#include "entity.h"
#include "update_strategy.h"

namespace strategy_object_oriented
{
	class Enemy : public Entity {
	public:
		explicit Enemy(std::unique_ptr<UpdateStrategy<Enemy>> updater)
			:updater_(std::move(updater))
		{
		}
		void update() override {
			updater_->update(*this);
		}
	private:
		std::unique_ptr<UpdateStrategy<Enemy>> updater_;
	};
}
#endif //STRATEGY_OO_ENEMY_H
