#include "ventana.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>


using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "labPaises_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Ventana w;
    w.show();
    return a.exec();
}
