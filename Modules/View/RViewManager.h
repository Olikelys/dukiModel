#ifndef RVIEWMANAGER_H
#define RVIEWMANAGER_H


#include <QObject>
#include <QJsonDocument>
#include <QFile>


class RViewManager : public QObject
{
    Q_OBJECT
public:
    explicit RViewManager();

    Q_INVOKABLE QVariant readJsonFile();  //传到qml是字符串，需要解析
    Q_INVOKABLE bool   writeJsonFile(QVariant jsonString); //qml 端直接stringify转成字符串
    Q_INVOKABLE void  setJsonFile( QString pathAndName);
private:
    QFile m_jsonFile;
};





















#endif // RVIEWMANAGER_H
