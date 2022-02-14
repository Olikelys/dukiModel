import QtQuick 2.0
import QtQuick.Controls 2.12
Item {
    width: statusPane.width
    //color: "#e9e7ef"
    //radius:10


    Rectangle{
        anchors{
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }
        width: parent.width -40
        height: parent.height+20
        radius: 20
    }

    Row{
        anchors.centerIn: parent
        Rectangle{
            width: 150
            height: 30
            color: "#A8CD98"
            Text {
                id: itemRunTime
                anchors.centerIn: parent
                text:"工作时间:"+globalState.runTime
            }
            radius: 8
        }
        Rectangle{
            width: 150
            height: 30
            color: "#A8CD98"
            Text {
                anchors.centerIn: parent
                text:"连接时间:"+globalState.linkTime
            }
            radius: 8
        }
        Rectangle{
            width: 150
            height: 30
            Text {
                anchors.centerIn: parent
                text:"消息总数:"+globalState.totalMessageNumber
            }
            radius: 8
        }
        Rectangle{
            width: 150
            height: 30
            color: "#A8CD98"
            Text {
                anchors.centerIn: parent
                text:"消息fps:"+globalState.messageFps
            }
            radius: 8
        }
        Rectangle{
            width: 150
            height: 30
            color: "#A8CD98"
            Text {
                anchors.centerIn: parent
                text:"图像总数:"+globalState.totalImageNumber
            }
            radius: 8
        }
        Rectangle{
            width: 150
            height: 30
            color: "#A8CD98"
            Text {
                anchors.centerIn: parent
                text:"图像fps:"+globalState.imageFps
            }
            radius: 8
        }


    }

}
