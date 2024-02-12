#include <iostream>

#include "crtp.h"

#include "strategy/player_update_strategy.h"
#include "strategy/enemy_update_strategy.h"

int main()
{
	// === CRTP ===
	const PlayerId player_1_id = PlayerId(1);
	const PlayerId player_2_id = PlayerId(2);

	// 計算機能を付加していないのならコンパイルエラーで未然に防止できる
	// auto invalid_addition = player_1_id + player_2_id;

	const PacketId packet_id = PacketId(100);
	std::cout << "Packet Id:" << packet_id << std::endl;

	Meter m1 = Meter(1);
	const Meter m2 = Meter(2);
	m1 += m2;
	std::cout << "Meter Added:" << m1 + m2 << std::endl;

	// === Strategy ===
	std::vector<std::unique_ptr<Entity>> entities;

	entities.emplace_back(std::make_unique<Player>(PlayerUpdateStrategy()));
	entities.emplace_back(std::make_unique<Enemy>(EnemyUpdateStrategy()));
	entities.emplace_back(std::make_unique<Enemy>(EnemyUpdateStrategy()));
	for (auto&& entity : entities)
	{
		entity->update();
	}

	return 0;
}