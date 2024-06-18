#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QImage rotarRGB(const QImage &in);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_dial_valueChanged(int);

    void on_dial_2_valueChanged(int);

    void on_dial_3_valueChanged(int);

private:
    Ui::Dialog *ui;

    int velocidadDial1;

    int velocidadDial2;

    int velocidadDial3;
};
#endif // DIALOG_H
