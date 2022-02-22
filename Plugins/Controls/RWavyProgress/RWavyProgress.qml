import QtQuick 2.0
import QtQuick.Controls 2.12
import "qrc:/Controls/library"
import "qrc:/Qml"
import "qrc:/QML/Pane"

ResizableRectangle {
    id:rWavyProgress
    width: 200
    height: 240
    property var allctx: {null}
    property string originType: "uu"
    property string originName: "uu"
    property real minVal: 1.0
    property real maxVal: 101.0

    path: "qrc:/Controls/RWavyProgress/RWavyProgress.qml"   //控件的路径不是菜单路径
    controlType:"RWavyProgress"

    WavyProgress{
        id:wavyProgress
        anchors.centerIn: parent
        width: parent.width
        height: width
        value: 0.7
    }
    Text {
        id: rWavyProgressName
        anchors{
            bottom: wavyProgress.bottom
            bottomMargin: -14
            horizontalCenter: parent.horizontalCenter
        }
        visible: nameVisble
        text: name
        font.bold: true

    }

   //右键双击
    onRightDoubleClicked: {
        controlMenuStackView.enabled = true
        rWavyProgress.isMenu = true
        controlMenuStackView.push("qrc:/Controls/RWavyProgress/RWavyProgressMenu.qml",{"allctx":getAll_ctx()} )
    }

    Button{
        onClicked:   {
           // var eee =JSON.stringify( getAll_ctx())
          // console.debug(eee)
           // rViewManager.writeJson( eee)
           var jsonfile =rViewManager.readJsonFile()  //其实是字符串需要格式化为json
            console.log( jsonfile)
            var jjj =JSON.parse(jsonfile)
            console.log(  jjj )
            console.log(jjj.basic.path)
           // mainBobyPane.createControl(path,getAll_ctx())

            //var yy = [{"11":2,"dd":3},{"df":4}]
            //console.debug(yy.length)
        }

    }


    function getAll_ctx()
    {
        var ctx =
                {
             "basic": getBasic_ctx(),
             "origin": {
                "type":originType,
                "name":originName
            },
             "argument":{
                "minVal": minVal,
                "maxVal": maxVal
            }
        }
        console.debug(ctx.basic.name)
        return ctx
    }
    function setAll_ctx(ctx)
    {
        setBasic_ctx(   ctx.basic  )
        originType = ctx.origin.type
        originName = ctx.origin.name
        minVal = ctx.argument.minVal
        maxVal = ctx.argument.maxVal

    }





}
