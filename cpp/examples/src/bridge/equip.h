#ifndef BRIGDE_EQUIP_H_
#define BRIGDE_EQUIP_H_

namespace bridge {
	class EquipStatus {
	public:
		explicit EquipStatus(uint64_t attack, uint64_t defense) : attack_(attack), defense_(defense) {}
	private:
		uint64_t attack_ = 0;
		uint64_t defense_ = 0;
	};
	class Equip {
	public:
		virtual ~Equip() = default;
		const EquipStatus& GetEquipStatus() const { return equip_status_; }
	private:
		EquipStatus equip_status_;

	};
}

#endif // BRIGDE_EQUIP_H_
