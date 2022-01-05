#if !defined(BITBOARD_H_)
#define BITBOARD_H_

#include <string>


#include "types.h"

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
constexpr Bitboard FILE_HBB = FILE_ABB << 7;
constexpr Bitboard RANK_1BB = 0xFFULL;
constexpr Bitboard RANK_8BB = RANK_1BB << (8 * 7);

template<Direction D>
constexpr Bitboard shift(Bitboard b) {
  return  D == NORTH      ?  b              << 8 : D == SOUTH      ?  b              >> 8
        : D == NORTH+NORTH?  b              <<16 : D == SOUTH+SOUTH?  b              >>16
        : D == EAST       ? (b & ~FILE_HBB) << 1 : D == WEST       ? (b & ~FILE_ABB) >> 1
        : D == NORTH_EAST ? (b & ~FILE_HBB) << 9 : D == NORTH_WEST ? (b & ~FILE_ABB) << 7
        : D == SOUTH_EAST ? (b & ~FILE_HBB) >> 7 : D == SOUTH_WEST ? (b & ~FILE_ABB) >> 9
        : 0;
}

inline Bitboard square_bb(Square sq) { return 1ULL << sq; }

inline Bitboard rank_bb(Rank r) { return RANK_1BB << (8 * r); }

inline Bitboard file_bb(File f) { return FILE_ABB << f; }

} // namespace Oscarfish


#endif // BITBOARD_H_
