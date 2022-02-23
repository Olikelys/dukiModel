import QtQuick 2.12
import QtQuick.Controls 2.2
import TaoQuick 1.0



Item {
    //color: "#cccccc"
    //color: "#C696F2"
    //左边的 排列
        Image {
            id:rIcon
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height-20
            width: height
            source: "qrc:/Images/logo/logo-redblue-128.ico"
        }
        Text {
            id: t
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: rIcon.right
            anchors.leftMargin: 2
            font.pixelSize: 26
            font.bold: true  //加粗
            text: "dukiModel"
            color: "#000000"
        }


        //来实现拖动窗口的矩形
        property alias blankItem: blankItem
        Item {
            id: blankItem
            objectName: "blankItem"
            anchors {
                left: parent.left
                leftMargin: 4
                right: controlButtons.left
                top: parent.top
                bottom: parent.bottom
            }
            Component.onCompleted: {
                view.setTitleItem(blankItem)
            }
            MoveArea {
                anchors.fill: parent
                onMove: {
                    view.x += xOffset
                    view.y += yOffset
                }
            }

        }


    //右边的
    property bool isMaxed: view.isMax
    Row {
        id: controlButtons
        objectName: "controlButtonsRow"
        height: parent.height
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 26
        spacing: 20
        CusButton_Image {
            anchors.verticalCenter: parent.verticalCenter
            ToolTip{
                visible: parent.hovered
                delay: 800
                text: "文档"
                background: Rectangle{
                    color: "#7f7f7f"
                    radius: 3
                }
            }
            btnImgUrl: "qrc:/Images/Window/help.png"
            property string urlName: "http://duki.cc"
            onClicked: {
                Qt.openUrlExternally(urlName)
            }
        }
        //最小
        CusButton_Image {
            anchors.verticalCenter: parent.verticalCenter
            btnImgUrl: "qrc:/Images/Window/window-minimize.png"
            ToolTip{
                visible: parent.hovered
                delay: 800
                text: "最小"
                background: Rectangle{
                    color: "#7f7f7f"
                    radius: 3
                }
            }
            onClicked: {
                view.showMinimized()
            }
        }
        //最大
        CusButton_Image {
            anchors.verticalCenter: parent.verticalCenter
            visible: !isMaxed
            btnImgUrl: "qrc:/Images/Window/window-maximize.png"
            ToolTip{
                visible: parent.hovered
                delay: 800
                text: "最大化"
                background: Rectangle{
                    color: "#7f7f7f"
                    radius: 3
                }
            }
            onClicked: {                
                view.showMaximized()
                rootBackground.fullscreen = true
            }
        }
        //正常
        CusButton_Image {
            anchors.verticalCenter: parent.verticalCenter
            visible: isMaxed
            btnImgUrl: "qrc:/Images/Window/window-restore.png"
            ToolTip{
                visible: parent.hovered
                delay: 800
                text: "还原"
                background: Rectangle{
                    color: "#7f7f7f"
                    radius: 3
                }
            }
            onClicked: {
                view.showNormal()
                rootBackground.fullscreen = false
            }
        }
        //关闭按钮
        CusButton_Image {
            anchors.verticalCenter: parent.verticalCenter
            ToolTip{
                visible: parent.hovered
                delay: 800
                text: "关闭"
                background: Rectangle{
                    color: "#7f7f7f"
                    radius: 3
                }
            }
            btnImgUrl: "qrc:/Images/Window/window-close.png"
            onClicked: {
                mainBobyPane.saveAllToJson(mainBobyPane.getAllWidget())
                view.close()
            }
        }
    }





}
