#include "arduinointerface.h"

ArduinoInterface::ArduinoInterface(QObject *parent) : QObject(parent)
{
	m_serialPort.setPortName("/dev/cu.usbmodem1411");
	m_serialPort.setBaudRate(9600);
	m_serialPort.open(QIODevice::WriteOnly);
}

void ArduinoInterface::writeColorToArduino(char colorIdent, char colorValue)
{
	char colorData[2];
	colorData[0] = colorIdent;
	colorData[1] = colorValue;

	m_serialPort.write(colorData, sizeof(colorData));
	m_serialPort.flush();
}
