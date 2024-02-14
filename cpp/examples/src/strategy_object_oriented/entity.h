#ifndef STRATEGY_OO_ENTITY_H
#define STRATEGY_OO_ENTITY_H
namespace strategy_object_oriented {
	class Entity {
	public:
		virtual ~Entity() = default;
		virtual void update() = 0;
	};
}

#endif // STRATEGY_OO_ENTITY_H
