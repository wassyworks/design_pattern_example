#ifndef BRIGDE_ENTITY_H_
#define BRIGDE_ENTITY_H_
#include <memory>
#include "equip.h"

namespace bridge {
	class Entity {
	public:
		virtual ~Entity() = default;
	protected:
		explicit Entity(std::unique_ptr<Equip> hand, std::unique_ptr<Equip> body)
			: hand_equip_(std::move(hand)), body_equip_(std::move(body))
		{

		}

		Equip* GetHandEquip() {
			return hand_equip_.get();
		}
		const Equip* GetHandEquip() const {
			return hand_equip_.get();
		}

		Equip* GetBodyEquip() {
			return body_equip_.get();
		}
		const Equip* GetBodyEquip() const {
			return body_equip_.get();
		}

	private:
		// Pimpl
		std::unique_ptr<Equip> hand_equip_;
		std::unique_ptr<Equip> body_equip_;

	};
}

#endif // BRIGDE_ENTITY_H_
