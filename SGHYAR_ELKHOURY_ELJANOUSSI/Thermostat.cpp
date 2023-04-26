#include "Thermostat.h"
#include <iostream>
#include <string>

using namespace std;


Thermostat::Thermostat() {
    capteur = new Capteur();
    automate = new Automate();
    ihm = new IHM();
}


void Thermostat::ajusterTemp(Piece* piece, string msg) {
    capteur->mesurerTemp(piece);

    automate->setTempPiece(capteur->envoiTemp());

    automate->reglerSeuil(ihm->getBoutonPoussoir());

    automate->comparerTempSeuil();

    switch (automate->getEtatThermostat())
    {
    case TEMP_NORMALE:
        msg += "\nEtat thermostat: Temperature normale";
        break;
    case TEMP_ELEVEE:
        msg += "\nEtat thermostat: Temperature elevee";
        break;
    case TEMP_BASSE:
        msg += "\nEtat thermostat: basse Temperature";
    case TEMP_FAUSSE:
        msg += "\nEnvoi du message: Temperature n'est pas maintenue entre les seuils ";
    }


    if (automate->getEtatIHM() == TEMP_PIECE) {
        msg += "\nEtat ecran: affichage TEMP_PIECE";
        msg += "­\nTemperature PIECE : " + to_string(automate->getTempPiece()) + " en degres ";
    }
    else if (automate->getEtatIHM() == SEUIL_HAUT) {
        msg += "\nEtat ecran: affichage SEUIL_HAUT";
        msg += "­\nTemperature SEUIL HAUT : " + to_string(automate->getSeuilHaut()) + " en degres ";
    }
    else if (automate->getEtatIHM() == SEUIL_BAS) {
        msg += "\nEtat ecran: affichage SEUIL_BAS";
        msg += "­\nTemperature SEUIL BAS : " + to_string(automate->getSeuilBas()) + " en degres ";
    }

    ihm->afficher(msg);
}

Automate* Thermostat::getAutomate() {
    return automate;
}

IHM* Thermostat::getIHM() {
    return ihm;
}

