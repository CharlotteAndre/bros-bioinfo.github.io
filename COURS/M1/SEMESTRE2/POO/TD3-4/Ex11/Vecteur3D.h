//
// Created by eliot on 18/01/19.
//

#ifndef POO_VECTEUR3D_H
#define POO_VECTEUR3D_H


class Vecteur3D {
private:
    double x;
    double y;
    double z;
public:
    void affiche();

    void affiche(const char *string);

    inline Vecteur3D(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    inline Vecteur3D() {
        x = 0;
        y = 0;
        z = 0;
    }

    double abscisse() const;

    void fixer_abscisse(double x);

    double ordonnee() const;

    void fixer_ordonnee(double y);

    double cote() const;

    void fixer_cote(double z);

    bool coincinde(Vecteur3D v);

    double produitScalaire(Vecteur3D v);

    Vecteur3D somme(Vecteur3D v);
};

#endif //POO_VECTEUR3D_H
