#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QQmlContext>
#include <QDir>
#include <QTime>
#include <QElapsedTimer>
#include <QQuickStyle>


#include "Frameless/TaoFrameLessView.h"
#include "QmlLog4/log4qml.h"
#include "RModulesConfig.h"
#include "Bridge.h"
#include "GlobalState.h"
#include "RProEng.h"


int main(int argc, char *argv[])
{
    QElapsedTimer debugTime;
    debugTime.start();







#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QCoreApplication::setOrganizationName("runhey");
    QCoreApplication::setOrganizationDomain("duki.cc");
    QCoreApplication::setApplicationName("dukiModel");


    Bridge bridge(&app);
    GlobalState globalState;
    //获取应用地址
    const auto appPath = QDir::cleanPath(app.applicationDirPath());
   // qDebug()<<"appPath"<<appPath;
    //qDebug()<<"workpath:"<<QDir::currentPath();
    //Log4Qml log4qml("appPath");


    QByteArray hexx("eeee");
    ROrigin *test20 = new ROrigin(RHEX,"00:22","hex", hexx);
    ROrigin *test21 = new ROrigin(RSTRING,"00:22","string","i am string");
    ROrigin *test22 = new ROrigin(RCHAR,"00:22","rchar",char('e'));
    ROrigin *test23 = new ROrigin(RUCHAR,"00:22","uchar",uchar(0xff));
    ROrigin *test24 = new ROrigin(RSHORT,"00:22","short",short('e'));
    ROrigin *test25 = new ROrigin(RUSHORT,"00:22","ushort",ushort('e'));
    ROrigin *test26 = new ROrigin(RINT,"00:22","Int",int(20));
    ROrigin *test27 = new ROrigin(RUINT,"00:22","Uint",uint(87));
    ROrigin *test28 = new ROrigin(RLONG,"00:22","long",QVariant::fromValue(long(888)));
    ROrigin *test29 = new ROrigin(RULONG,"00:22","ulong",QVariant::fromValue(ulong(444)) );
    ROrigin *test39 = new ROrigin(RFLOAT,"00:22","float",float(44.5));
    ROrigin *test30 = new ROrigin(RDOUBLE,"00:22","double",double(33.5));
    ROrigin *test31 = new ROrigin(RINT8,"00:22","qint8",qint8(8));
    ROrigin *test32 = new ROrigin(RINT16,"00:22","qint16",qint16(16));
    ROrigin *test33 = new ROrigin(RINT32,"00:22","qint32",qint32(32));
    ROrigin *test34 = new ROrigin(RINT64,"00:22","qint64",qint64(64));
    ROrigin *test35 = new ROrigin(RUINT8,"00:22","quint8",quint8(18));
    ROrigin *test36 = new ROrigin(RUINT16,"00:22","quint16",quint16(116));
    ROrigin *test37 = new ROrigin(RUINT32,"00:22","quint32",quint32(132));
    ROrigin *test38 = new ROrigin(RUINT64,"00:22","quint64",quint64(164));
    RModelManager::Instance()->originModel->addROrigin(test20);
    RModelManager::Instance()->originModel->addROrigin(test21);
    RModelManager::Instance()->originModel->addROrigin(test22);
    RModelManager::Instance()->originModel->addROrigin(test23);
    RModelManager::Instance()->originModel->addROrigin(test24);
    RModelManager::Instance()->originModel->addROrigin(test25);
    RModelManager::Instance()->originModel->addROrigin(test26);
    RModelManager::Instance()->originModel->addROrigin(test27);
    RModelManager::Instance()->originModel->addROrigin(test28);
    RModelManager::Instance()->originModel->addROrigin(test29);
    RModelManager::Instance()->originModel->addROrigin(test39);
    RModelManager::Instance()->originModel->addROrigin(test30);
    RModelManager::Instance()->originModel->addROrigin(test31);
    RModelManager::Instance()->originModel->addROrigin(test32);
    RModelManager::Instance()->originModel->addROrigin(test33);
    RModelManager::Instance()->originModel->addROrigin(test34);
    RModelManager::Instance()->originModel->addROrigin(test35);
    RModelManager::Instance()->originModel->addROrigin(test36);
    RModelManager::Instance()->originModel->addROrigin(test37);
    RModelManager::Instance()->originModel->addROrigin(test38);


    ROrigin *test50 = new ROrigin(RINT,"00:22","Int1",int(40));
    ROrigin *test51 = new ROrigin(RINT,"00:22","Int2",int(60));
    ROrigin *test52 = new ROrigin(RINT,"00:22","Int3",int(80));
    RModelManager::Instance()->originModel->addROrigin(test50);
    RModelManager::Instance()->originModel->addROrigin(test51);
    RModelManager::Instance()->originModel->addROrigin(test52);

    TaoFrameLessView view;
    view.setMinimumSize({ 800, 600 });
    view.resize(1440, 960);
    view.moveToScreenCenter();
    //上下文
    view.rootContext()->setContextProperty("globalState",&globalState);
    view.rootContext()->setContextProperty("taoQuickImagePath", TaoQuickImagePath);
    view.rootContext()->setContextProperty("view", &view);
    view.rootContext()->setContextProperty("rViewManager",bridge.rViewManager);
    view.rootContext()->setContextProperty("rModeManager",RModelManager::Instance());
    //view.rootContext()->setContextProperty("log4Qml",&log4qml);
    //导包
    view.engine()->addImportPath(TaoQuickImportPath);
    //view.engine()->addImportPath("qrc:/RControls");   //妈的这个项目的  qml模块系统整我恶心了 槽
    //view.engine()->addImportPath("qrc:/Link/");
//    for(QString path : view.engine()->importPathList())
//        qDebug() << path;

    //改存储的地方
    view.engine()->setOfflineStoragePath(appPath);


    RMODULESCONFIG_INIT;



    const QUrl url(QStringLiteral("qrc:/main.qml"));
    view.setSource(url);
    view.show();
    qInfo()<<"启动时间"<<debugTime.elapsed();
    return app.exec();
}
