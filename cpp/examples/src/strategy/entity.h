#ifndef STRATEGY_ENTITY_H
#define STRATEGY_ENTITY_H

class Entity {
public:
	virtual ~Entity() = default;
	virtual void update() = 0;
};

#endif // STRATEGY_ENTITY_H