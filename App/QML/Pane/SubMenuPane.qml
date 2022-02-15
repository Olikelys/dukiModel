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
        DataShowView{
            visible: 3 == rootBackground.menuPaneFlag
        }





}
