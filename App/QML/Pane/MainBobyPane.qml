import QtQuick 2.0
import QtQuick.Controls 2.12
import TaoQuick 1.0
import QtQuick.Shapes 1.15
import QtGraphicalEffects 1.15
import "qrc:/Qml"
import "qrc:/Controls"



Item {
    id:mainBobyPane
    Rectangle{
        id:mBPI_Rectangel
        anchors.fill: parent
        radius: 20
    }
    DropShadow
    {
        anchors.fill: mBPI_Rectangel
        radius: 8.0
        samples: 16
        color: "#dd000000"
        source: mBPI_Rectangel
     }
    Image {
        id: mBPbgimg
        anchors.centerIn: parent
        source: "qrc:/Images/logo/logo-redblue-512.png"
        width: parent.width<parent.height ? parent.width/3 : parent.height/3
        height: width
        opacity: 0.08
    }
    //拖拽区域
    DropArea{
        anchors.fill: parent
        //进入
        onEntered: {
        }
        onDropped: {
            //拷贝
            if(drop.proposedAction == Qt.CopyAction){
                drop.acceptProposedAction()
                snackbar.open(drop.getDataAsString("DragDoneShow"))
                //snackbar.open("拖拽完成"+drop.x+drop.y+drop.getDataAsString("DragDoneShow")+drop.getDataAsString("type"))
                //new 一个新的对象
                //var obj =Qt.createComponent(contentsPath+drop.getDataAsString("ual")).createObject(platformBobyItem,{"x":drop.x,"y":drop.y});
            }

        }
    }


    ResizableRectangle{

    }
    RWavyProgress{

    }



}
