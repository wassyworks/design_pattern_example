#include "player.h"
#include "weapon.h"
#include "armor.h"

namespace bridge
{
	Player::Player()
		: Entity(std::make_unique<Weapon>(), std::make_unique<Armor>())
	{

	}

}
