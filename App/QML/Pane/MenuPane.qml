import QtQuick 2.0
import TaoQuick 1.0
import QtQml.Models 2.12
import QtQuick.Controls 2.12
import Qt.labs.settings 1.0

Rectangle {
    id:menuPaneItem
    width: parent.width
    height: parent.height
    anchors.left: parent.left
    color: "#434343"

    Settings{
        property alias menuPaneListView_currentIndex: menuPaneListView.currentIndex
    }

    ListModel{
        id:menuPaneListModel
        //平台
        ListElement{
            name: "Platform"
            text: "平台"
            visible: true
            icon1: "qrc:/Images/Window/robot (1).png"
            icon2: "qrc:/Images/Window/robot.png"
        }
        //连接
        ListElement{
            name: "Connect"
            text: "连接"
            visible: true
            icon1: "qrc:/Images/Window/link (1).png"
            icon2: "qrc:/Images/Window/link.png"

        }
        //控件
        ListElement{
            name: "Connect"
            text: "控件"
            visible: true
            icon1: "qrc:/Images/Window/shapes (1).png"
            icon2: "qrc:/Images/Window/shapes.png"

        }
        //数据
        ListElement{
            name: "Data"
            text: "数据"
            visible: true
            icon1: "qrc:/Images/Window/server (1).png"
            icon2: "qrc:/Images/Window/server.png"

        }
        //仿真
        ListElement{
            name: "Simulation"
            text: "仿真"
            visible: true
            icon1: "qrc:/Images/Window/key (1).png"
            icon2: "qrc:/Images/Window/key.png"

        }
    }
    ListView{
        id:menuPaneListView
        width: parent.width
        anchors{
            fill: parent
        }
        model: menuPaneListModel
        delegate: menuPaneListDelegate
        currentIndex: 0

    //委托
    Component{
        id:menuPaneListDelegate
        Button{
            anchors.right: parent.right
            width:  parent.width
            height: 50
            icon.source: ListView.isCurrentItem ? model.icon1 : model.icon2
            icon.color: "transparent"
            icon.width: parent.width
            icon.height: parent.height
            background: Rectangle{
                anchors.fill: parent
                color: "transparent"
            }
            ToolTip{
                visible: parent.hovered
                delay: 800
                text: model.text
                background: Rectangle{
                    color: "#7f7f7f"
                    radius: 3
                }
            }
            onClicked:{
                menuPaneListView.currentIndex = index
                rootBackground.menuPaneFlag   = index
                //console.debug("clicked",rootBackground.menuPaneFlag)
            }
        }

    }
    }


}
