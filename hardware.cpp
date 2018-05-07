#include "hardware.h"

hardware::hardware(QTextEdit *text, QSerialPort *m_s,QPushButton *Btn,QObject *parent) : QObject(parent)
{
    this->ted=text;
    this->m_serialPort=m_s;
    this->BtnOfSerialPort=Btn;

}

void hardware::setSerialPortOpenOrDown()
{
    if(m_serialPort->isOpen())
        BtnOfSerialPort->setText("关闭串口");
    else
        BtnOfSerialPort->setText("打开串口");

}

QList<QString> hardware::getCanBeUsedSerialPortMessage()
{
    foreach (const QSerialPortInfo qspinfo, QSerialPortInfo::availablePorts())
    {


        message.append(qspinfo.portName()+'\n'+qspinfo.description()+'\n'+qspinfo.manufacturer()+ '\n'+qspinfo.serialNumber()+'\n'+qspinfo.serialNumber()+'\n');

    }
    return message;
}

QList<QString> hardware::getSerialPort()
{
     QList<QString> portscomlist;
    foreach (const QSerialPortInfo qspinfo, QSerialPortInfo::availablePorts())
    {

        portscomlist.append(qspinfo.portName());
    }
    return portscomlist;
}

QList<QString> hardware::getBaudRate()
{
    QList<QString> brlist;
    QString BaudRate[]={"9600","38400","100000","115200","128000","921600"};
    for(uint i=0;i<(sizeof(BaudRate)/sizeof(QString));i++)
    {
        brlist.append(BaudRate[i]);
    }
    return brlist;
}

QList<QString> hardware::getDataBits()
{
    QList<QString> dblist;
    QString dataBits[]={"8","7","6","5"};
    for(uint i=0;i<(sizeof(dataBits)/sizeof(QString));i++)
    {
        dblist.append(dataBits[i]);
    }
    return dblist;
}

QList<QString> hardware::getParity()
{
     QList<QString> pylist;
    QString parity[]={"无","奇校验","偶校验"};
    for(uint i=0;i<(sizeof(parity)/sizeof(QString));i++)
    {
        pylist.append(parity[i]);

    }
     return pylist;

}

QList<QString> hardware::getStopbits()
{
     QList<QString> pylist;
    QString stopBits[]={"1","1.5","2"};
    for(uint i=0;i<(sizeof(stopBits)/sizeof(QString));i++)
    {
        pylist.append(stopBits[i]);
    }
    return pylist;
}

void hardware::serialPortinit(QVector<QString> mm)
{
    m_serialPort->setPortName(mm.at(0));
    m_serialPort->setBaudRate(mm.at(1).toInt());
      qDebug()<<" !!!!!!!!!!!!!!";
      switch(mm.at(2).toInt())
      {
      case 8:m_serialPort->setDataBits(QSerialPort::Data8);
          break;
      case 7:m_serialPort->setDataBits(QSerialPort::Data7);
          break;
      case 6:m_serialPort->setDataBits(QSerialPort::Data6);
          break;
      case 5:m_serialPort->setDataBits(QSerialPort::Data5);
          break;
      }
      qDebug()<<" !!!!!!!!!!!!!!";
      if(mm.at(3)=="无")
      {
          m_serialPort->setParity(QSerialPort::NoParity);
      }
      else if(mm.at(3)=="奇校验")
      {
          m_serialPort->setParity(QSerialPort::NoParity);
      }
      else if(mm.at(3)=="偶校验")
      {
          m_serialPort->setParity(QSerialPort::NoParity);
      }
      if(mm.at(4).toFloat()==1)
      {
          m_serialPort->setStopBits(QSerialPort::OneStop);
      }
      else if(mm.at(4).toFloat()==1.5)
      {
          m_serialPort->setStopBits(QSerialPort::OneAndHalfStop);
      }
      else if(mm.at(4).toFloat()==2)
      {
          m_serialPort->setStopBits(QSerialPort::TwoStop);
      }

}

void hardware::getMessageOfSerialPort(QVector<QString> messageOfSerialPort)
{

   for(uint i=0;i<5;i++)
    {
        ted->append(messageOfSerialPort.at(i));
    }//执行了

     qDebug()<<"open database succesful!!!!!!!!!!!!!!";

  serialPortinit(messageOfSerialPort);//一定记得要传值
}
