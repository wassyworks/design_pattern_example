#include <iostream>

#include "crtp.h"
// main function
int main()
{
	// === CRTP ===
	const PlayerId player_1_id = PlayerId(1);
	const PlayerId player_2_id = PlayerId(2);

	// 計算はコンパイルエラーで未然に防止できる
	// auto invalid_addition = player_1_id + player_2_id;

	const PacketId packet_id = PacketId(100);
	std::cout << "Packet Id:" << packet_id << std::endl;

	Meter m1 = Meter(1);
	const Meter m2 = Meter(2);
	m1 += m2;
	std::cout << "Meter Added:" << m1 + m2 << std::endl;

	return 0;
}