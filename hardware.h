#ifndef HARDWARE_H
#define HARDWARE_H

#include <QObject>
#include <QSerialPort>
#include <QPushButton>
#include <QTextEdit>
#include <QtDebug>
#include <QVector>
#include <QSerialPortInfo>
class hardware : public QObject
{
    Q_OBJECT//要是向向类中传信号就一定要有
public:
    explicit hardware(QTextEdit *text, QSerialPort *m_s, QPushButton *Btn,QObject *parent = nullptr);
   void setSerialPortOpenOrDown();
      QList<QString>  getCanBeUsedSerialPortMessage();
      QList <QString> getSerialPort();//得到端口列表
      QList <QString> getBaudRate();//得到波特率列表
      QList <QString> getDataBits();//得到数据位列表
      QList <QString> getParity();//得到奇偶校验列表
      QList <QString> getStopbits();//得到停止位列表

private:
   QTextEdit *ted;
   QPushButton *BtnOfSerialPort;
   QSerialPort *m_serialPort;//忘了定义成指针型error: no match for 'operator=' (operand types are 'QSerialPort' and 'QSerialPort*')
                             // this->m_serialPort=m_s;


    QList<QString> message;
    void serialPortinit(QVector<QString> mm);
    QVector<QString> messageOfSerialPort ;

signals:
private slots:
   void getMessageOfSerialPort(QVector<QString> messageOfSerialPort);

public slots:
};

#endif // HARDWARE_H
