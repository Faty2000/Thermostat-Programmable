#pragma once
#include <iostream>

using namespace std;


class IHM {
public:
    IHM();
    void afficher(string msg);
    void setBoutonPoussoir(float bouton);
    float getBoutonPoussoir();

private:
    float boutonPoussoir; 
};
