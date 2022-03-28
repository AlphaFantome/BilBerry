#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

#include "traitement.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots: //Fonctions lier à la MainWindow

    void on_ouvrir_clicked(); // Ouvrir une photo contenu dans un dossier
    void on_Noir_Blanc_clicked(); // Pixels vert = Blanc et Pixels autres = Noir
    void afficher(); // Affiche l'image
    void on_save_clicked(); // Sauvegarde l'image dans un dossier
    void on_Reset_clicked();//Retourne sur l'image de départ et sans les modifications

private:

    Ui::MainWindow* ui;
    TraiterImage im; // Utiliser pour appliquer le filtre
    QString fileName; // Nom du dossier de sauvegarde
    QString fileReset;// Nom du dossier de la photo choisie
    QString chemin; // Chemin de la sauvegarde
    QImage* image1; // Copie de l'image choisie dans un QImage

};
#endif // MAINWINDOW_H
