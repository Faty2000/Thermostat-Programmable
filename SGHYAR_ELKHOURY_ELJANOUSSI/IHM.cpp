#include "IHM.h"
#include <iostream>

using namespace std;

IHM::IHM() {
	boutonPoussoir = 0;
}
void IHM::afficher(string msg) {
	system("CLS");
	cout << boolalpha << msg;
}

void IHM::setBoutonPoussoir(float bouton) {
	boutonPoussoir = bouton;
}

float IHM::getBoutonPoussoir() {
	return boutonPoussoir;
}

