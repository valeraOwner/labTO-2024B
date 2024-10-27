#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"
#include "formtask.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButton, &QPushButton::clicked,this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addTask()
{
    qDebug() << "Entrando a addTask";
    FormTask taskForm(this);
    disconnect(&taskForm, &FormTask::taskCreada, this, &MainWindow::addTaskToList);
    connect(&taskForm, &FormTask::taskCreada, this, &MainWindow::addTaskToList);

    taskForm.exec();//Mostrar el formulario
}



void MainWindow::addTaskToList(const QString &taskName)
{
    Task *task = new Task(this);//crear tarea
    task->setTaskName(taskName);

    mTasks.append(task);//tarea a la lista
    ui->taskLayout->addWidget(task);//mostrar a la interfaz

    connect(task, &Task::removed, this, &MainWindow::removeTask);
}


//función removeTask
void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->taskLayout->removeWidget(task);
    task->deleteLater();//elimina el widget
}
