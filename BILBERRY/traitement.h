#include <iostream>
#include <fstream>
#include <QImage>
#include <QColor>

#ifndef TRAITEMENT_H
#define TRAITEMENT_H

class TraiterImage
{
protected:
    int w; //Longueur de l'image
    int h; // Largeur de l'image

public:
    TraiterImage(int nHeight = 0, int nWidth = 0); // Constructeur
    int Width() ;  // longeur d'image
    int Height();  // largeur d'image
    void noirEtBlanc(QImage *image); //Noir et Blanc
};

#endif // TRAITEMENT_H
