#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "Automate.h"
#include <iostream>
#include <stdio.h>


using namespace std;

Automate::Automate() {
    tempPiece = 22.50;
    seuilHaut = 26.50;
    seuilBas = 24.50;
    etatCourant = TEMP_NORMALE;
    signalRechauff = false;
    signalVentil = false;
}

float Automate::convertir(float x, int nc) {
    // x = 12.7582;
    int y = x; // convertir en entier x = 12 entier
    float z = x - y; // recuperer la partie fractionnaire z = 0.7582;
    z = z * pow(10, nc); /* on obtient les chiffres désirés ex nc = 2
                            z = 75.82; */
    int m = z;   // m = 75
    z = m / pow(10, nc); //  0.75
    return y + z ;   // 12 + 0.75 = 12.75 donc un nombre réel avec 2 chiffres apres la virgule
}

void Automate::comparerTempSeuil() {
    switch (etatCourant)
    {
    case TEMP_NORMALE:
        if (tempPiece < seuilBas) {
            etatCourant = TEMP_BASSE;
            signalRechauff = true;
        }
        else if (tempPiece > seuilHaut && tempPiece != seuilHaut) {
            etatCourant = TEMP_ELEVEE;
            signalVentil = true;
        }
        break;

    case TEMP_ELEVEE:
        if (tempPiece <= seuilBas) {
            etatCourant = TEMP_NORMALE;
            signalVentil = false;
        }
        break;

    case TEMP_BASSE:
        if (tempPiece >= seuilHaut) {
            etatCourant = TEMP_NORMALE;
            signalRechauff = false;
        }
        break;

    case TEMP_FAUSSE:
        if (tempPiece > seuilHaut || tempPiece < seuilBas) {
            Sleep(1000);
                if (tempPiece > seuilHaut || tempPiece < seuilBas) {
                    etatCourant = TEMP_FAUSSE;
                    signalRechauff = false;
                    signalVentil = false;
                }
        }
        break;
    }
}


void Automate::setSignalVentil(bool signalVenti) {
    signalVentil = signalVenti;
}

void Automate::setSignalRechauff(bool signalRech) {
    signalRechauff = signalRech;
}

bool Automate::getSignalVentil() {
    return signalVentil;
}

bool Automate::getSignalRechauff() {
    return signalRechauff;
}

EtatThermostat Automate::getEtatThermostat() {
    return etatCourant;
}
EtatIHM Automate::getEtatIHM() {
    return etatIHM;
}

void Automate::setTempPiece(float tempP) {
    tempPiece = tempP;
}

void Automate::setSeuilHaut(float seuilH) {
    if (seuilH >= seuilBas)
        seuilHaut = seuilH;
}

void Automate::setSeuilBas(float seuilB) {
    if (seuilB <= seuilHaut)
        seuilBas = seuilB;
}


float Automate::getTempPiece() {
    return convertir(tempPiece,1);
}

float Automate::getSeuilHaut() {
    return convertir(seuilHaut,1);
}

float Automate::getSeuilBas() {
    return convertir(seuilBas,1);
}

int Automate::getTempsMort() {
    return tempsMort;
}

void Automate::reglerSeuil(float bouton) {
    if (bouton == 24.5) {
        tempsMort = 4;
        etatIHM = SEUIL_HAUT;
        setSeuilHaut(seuilHaut - 1);
    }
    else if (bouton == 25.5) {
        tempsMort = 4;
        etatIHM = SEUIL_BAS;
        setSeuilBas(seuilBas + 1);
    }
    else if (bouton == 26.5) {
        tempsMort = 4;
        etatIHM = SEUIL_HAUT;
        setSeuilHaut(seuilHaut + 1);
    }
    else if ( bouton == 27.5) {
        tempsMort = 4;
        etatIHM = SEUIL_BAS;
        setSeuilBas(seuilBas - 1);
    }
    else
        (tempsMort <= 0) ? etatIHM = TEMP_PIECE : tempsMort--;
   
}