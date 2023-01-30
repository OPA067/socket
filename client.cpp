#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    //设置当前IP地址和端口号
    ui->ip->setText("127.0.0.1");
    ui->port->setText(QString::number(6666)); // 强制转化成字符串类型显示在QLineEdit
    client=new QTcpSocket(this);            //创建一个套接字client
    //连接服务器
    client->connectToHost(ui->ip->text(),ui->port->text().toInt());//转化为int数据类型
    connect(ui->sendBtn,&QPushButton::clicked,[=](){
        QString msg = ui->msgEdit->toPlainText();
        client->write(msg.toUtf8());
        ui->record->append("我发送的数据: "+ msg);
    });
    //客户端接收数据
    connect(client,&QTcpSocket::readyRead,[=](){
        QByteArray array = client->readAll();
        ui->record->append("服务器端发送的数据: "+array);
    });
}

Client::~Client()
{
    delete ui;
}
