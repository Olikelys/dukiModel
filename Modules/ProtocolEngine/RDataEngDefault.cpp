#include "RDataEngDefault.h"
#include <QDebug>
#include <QTime>
#include "RProEng.h"
#include <QDataStream>
#include "RConnectManager.h"
#include "RConnectManager.h"
#include "ByteToVariant/ByteToVariant.h"

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
    quint32 unPackedLength=0;  //这个是已近解包的数据长度
    QString rCurrentTime = QTime::currentTime().toString("hh:mm:ss.zzz");
    qDebug()<<"我在解包"<<unPackDataBuffer->toHex();
    while (unPackedLength<datalength) {
        quint32 OnceLength=0;  //每次解一组的长度
        bool currentIsName=true;  //现在这个 i是name
        QByteArray OnceName = "";
        QVariant OnceVal ;
        for(int i=0;i<=unPackDataBuffer->size();i++)
        {
            if(unPackDataBuffer->constData()[i]!=',' && currentIsName )//现在是名字
            {
                OnceName.append(unPackDataBuffer->constData()[i]);
            }
            else if(unPackDataBuffer->constData()[i] ==',' && currentIsName)
            {
                currentIsName=false;
            }
            else{
                OnceLength =i;
                unPackDataBuffer->remove(0,i);
                //qDebug()<<"取出名字后的缓存"<<unPackDataBuffer->toHex()<<"name"<<OnceName;
                switch (datatype) {
                case RHEX:{  /*************************************  hex  **************************************************************************************/
                     QByteArray tempHex =  QByteArray( unPackDataBuffer->data() ,datalength-OnceLength-1);
                     unPackDataBuffer->remove(0,datalength-OnceLength);
                     //qDebug()<<"hex"<<tempHex.toHex()<<unPackDataBuffer[1].toHex();
                     OnceVal = (QByteArray)tempHex;

                     OnceLength = datalength;
                }break;
                case RSTRING:{ /*************************************  string  **************************************************************************************/
                    QString tempString =  (QString)QByteArray( unPackDataBuffer->data() ,datalength-OnceLength-1);
                    //qDebug()<<"string"<<tempString;
                    unPackDataBuffer->remove(0,datalength-OnceLength);
                    OnceVal = (QString)tempString;
                    OnceLength = datalength;
                }break;
                case RCHAR:{  /*************************************  char   **************************************************************************************/
                    char tempChar = unPackDataBuffer->constData()[0];
                    OnceVal = (char)tempChar;
                    unPackDataBuffer->remove(0,1);
                    //qDebug()<<"取出 值 后的缓存"<<unPackDataBuffer->toHex();
                    OnceLength +=1;
                }break;
                case RUCHAR:{ /*************************************  uchar   **************************************************************************************/
                    uchar tempChar =  unPackDataBuffer->constData()[0];
                    OnceVal = (uchar)tempChar;
                    unPackDataBuffer->remove(0,1);
                    OnceLength +=1;
                }break;
                case RSHORT:{ /*************************************  short   **************************************************************************************/
                    short tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    OnceVal = (short)tempChar;
                    unPackDataBuffer->remove(0,2);
                    OnceLength +=2;
                }break;
                case RUSHORT:{ /*************************************  ushort   **************************************************************************************/
                    ushort tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    OnceVal = (ushort)tempChar;
                    unPackDataBuffer->remove(0,2);
                    OnceLength +=2;
                    short uu =858;
                    qDebug()<<"uu"<<QByteArray::number(uu).toHex()<<QByteArray::number(uu).size();
                }break;
                case RINT:{  /*************************************  int  **************************************************************************************/
                    int tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    *(p+2) =    unPackDataBuffer->constData()[2];
                    *(p+3) =    unPackDataBuffer->constData()[3];
                    OnceVal = (int)tempChar;
                    unPackDataBuffer->remove(0,4);
                    OnceLength +=4;
                }break;
                case RUINT:{ /*************************************  uint  **************************************************************************************/
                    uint tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    *(p+2) =    unPackDataBuffer->constData()[2];
                    *(p+3) =    unPackDataBuffer->constData()[3];
                    OnceVal = (uint)tempChar;
                    unPackDataBuffer->remove(0,4);
                    OnceLength +=4;
                }break;
                case RLONG:{ /*************************************  long  **************************************************************************************/
                    long tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    *(p+2) =    unPackDataBuffer->constData()[2];
                    *(p+3) =    unPackDataBuffer->constData()[3];
                    OnceVal = QVariant::fromValue((long)tempChar);
                    unPackDataBuffer->remove(0,4);
                    OnceLength +=4;
                }break;
                case RULONG:{/*************************************  ulong  **************************************************************************************/
                    ulong tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    *(p+2) =    unPackDataBuffer->constData()[2];
                    *(p+3) =    unPackDataBuffer->constData()[3];
                    OnceVal = QVariant::fromValue((ulong)tempChar);
                    unPackDataBuffer->remove(0,4);
                    OnceLength +=4;


                }break;
                case RFLOAT:{ /*************************************  float  **************************************************************************************/
                    float tempFloat;
                    char* v_p  = (char*)&tempFloat;
                    *(v_p + 0) = unPackDataBuffer->constData()[0];
                    *(v_p + 1) = unPackDataBuffer->constData()[1];
                    *(v_p + 2) = unPackDataBuffer->constData()[2];
                    *(v_p + 3) = unPackDataBuffer->constData()[3];
                    OnceVal = tempFloat;
                    unPackDataBuffer->remove(0,4);
                    OnceLength +=4;
                }break;
                case RDOUBLE:{ /*************************************  double  **************************************************************************************/
                    double tempFloat;
                    char* v_p  = (char*)&tempFloat;
                    *(v_p + 0) = unPackDataBuffer->constData()[0];
                    *(v_p + 1) = unPackDataBuffer->constData()[1];
                    *(v_p + 2) = unPackDataBuffer->constData()[2];
                    *(v_p + 3) = unPackDataBuffer->constData()[3];
                    *(v_p + 4) = unPackDataBuffer->constData()[4];
                    *(v_p + 5) = unPackDataBuffer->constData()[5];
                    *(v_p + 6) = unPackDataBuffer->constData()[6];
                    *(v_p + 7) = unPackDataBuffer->constData()[7];
                    OnceVal = (double)tempFloat;
                    unPackDataBuffer->remove(0,8);
                    OnceLength +=8;
                }break;
                case RINT8:{ /*************************************  int8  **************************************************************************************/
                    qint8 tempChar = unPackDataBuffer->constData()[0];
                    OnceVal = (qint8)tempChar;
                    unPackDataBuffer->remove(0,1);
                    OnceLength +=1;
                }break;
                case RINT16:{ /*************************************  int16  **************************************************************************************/
                    qint16 tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    OnceVal = (qint16)tempChar;
                    unPackDataBuffer->remove(0,2);
                    OnceLength +=2;
                }break;
                case RINT32:{ /*************************************  int32  **************************************************************************************/
                    qint32 tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    *(p+2) =    unPackDataBuffer->constData()[2];
                    *(p+3) =    unPackDataBuffer->constData()[3];
                    OnceVal = (qint32)tempChar;
                    unPackDataBuffer->remove(0,4);
                    OnceLength +=4;
                }break;
                case RINT64:{ /*************************************  int64  **************************************************************************************/
                    qint64 tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    *(p+2) =    unPackDataBuffer->constData()[2];
                    *(p+3) =    unPackDataBuffer->constData()[3];
                    *(p+4) =    unPackDataBuffer->constData()[4];
                    *(p+5) =    unPackDataBuffer->constData()[5];
                    *(p+6) =    unPackDataBuffer->constData()[6];
                    *(p+7) =    unPackDataBuffer->constData()[7];
                    OnceVal = (qint64)tempChar;
                    unPackDataBuffer->remove(0,8);
                    OnceLength +=8;
                }break;
                case RUINT8:{ /*************************************  uint8  **************************************************************************************/
                    quint8 tempChar = unPackDataBuffer->constData()[0];
                    OnceVal = (quint8)tempChar;
                    unPackDataBuffer->remove(0,1);
                    OnceLength +=1;
                }break;
                case RUINT16:{ /*************************************  uint16  **************************************************************************************/
                    quint16 tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    OnceVal = (quint16)tempChar;
                    unPackDataBuffer->remove(0,2);
                    OnceLength +=2;
                }break;
                case RUINT32:{ /*************************************  uint32  **************************************************************************************/
                    quint32 tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    *(p+2) =    unPackDataBuffer->constData()[2];
                    *(p+3) =    unPackDataBuffer->constData()[3];
                    OnceVal = (quint32)tempChar;
                    unPackDataBuffer->remove(0,4);
                    OnceLength +=4;
                }break;
                case RUINT64:{ /*************************************  uin64  **************************************************************************************/
                    quint64 tempChar ;  char * p = (char *)& tempChar;
                    *(p+0) =    unPackDataBuffer->constData()[0];
                    *(p+1) =    unPackDataBuffer->constData()[1];
                    *(p+2) =    unPackDataBuffer->constData()[2];
                    *(p+3) =    unPackDataBuffer->constData()[3];
                    *(p+4) =    unPackDataBuffer->constData()[4];
                    *(p+5) =    unPackDataBuffer->constData()[5];
                    *(p+6) =    unPackDataBuffer->constData()[6];
                    *(p+7) =    unPackDataBuffer->constData()[7];
                    OnceVal = (quint64)tempChar;
                    unPackDataBuffer->remove(0,8);
                    OnceLength +=8;
                }break;

                default:{
                    qWarning()<<"没有这个数据类型";
                }
                }
                currentIsName =true;
                break;
            }
        }
        unPackedLength+=OnceLength;
        qDebug()<<"while循环里面"<<"类型"<<datatype<<"名字"<<QString(OnceName)<<"值"<<OnceVal<<"长度"<<OnceLength;
        ROrigin *tempOrigin = new ROrigin(datatype,rCurrentTime,QString(OnceName),OnceVal);
        emit RProEngManager::Instance()->m_RDataEngDefault->sigROriginModel_unPackROrigin(tempOrigin);
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
//template< typename T>
//quint32 RDataEngDefault::GetDataOnce(QByteArray* packDataBuffer, \
//                                 QString* variableName, \
//                                 T(&variableValue))
//{
////    bool isVariableName=true;
//    quint32 stringLength=0; //这次解包 花费了多少长度
////    for(int i=0;i<=packDataBuffer->size();i++)
////    {
////        qDebug()<<"i"<<i<<"值"<<packDataBuffer->constData()[i];
////        if(packDataBuffer->constData()[i]!=':' && isVariableName )
////        {
////            variableName->append(packDataBuffer->constData()[i]);
////        }
////        else if(packDataBuffer->constData()[i] ==':' && isVariableName)
////        {
////            isVariableName=false;
////        }
////        else{
////            variableValue =packDataBuffer->constData()[i];
////            uselength = (i+1);
////            break;
////        }
////    }
//    QDataStream  dataOnce(*packDataBuffer);
//    dataOnce.setVersion(QDataStream::Qt_5_15);
//    //dataOnce>>*variableName>>variableValue;

//    return stringLength;
//}
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

quint32 RDataEngDefault::DealWithOnce_NameVal(QByteArray* packDataBuffer,ROrigin *temrorigin)
{
    quint32 stringLength;
    bool isVariableName=true;
    quint8 temptype = temrorigin->htype();
    QString tempname = "";

    switch (temptype) {
    case RINT8:{

    }break;
    default:{
        qWarning()<<"处理一次数据 失败";
    }

    }

}
