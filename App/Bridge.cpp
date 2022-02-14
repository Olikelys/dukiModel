#include "Bridge.h"
#include <QDebug>




Bridge::Bridge()
{
}
Bridge::Bridge(QObject *parent)
    :QObject(parent)
{
     rProEngManager = new RProEngManager(this);
     rModelManager  = new RModelManager(this);
     rModelManager->setROriginModel(new ROriginModel);
     //下面连接各种 信号 槽


}

Bridge::~Bridge()
{
qDebug()<<"析构Bridge";
delete rProEngManager;
delete rModelManager;
}

int Bridge::ResetConnect()
{
    return 0;
}
