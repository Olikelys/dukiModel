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
                createControl(drop.getDataAsString("path"),{"x":drop.x,"y":drop.y})
            }

        }
    }

    //一个装所有控件的容器
    Item {
        id: allControlsItem
        anchors.fill: parent
        Component.onCompleted: {
            readAllJson()
        }
    }




    //动态创建组件 参数只有x和y的是从左边拖过来创建的  有全部参数的是从json文件解析创建的
    function createControl(path,allctx)
    {

        if(allctx.x>=0 && allctx.y>=0)
        {
            console.debug("我在创建没有参数的控件:"+"路径"+path)
            var obj = Qt.createComponent(path).createObject(allControlsItem)
            obj.x = allctx.x
            obj.y = allctx.y
        }
        else{
            var obj = Qt.createComponent(path).createObject(allControlsItem,{"allctx":allctx})
            obj.setAll_ctx(allctx)
        }
    }
    //读取json配置文件
    function readAllJson()
    {
        var jsonString =rViewManager.readJsonFile()  //其实是字符串需要格式化为json
        var all = JSON.parse(jsonString)
        for(var i=0 ;i<all.widget.length;i++)
        {
            createControl(all.widget[i].basic.path,all.widget[i])
        }
        snackbar.open("读取配置文件成功")
    }

    //获取全部widget的json参数
    function getAllWidget()
    {
        var widget =[]

        for( var i=0 ; i<allControlsItem.children.length;i++)
        {
            widget.push(allControlsItem.children[i].getAll_ctx())
        }
        return widget
    }
    //保存 窗口配置文件为json包括widget参数和其他信息
    function saveAllToJson( allwidget)
    {
        var all ={}
        all.name = "i name"
        all.widget = allwidget
        var jsonfile =JSON.stringify(all)
        rViewManager.writeJsonFile(jsonfile)
    }

}
