#include "traitement.h"

//Longueur de l'image
int TraiterImage::Width(void) //Set longueur
{
    return w;
}

// Largeur d'image

int TraiterImage::Height(void) // Set largeur
{
    return h;
}

// Constructeur
TraiterImage::TraiterImage(int nHeight, int nWidth)
    : w(nWidth)
    , h(nHeight)
{}

void TraiterImage::noirEtBlanc(QImage* image) // Algorithme de Noir et Blanc
{
    for (int i = 0; i < image->height(); i++)
    {
        uint* pixels_line = (uint*) image->scanLine(i);

        for (int j = 0; j < image->width(); j++)
        {
            int G = qGreen(pixels_line[j]);
            if (G <= 200)
            {
                pixels_line[j] = qRgb(255, 255, 255);
            }
            else
            {
                pixels_line[j] = qRgb(0, 0, 0);
            }
        }
    }
}
