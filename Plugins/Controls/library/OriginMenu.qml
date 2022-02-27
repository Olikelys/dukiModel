import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12


//通道菜单 设置
Column{
    id:originMenu
    height: opened ? 80 :40
    clip: true
    anchors{
        right: parent.right
        rightMargin: 10
        left: parent.left
        leftMargin: 10
    }
    property bool opened: true
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
            model:typeMode
            font.bold: true
            font.pixelSize: 20
            onPressedChanged: {
                model = typeModel
                //console.debug("type按下了")
            }
        }
        ComboBox{
            id:originName
            anchors{
                right: parent.right
                rightMargin: 10
            }
            Material.background: "transparent"
            Material.foreground: "white"
            model:nameMode
            font.bold: true
            font.pixelSize: 20
            onPressedChanged: {
                //当按下的时候对模型请求 有哪些这个类型的变量放回变量名列表
                //model = typeModel
                model = rModeManager.rOriginModel.TypeFilter(originType.currentText)//报错是  js引擎默认函数开头不能大写但是这个不影响工作
               // console.debug("name按下了")
            }
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
        originType.model=[ctx.type]
        originName.model=[ctx.name]
    }
}


