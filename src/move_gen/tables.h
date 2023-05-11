#pragma once
#pragma once

#include "types/types.h"
#include "../board/types/bitboard.h"
#include "../board/types/piece.h"
#include "../../tests/lib/doctests.h"

namespace tables {
	namespace {
		struct SquareData {
			Bitboard attack_mask{};
			u32 offset{};
		};

		struct AttackData {
			array<SquareData, NSQUARES> data{};
			u32 table_size{};
		};

		constexpr Bitboard FILLED_BOARD = 0XFFFFFFFFFFFFFFFF;

		constexpr array<i32, NSQUARES> ROOK_SHIFTS = {
				52, 53, 53, 53, 53, 53, 53, 52,
				53, 54, 54, 54, 54, 54, 54, 53,
				53, 54, 54, 54, 54, 54, 54, 53,
				53, 54, 54, 54, 54, 54, 54, 53,
				53, 54, 54, 54, 54, 54, 54, 53,
				53, 54, 54, 54, 54, 54, 54, 53,
				53, 54, 54, 54, 54, 54, 54, 53,
				52, 53, 53, 53, 53, 53, 53, 52
		};

		constexpr array<i32, NSQUARES> BISHOP_SHIFTS = {
				59, 60, 59, 59, 59, 59, 60, 58,
				60, 60, 59, 59, 59, 59, 60, 60,
				59, 59, 57, 57, 57, 57, 59, 59,
				59, 59, 57, 55, 55, 57, 59, 59,
				59, 59, 57, 55, 55, 57, 59, 59,
				59, 59, 57, 57, 57, 57, 59, 60,
				60, 60, 59, 59, 59, 59, 60, 60,
				59, 60, 59, 59, 59, 59, 60, 58
		};

		constexpr array<Bitboard, NSQUARES> KING_ATTACKS = {
				0x302, 0x705, 0xe0a, 0x1c14,
				0x3828, 0x7050, 0xe0a0, 0xc040,
				0x30203, 0x70507, 0xe0a0e, 0x1c141c,
				0x382838, 0x705070, 0xe0a0e0, 0xc040c0,
				0x3020300, 0x7050700, 0xe0a0e00, 0x1c141c00,
				0x38283800, 0x70507000, 0xe0a0e000, 0xc040c000,
				0x302030000, 0x705070000, 0xe0a0e0000, 0x1c141c0000,
				0x3828380000, 0x7050700000, 0xe0a0e00000, 0xc040c00000,
				0x30203000000, 0x70507000000, 0xe0a0e000000, 0x1c141c000000,
				0x382838000000, 0x705070000000, 0xe0a0e0000000, 0xc040c0000000,
				0x3020300000000, 0x7050700000000, 0xe0a0e00000000, 0x1c141c00000000,
				0x38283800000000, 0x70507000000000, 0xe0a0e000000000, 0xc040c000000000,
				0x302030000000000, 0x705070000000000, 0xe0a0e0000000000, 0x1c141c0000000000,
				0x3828380000000000, 0x7050700000000000, 0xe0a0e00000000000, 0xc040c00000000000,
				0x203000000000000, 0x507000000000000, 0xa0e000000000000, 0x141c000000000000,
				0x2838000000000000, 0x5070000000000000, 0xa0e0000000000000, 0x40c0000000000000,
		};

		constexpr array<Bitboard, NSQUARES> KNIGHT_ATTACKS = {
				0x20400, 0x50800, 0xa1100, 0x142200,
				0x284400, 0x508800, 0xa01000, 0x402000,
				0x2040004, 0x5080008, 0xa110011, 0x14220022,
				0x28440044, 0x50880088, 0xa0100010, 0x40200020,
				0x204000402, 0x508000805, 0xa1100110a, 0x1422002214,
				0x2844004428, 0x5088008850, 0xa0100010a0, 0x4020002040,
				0x20400040200, 0x50800080500, 0xa1100110a00, 0x142200221400,
				0x284400442800, 0x508800885000, 0xa0100010a000, 0x402000204000,
				0x2040004020000, 0x5080008050000, 0xa1100110a0000, 0x14220022140000,
				0x28440044280000, 0x50880088500000, 0xa0100010a00000, 0x40200020400000,
				0x204000402000000, 0x508000805000000, 0xa1100110a000000, 0x1422002214000000,
				0x2844004428000000, 0x5088008850000000, 0xa0100010a0000000, 0x4020002040000000,
				0x400040200000000, 0x800080500000000, 0x1100110a00000000, 0x2200221400000000,
				0x4400442800000000, 0x8800885000000000, 0x100010a000000000, 0x2000204000000000,
				0x4020000000000, 0x8050000000000, 0x110a0000000000, 0x22140000000000,
				0x44280000000000, 0x0088500000000000, 0x0010a00000000000, 0x20400000000000
		};

		constexpr array<Bitboard, NSQUARES> WHITE_PAWN_ATTACKS = {
				0x200, 0x500, 0xa00, 0x1400,
				0x2800, 0x5000, 0xa000, 0x4000,
				0x20000, 0x50000, 0xa0000, 0x140000,
				0x280000, 0x500000, 0xa00000, 0x400000,
				0x2000000, 0x5000000, 0xa000000, 0x14000000,
				0x28000000, 0x50000000, 0xa0000000, 0x40000000,
				0x200000000, 0x500000000, 0xa00000000, 0x1400000000,
				0x2800000000, 0x5000000000, 0xa000000000, 0x4000000000,
				0x20000000000, 0x50000000000, 0xa0000000000, 0x140000000000,
				0x280000000000, 0x500000000000, 0xa00000000000, 0x400000000000,
				0x2000000000000, 0x5000000000000, 0xa000000000000, 0x14000000000000,
				0x28000000000000, 0x50000000000000, 0xa0000000000000, 0x40000000000000,
				0x200000000000000, 0x500000000000000, 0xa00000000000000, 0x1400000000000000,
				0x2800000000000000, 0x5000000000000000, 0xa000000000000000, 0x4000000000000000,
				0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};

		constexpr array<Bitboard, NSQUARES> BLACK_PAWN_ATTACKS = {
				0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
				0x2, 0x5, 0xa, 0x14, 0x28, 0x50, 0xa0, 0x40,
				0x200, 0x500, 0xa00, 0x1400,
				0x2800, 0x5000, 0xa000, 0x4000,
				0x20000, 0x50000, 0xa0000, 0x140000,
				0x280000, 0x500000, 0xa00000, 0x400000,
				0x2000000, 0x5000000, 0xa000000, 0x14000000,
				0x28000000, 0x50000000, 0xa0000000, 0x40000000,
				0x200000000, 0x500000000, 0xa00000000, 0x1400000000,
				0x2800000000, 0x5000000000, 0xa000000000, 0x4000000000,
				0x20000000000, 0x50000000000, 0xa0000000000, 0x140000000000,
				0x280000000000, 0x500000000000, 0xa00000000000, 0x400000000000,
				0x2000000000000, 0x5000000000000, 0xa000000000000, 0x14000000000000,
				0x28000000000000, 0x50000000000000, 0xa0000000000000, 0x40000000000000,
		};

		constexpr array<Bitboard, NSQUARES> BISHOP_MAGICS = {
				0x69906270549A3405, 0xE846197A0E88067F, 0x54D7C7FB06DE5827, 0xF4380209C8E966FE,
				0xDF33F39ECD91FCF6, 0xC580F3DFFCC85DB4, 0xC6A89809B600286C, 0xC1DE00D4289BFFC0,
				0x7BDA249AC632C811, 0x83534631B40CA406, 0x6EA35817F035775C, 0x6DB23BEF4DF5645E,
				0x5555D3FB9F934CD3, 0xE6766DFD0FC609F8, 0xFC2EB0C6C58C8021, 0x6786D25EACCFDF72,
				0x86E8324A02CA8AEF, 0xF91A13391D2D97F1, 0x131810CFFD99BE90, 0x8537F35C05EFA08B,
				0x5D598243FF5FD71A, 0x1D09FFBF00FAD72B, 0xD16A319977FC05FD, 0x8D6601E599347F90,
				0x4404409F5EC1F3DB, 0x25A7EC287E0BB817, 0x22F9F7FF5AF54401, 0x00200302080070E0,
				0x3D1900D006FFC014, 0x3958E700A5FEBEFB, 0xD48AA0E6BBFC0214, 0x56BBF68FC6CD5C13,
				0xD4CFE69F216FF3C9, 0xE46CEF960C704413, 0x7985CEB00428057B, 0x4900220082080080,
				0x028422C010040100, 0x119377F9FFF6BEEB, 0x2787B8DA98AC0221, 0xCF340AB7795DFC80,
				0x5F4D27A008D84FE9, 0x4339FF0FE25ED893, 0x88F477A178045010, 0x7B293EDFD1015806,
				0x1F61DFF2047F5BFF, 0xE2E1B97D1A009100, 0x9C9F7BCC878F1A08, 0xABFFCA859DA3CDFE,
				0x1CD806CBB423E49B, 0x5EE7FB86BD527D9B, 0xBB0A8BC1EAB02192, 0xB75E295A3FCE452C,
				0x911D2E51E6060430, 0x133E017175D1FB87, 0xD7C00065234350D1, 0x220029F586970AD8,
				0xA6F001938E193FDB, 0xDF725BF4FA4505B6, 0xE5DE50FA3FDC8C72, 0x3CE77ED6760FC3D0,
				0x4CAD71659E41C408, 0xE6766DFD0FC609F8, 0x45D7FEA873649EA8, 0xA8806CA2E576C9E4
		};

		constexpr array<Bitboard, NSQUARES> ROOK_MAGICS = {
				0x2080002040068490, 0x06C0021001200C40, 0x288009300280A000, 0x0100089521003000,
				0x6100040801003082, 0x65FFEBC5FFEEE7F0, 0x0400080C10219112, 0x0200014434060003,
				0x96CD8008C00379D9, 0x2A06002101FF81CF, 0x7BCA0020802E0641, 0xDAE2FFEFFD0020BA,
				0x62E20005E0D200AA, 0x2302000830DA0044, 0xE81C002CE40A3028, 0xC829FFFAFD8BBC06,
				0x12C57E800740089D, 0xA574FDFFE13A81FD, 0xF331B1FFE0BF79FE, 0x0000A1003001010A,
				0x7CD4E2000600264F, 0x0299010004000228, 0xA36CEBFFAE0FA825, 0x9A87E9FFF4408405,
				0x0BAEC0007FF8EB82, 0xF81909BDFFE18205, 0x0391AF45001FFF01, 0xD000900100290021,
				0x2058480080040080, 0x6DCDFFA2002C38D0, 0xC709C80C00951002, 0xB70EE5420008FF84,
				0x6E254003897FFCE6, 0xD91D21FE7E003901, 0xA0D1EFFF857FE001, 0x7C45FFC022001893,
				0x8180818800800400, 0x2146001CB20018B0, 0x843C20E7DBFF8FEE, 0x09283C127A00083F,
				0x01465F8CC0078000, 0xA30A50075FFD3FFF, 0x39593D8231FE0020, 0x8129FE58405E000F,
				0x1140850008010011, 0x2302000830DA0044, 0xD706971819F400B0, 0xA0B2A3BC86E20004,
				0x10FFF67AD3B88200, 0x10FFF67AD3B88200, 0x5076D15DBDF97E00, 0xD861C0D1FFC8DE00,
				0x5CA002003B305E00, 0x84FFFFCF19605740, 0xD26F0FA80A28AC00, 0x342F7E87013BFA00,
				0x63BB9E8FBF01FE7A, 0x260ADF40007B9101, 0x2013CEFF6000BEF7, 0x13AD6200060EBFE6,
				0x2D4DFFFF28F4D9FA, 0x766200004B3A92F6, 0xB6AE6FF7FE8A070C, 0xD065F4839BFC4B02
		};

		[[nodiscard]] constexpr Bitboard board_edge(Direction D) {
			if (D == NORTH) return MASK_RANK[RANK8];
			else if (D == SOUTH) return MASK_RANK[RANK1];
			else if (D == EAST) return MASK_FILE[HFILE];
			else if (D == WEST) return MASK_FILE[AFILE];

			else if (D == NORTH_EAST) return board_edge(NORTH) | board_edge(EAST);
			else if (D == NORTH_WEST) return board_edge(NORTH) | board_edge(WEST);
			else if (D == SOUTH_EAST) return board_edge(SOUTH) | board_edge(EAST);
			else if (D == SOUTH_WEST) return board_edge(SOUTH) | board_edge(WEST);

			return 0;
		}

		[[nodiscard]] constexpr Bitboard generate_sliding_attacks(Square sq, Direction direction, Bitboard occupancy) {
			Bitboard attacks{};

			Bitboard blockers = board_edge(direction);
			Bitboard square_bb = square_to_bitboard(sq);

			if ((blockers & square_bb) != 0) {
				return attacks;
			}

			blockers |= occupancy;

			do {
				square_bb = shift(direction, square_bb);
				attacks |= square_bb;
			} while ((blockers & square_bb) == 0);

			return attacks;
		}

		[[nodiscard]] consteval AttackData generate_orthogonal_slider_data() {
			AttackData dst{};

			for (Square sq = a1; sq < NSQUARES; sq++) {
				dst.data[sq].attack_mask = FILLED_BOARD;

				for (const Direction dir: {NORTH, SOUTH, EAST, WEST}) {
					const Bitboard attacks = generate_sliding_attacks(sq, dir, 0);
					dst.data[sq].attack_mask &= ~(attacks & ~board_edge(dir));
				}

				dst.data[sq].offset = dst.table_size;
				dst.table_size += 1 << (NSQUARES - ROOK_SHIFTS[sq]);
			}

			return dst;
		}

		[[nodiscard]] consteval AttackData generate_diagonal_slider_data() {
			AttackData dst{};

			for (Square sq = a1; sq < NSQUARES; sq++) {
				dst.data[sq].attack_mask = FILLED_BOARD;

				for (const Direction dir: {NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST}) {
					const Bitboard attacks = generate_sliding_attacks(sq, dir, 0);
					dst.data[sq].attack_mask &= ~(attacks & ~board_edge(dir));
				}

				dst.data[sq].offset = dst.table_size;
				dst.table_size += 1 << (NSQUARES - BISHOP_SHIFTS[sq]);
			}

			return dst;
		}

		constexpr AttackData rook_data = generate_orthogonal_slider_data();
		constexpr AttackData bishop_data = generate_diagonal_slider_data();


		[[nodiscard]] inline u64 rook_idx(Bitboard occupancy, Square src) {
			const auto s = static_cast<i32>(src);

			const auto &data = rook_data.data[s];

			const auto magic = ROOK_MAGICS[s];
			const auto shift = ROOK_SHIFTS[s];

			return ((occupancy | data.attack_mask) * magic) >> shift;
		}

		[[nodiscard]] inline u64 bishop_idx(Bitboard occupancy, Square src) {
			const auto s = static_cast<i32>(src);

			const auto &data = bishop_data.data[s];

			const auto magic = BISHOP_MAGICS[s];
			const auto shift = BISHOP_SHIFTS[s];

			return ((occupancy | data.attack_mask) * magic) >> shift;
		}

		/*
		[[nodiscard]] inline Bitboard getRookAttacks(Square src, Bitboard occupancy) {
			const auto s = static_cast<i32>(src);

			const auto &data = black_magic::RookData.data[s];
			const auto idx = rook_idx(occupancy, src);

			return RookAttacks[data.offset + idx];
		}

		[[nodiscard]] inline Bitboard getBishopAttacks(Square src, Bitboard occupancy) {
			const auto s = static_cast<i32>(src);

			const auto &data = black_magic::BishopData.data[s];
			const auto idx = bishop_idx(occupancy, src);

			return BishopAttacks[data.offset + idx];
		}
		 */

	} // anon namespace
	TEST_SUITE_BEGIN("tables");

	TEST_CASE("generate-sliding-attacks") {
		CHECK_EQ(generate_sliding_attacks(a5, NORTH, 0), 0x101010000000000);
		CHECK_EQ(generate_sliding_attacks(a5, SOUTH, 0), 0x1010101);
		CHECK_EQ(generate_sliding_attacks(e4, NORTH, 0), 0x1010101000000000);
		CHECK_EQ(generate_sliding_attacks(e4, SOUTH, 0), 0x101010);
		CHECK_EQ(generate_sliding_attacks(e4, EAST, 0), 0xe0000000);
		CHECK_EQ(generate_sliding_attacks(e4, WEST, 0), 0xf000000);
		CHECK_EQ(generate_sliding_attacks(e4, NORTH_EAST, 0), 0x80402000000000);
		CHECK_EQ(generate_sliding_attacks(e4, NORTH_WEST, 0), 0x102040800000000);
		CHECK_EQ(generate_sliding_attacks(e4, SOUTH_EAST, 0), 0x204080);
		CHECK_EQ(generate_sliding_attacks(e4, SOUTH_WEST, 0), 0x80402);
	}

	TEST_SUITE_END();
} // table namespace