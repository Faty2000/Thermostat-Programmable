#pragma once

#include "Automate.h"

enum EtatIHM { TEMP_PIECE, SEUIL_HAUT, SEUIL_BAS };
enum EtatThermostat { TEMP_ELEVEE, TEMP_NORMALE, TEMP_BASSE, TEMP_FAUSSE };

class Automate {
public:
	Automate();
	void comparerTempSeuil();
	void setSignalVentil(bool signalVenti);
	void setSignalRechauff(bool signalRech);
	void setTempPiece(float);
	void setSeuilHaut(float);
	void setSeuilBas(float);
	bool getSignalVentil();
	bool getSignalRechauff();
	float getTempPiece();
	float getSeuilBas();
	float getSeuilHaut();
	float convertir(float x, int nc);
	EtatThermostat getEtatThermostat();
	void reglerSeuil(float bouton);
	int getTempsMort();
	EtatIHM getEtatIHM();

private:
	float tempPiece;
	float seuilHaut;
	float seuilBas;
	bool signalVentil;
	bool signalRechauff;
	int tempsMort;
	int tempsMort1;
	EtatThermostat etatCourant;
	EtatIHM etatIHM;
};
