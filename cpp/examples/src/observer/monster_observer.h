#ifndef MONSTER_OBSERVER_H
#define MONSTER_OBSERVER_H
#include <iostream>
#include "observer.h"
#include "monster.h"
namespace observer
{
	class MonsterHpChangeObserver : public Observer<Monster, Monster::ObserverEventTag>
	{
	public:
		void OnUpdate(const Monster& monster, Monster::ObserverEventTag event) override
		{
			if (event == Monster::ObserverEventTag::HP_CHANGED)
			{
				std::cout << "monster hp updated. " << monster.GetHp() << std::endl;
			}

		}

	};
	class MonsterTargetChangeObserver : public Observer<Monster, Monster::ObserverEventTag>
	{
	public:
		void OnUpdate(const Monster& monster, Monster::ObserverEventTag event) override
		{
			if (event == Monster::ObserverEventTag::TARGET_CHANGED)
			{
				std::cout << "monster target updated. " << monster.GetTargetId() << std::endl;
			}
		}
	};
}

#endif // MONSTER_OBSERVER_H