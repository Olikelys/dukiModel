import QtQuick 2.0
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.15
import QtQuick.Layouts 1.12
import QtQml.Models 2.15

Item {
    anchors.fill: parent
    clip: true
    DropShadow
    {
        anchors.fill: cItemDropShadow
        radius: 8.0
        samples: 16
        color: "#7b40f2"
        source: cItemDropShadow
     }
    Rectangle{
        id:cItemDropShadow
        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
            margins: 10
            topMargin: 22
        }
        height: 120
        color: "#7b40f2"//"transparent"
        radius: 20
    }
    Item {
        id: cItemTextItem
        anchors.fill: cItemDropShadow
        clip: true
        GridLayout{
            id:cITI_aGridLayout
            anchors{
                left: parent.left
                leftMargin: 10
                right: parent.right
                rightMargin: 14
                top: parent.top
                topMargin: 14
            }
            Item{
                width: 60
                height: 20
            Text{
                anchors.verticalCenter: parent.verticalCenter
                text: "控件"
                font.pixelSize : 22
                font.bold: true
                color: "white"
            }}
            Image {
                width: 18
                height: 18
                Layout.alignment:Qt.AlignRight
                source: "qrc:/Images/Window/more_white.png"
            }
        }
        Rectangle{
            id:cITI_RectangleLine1
            height: 4
            anchors{
                left: parent.left
                leftMargin: 10
                right: parent.right
                rightMargin: 10
                top: cITI_aGridLayout.bottom
                topMargin: 14
            }
            radius:4
            color: "#DDDDDD"
        }
    }
    ListModel{
        id:cITI_ListModelleft
        ListElement{
            img : "qrc:/Images/Control/btu.png"
            name : "按钮"
            DragDoneShow:"待开发，感谢理解"
            type:"类型xx"
        }
        ListElement{
            img : "qrc:/Images/Control/switch.png"
            name : "开关"
            DragDoneShow:"待开发，感谢理解"
            type:"类型xx"
        }
        ListElement{
            img : "qrc:/Images/Control/slider.png"
            name : "滑块"
            DragDoneShow:"待开发，感谢理解"
            type:"类型xx"
        }
        ListElement{
            img : "qrc:/Images/Control/light.png"
            name : "灯"
            DragDoneShow:"待开发，感谢理解"
            type:"类型xx"
        }
    }
    ListModel{
        id:cITI_ListModelRight
        ListElement{
            img : "qrc:/Images/Control/image.png"
            name : "图像"
            DragDoneShow:"待开发，感谢理解"
            type:"类型xx"
        }
        ListElement{
            img : "qrc:/Images/Control/graph.png"
            name : "曲线"
            DragDoneShow:"待开发，感谢理解"
            type:"类型xx"
        }
        ListElement{
            img : "qrc:/Images/Control/waterprogress.png"
            name : "进度条"
            DragDoneShow:"待开发，感谢理解"
            type:"类型xx"
        }
        ListElement{
            img : "qrc:/Images/Control/gauge.png"
            name : "仪表"
            DragDoneShow:"待开发，感谢理解"
            type:"类型xx"
        }
    }
    Item{
        id:cITI_ListViewItemLeft
        clip: true
        anchors{
            top: cItemDropShadow.bottom
            //topMargin: 20
            left: cItemDropShadow.left
            //right: cItemDropShadow.right
            bottom: parent.bottom
        }
        width: cItemDropShadow.width/2
        ListView{
            anchors.fill: parent
            model:cITI_ListModelleft
            delegate:cITI_ListDelegateLeft
        }
    }
    Item{
        id:cITI_ListViewItemRight
        clip: true
        anchors{
            top: cItemDropShadow.bottom
            right: cItemDropShadow.right
            bottom: parent.bottom
        }
        width: cItemDropShadow.width/2
        ListView{
            anchors.fill: parent
            model:cITI_ListModelRight
            delegate:cITI_ListDelegateRight
        }
    }
    Component{
        id:cITI_ListDelegateLeft
        Item {
            id:cITILD_root
            width: cITI_ListViewItemLeft.width
            height: width

            Image {
                id: cITILD_rootImage
                anchors.centerIn: parent
                width: parent.width/2
                height: width
                source: img
                Drag.active: cITILD_rootImageMouseArea.drag.active
                Drag.dragType: Drag.Automatic//自动拖放
                Drag.supportedActions: Qt.CopyAction
                Drag.imageSource:img
                Drag.mimeData: {
                    "DragDoneShow":DragDoneShow,
                    "type":type
                }

                MouseArea{
                    id:cITILD_rootImageMouseArea
                    anchors.fill: parent
                    drag.target: parent
                }
            }
            Text {
                id: cITILD_rootText
                anchors{
                    top: cITILD_rootImage.bottom
                    horizontalCenter: parent.horizontalCenter
                }
                text: name
                color: "white"
                font.bold: true
                font.pixelSize : 18
            }

        }
    }
    Component{
        id:cITI_ListDelegateRight
        Item {
            id:cITILD_root
            width: cITI_ListViewItemRight.width
            height: width

            Image {
                id: cITILD_rootImage
                anchors.centerIn: parent
                width: parent.width/2
                height: width
                source: img
                Drag.active: cITILD_rootImageMouseArea.drag.active
                Drag.dragType: Drag.Automatic//自动拖放
                Drag.supportedActions: Qt.CopyAction
                Drag.imageSource:img
                Drag.mimeData: {
                    "DragDoneShow":DragDoneShow,
                    "type":type
                }

                MouseArea{
                    id:cITILD_rootImageMouseArea
                    anchors.fill: parent
                    drag.target: parent
                }
            }
            Text {
                id: cITILD_rootText
                anchors{
                    top: cITILD_rootImage.bottom
                    horizontalCenter: parent.horizontalCenter
                }
                text: name
                color: "white"
                font.bold: true
                font.pixelSize : 18
            }

        }
    }


}
