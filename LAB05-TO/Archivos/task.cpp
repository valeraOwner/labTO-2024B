#include "task.h"
#include "ui_task.h"
#include <QInputDialog>

Task::Task(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);

    connect(ui->editarBoton, &QPushButton::clicked, this, &Task::onEditClicked);
    connect(ui->quitarBoton, &QPushButton::clicked, [this] { emit removed(this); });

}

Task::~Task()
{
    delete ui;
}

void Task::setTaskName(const QString &name)
{
    ui->checkBoxNombre->setText(name); //cambiar texto
}

void Task::onEditClicked()
{
    bool ok;
    QString sinonimo = QInputDialog::getText(this, tr("Agregar sinonimo"),
                                            tr("Ingrese un sinonimo:"), QLineEdit::Normal,
                                            "", &ok);


    if (ok && !sinonimo.isEmpty()) {
        ui->listaSinonimos->addItem(sinonimo); //agrega el sinónimo
    }
}
