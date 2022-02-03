import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

Page {
    anchors.fill: parent
    Rectangle{
        id: boughtcarlights
        color: "#33AFFF"
        anchors.fill: parent
        Rectangle
        {
            color: "white"
            x: 125
            y: 0
            width: 407
            height: 480

        }

        ScrollView {
            id: scrollView
            x: 132
            y: 83
            width: 392
            height: 341
            Text {
                id: element
                x: 0
                y: 0
                text: qsTr(manage1.showqstring(2))
                font.pixelSize: 12
            }

        }
        Button {
            id: button
            x: 474
            y: 402
            width: 82
            height: 40
            text: qsTr("OK")
            onClicked: pages.push("OptionPage.qml")
        }
        Text {
            id: element1
            x: 240
            y: 25
            text: qsTr("Your Carlights")
            font.pixelSize: 20
        }
    }


}
