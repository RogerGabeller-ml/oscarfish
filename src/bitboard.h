#if !defined(BITBOARD_H_)
#define BITBOARD_H_

#include "types.h"
#include <iostream>

namespace Oscarfish
{

extern Bitboard pseduoAttacks[PIECES][SQUARES];
extern Bitboard squareBoards[SQUARES];

namespace Bitboards
{

void init();
std::string pretty(Bitboard b);

} // namespace Bitboards

constexpr Bitboard FILE_ABB = 0x0101010101010101ULL;
constexpr Bitboard FILE_BBB = FILE_ABB << 1;
constexpr Bitboard FILE_CBB = FILE_ABB << 2;
constexpr Bitboard FILE_DBB = FILE_ABB << 3;
constexpr Bitboard FILE_EBB = FILE_ABB << 4;
constexpr Bitboard FILE_FBB = FILE_ABB << 5;
constexpr Bitboard FILE_GBB = FILE_ABB << 6;
constexpr Bitboard FILE_HBB = FILE_ABB << 7;

constexpr Bitboard RANK_1BB = 0xFF;
constexpr Bitboard RANK_2BB = RANK_1BB << (8 * 1);
constexpr Bitboard RANK_3BB = RANK_1BB << (8 * 2);
constexpr Bitboard RANK_4BB = RANK_1BB << (8 * 3);
constexpr Bitboard RANK_5BB = RANK_1BB << (8 * 4);
constexpr Bitboard RANK_6BB = RANK_1BB << (8 * 5);
constexpr Bitboard RANK_7BB = RANK_1BB << (8 * 6);
constexpr Bitboard RANK_8BB = RANK_1BB << (8 * 7);


template<typename D>
constexpr Bitboard shift(D s, Bitboard b) {
  return  s == NORTH      ?  b              << 8 : s == SOUTH      ?  b              >> 8
        : s == NORTH+NORTH?  b              <<16 : s == SOUTH+SOUTH?  b              >>16
        : s == EAST       ? (b & ~FILE_HBB) << 1 : s == WEST       ? (b & ~FILE_ABB) >> 1
        : s == NORTH_EAST ? (b & ~FILE_HBB) << 9 : s == NORTH_WEST ? (b & ~FILE_ABB) << 7
        : s == SOUTH_EAST ? (b & ~FILE_HBB) >> 7 : s == SOUTH_WEST ? (b & ~FILE_ABB) >> 9
        : 0;
}


inline Bitboard square_bb(int sq) {
  if (sq > SQ_H8 || sq < SQ_A1) { return 0; }
  assert(squareBoards[sq]);
  return squareBoards[sq]; 
}


inline Bitboard square_bb(Square sq) { 
  return square_bb((int)sq); 
}


inline Bitboard make_square(Rank r, File f) { 
  return square_bb((r << 3) + f); 
}


inline Bitboard rank_bb(Rank r) { 
  return RANK_1BB << (8 * r); 
}


inline Bitboard file_bb(File f) { 
  return FILE_ABB << f;
}

} // namespace Oscarfish


#endif // BITBOARD_H_
