import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12


//通道菜单 设置
Column{
    id:originMenu
    height: opened ? 80 :40
    anchors{
        right: parent.right
        rightMargin: 10
        left: parent.left
        leftMargin: 10
    }
    //spacing: 10
    property bool opened: true
    clip: true

    Rectangle{
        width: originMenu.width
        height: 30
        radius: 10
        color: "#FF9900"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                originMenu.opened = !originMenu.opened
            }
        }
        Text {
            anchors{
                left: parent.left
                leftMargin: 10
                verticalCenter: parent.verticalCenter
            }
            font.pixelSize : 18
            font.bold: true
            color: "white"
            text:"绑定数据源"
        }
        Image {
            anchors{
                right: parent.right
                rightMargin: 10
                verticalCenter: parent.verticalCenter
            }
            source: originMenu.opened ? "qrc:/Controls/library/Image/leftclose.png" : "qrc:/Controls/library/Image/downopen.png"
        }
    }
    Item{
        height: 30
        //color: "red"
        width: originMenu.width
        visible: originMenu.opened
        ComboBox{
            id:originType
            anchors{
                left: parent.left
                leftMargin: 10
            }
            Material.background: "transparent"
            Material.foreground: "white"
            model:["type1","type2","type3"]
            font.bold: true
            font.pixelSize: 20
        }
        ComboBox{
            id:originName
            anchors{
                right: parent.right
                rightMargin: 10
            }
            Material.background: "transparent"
            Material.foreground: "white"
            model:["源1","源2","源3"]
            font.bold: true
            font.pixelSize: 20
        }
    }


    function getOrigin_ctx()
    {
        var ctx = {
            "type" : originType.currentText,
            "name" : originName.currentText
        }
        return ctx
    }
    function setOrigin_ctx(ctx)
    {
        originType.model = [ctx.type]
        originName.model = [ctx.name]
    }
}


