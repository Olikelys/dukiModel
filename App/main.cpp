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
    //QQuickStyle::setStyle("Material");

    //获取应用地址
    const auto appPath = QDir::cleanPath(app.applicationDirPath());
   // qDebug()<<"appPath"<<appPath;
    //qDebug()<<"workpath:"<<QDir::currentPath();
   // Log4Qml log4qml("appPath");

    Bridge bridge(&app);
    TaoFrameLessView view;
    view.setMinimumSize({ 800, 600 });
    view.resize(1440, 960);
    view.moveToScreenCenter();
    //上下文
    view.rootContext()->setContextProperty("taoQuickImagePath", TaoQuickImagePath);
    view.rootContext()->setContextProperty("view", &view);
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
