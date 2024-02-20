#ifndef OBSERVER_H
#define OBSERVER_H

namespace observer
{
	template<typename Subject, typename Tag>
	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void OnUpdate(const Subject& sublect, Tag tag) = 0;

	};


}
#endif // OBSERVER_H