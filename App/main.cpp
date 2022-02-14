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

    GlobalState globalState;
    Bridge bridge(&app);
    //获取应用地址
    const auto appPath = QDir::cleanPath(app.applicationDirPath());
   // qDebug()<<"appPath"<<appPath;
    //qDebug()<<"workpath:"<<QDir::currentPath();
   // Log4Qml log4qml("appPath");



    ROrigin * tset1 = new ROrigin();
    ROrigin * tset2 = new ROrigin("int","I nodw ","value");
    ROrigin * tset3 = new ROrigin();
    ROrigin * tset4 = new ROrigin();
    ROrigin * tset5 = new ROrigin();
    ROrigin * tset6 = new ROrigin();
    ROrigin * tset7 = new ROrigin();
    ROrigin * tset8 = new ROrigin();
    ROrigin * tset9 = new ROrigin();
    ROrigin * tset10 = new ROrigin();
    ROrigin * tset11 = new ROrigin();
    ROrigin * tset12 = new ROrigin();
    ROrigin * tset13 = new ROrigin();
    ROrigin * tset14 = new ROrigin();
    ROrigin * tset15 = new ROrigin();


    RModelManager::Instance()->originModel->addROrigin(tset1);
    RModelManager::Instance()->originModel->addROrigin(tset2);
    RModelManager::Instance()->originModel->addROrigin(tset3);
    RModelManager::Instance()->originModel->addROrigin(tset4);
    RModelManager::Instance()->originModel->addROrigin(tset5);
    RModelManager::Instance()->originModel->addROrigin(tset6);
    RModelManager::Instance()->originModel->addROrigin(tset7);
    RModelManager::Instance()->originModel->addROrigin(tset8);
    RModelManager::Instance()->originModel->addROrigin(tset9);
    RModelManager::Instance()->originModel->addROrigin(tset10);
    RModelManager::Instance()->originModel->addROrigin(tset11);
    RModelManager::Instance()->originModel->addROrigin(tset12);
    RModelManager::Instance()->originModel->addROrigin(tset13);
    RModelManager::Instance()->originModel->addROrigin(tset14);
    RModelManager::Instance()->originModel->addROrigin(tset15);


    TaoFrameLessView view;
    view.setMinimumSize({ 800, 600 });
    view.resize(1440, 960);
    //view.setColor(QColor(Qt::transparent));
    view.moveToScreenCenter();
    //上下文
    view.rootContext()->setContextProperty("globalState",&globalState);
    view.rootContext()->setContextProperty("taoQuickImagePath", TaoQuickImagePath);
    view.rootContext()->setContextProperty("view", &view);
    view.rootContext()->setContextProperty("rModeManager",RModelManager::Instance());
    //view.rootContext()->setContextProperty("log4Qml",&log4qml);
    //导包
    view.engine()->addImportPath(TaoQuickImportPath);
    view.engine()->addImportPath("qrc:/Link/");
    //改存储的地方
    view.engine()->setOfflineStoragePath(appPath);


    RMODULESCONFIG_INIT;



    const QUrl url(QStringLiteral("qrc:/main.qml"));
    view.setSource(url);
    view.show();
    qInfo()<<"启动时间"<<debugTime.elapsed();
    return app.exec();
}
