#include "ledcontrol.h"
#include "ui_ledcontrol.h"

LedControl::LedControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LedControl)
{
    ui->setupUi(this);

    reset();
}

LedControl::~LedControl()
{
    delete ui;
}

void LedControl::on_pbClose_clicked()
{
    close();
}

void LedControl::reset()
{
    ui->hsRed->setValue(DEFAULT_LED_VALUE);
    ui->hsGreen->setValue(DEFAULT_LED_VALUE);
    ui->hsBlue->setValue(DEFAULT_LED_VALUE);

    setLedSlidersEnabled(true);
    sendAllColors(DEFAULT_LED_VALUE, DEFAULT_LED_VALUE, DEFAULT_LED_VALUE);
}

void LedControl::on_pbReset_clicked()
{
    reset();
}

void LedControl::onSliderMoved(LedColor color, int value)
{
    QLineEdit* txtValue;
    switch (color) {
    case LedColor::Red:
        txtValue = ui->txtRed;
        break;
    case LedColor::Green:
        txtValue = ui->txtGreen;
        break;
    case LedColor::Blue:
        txtValue = ui->txtBlue;
        break;
    }

    if (value > 0) {
        txtValue->setText(QString::number(value));
    } else {
        txtValue->setText("-");
    }

    emit sendColor(color, value);
}

void LedControl::on_hsRed_valueChanged(int value)
{
    onSliderMoved(LedColor::Red, value);
}

void LedControl::on_hsGreen_valueChanged(int value)
{
    onSliderMoved(LedColor::Green, value);
}

void LedControl::on_hsBlue_valueChanged(int value)
{
    onSliderMoved(LedColor::Blue, value);
}

void LedControl::setLedSlidersEnabled(bool bEnabled)
{
    ui->hsRed->setEnabled(bEnabled);
    ui->hsGreen->setEnabled(bEnabled);
    ui->hsBlue->setEnabled(bEnabled);
}

void LedControl::sendAllColors(int red, int green, int blue)
{
    emit sendColor(LedColor::Red, red);
    emit sendColor(LedColor::Green, green);
    emit sendColor(LedColor::Blue, blue);
}

void LedControl::on_pbOnOff_clicked()
{
    bool bNewValue = !ui->hsRed->isEnabled();
    setLedSlidersEnabled(bNewValue);

    if (bNewValue) {
        sendAllColors(ui->hsRed->value(), ui->hsGreen->value(), ui->hsBlue->value());
    } else {
        sendAllColors(0, 0, 0);
    }
}
