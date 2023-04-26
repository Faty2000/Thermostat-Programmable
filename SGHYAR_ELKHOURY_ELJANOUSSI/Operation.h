#pragma once
#include "Piece.h"
#include "Operation.h"

class Operation {
public:
    Operation();
    void VentilationPiece(Piece* piece);
    void RechauffementPiece(Piece* piece);
    void setSignalVentilation(bool signalVenti);
    void setSignalRechauffement(bool signalRechauf);
    bool getSignalVentilation();
    bool getSignalRechauffement();

private:
    bool signalVentilation;
    bool signalRechauffement;
};
