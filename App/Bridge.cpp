#include "Bridge.h"
#include <QDebug>




Bridge::Bridge()
{
}
Bridge::Bridge(QObject *parent)
    :QObject(parent)
{
     rProEngManager = new RProEngManager(this);
    //下面连接各种 信号 槽

}

Bridge::~Bridge()
{
qDebug()<<"析构Bridge";
}

int Bridge::ResetConnect()
{
    return 0;
}
