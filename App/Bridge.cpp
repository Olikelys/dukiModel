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

     //这个是解析出一组数据后扔到 模型
     connect(rProEngManager->m_RDataEngDefault,\
             SIGNAL( sigROriginModel_unPackROrigin(ROrigin *) ),\
             rModelManager->rOriginModel(),\
             SLOT(   ROriginModel_unPackROrigin(ROrigin *) ));


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
