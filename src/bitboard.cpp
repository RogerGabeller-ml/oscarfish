#include "bitboard.h"


#include <iostream>

namespace Oscarfish
{

std::string Bitboards::pretty(Bitboard b) {

    std::string s = "+---+---+---+---+---+---+---+---+\n";
    for (Rank r = RANK_8; r >= RANK_1; --r) {
        for (File f = FILE_A; f < FILES; ++f) {
            s += b & squareBoards[(r << 3) + f] ? "| X " : "|   ";
        }
        s += "| " + std::to_string(r + 1) + "\n+---+---+---+---+---+---+---+---+\n";
    }
    return s + "  a   b   c   d   e   f   g   h\n";;
}


Bitboard pseduoAttacks[PIECES][SQUARES];
Bitboard squareBoards[SQUARES];

void Bitboards::init() {

    for (Square sq = SQ_A1; sq < SQUARES; ++sq) {
        File f = in_file(sq); Rank r = in_rank(sq);
        Bitboard s = square_bb(sq);
        squareBoards[sq] = s;
        pseduoAttacks[ROOK][sq] = rank_bb(r) | file_bb(f);

        for (Square sqD = SQ_A1; sqD < SQUARES; ++sqD) {
            File fD = in_file(sqD); Rank rD = in_rank(sqD);
            if(f + r == fD + rD || r - rD == f - fD) {
                pseduoAttacks[BISHOP][sqD] |= squareBoards[sq];
            }
            pseduoAttacks[QUEEN][sqD] = pseduoAttacks[ROOK][sqD] | pseduoAttacks[BISHOP][sqD];
        }

        pseduoAttacks[KING][sq] = shift<NORTH>(s)       | shift<SOUTH>(s)       |
                                  shift<EAST>(s)        | shift<WEST>(s)        |
                                  shift<NORTH_EAST>(s)  | shift<NORTH_WEST>(s)  |
                                  shift<SOUTH_EAST>(s)  | shift<SOUTH_WEST>(s);

        
        pseduoAttacks[KNIGHT][sq] = shift<NORTH>(shift<NORTH_EAST>(s))  | shift<SOUTH>(shift<SOUTH_EAST>(s))    |
                                    shift<EAST>(shift<NORTH_EAST>(s))   | shift<WEST>(shift<NORTH_WEST>(s))     |
                                    shift<NORTH>(shift<NORTH_WEST>(s))  | shift<SOUTH>(shift<SOUTH_WEST>(s))    |
                                    shift<EAST>(shift<SOUTH_EAST>(s))   | shift<WEST>(shift<SOUTH_WEST>(s));
        
        if(r != RANK_1 && r != RANK_8) {
            pseduoAttacks[PAWN][sq] = shift<NORTH_EAST>(s) | shift<NORTH_WEST>(s);
        }
    }

    for (Square sq = SQ_A1; sq < SQUARES; ++sq) {
        std::cout << Bitboards::pretty(pseduoAttacks[PAWN][sq]) << std::endl;
    }
}


} // namespace Oscarfish
