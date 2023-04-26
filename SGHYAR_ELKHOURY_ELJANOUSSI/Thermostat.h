#pragma once

#include "Thermostat.h"
#include "Capteur.h"
#include "Automate.h"
#include "IHM.h"
#include "Capteur.h"


class Thermostat {
public:
    Thermostat();
    void ajusterTemp(Piece* piece, string msg);
    Automate* getAutomate();
    IHM* getIHM();
private:
    Capteur* capteur;
    Automate* automate;
    IHM* ihm;
};
