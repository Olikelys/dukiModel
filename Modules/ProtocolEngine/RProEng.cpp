#include "RProEng.h"
#include "QDebug"





RProEng::RProEng(QObject *parent)
    :QObject(parent)
{
    Q_UNUSED(parent)


}
RProEng::~RProEng()
{

}



int RProEng::Read(QByteArray * qByteArrayBuffer)
{
    //qDebug()<<qByteArrayBuffer->data()<<qByteArrayBuffer;


    if(qByteArrayBuffer->size() <= 0)
    {return 10; qWarning()<<"没有数据";} //没有数据

    /*--------------------------------------数据流切分--------------------------------------------*/
    m_revbuffer.append(qByteArrayBuffer->data());//扔到内部的数据流上

    while (m_revbuffer.contains(flagheader)) {   //循环为了粘包断包
        //qDebug()<<"原来的"<<m_revbuffer.toHex();
        if(m_revbuffer.startsWith(flagheader))
        {
            //qDebug()<<"开头是标识头"<<m_revbuffer.toHex();
            m_revbuffer.remove(0,2);      //去掉标识头
            //数据类型
            datatype  = m_revbuffer.at(1);
            //qDebug()<<"数据类型"<<datatype;
            datalength = CHARTTOUINT32(m_revbuffer.constData()[2],m_revbuffer.constData()[3],m_revbuffer.constData()[4],m_revbuffer.constData()[5]);
            //qDebug()<<"数据长度"<<datalength;
            //qDebug()<<"去掉标识头hou"<<m_revbuffer.toHex();
            switch (m_revbuffer.at(0)) {
            case PUSH:{              //推送

            }break;
            case REQUEST:{            //请求

            }break;
            case REPLY:{              //

            }break;
            case KEEPALIVE:{

            }break;
            case ERRER:{

            }break;
            default:{                  //没有消息类型默认是乱帧 扔掉
                break;
            }break;
            }
        }
        else {
            m_revbuffer.remove(0,1);   //如果开头不是 标志头那就扔掉
            //qDebug()<<"开头不是标识头去掉一个字节后"<<m_revbuffer.toHex();
        }


    }

    delete  qByteArrayBuffer;

    return 0;
}
