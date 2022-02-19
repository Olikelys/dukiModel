import QtQuick 2.0
import QtQuick.Controls 2.12
import Qt.labs.settings 1.0
import QtGraphicalEffects 1.0
import "qrc:/Link"
import "qrc:/Qml"


Item{
    clip: true
    Rectangle{
        id:sMPI_background
        opacity: 0.60
        clip: true
        anchors{
            bottom: parent.bottom
            right: parent.right
        }
        radius: 120
        width: parent.width+radius
        height: parent.height+radius// -45
        color: "#7b40f2"
      }
    Image {
        anchors{
            left: parent.left
            leftMargin: 200
            bottom: parent.bottom
        }
        sourceSize: Qt.size(500, 500)  //妈耶这个大尺寸图片太吃内存了
        opacity: 0.1
        cache: false
        source: "qrc:/Images/Window/background1.png"
    }

    DropShadow
    {
        //anchors.fill: sMPI_background
        width: main_Rect11.width+100

        radius: 8.0
        samples: 16
        color: "#dd000000"
        source: sMPI_background
     }


        RConnectManagerView{
            visible:  1 == rootBackground.menuPaneFlag
        }
        Controls{
            visible:  2 == rootBackground.menuPaneFlag
        }
        DataShowView{
            visible: 3 == rootBackground.menuPaneFlag
        }





}
