#include "formtask.h"
#include "ui_formtask.h"
#include <QDebug>


FormTask::FormTask(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormTask)
{
    ui->setupUi(this);

    connect(ui->confirmarButton, &QPushButton::clicked, this, &FormTask::on_confirmarButton_clicked);
    connect(ui->cancelarButton, &QPushButton::clicked, this, &FormTask::on_cancelarButton_clicked);
}

FormTask::~FormTask()
{
    delete ui;
}




void FormTask::on_confirmarButton_clicked()
{
    QString taskName = ui->lineEdit->text();
    if (!taskName.isEmpty()) {
        qDebug() << "Creando Tarea con nombre:" << taskName;//consola
        disconnect(ui->confirmarButton, &QPushButton::clicked, this, &FormTask::on_confirmarButton_clicked);

        emit taskCreada(taskName);//emitir la señal
        accept(); //cerrar ventana
    } else {
        qDebug() << "No hay nombre en el campo.";//consola
    }

}


void FormTask::on_cancelarButton_clicked()
{
    reject();//cerrar sin hacer nada
}

