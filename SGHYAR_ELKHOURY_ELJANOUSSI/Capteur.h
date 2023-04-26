#pragma once

#include "Capteur.h"
#include "Piece.h"

class Capteur {
public:
    Capteur();
    void mesurerTemp(Piece* piece);
    float envoiTemp();
    float convertir(float x, int nc);
private:
    float tempMesuree;
};
