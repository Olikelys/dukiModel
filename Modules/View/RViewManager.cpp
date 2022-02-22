#include "RViewManager.h"
#include <QDir>
#include <QDebug>
#include <QJsonObject>
#include <QSettings>

RViewManager::RViewManager()
{

    m_jsonFile.setFileName(QDir::currentPath() + "/defaultView.json");
    if(!m_jsonFile.exists()){
        m_jsonFile.open(QIODevice::Text|QIODevice::ReadOnly);
        m_jsonFile.close();
    }
}




void  RViewManager::setJsonFile(QString pathAndName)
{
    if(m_jsonFile.isOpen()){
        qWarning("文件打开中无法操作");
    }
    qDebug()<<"设置窗体配置json文件为:"<<pathAndName;
    m_jsonFile.setFileName(pathAndName.remove("file:///"));

}





QVariant RViewManager::readJsonFile()
{
    if(!m_jsonFile.open(QIODevice::ReadWrite)) {
            qWarning() << "File open error";
        }
    QVariant jsonFileVal = m_jsonFile.readAll();
    m_jsonFile.close();
    return jsonFileVal;
}
bool   RViewManager::writeJsonFile(QVariant jsonString)
{
    if(!m_jsonFile.open(QIODevice::ReadWrite)) {
            qWarning() << "File open error";
        }
    m_jsonFile.resize(0);
    if(m_jsonFile.write(jsonString.toByteArray())){
        m_jsonFile.close();
        return 1;
    }
    else{
        qWarning()<<"写入文件失败";
        return 0;
    }
}
