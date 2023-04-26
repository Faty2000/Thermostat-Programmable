#include <iostream>
#include "Capteur.h"

Capteur::Capteur() {
    tempMesuree = 0;
}

void Capteur::mesurerTemp(Piece* piece) {
    tempMesuree = piece->getTempPiece();
}

float Capteur::convertir(float x, int nc) {
    // x = 12.7582;
    int y = x; // convertir en entier x = 12 entier
    float z = x - y; // recuperer la partie fractionnaire z = 0.7582;
    z = z * pow(10, nc); /* on obtient les chiffres désirés ex nc = 2
                            z = 75.82; */
    int m = z;   // m = 75
    z = m / pow(10, nc); //  0.75
    return y + z;   // 12 + 0.75 = 12.75 donc un nombre réel avec 2 chiffres apres la virgule
}

float Capteur::envoiTemp() {
    return convertir(tempMesuree,1);
}
