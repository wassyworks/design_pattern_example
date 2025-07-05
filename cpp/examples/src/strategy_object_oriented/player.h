#ifndef STRATEGY_OO_PLAYER_H
#define STRATEGY_OO_PLAYER_H

#include <memory>
#include "entity.h"
#include "update_strategy.h"

namespace strategy_object_oriented
{
	class Player : public Entity {
	public:
		explicit Player(std::unique_ptr<UpdateStrategy<Player>> updater) : updater_(std::move(updater)) {

		}

		void update() override {
			updater_->update(*this);
		}

	private:
		std::unique_ptr<UpdateStrategy<Player>> updater_;
	};
}
#endif //STRATEGY_OO_PLAYER_H
