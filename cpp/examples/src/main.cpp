#include <iostream>

#include "crtp.h"

#include "strategy/player_update_strategy.h"
#include "strategy/enemy_update_strategy.h"
#include "strategy_object_oriented/player_update_strategy.h"
#include "strategy_object_oriented/enemy_update_strategy.h"
#include "adapter/xml_to_json_logger_adapter.h"
#include "observer/monster_observer.h"
#include "bridge/player.h"

int main()
{
	// === CRTP ===
	{
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

	}

	// === Strategy ===
	{
		std::vector<std::unique_ptr<Entity>> entities;

		entities.emplace_back(std::make_unique<Player>(PlayerUpdateStrategy()));
		entities.emplace_back(std::make_unique<Enemy>(EnemyUpdateStrategy()));
		entities.emplace_back(std::make_unique<Enemy>(EnemyUpdateStrategy()));
		for (auto&& entity : entities)
		{
			entity->update();
		}

		std::vector<std::unique_ptr<strategy_object_oriented::Entity>> soo_entities;
		soo_entities.emplace_back(std::make_unique<strategy_object_oriented::Player>(std::make_unique<strategy_object_oriented::PlayerUpdateStrategy>()));
		soo_entities.emplace_back(std::make_unique<strategy_object_oriented::Enemy>(std::make_unique<strategy_object_oriented::EnemyUpdateStrategy>()));
		soo_entities.emplace_back(std::make_unique<strategy_object_oriented::Enemy>(std::make_unique<strategy_object_oriented::EnemyUpdateStrategy>()));

		for (auto&& entity : soo_entities)
		{
			entity->update();
		}

	}

	// === Adapter ===
	{
		adapter::Logger logger;
		logger.Logging("foo");

		adapter::XmlToJsonLoggerAdapter adapter;
		adapter.Logging("foo");

	}

	// === Observer ===
	{
		observer::Monster monster(100, 0);
		observer::MonsterHpChangeObserver hp_change_observer;
		observer::MonsterTargetChangeObserver target_change_observer;
		monster.Attach(&hp_change_observer);
		monster.Attach(&target_change_observer);
		monster.SetHp(200);
		monster.SetTargetId(1);
		monster.Detach(&hp_change_observer);
		monster.Detach(&target_change_observer);
		monster.SetHp(300);
		monster.SetTargetId(2);

	}

	// === Bridge ===
	{
		bridge::Player player;

	}
	return 0;
}