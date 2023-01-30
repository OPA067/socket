#include "server.h"
#include "client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server w;
    w.resize(400,300);
    w.setWindowTitle("服务端");
    w.show();

    Client c;
    c.setWindowTitle("客户端");
    c.show();
    c.resize(400,300);
    return a.exec();
}
