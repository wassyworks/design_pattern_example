#ifndef OBSERVER_MONSTER_H
#define OBSERVER_MONSTER_H
#include "observer.h"
#include <unordered_set>

namespace observer
{
	class Monster
	{
	public:
		enum class ObserverEventTag : uint8_t
		{
			HP_CHANGED,
			TARGET_CHANGED
		};
		using MonsterObserver = Observer<Monster, ObserverEventTag>;

	public:
		Monster(int32_t hp, uint64_t target_id) : hp_(hp), target_id_(target_id) {}
		void Attach(MonsterObserver* observer) { observers_.insert(observer); }
		void Detach(MonsterObserver* observer) { observers_.erase(observer); }
		void Notify(ObserverEventTag event_tag) {
			for (auto it = observers_.begin(); it != observers_.end();)
			{
				if (auto observer = *it++)
				{
					observer->OnUpdate(*this, event_tag);
				}
			}
		};
		void SetHp(int hp) { hp_ = hp; Notify(ObserverEventTag::HP_CHANGED); }
		int GetHp() const { return hp_; }
		int GetTargetId() const { return target_id_; }
		void SetTargetId(int id) { target_id_ = id; Notify(ObserverEventTag::TARGET_CHANGED); }

	private:
		std::unordered_set<MonsterObserver*> observers_;

		int32_t hp_ = 0;
		uint64_t target_id_ = 0;
	};

}

#endif //OBSERVER_MONSTER_H
