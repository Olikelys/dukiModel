import QtQuick 2.0
import QtQuick.Controls 2.12
import "qrc:/Controls/library"
import "qrc:/Qml"
import "qrc:/QML/Pane"
import RLink 1.0

ResizableRectangle {
    id:rWavyProgress
    width: 200
    height: 240
    property var menuObj: null
    property var allctx: {null}
    property string originType: "int"
    property string originName: "uu"
    property real minVal: 1.0
    property real maxVal: 101.0
    property real realval: rOriginAgency.agencyVal


    path: "qrc:/Controls/RWavyProgress/RWavyProgress.qml"   //控件的路径不是菜单路径
    controlType:"RWavyProgress"

    WavyProgress{
        id:wavyProgress
        anchors.centerIn: parent
        width: parent.width
        height: width
        value: realval<minVal ? 0 :
               realval>maxVal ? 1 :
               (realval-minVal)/(maxVal-minVal)
    }
    ROriginAgency{
        id:rOriginAgency
        agencyVal:0
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
        if(!rWavyProgress.isMenu){
        controlMenuStackView.enabled = true
        rWavyProgress.isMenu = true
        var component  = Qt.createComponent("qrc:/Controls/RWavyProgress/RWavyProgressMenu.qml")
        if(component.status === Component.Ready){
                  menuObj = component.createObject(rWavyProgress,{"allctx": getAll_ctx()})
                  controlMenuStackView.push(menuObj)
        }//推到staackivew  但是生命周期还是这里管所以关闭菜单的时候随带销毁
        //绑定信号  删除的时候解绑
        rWavyProgress.rectAndRotation.connect(menuObj.onRectAndRotationed)
        menuObj.backAllCtx.connect(onBackAllCtxed)
        }

    }

    //菜单返回的ctx
    function onBackAllCtxed(type,val)
    {
        rWavyProgress.isMenu = false
        rWavyProgress.rectAndRotation.disconnect(menuObj.onRectAndRotationed)
        menuObj.backAllCtx.disconnect(rWavyProgress.onBackAllCtxed)
        menuObj.destroy()
        setAll_ctx(val)
        //然后根据的值重新绑定  model
        if(type === 0){  //关闭菜单
            //snackbar.open("已关闭菜单")
        }
        else{//删除这个控件
            snackbar.open("已删除")
            rWavyProgress.destroy()
        }
    }
    function bindOriginModle()
    {
        if(rOriginAgency.setAgency(originType,originName) ){
             snackbar.open("("+originType+":"+originName+")绑定成功")
        }
        else{
             snackbar.open("("+originType+":"+originName+")绑定失败")
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
        return ctx
    }
    function setAll_ctx(ctx)
    {
        setBasic_ctx(   ctx.basic  )
        originType = ctx.origin.type
        originName = ctx.origin.name
        minVal = ctx.argument.minVal
        maxVal = ctx.argument.maxVal
        bindOriginModle()

    }


    //销毁后输出表示安全
    Component.onDestruction: print("Destroying RWavyprogress ")



}
