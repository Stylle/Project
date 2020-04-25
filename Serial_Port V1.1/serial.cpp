#include "serial.h"
#include "ui_serial.h"

serial::serial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serial)
{
    ui->setupUi(this);
    system_init();
}

/*** QT快捷键
*F4:.c文件转换到.h文件
*CTRL + B :编译文件
*CTRL + R :编译且运行
***/

serial::~serial()
{
    delete ui;
}

/***子函数代码区****/

//初始化控件
void serial::system_init()
{
    //串口初始化
    //奇偶校验
    //波特率
    //数据位宽
    //串口号
    //打开串口
//    global_port.setParity(QSerialPort::NoParity);
//    //数据位宽
//    global_port.setDataBits(QSerialPort::Data8);
//    //停止位
//    global_port.setStopBits(QSerialPort::OneStop);
    //自动搜索串口号
    QList<QSerialPortInfo>serialPortInfo = QSerialPortInfo::availablePorts();
    int count = serialPortInfo.count();
    for(int i = 0;i<count;i++)
    {
        ui->cmb_com->addItem(serialPortInfo.at(i).portName());
    }
    // 禁止最大化按钮
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    // 禁止拖动窗口大小
    setFixedSize(this->width(),this->height());
    //流控设置
    global_port.setFlowControl(QSerialPort::NoFlowControl);
    //按钮执行事件绑定  connect(信号发出者地址，发什么信号，在那个类触发，触发事件)
    //打开串口绑定
    connect(ui->btn_open,&QPushButton::clicked,this,&serial::btn_open);
    //搜索串口
    connect(ui->btn_search,&QPushButton::clicked,this,&serial::btn_search);
    //发送数据绑定
    connect(ui->btn_push,&QPushButton::clicked,this,&serial::btn_push_send);
    //接受数据
    connect(&global_port,&QSerialPort::readyRead,this,&serial::accept_date);
    //清除接受区域
    connect(ui->btn_del_accept,&QPushButton::clicked,this,&serial::del_Accept);
    //清除发送区域
    connect(ui->btn_del_push,&QPushButton::clicked,this,&serial::del_Send);
    //定时发送
    connect(ui->btn_tim_push,&QPushButton::clicked,this,&serial::timer_send);
    //停止发送
    connect(ui->btn_tim_off,&QPushButton::clicked,this,&serial::send_stop);
    //定时器
    connect(timer, SIGNAL(timeout()), this,SLOT(while_send()));
}
//串口信息配置函数
void serial::btn_open(bool)
{
    //qDebug("按钮Ok");
    //取下拉菜单选项第一个选项为0以此递增
    //qDebug()<<ui->cmb_com->currentIndex();
    //打开串口
    QList<QSerialPortInfo>serialPortInfo = QSerialPortInfo::availablePorts();
    int count = serialPortInfo.count();
    //先清除开始的串口信息
    ui->cmb_com->clear();
    for(int i = 0;i<count;i++)
    {
        ui->cmb_com->addItem(serialPortInfo.at(i).portName());
    }
    if(flag == 0 && count > 0 )
    {
        flag = 1;
        //设置串口号
        QString Port_Name = ui->cmb_com->currentText();
        global_port.setPortName(Port_Name);
        //数据位宽
        switch(ui->cmb_date->currentIndex())
        {
            case 0:
                global_port.setDataBits(QSerialPort::Data8);
                break;
            case 1:
                global_port.setDataBits(QSerialPort::Data7);
                break;
            case 2:
                global_port.setDataBits(QSerialPort::Data6);
                break;
            default:
                global_port.setDataBits(QSerialPort::Data5);
                break;
        }
        //停止位
        switch(ui->cmb_stop->currentIndex())
        {
            case 0:
                global_port.setStopBits(QSerialPort::OneStop);
                break;
            case 1:
                global_port.setStopBits(QSerialPort::OneAndHalfStop);
                break;
            default:
                global_port.setStopBits(QSerialPort::TwoStop);
                break;
        }
        //奇偶校验
        switch(ui->cmb_parity->currentIndex())
        {
            case 0:
                global_port.setParity(QSerialPort::NoParity);
                break;
            case 1:
                global_port.setParity(QSerialPort::OddParity);
                break;
            default:
                global_port.setParity(QSerialPort::EvenParity);
                break;
        }
        //波特率
        switch(ui->cmb_bound->currentIndex())
        {
            case 0:
                global_port.setBaudRate(QSerialPort::Baud115200);
                break;
            case 1:
                global_port.setBaudRate(QSerialPort::Baud57600);
                break;
            case 2:
                global_port.setBaudRate(QSerialPort::Baud38400);
                break;
            case 3:
                global_port.setBaudRate(QSerialPort::Baud9600);
                break;
            case 4:
                global_port.setBaudRate(QSerialPort::Baud2400);
                break;
            default:
                global_port.setBaudRate(QSerialPort::Baud1200);
                break;
        }

        global_port.open(QSerialPort::ReadWrite);
        ui->btn_open->setText("关闭串口");
        ui->lab_state->setText("串口已打开");
    }
    else if(flag == 0 && count <= 0)
    {
        QMessageBox::information(this,tr("Error"),QStringLiteral("没有搜索到串口"),QMessageBox::Ok);
    }
    else
    {
        global_port.close();
        ui->btn_open->setText("打开串口");
        ui->lab_state->setText("串口未打开");
        flag = 0;
    }
}
//搜索串口函数
void serial::btn_search(bool)
{

    //自动搜索串口号
    QList<QSerialPortInfo>serialPortInfo = QSerialPortInfo::availablePorts();
    int count = serialPortInfo.count();
    //先清除开始的串口信息
    ui->cmb_com->clear();
    for(int i = 0;i<count;i++)
    {
        ui->cmb_com->addItem(serialPortInfo.at(i).portName());
    }
}
//数据发送函数
void serial::btn_push_send(bool)
{

    //获取发送信息框数据-》存储到qstring类型变量-》转变类型-》发送数据
//     QString data = ui->lint_send->text();
//     QByteArray array = data.toLatin1();
//     global_port.write(array);

    QString str = ui->lint_send->text();

//    str = ui->lint_send->toPlainText();
     //要能正确发送中文字符，需要使用QString的toLocal8Bit方法
//    serial->write(str.toLatin1());

        global_port.write(str.toLocal8Bit());
        global_port.write("\r\n");

//    serial->write(str.toLocal8Bit());
//    ui->lint_accept->insertPlainText(array);
//    QByteArray data = ui->lint_send->textEdited();
//    global_port.write(data);
}

//数据接受函数
void serial::accept_date()
{
//    //获取数据-》存储到QByteArray类型变量-》转变类型-》添加到接受区
//     QByteArray array = global_port.readAll();
////     QString date = array;(QString(array));
////     ui->lint_accept->insert(array.toHex());
////     qDebug()<<ui->cbox_hex->checkState();
//     if(ui->cbox_hex->checkState() == Qt::Checked)
//     {
//         //qDebug("yes");
//         ui->lint_accept->insertPlainText(QString(array.toHex(' ').toUpper().append(' ')));
//     }
//     else
//     {
//         //qDebug("no");
//         ui->lint_accept->insertPlainText(QString(array));
//     }
     //qDebug("1");
     //qDebug()<<QString(array);

     //v2
     QByteArray buf;
     QString res;

     buf = global_port.readAll();
     res = QString(buf);

     if(!buf.isEmpty())
     {
         // 调试输出buf大小
         //qDebug()<<buf.size()<<endl;

         // 将QByteArray数据类型转换，要能正确显示中文，需要使用QString::fromLocal8Bit
         //        QString str = QString::fromUtf8( buf );
         QString str = QString::fromLocal8Bit( buf );

         //qDebug()<< str <<endl;

         // 如果以16进制显示数据：
         if (ui->cbox_hex->isChecked())
         {
             QString hex_data = buf.toHex().data(); // 将buf里的数据转换为16进制
             hex_data = hex_data.toUpper(); // 转换为大写
             QString hex_str;
             // 将16进制转换为大写
             for (int i=0; i< hex_data.length(); i+=2)
             {
                 QString st = hex_data.mid(i,2);
                 hex_str+=st;
                 hex_str+=' ';
             }
             ui->lint_accept->insertPlainText(hex_str);
         }
         else
         {
             ui->lint_accept->insertPlainText(str);
         }
     }

     buf.clear();
}
//清除接受区域函数
void serial::del_Accept(bool)
{
    ui->lint_accept->clear();
}
//清除发送区域函数
void serial::del_Send(bool)
{
    ui->lint_send->clear();
}
//定时发送函数
void serial::timer_send(bool)
{
    //timerEvent();
    QString ms = ui->lint_ms->text();
    //qDebug()<< ms;
    //按钮可用控制

    timer->start(ms.toInt());
    ui->btn_tim_push->setEnabled(false);
    ui->btn_tim_off->setEnabled(true);
}
//停止发送函数
void serial::send_stop(bool)
{
    timer->stop();
    //按钮可用控制
    ui->btn_tim_push->setEnabled(true);
    ui->btn_tim_off->setEnabled(false);
}
//定时器函数
void serial::while_send()
{
    //qDebug()<<"循环执行函数";
    QString str = ui->lint_send->text();
    global_port.write(str.toLocal8Bit());
    global_port.write("\r\n");
}

/****end*********/
