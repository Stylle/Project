#ifndef SERIAL_H
#define SERIAL_H

#include <QMainWindow>

/*******user include**********/

//串口头
#include <QSerialPort>
#include <QSerialPortInfo>
//debug
#include <qDebug>
//定时器
#include <QTimer>
//串口号数组
#include <QList>
//消息弹窗
#include <QMessageBox>
/***********end***************/

namespace Ui {
class serial;
}

class serial : public QMainWindow
{
    Q_OBJECT

public:
    explicit serial(QWidget *parent = 0);
    ~serial();

private slots:
    //打开串口按钮函数
    void btn_open(bool);
    //搜索串口按钮函数
    void btn_search(bool);
    //发送信息按钮函数
    void btn_push_send(bool);
    //接受数据
    void accept_date();
    //清除接受
    void del_Accept(bool);
    //清除发送
    void del_Send(bool);
    //定时发送
    void timer_send(bool);
    //停止发送
    void send_stop(bool);
    //定时执行函数
    void while_send();

private:
    Ui::serial *ui;
    /***funtion****/
    //声明子函数
    void system_init();

    /***variable***/
    //声明变量
    QSerialPort global_port;
    //定时器变量
    QTimer *timer = new QTimer(this);
    //打开按钮状态
    bool flag = 0;
};

#endif // SERIAL_H
