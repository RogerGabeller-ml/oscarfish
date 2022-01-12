#if !defined(POSITION_H_)
#define POSITION_H_

#include "types.h"

namespace Oscarfish
{
    
class Position {

    Bitboard board[COLOURS][PIECES];

    MoveHistory moveHist;
    MoveList moveList;

    Piece pieceLookup[SQUARES];
    Bitboard colours[COLOURS];

    public:
    
    template<Colour c, Piece p>
    Bitboard getPieceBB();

    template<Colour c, Piece p>
    void setPieceBB(Bitboard b);

    template<Colour c>
    Bitboard getColourBB();

    bool makeMove(Move m);
    bool undoMove(Move m);
};

template<Colour c, Piece p>
inline Bitboard Position::getPieceBB() {
    return board[c][p];
}

template<Colour c, Piece p>
inline void Position::setPieceBB(Bitboard b) {
    colours[c] ^= b;
    board[c][p] = b;
}


template<Colour c>
inline Bitboard Position::getColourBB() {
    return colours[c];
}

} // namespace Oscarfish


#endif // POSITION_H_
