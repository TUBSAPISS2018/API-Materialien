#ifndef ARDUINOINTERFACE_H
#define ARDUINOINTERFACE_H

#include <QObject>
#include <QSerialPort>

class ArduinoInterface : public QObject
{
	Q_OBJECT
public:
    explicit ArduinoInterface(QObject *parent = nullptr);

private:
	QSerialPort m_serialPort;

signals:

public slots:
	void writeColorToArduino(char colorIdent, char colorValue);
};

#endif // ARDUINOINTERFACE_H
