import QtQuick 2.12
import QtQuick.Controls 2.2
import TaoQuick 1.0



Rectangle {
    color: "#cccccc"

    //左边的 排列
    Row {
        anchors.left: parent.left
        anchors.leftMargin: rootBackground.fullscreen ? 44 :6
        height: parent.height
        spacing: 6
        Image {
            //visible: rootBackground.fullscreen ? false : true
            anchors.bottom: parent.bottom
            width: rootBackground.fullscreen ? 20 :30
            height: rootBackground.fullscreen ? 20 :30
            source: "qrc:/Images/logo/logo-redblue-128.ico"
        }
        Text {
            id: t
            //anchors.verticalCenter: parent.verticalCenter
            anchors.bottom: parent.bottom
            font.pixelSize: rootBackground.fullscreen ? 20 :26
            font.bold: true  //加粗
            text: "dukiModel"
            color: "#000000"
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
        anchors.rightMargin: 10
        spacing: 14
        //最小
        CusButton_Image {
            width: 20
            height: 20
            anchors.top: parent.top
            //anchors.verticalCenter: parent.verticalCenter
            btnImgUrl: "qrc:/Images/Window/window-minimize.png"
            tipText: "最小"
            onClicked: {
                view.showMinimized()
            }
        }
        //最大
        CusButton_Image {
            anchors.bottom: parent.bottom
            visible: !isMaxed
            btnImgUrl: "qrc:/Images/Window/window-maximize.png"
            tipText: "最大"
            onClicked: {                
                view.showMaximized()
                rootBackground.fullscreen = true
            }
        }
        //正常
        CusButton_Image {
            anchors.bottom: parent.bottom
            visible: isMaxed
            btnImgUrl: "qrc:/Images/Window/window-restore.png"
            tipText: "缩小"
            onClicked: {
                view.showNormal()
                rootBackground.fullscreen = false
            }
        }
        //关闭按钮
        CusButton_Image {
            anchors.bottom: parent.bottom
            tipText: "关闭"
            btnImgUrl: "qrc:/Images/Window/window-close.png"
            onClicked: {
                view.close()
            }
        }
    }
    //分隔栏
    Rectangle {
        id: splitLine
        height: parent.height * 0.6
        width: 1
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: controlButtons.left
        anchors.rightMargin: 10
        color: "white"
    }
    //工具栏
    Row {
        id: toolRow

        height: parent.height
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: splitLine.left
        anchors.rightMargin: 20
        spacing: 20
        CusButton_Image {
            width: 24
            height: 24
            anchors.bottom:  parent.bottom
            tipText: "设置"
            btnImgUrl: "qrc:/Images/Window/setting-filling.png"
            onClicked: {

            }
        }
        CusButton_Image {
            width: 24
            height: 24
            anchors.bottom:  parent.bottom
            tipText: "文档"
            btnImgUrl: "qrc:/Images/Window/help.png"

            property string urlName: "http://duki.cc"
            onClicked: {
                Qt.openUrlExternally(urlName)
            }
        }
    }

    //来实现拖动窗口的矩形
    property alias blankItem: blankItem
    Item {
        id: blankItem
        objectName: "blankItem"
        anchors {
            left: parent.left
            leftMargin: 4
            right: toolRow.left
            top: parent.top
            topMargin: 4
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


}
