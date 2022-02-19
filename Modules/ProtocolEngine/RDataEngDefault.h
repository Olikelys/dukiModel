#ifndef RDATAENGDEFAULT_H
#define RDATAENGDEFAULT_H

#include "RDataEngAbstract.h"
#include "ROrigin.h"



class RDataEngDefault :public RDataEngAbstract
{
    Q_OBJECT
public:
    explicit RDataEngDefault(QObject *parent = nullptr);
    ~RDataEngDefault();

    virtual int UnPack(QByteArray * unPackDataBuffer);
            int UnPack(QByteArray * unPackDataBuffer,char datatype,quint32 datalength);
    virtual QByteArray* Pack(QByteArray* packDataBuffer);

signals:
    void sigROriginModel_unPackROrigin(ROrigin *rrrorigin);  //跨线程还是得用信号

    //解压一次 获取一组数据的值  第一个是输入地址 第三个是变量名 第四个是..

public:
/*****************************宝宝问我为什么不用函数模板，爹爹也想啊QDataStram会和模板函数起冲突**************************************************************/
    int     GetDataOnce(QByteArray* packDataBuffer, char dataType, QString* variableName, char* variableValue);
//    template< typename T>
//    quint32 GetDataOnce(QByteArray* packDataBuffer, QString* variableName, T(& variableValue));


    quint32 GetDataOnce(QByteArray* packDataBuffer, QString* variableName, float &variableValue);



    quint32 GetDataOnce(QByteArray* packDataBuffer, QString* variableName, qint8& variableValue);
    quint32 GetDataOnce(QByteArray* packDataBuffer, QString* variableName, quint8& variableValue);
    quint32 GetDataOnce(QByteArray* packDataBuffer, QString* variableName, qint32& variableValue);
    quint32 GetDataOnce(QByteArray* packDataBuffer, QString* variableName, quint32& variableValue);


    quint32 DealWithOnce_NameVal(QByteArray* packDataBuffer,ROrigin *temrorigin);

};



#endif // RDATAENGDEFAULT_H
