#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_SerialPort=new QSerialPort;
    m_hardware=new hardware(ui->messageOfRec,m_SerialPort,ui->BtnOfSerialPort);
    m_hardware->setSerialPortOpenOrDown();
    windowInit();


    connect(this,SIGNAL(sendToHardwaremessageOfSerialPort(QVector<QString>  )),m_hardware,SLOT(getMessageOfSerialPort(QVector<QString> )));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::windowInit()
{
    foreach (const QString messages,m_hardware->getCanBeUsedSerialPortMessage()) {
        ui->messageOfRec->append(messages);
    }
    ui->serialPortComs->addItems(m_hardware->getSerialPort());
    ui->BaudRate->addItems(m_hardware->getBaudRate());
    ui->DataBits->addItems(m_hardware->getDataBits());
    ui->Parity->addItems(m_hardware->getParity());
    ui->Stopbits->addItems(m_hardware->getStopbits());
    ui->Parity->addItems(m_hardware->getParity());
}

void MainWindow::on_BtnOfSerialPort_clicked()
{
    messageOfSerialPort.append(ui->serialPortComs->currentText());
    messageOfSerialPort.append(ui->BaudRate->currentText());
    messageOfSerialPort.append(ui->DataBits->currentText());
    messageOfSerialPort.append(ui->Parity->currentText());
    messageOfSerialPort.append(ui->Stopbits->currentText());
    ui->messageOfRec->clear();
    emit sendToHardwaremessageOfSerialPort(messageOfSerialPort);
}
