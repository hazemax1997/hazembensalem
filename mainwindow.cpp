#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chambre.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabchambre->setModel(tmp.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int num = ui->lineEdit_id->text().toInt();
    QString type= ui->lineEdit_nom->text();
    QString statut= ui->lineEdit_prenom->text();
  Chambre c(num,type,statut);
  bool test=c.ajouter();
  if(test)
{ui->tabchambre->setModel(tmp.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une chambre"),
                  QObject::tr("Chambre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un chambre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int num = ui->lineEdit_id->text().toInt();
bool test=tmp.supprimer(num);
if(test)
{ui->tabchambre->setModel(tmp.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une chambre"),
                QObject::tr("Chambre supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une chambre"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_clicked()
{
    int num = ui->lineEdit_id->text().toInt();
        bool test=tmp.chercher(num);
        if(test)
        {
        ui->tabchambre->setModel(tmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("Cherhcer une chambre"),
                    QObject::tr("Chambre disponible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Chercher une chambre"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        }

