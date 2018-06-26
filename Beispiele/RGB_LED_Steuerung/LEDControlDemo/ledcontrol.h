#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <QWidget>

namespace Ui {
class LedControl;
}

class LedControl : public QWidget
{
    Q_OBJECT

public:
    explicit LedControl(QWidget *parent = 0);
    ~LedControl();

private slots:
    void on_pbClose_clicked();

    void on_pbReset_clicked();

    void on_hsRed_valueChanged(int value);

    void on_hsGreen_valueChanged(int value);

    void on_hsBlue_valueChanged(int value);

    void on_pbOnOff_clicked();

private:
    Ui::LedControl *ui;

    const int DEFAULT_LED_VALUE = 10;
    enum LedColor : char {
        Red = 101,
        Green = 102,
        Blue = 103
    };

    void reset();
    void onSliderMoved(LedColor color, int value);
    void setLedSlidersEnabled(bool bEnabled);
    void sendAllColors(int red, int green, int blue);

signals:
    void sendColor(char colorIdentifier, char colorValue);
};

#endif // LEDCONTROL_H
