#include "ledcontrol.h"
#include "arduinointerface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LedControl w;
    w.show();

    ArduinoInterface arduinoInterface;
	QObject::connect(&w, SIGNAL(sendColor(char,char)), &arduinoInterface, SLOT(writeColorToArduino(char,char)));

    return a.exec();
}
