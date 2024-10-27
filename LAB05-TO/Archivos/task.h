#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();
    void setTaskName(const QString &name);

private:
    Ui::Task *ui;

signals:
    void removed(Task* task);

private slots:
    void onEditClicked();  // Para editar


};

#endif // TASK_H
