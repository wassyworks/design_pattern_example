#pragma once
#include <cstdint>

// 実装パターンとしての CRTP (Curiously Recurring Template Pattern) (x デザインパターンとしてのCRTP)

// StrongType単体だと機能を持たないけど、可変長引数テンプレートを使って、mixinクラスを加えることで機能を追加できるようにする
template <typename T, typename Tag, template<typename> class... Mixins>
struct StrongType : private Mixins<StrongType<T, Tag, Mixins...>>... {
public:
	explicit StrongType(const T& value) : value_(value) {}
	T& value() { return value_; }
	const T& value() const { return value_; }


private:
	T value_;
};

template <typename Derived>
struct Printable {
	friend std::ostream& operator<<(std::ostream& os, const Derived& derived) {
		os << derived.value();
		return os;
	}
};

template <typename Derived>
struct Addable {
	friend Derived operator+(const Derived& lhs, const Derived& rhs) {
		return Derived(lhs.value() + rhs.value());
	}
	friend Derived& operator+=(Derived& lhs, const Derived& rhs) {
		 lhs.value() += rhs.value();
		 return lhs;
	}
};

// 強固な型付けクラス
using PlayerId = StrongType<uint64_t, struct PlayerIdTag>;


// ストリーム出力可能になった
using PacketId = StrongType<uint16_t, struct PacketIdTag, Printable>;

using Meter = StrongType<uint32_t, struct MeterTag, Addable, Printable>;
