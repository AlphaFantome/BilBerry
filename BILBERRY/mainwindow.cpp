#include "mainwindow.h"

#include <QtGui>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficher() // Affichage de l'image
{
    QSize size(ui->Label_image->width(), ui->Label_image->height());
    QImage image2 = image1->scaled(size, Qt::KeepAspectRatio);
    ui->Label_image->setPixmap(QPixmap::fromImage(image2));
}

void MainWindow::on_ouvrir_clicked() // Ouverture du dossier avec la photo
{
    fileName = QFileDialog::getOpenFileName(this, "Ouvrir un fichier...","/home", QString());

    if (!fileName.isEmpty())
    {
        QImage* image = new QImage(fileName);
        image1 = image;
        fileReset=fileName;
        if (image1->isNull())
        {
            QMessageBox::information(this, "MainWindow ",tr("ne peut pas être chargée.").arg(fileName));
            return;
        }

        im = TraiterImage(image1->height(), image1->width()); //Envois des données de l'image pour le préparer au traitement
        afficher();
    }
}

void MainWindow::on_Noir_Blanc_clicked() // Utilisation de l'algorithme Noir et Blanc
{
    if (image1->isNull())
        return;
    im.noirEtBlanc(image1);
    afficher();
}

void MainWindow::on_save_clicked() //Selection du fichier de sauvegarde puis sauvegarde de la photo
{
    if (image1->isNull())
        return;
        chemin = QFileDialog::getExistingDirectory(this, tr("Ouvrir un fichier"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

            if(chemin!="")
            {
                 fileName = chemin+"/New.png";
                 image1->save(fileName, "PNG");
            }
}

void MainWindow::on_Reset_clicked() // Retourne sur l'image de départ et sans les modifications

{
    if (image1->isNull())
        return;
    QPixmap image(fileReset);
    int w =  ui->Label_image->width();
    int h =  ui->Label_image->height();
    ui->Label_image->setPixmap(image.scaled(w,h,Qt::KeepAspectRatio));
}

