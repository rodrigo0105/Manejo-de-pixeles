#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

QImage Dialog::rotarRGB(const QImage &in)
{
    //asignamos el tamaño de la imagen de la (in) y su formato
    QImage out(in.size(), in.format());
    //recorree el arreglo de pixeles
    for(int line=0; line < in.height() ; line++)
    {
        //pixeles de entrada
        const QRgb* inPixels = reinterpret_cast<const QRgb*>(in.scanLine(line));
        //pixeles de salida, estos son los que se van a modificar
        QRgb* outpixels = reinterpret_cast<QRgb*>(out.scanLine(line));
        for (int pos = 0; pos < in.width() ; pos++)
        {
            int red = qRed(inPixels[pos]);
            //red <<=2;
            int green = qGreen(inPixels[pos]);
            //int redDial = ui->lcdNumber;
            int blue = qBlue(inPixels[pos]);
            int alpha = qAlpha(inPixels[pos]);

            //outpixels[pos] = qRgba(red,greed,blue,alpha);
            //outpixels[pos] = qRgba(red,greed,blue,alpha);
            //outpixels[pos] = qRgba(blue,red,greed,alpha);
            //outpixels[pos] = qRgba(greed,blue,red,alpha);
            //outpixels[pos] = qRgba(155,155,155,155);
            //outpixels[pos] = qRgba(blue,0, blue,alpha);
            //outpixels[pos] = qRgba(red | 0x0000ff,greed | 0x00FF00,blue | 0xFF0000,alpha);
            //outpixels[pos] = qRgba(red ^ 0x0000ff,greed ^ 0x00FF00,blue ^ 0xFF0000,alpha);
            //outpixels[pos] = qRgba(red,red,red,alpha);
            //outpixels[pos] = qRgba(greed,greed,greed,alpha);
            //outpixels[pos] = qRgba(red & 0x0000ff,red & 0x00FF00,red & 0xFF0000,alpha);
            //outpixels[pos] = qRgba(~red,~red,~blue,alpha);
            //outpixels[pos] = qRgba(red>>2,greed<<2,blue<<2,alpha);

            outpixels[pos] = qRgba(velocidadDial1,green,blue,alpha);
            outpixels[pos] = qRgba(red,velocidadDial2,blue,alpha);
            outpixels[pos] = qRgba(red,green,velocidadDial3,alpha);

        }

    }
    return out;
}


void Dialog::on_pushButton_clicked()
{
    //imagendel pezz
    QImage ima(":/ima/pez.jpg");

    ima = rotarRGB(ima);
    ui->label_2->setPixmap(QPixmap::fromImage(ima));
    ui->label_2->setScaledContents(true);

    ima = rotarRGB(ima);
    ui->label_3->setPixmap(QPixmap::fromImage(ima));
    ui->label_3->setScaledContents(true);

    ima = rotarRGB(ima);
    ui->label_4->setPixmap(QPixmap::fromImage(ima));
    ui->label_4->setScaledContents(true);
}



/*
aplicacion interactiba (el usuario tendra las sig opciones
para manipular una imagen y mostrarla minimo una salida,
usar slider, dial, mostrar valores en LCD'S, SPINNER
)
*/


void Dialog::on_pushButton_2_clicked()
{
    close();
}


void Dialog::on_dial_valueChanged(int posicion)
{
    velocidadDial1 = posicion;
    ui->lcdNumber->display(velocidadDial1);

}


void Dialog::on_dial_2_valueChanged(int posicion)
{
    velocidadDial2 = posicion;
    ui->lcdNumber_2->display(velocidadDial2);
}


void Dialog::on_dial_3_valueChanged(int posicion)
{
    velocidadDial3 = posicion;
    ui->lcdNumber_3->display(velocidadDial3);
}

