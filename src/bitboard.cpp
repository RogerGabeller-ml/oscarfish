#include "bitboard.h"
#include <iostream>

namespace Oscarfish
{

// Bitboards::pretty() creates a human readable ASCII represenation of a given bitboard

std::string Bitboards::pretty(Bitboard b) {

    std::string s = "+---+---+---+---+---+---+---+---+\n";
    for (Rank r = RANK_8; r >= RANK_1; --r) {
        for (File f = FILE_A; f < FILES; ++f) {
            s += b & make_square(r, f) ? "| X " : "|   ";
        }
        s += "| " + std::to_string(r + 1) + "\n+---+---+---+---+---+---+---+---+\n";
    }
    return s + "  a   b   c   d   e   f   g   h\n";;
}

Bitboard pseduoAttacks[PIECES][SQUARES];
Bitboard squareBoards[SQUARES];


// Initialises pseduoAttacks' bitboards for easy lookup when masking

void Bitboards::init() {

    // Bitboards for isolated squares
    for (Square sq = SQ_A1; sq < SQUARES; ++sq) {

        squareBoards[sq] = 1ULL << sq;
    }
    
    for (Square sq = SQ_A1; sq < SQUARES; ++sq) {

        // ROOK Attacks
        for (Direction d : {NORTH, SOUTH, EAST, WEST}) {

            Bitboard x = square_bb(sq);
            for (int i = 0; i < 7; i++) {

                x = shift<Direction>(d, x);
                pseduoAttacks[ROOK][sq] |= x;
            }
        }

        // BISHOP Attacks
        for (Direction d : {NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST}) {

            Bitboard x = square_bb(sq);
            for (int i = 0; i < 7; i++) {

                x = shift<Direction>(d, x);
                pseduoAttacks[BISHOP][sq] |= x;
            }
        }

        // QUEEN Attacks (ROOK | BISHOP)
        pseduoAttacks[QUEEN][sq] = pseduoAttacks[ROOK][sq] | pseduoAttacks[BISHOP][sq];

        // KING Attacks
        for (Direction d : {NORTH, SOUTH, EAST, WEST, 
                            NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST}) {

            pseduoAttacks[KING][sq] |= shift<Direction>(d, square_bb(sq));
        } 

        // PAWN Attacks (Can only be generated in one direction ie WHITE)
        for (Direction d : {NORTH_WEST, NORTH_EAST}) {

            pseduoAttacks[PAWN][sq] |= shift<Direction>(d, square_bb(sq));
        }
    }
}


} // namespace Oscarfish
