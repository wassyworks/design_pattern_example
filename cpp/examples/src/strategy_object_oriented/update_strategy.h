#ifndef STRATEGY_OO_UPDATE_STRATEGY_H
#define STRATEGY_OO_UPDATE_STRATEGY_H
namespace strategy_object_oriented
{
    template<typename T>
	class UpdateStrategy
	{
	public:
        virtual ~UpdateStrategy() = default;
		virtual void update(T& entity) const = 0;
	};
}

#endif //  STRATEGY_OO_UPDATE_STRATEGY_H