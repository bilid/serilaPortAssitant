#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <hardware.h>
#include<QVector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BtnOfSerialPort_clicked();

private:
    Ui::MainWindow *ui;

    QSerialPort *m_SerialPort;
    hardware *m_hardware;

  void windowInit();

  QVector<QString> messageOfSerialPort ;
signals:
  void sendToHardwaremessageOfSerialPort( QVector<QString> messageOfSerialPort);

};

#endif // MAINWINDOW_H
