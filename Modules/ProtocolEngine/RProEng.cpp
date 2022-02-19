#include "RProEng.h"
#include "QDebug"
#include <QTime>
#include "GlobalState.h"

RDataEngDefault * m_rDataEngDefault;


RProEng::RProEng(QObject *parent)
    :QObject(parent)
{
    Q_UNUSED(parent)


}
RProEng::~RProEng()
{
  this->deleteLater();
}



int RProEng::Read(QByteArray * qByteArrayBuffer)
{
    //qDebug()<<"串口接收的数据"<<qByteArrayBuffer->toHex();


    if(qByteArrayBuffer->size() <= 0)
    { qWarning()<<"没有数据";return 10;} //没有数据

    /*--------------------------------------数据流切分--------------------------------------------*/
    m_revbuffer.append(qByteArrayBuffer->data(),qByteArrayBuffer->size());//扔到内部的数据流上
    //qDebug()<<"m_revbuffer加入后面"<<m_revbuffer.toHex();
    while (m_revbuffer.contains(flagheader)) {   //循环为了粘包断包
        //qDebug()<<"原来的"<<m_revbuffer.toHex();
        if(m_revbuffer.startsWith(flagheader))
        {
            //qDebug()<<"开头是标识头"<<m_revbuffer.toHex();
            m_revbuffer.remove(0,2);      //去掉标识头
            //qDebug()<<"去掉标识头hou"<<m_revbuffer.toHex();
            //消息类型
            messagetype = m_revbuffer.at(0);
            //数据类型
            datatype  = m_revbuffer.at(1);
            //qDebug()<<"数据类型"<<datatype;
            datalength = CHARTTOUINT32(m_revbuffer.constData()[2],m_revbuffer.constData()[3],m_revbuffer.constData()[4],m_revbuffer.constData()[5]);
            //qDebug()<<"数据长度"<<datalength;
            if((uint)m_revbuffer.size() < (datalength+6))  //如果实际长度小于帧的所告诉的长度 等待下一次数据来再来判断
            {   qWarning()<<"实际数据少"<<m_revbuffer.toHex();
                break;
            }
            m_revbuffer.remove(0,6);
            //判断本次消息类型
            switch (messagetype) {
            case PUSH:{              //推送
                 m_rDataEngDefault->UnPack(&m_revbuffer,datatype,datalength);
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

            GlobalState::Instace()->AddOnceMessage();


            //qDebug()<<"解析一帧后数据"<<m_revbuffer.toHex();
        }
        else {
            m_revbuffer.remove(0,1);   //如果开头不是 标志头那就扔掉
            //qDebug()<<"开头不是标识头去掉一个字节后"<<m_revbuffer.toHex();
        }



    }
    //qDebug()<<"while循环完后m_revbuffer缓存区"<<m_revbuffer.toHex();

    delete  qByteArrayBuffer;
    //qDebug()<<"删除qByteArrayBuffer后m_revbuffer缓存区"<<m_revbuffer.toHex();

    return 0;
}
