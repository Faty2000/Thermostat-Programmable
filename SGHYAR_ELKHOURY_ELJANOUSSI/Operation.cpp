#include "Operation.h"
#include <iostream>

using namespace std;


Operation::Operation() {
    signalVentilation = false;
    signalRechauffement = false;
}
void Operation::VentilationPiece(Piece* piece) {
    if (signalVentilation)
    piece->setTempPiece(piece->getTempPiece() - 1);
}
void Operation::RechauffementPiece(Piece* piece) {
    if (signalRechauffement)
    piece->setTempPiece(piece->getTempPiece() + 1);
}
void Operation::setSignalVentilation(bool signalVenti) {
    signalVentilation = signalVenti;
}
void Operation::setSignalRechauffement(bool signalRechauf) {
    signalRechauffement = signalRechauf;
}
bool Operation::getSignalVentilation() {
    return signalVentilation;
}
bool Operation::getSignalRechauffement() {
    return signalRechauffement;
}

