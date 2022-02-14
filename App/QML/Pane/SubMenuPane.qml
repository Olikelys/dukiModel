import QtQuick 2.0
import QtQuick.Controls 2.12
import Qt.labs.settings 1.0
import QtGraphicalEffects 1.0
import "qrc:/Link"
import "qrc:/Qml"


Item{
    clip: true
    LinearGradient{
        anchors.fill:parent
        gradient:   Gradient {
            GradientStop { position: 0.1;   color: "#e9e4f0" }
            GradientStop { position: 0.9;   color: "#d3cce3" }
                      }
    start:Qt.point(0,0)
    end:Qt.point(parent.width,parent.width)
    }
    RConnectManagerView{
        visible:  1 == rootBackground.menuPaneFlag
    }
    DataShowView{
        visible: 3 == rootBackground.menuPaneFlag
    }



}
