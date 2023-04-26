#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <stdio.h>
#include <string>
#include "Piece.h"
#include "Operation.h"
#include "Automate.h"
#include "Capteur.h"
#include "IHM.h"
#include "Thermostat.h"
using namespace std;
int main() {
    Piece* piece = new Piece();
    Operation* oper = new Operation();
    Thermostat* thermo = new Thermostat();

    piece->setTempPiece(19.70);
    int timerPiece = -1;
    string msg = "";

    while (1) {
        msg = "THERMOSTAT PROGRAMMABLE\n\n";
        msg += "RECHAUFFEMENT : " + to_string(oper->getSignalRechauffement());
        msg += "\nVENTILATION : " + to_string(oper->getSignalVentilation());

        if (timerPiece == 5) { //temp piece varie aleatoirement chaque 5 secondes +1 ou -1
            timerPiece = 0;
            piece->evolutionTemp();
        }

        if (GetAsyncKeyState(VK_UP)) {
            //seuil min ++
            thermo->getIHM()->setBoutonPoussoir(25.50);
        }
        else if (GetAsyncKeyState(VK_LEFT)) {
            //seuil max --
            thermo->getIHM()->setBoutonPoussoir(24.50);

        }
        else if (GetAsyncKeyState(VK_RIGHT)) {
            //seuil max ++
            thermo->getIHM()->setBoutonPoussoir(26.50);
        }
        else if (GetAsyncKeyState(VK_DOWN)) {
            //seuil min --
            thermo->getIHM()->setBoutonPoussoir(27.50);
        }

        thermo->ajusterTemp(piece, msg);
        oper->setSignalRechauffement(thermo->getAutomate()->getSignalRechauff());
        oper->setSignalVentilation(thermo->getAutomate()->getSignalVentil());

        oper->RechauffementPiece(piece);
        oper->VentilationPiece(piece);

        Sleep(1000);
        timerPiece++;
        thermo->getIHM()->setBoutonPoussoir(0);
        msg = "";
    }

    return 0;
}