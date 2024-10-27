#include "ventana.h"
#include "ui_ventana.h"

#include <QListWidgetItem>
#include <QString>
#include <QMessageBox>

using namespace std;

Ventana::Ventana(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);
    ui->lista->setVisible(false);

    inicioPaises();

    connect(ui->lista, &QListWidget::itemClicked, this, &Ventana::on_lista_itemClicked);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::inicioPaises()
{
    // Aquí inicializamos el mapa con los datos de los países, idiomas y capitales
    paises["PERU"]["Español"] = "Lima";
    paises["CHILE"]["Español"] = "Santiago";
    paises["BOLIVIA"]["Español"] = "La Paz";
    paises["ARGENTINA"]["Español"] = "Buenos Aires";
    paises["COLOMBIA"]["Español"] = "Bogota";
    paises["ECUADOR"]["Español"] = "Quito";
    paises["VENEZUELA"]["Español"] = "Caracas";
    paises["PARAGUAY"]["Español"] = "Asuncion";
    paises["URURGUAY"]["Español"] = "Montevideo";
    paises["USA"]["Ingles"] = "Washington DC";
    paises["CANADA"]["Ingles"] = "Ottawa";
    paises["ESPAÑA"]["Español"] = "Madrid";
    paises["FRANCIA"]["Frances"] = "Paris";
    paises["ITALIA"]["Italiano"] = "Roma";
    paises["PORTUGAL"]["Portugues"] = "Lisboa";
    paises["BRASIL"]["Portugues"] = "Brasilia";
    paises["CHINA"]["Chino"] = "Pekin";
    paises["JAPON"]["Japones"] = "Tokio";
    paises["RUSIA"]["Ruso"] = "Moscu";
    paises["MARRUECOS"]["Arabe"] = "Rabat";
    paises["FILIPINAS"]["Filipino"] = "Manila";
}

void Ventana::on_boton_clicked()
{
    if(!ui->lista->isVisible()){
        ui->lista->setVisible(true);
    }
}


void Ventana::on_lista_itemClicked(QListWidgetItem *item)
{
    //manejando texto con QString y text() para manejar el tipo Qstring
    QString paisSel = item->text();

    //buscar paises con find(), si lo encuentra devuelve iterador que apunta al pais
    auto it = paises.find(paisSel.toStdString());

    //si el iterador si encuentra al pais(diferente al end())
    if (it != paises.end()) {
        //accedemos al primer y segundo valor del primer map
        string idioma = it->second.begin()->first;
        string capital = it->second.begin()->second;

        //mostrando el idioma en los labels y conviertiendo
        //el string a Qstring para mostrar
        ui->lineEdit->setText(QString::fromStdString(idioma));
        ui->lineEdit_2->setText(QString::fromStdString(capital));



    }
    else{

    }
}

