#pragma once
#include "Piece.h"

class Piece {
public:
    Piece();
    float evolutionTemp();
    float getTempPiece();
    void setTempPiece(float tempPiece);
    float convertir(float x, int nc);
private:
    float tempPiece;
};

