#pragma once
#include "types.h"

// Source: Stockfish
class PRNG {
	u64 s;
	u64 rand64() {
		s ^= s >> 12, s ^= s << 25, s ^= s >> 27;
		return s * 2685821657736338717LL;
	}

public:
	explicit PRNG(u64 seed) : s(seed) {}
	template<typename T> T rand() { return T(rand64()); }
	template<typename T>
	T sparse_rand() { return T(rand64() & rand64() & rand64()); }
};
