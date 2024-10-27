#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QCoreApplication>
#include "task.h"
#include "formtask.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<Task*> mTasks;//vector para tareas


public slots:
    void addTask();
    void removeTask(Task* task);
    void addTaskToList(const QString &taskName);



};
#endif // MAINWINDOW_H
