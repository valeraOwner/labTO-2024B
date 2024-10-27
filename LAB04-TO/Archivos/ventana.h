#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <map>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class Ventana;
}
QT_END_NAMESPACE

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void on_boton_clicked();

    void on_lista_itemClicked(QListWidgetItem *item);

private:
    Ui::Ventana *ui;

    std::map<std::string, std::map<std::string, std::string>> paises;

    void inicioPaises();
};
#endif // VENTANA_H
