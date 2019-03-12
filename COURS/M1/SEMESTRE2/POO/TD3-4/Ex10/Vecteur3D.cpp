//
// Created by eliot on 18/01/19.
//

#include <iostream>
#include "Vecteur3D.h"

using namespace std;

void Vecteur3D::affiche() {
    cout << "(" << x << ", " << y << ", " << z << ")\n";
}

void Vecteur3D::affiche(const char *string) {
    cout << string << endl;
    affiche();
}

double Vecteur3D::abscisse() const {
    return x;
}

void Vecteur3D::fixer_abscisse(double x){
    this->x = x;
}

double Vecteur3D::ordonnee() const {
    return y;
}

void Vecteur3D::fixer_ordonnee(double y){
    Vecteur3D::y = y;
}

double Vecteur3D::cote() const {
    return z;
}

void Vecteur3D::fixer_cote(double z){
    Vecteur3D::z = z;
}

bool Vecteur3D::coincinde(Vecteur3D v) {
    return x == v.x && y == v.y && z == v.z;
}