#if !defined(TYPES_H_)
#define TYPES_H_

namespace Oscarfish
{

typedef uint64_t Bitboard;

enum Piece {
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,

    PIECES
};

enum Square {
    SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1, 
    SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2, 
    SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3, 
    SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4, 
    SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5, 
    SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6, 
    SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7, 
    SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8,

    SQUARES
};

enum Rank {
    RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8,

    RANKS
};

enum File {
    FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H,

    FILES
};

enum Direction {
    EAST = 1,
    WEST = -EAST,
    NORTH = EAST << 3,
    SOUTH = -NORTH,
    
    NORTH_WEST = NORTH + WEST,
    NORTH_EAST = NORTH + EAST,
    SOUTH_WEST = SOUTH + WEST,
    SOUTH_EAST = SOUTH + EAST
};

typedef int move;


#define ENABLE_INCR_OPERATORS(T)                            \
inline T& operator++(T& a) { return a = T(int(a) + 1); }    \
inline T& operator--(T& a) { return a = T(int(a) - 1); }    

ENABLE_INCR_OPERATORS(File)
ENABLE_INCR_OPERATORS(Rank)
ENABLE_INCR_OPERATORS(Square)

#undef ENABLE_INCR_OPERATORS

inline Rank in_rank(Square sq) {
    return Rank((int)sq / 8);
}

inline File in_file(Square sq) {
    return File((int)sq % 8);
}

} // namespace Oscarfish


#endif // TYPES_H_