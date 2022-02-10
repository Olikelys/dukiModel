#include "RDataEngDefault.h"
#include <QDebug>
#include "RProEng.h"
#include <QDataStream>
#include "RConnectManager.h"

RDataEngDefault::RDataEngDefault(QObject *parent)
    :RDataEngAbstract(parent)
{
    Q_UNUSED(parent)
}
RDataEngDefault::~RDataEngDefault()
{
  this->deleteLater();
}
int RDataEngDefault::UnPack(QByteArray * unPackDataBuffer)
{
    return 0;
}
int RDataEngDefault::UnPack(QByteArray * unPackDataBuffer,char datatype,quint32 datalength)
{
    quint32 unpackdatalength=0;  //这个是已近解包的数据长度
    qDebug()<<"我在解包"<<unPackDataBuffer->toHex();
    switch (datatype) {
    case RHEX :{

    }break;
    case RSTRING :{

    }break;
    /*******************************************char*********************************************/
    case RCHAR :{         //解包char
        while (unpackdatalength<datalength) {
            quint32 useOnceLength=0;
            QString * p_dataname = new QString("");
            char *dataVlaue =new char(' ');
            char &nDataVlaue = *dataVlaue;
            //qDebug()<<"现在 p_dataname:"<<*p_dataname<<"nDataVlaue:"<<nDataVlaue;
            useOnceLength=GetDataOnce<char&>(unPackDataBuffer,p_dataname,nDataVlaue);
            unpackdatalength +=useOnceLength;
            unPackDataBuffer->remove(0,useOnceLength);
            //qDebug()<<"解包所花费的长度"<<unpackdatalength;
            //qDebug()<<"解后 p_dataname:"<<*p_dataname<<"nDataVlaue:"<<nDataVlaue;
        }

    }break;
    /*******************************************uchar*********************************************/
    case RUCHAR :{
        while (unpackdatalength<datalength) {
            quint32 useOnceLength=0;
            QString * p_dataname = new QString("");
            uchar *dataVlaue =new uchar(' ');
            uchar &nDataVlaue = *dataVlaue;
            //qDebug()<<"现在 p_dataname:"<<*p_dataname<<"nDataVlaue:"<<nDataVlaue;
            useOnceLength=GetDataOnce<uchar&>(unPackDataBuffer,p_dataname,nDataVlaue);
            unpackdatalength +=useOnceLength;
            unPackDataBuffer->remove(0,useOnceLength);
            //qDebug()<<"解包所花费的长度"<<unpackdatalength;
            //qDebug()<<"解后 p_dataname:"<<*p_dataname<<"nDataVlaue:"<<nDataVlaue;
        }

    }break;
    case RSHORT :{

    }break;
    case RUSHORT :{

    }break;
    case RINT :{
        while (unpackdatalength<datalength) {
        quint32 useOnceLength=0;
        QString * p_dataname = new QString("");
        int *dataVlaue =new int(' ');
        int &nDataVlaue = *dataVlaue;
        useOnceLength=GetDataOnce<int&>(unPackDataBuffer,p_dataname,nDataVlaue);
        unpackdatalength +=useOnceLength;
        unPackDataBuffer->remove(0,useOnceLength);
        //qDebug()<<"解后 p_dataname:"<<*p_dataname<<"nDataVlaue:"<<nDataVlaue;
        }
    }break;
    case RUINT :{

    }break;
    case RLONG :{

    }break;
    case RULONG :{

    }break;
    case RFLOART :{/************************************    float    ****************************************************************/
        while (unpackdatalength<datalength) {
        quint32 useOnceLength=0;
        QString * p_dataname = new QString("");
        float *dataVlaue =new float(' ');
        float &nDataVlaue = *dataVlaue;
        useOnceLength=GetDataOnce(unPackDataBuffer,p_dataname,nDataVlaue);
        unpackdatalength +=useOnceLength;
        qDebug()<<"解后 p_dataname:"<<*p_dataname<<"nDataVlaue:"<<nDataVlaue;
        }

    }break;
    case RDOUBLE :{

    }break;
    case RINT8 :{/************************************    int8    ****************************************************************/
        while (unpackdatalength<datalength) {
        quint32 useOnceLength=0;
        QString * p_dataname = new QString("");
        qint8 *dataVlaue =new qint8(' ');
        qint8 &nDataVlaue = *dataVlaue;
        useOnceLength=GetDataOnce(unPackDataBuffer,p_dataname,nDataVlaue);
        unpackdatalength +=useOnceLength;
        }
    }break;
    case RINT16 :{/************************************    int16    ****************************************************************/

    }break;
    case RINT32 :{
        while (unpackdatalength<datalength) {
        quint32 useOnceLength=0;
        QString * p_dataname = new QString("");
        quint32 *dataVlaue =new quint32(' ');
        quint32 &nDataVlaue = *dataVlaue;
        useOnceLength=GetDataOnce(unPackDataBuffer,p_dataname,nDataVlaue);
        unpackdatalength +=useOnceLength;

        //qDebug()<<"解后 p_dataname:"<<*p_dataname<<"nDataVlaue:"<<nDataVlaue;
        //qDebug()<<"解包所花费的长度"<<unpackdatalength;
        }
    }break;
    case RINT64 :{

    }break;
    case RUINT8 :{

    }break;
    case RUINT16 :{

    }break;
    case RUINT32 :{

    }break;
    case RUINT64 :{

    }break;
    default:{
        qWarning()<<"RDataEngDefault解析:没有这个数据类型";
    }

    }

    return 0;
}
QByteArray * RDataEngDefault::Pack(QByteArray * PackDataBuffer)
{
    return nullptr;
}


/**
*   解包一次
*
*
*/
int RDataEngDefault::GetDataOnce(QByteArray* packDataBuffer, \
                                 char dataType, \
                                 QString* variableName, \
                                 char* variableValue)
{
    return 0;
}
/**
*
*
*
**/
template< typename T>
quint32 RDataEngDefault::GetDataOnce(QByteArray* packDataBuffer, \
                                 QString* variableName, \
                                 T(&variableValue))
{
//    bool isVariableName=true;
    quint32 stringLength=0; //这次解包 花费了多少长度
//    for(int i=0;i<=packDataBuffer->size();i++)
//    {
//        qDebug()<<"i"<<i<<"值"<<packDataBuffer->constData()[i];
//        if(packDataBuffer->constData()[i]!=':' && isVariableName )
//        {
//            variableName->append(packDataBuffer->constData()[i]);
//        }
//        else if(packDataBuffer->constData()[i] ==':' && isVariableName)
//        {
//            isVariableName=false;
//        }
//        else{
//            variableValue =packDataBuffer->constData()[i];
//            uselength = (i+1);
//            break;
//        }
//    }
    QDataStream  dataOnce(*packDataBuffer);
    dataOnce.setVersion(QDataStream::Qt_5_15);
    //dataOnce>>*variableName>>variableValue;

    return stringLength;
}
/********************************                             *********************************************************************************/
/********************************--          float--       ---*********************************************************************************/
/********************************                             *********************************************************************************/
quint32 RDataEngDefault::GetDataOnce(QByteArray* packDataBuffer, QString* variableName, float & variableValue)
{
    quint32 stringLength;
    bool isVariableName=true;
    for(int i=0;i<=packDataBuffer->size();i++)
    {
        if(packDataBuffer->constData()[i]!=',' && isVariableName )
        {
            variableName->append(packDataBuffer->constData()[i]);
        }
        else if(packDataBuffer->constData()[i] ==',' && isVariableName)
        {
            isVariableName=false;
        }
        else{
            stringLength =i;
            packDataBuffer->remove(0,stringLength);
            char* v_p  = (char*)&variableValue;
            *(v_p + 0) = packDataBuffer->constData()[3];
            *(v_p + 1) = packDataBuffer->constData()[2];
            *(v_p + 2) = packDataBuffer->constData()[1];
            *(v_p + 3) = packDataBuffer->constData()[0];
            packDataBuffer->remove(0,4);
            break;
        }
    }
    return (  (quint32)4 + stringLength );
}




quint32 RDataEngDefault::GetDataOnce(QByteArray* packDataBuffer, \
                                     QString* variableName, \
                                     qint8& variableValue)
{

    quint32 stringLength;
    bool isVariableName=true;
    for(int i=0;i<=packDataBuffer->size();i++)
    {
        if(packDataBuffer->constData()[i]!=',' && isVariableName )
        {
            variableName->append(packDataBuffer->constData()[i]);
        }
        else if(packDataBuffer->constData()[i] ==',' && isVariableName)
        {
            isVariableName=false;
        }
        else{
            stringLength =i;
            packDataBuffer->remove(0,stringLength);
            variableValue = packDataBuffer->constData()[0];
            packDataBuffer->remove(0,1);
            break;
        }
    }
    return (  (quint32)4 + stringLength );
}
quint32 RDataEngDefault::GetDataOnce(QByteArray* packDataBuffer, \
                                     QString* variableName, \
                                     quint8& variableValue)
{

    quint32 stringLength;
    bool isVariableName=true;
    for(int i=0;i<=packDataBuffer->size();i++)
    {
        if(packDataBuffer->constData()[i]!=',' && isVariableName )
        {
            variableName->append(packDataBuffer->constData()[i]);
        }
        else if(packDataBuffer->constData()[i] ==',' && isVariableName)
        {
            isVariableName=false;
        }
        else{
            stringLength =i;
            packDataBuffer->remove(0,stringLength);
            variableValue = packDataBuffer->constData()[0];
            packDataBuffer->remove(0,1);
            break;
        }
    }
    return (  (quint32)4 + stringLength );
}
quint32 RDataEngDefault::GetDataOnce(QByteArray* packDataBuffer, \
                                     QString* variableName, \
                                     qint32& variableValue)
{

    quint32 stringLength;
    bool isVariableName=true;
    for(int i=0;i<=packDataBuffer->size();i++)
    {
        if(packDataBuffer->constData()[i]!=',' && isVariableName )
        {
            variableName->append(packDataBuffer->constData()[i]);
        }
        else if(packDataBuffer->constData()[i] ==',' && isVariableName)
        {
            isVariableName=false;
        }
        else{
            stringLength =i;
            packDataBuffer->remove(0,stringLength);
            variableValue = BYTETO32(packDataBuffer->constData()[0],packDataBuffer->constData()[1],packDataBuffer->constData()[2],packDataBuffer->constData()[3]);
            packDataBuffer->remove(0,4);
            break;
        }
    }
    return (  (quint32)4 + stringLength );
}
quint32 RDataEngDefault::GetDataOnce(QByteArray* packDataBuffer, \
                                     QString* variableName, \
                                     quint32& variableValue)
{

    quint32 stringLength;
    bool isVariableName=true;
    for(int i=0;i<=packDataBuffer->size();i++)
    {
        if(packDataBuffer->constData()[i]!=',' && isVariableName )
        {
            variableName->append(packDataBuffer->constData()[i]);
        }
        else if(packDataBuffer->constData()[i] ==',' && isVariableName)
        {
            isVariableName=false;
        }
        else{
            stringLength =i;
            packDataBuffer->remove(0,stringLength);
            variableValue = BYTETO32(packDataBuffer->constData()[0],packDataBuffer->constData()[1],packDataBuffer->constData()[2],packDataBuffer->constData()[3]);
            packDataBuffer->remove(0,4);
            break;
        }
    }
    return (  (quint32)4 + stringLength );
}
