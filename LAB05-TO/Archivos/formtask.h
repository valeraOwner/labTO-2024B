#ifndef FORMTASK_H
#define FORMTASK_H

#include <QWidget>
#include <QCoreApplication>
#include <QDialog>

namespace Ui {
class FormTask;
}

class FormTask : public QDialog
{
    Q_OBJECT

public:
    explicit FormTask(QWidget *parent = nullptr);
    ~FormTask();

signals:
    void taskCreada(const QString &nombreTarea);

private slots:

    void on_confirmarButton_clicked();

    void on_cancelarButton_clicked();


private:
    Ui::FormTask *ui;
};

#endif // FORMTASK_H
