import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2


Page {
    id: page

    anchors.fill: parent
    Rectangle{
        id:quality1
        color: "#33AFFF"
        anchors.fill: parent
    }

    RadioButton {
        id: radioButton
        x: 62
        y: 75
        text: qsTr("Low")
        onCheckedChanged: if(checked) {manage1.lightqualityslot(1)}
    }

    RadioButton {
        id: radioButton1
        x: 62
        y: 121
        text: qsTr("Average")
        onCheckedChanged: if(checked) {manage1.lightqualityslot(2)}
    }

    RadioButton {
        id: radioButton2
        x: 62
        y: 167
        text: qsTr("High")
        onCheckedChanged: if(checked) {manage1.lightqualityslot(3)}
    }

    Text {
        id: element
        x: 62
        y: 48
        color: "#000000"
        text: qsTr("What Quality do you want?")
        font.pixelSize: 17
    }
    Dialog{
        id: dialog1
        Text {
            id: dlg
            text: qsTr("Bought Successfully!")
        }
    }

    Dialog
    {
        id: dialog2
        Text {
            id:dlg2
            text : qsTr("Choose an Option!")
        }
    }
    Connections
    {
        target: manage1
        onNotbought: dlg.text = "You don't have enough money! \nPlease increment your balance."
        onBought: dlg.text = "Bought Successfully!"
    }

    Button {
        id: button
        x: 474
        y: 402
        width: 82
        height: 40
        text: qsTr("Buy")
        onClicked: {
            if(radioButton.checked || radioButton1.checked || radioButton2.checked)
            {
                manage1.holdercarlight()
                dialog1.open()
                pages.push("OptionPage.qml")
            }
            else
            {
                dialog2.open();
            }

        }
    }

    Image {
        id: image
        x: 359
        y: 93
        width: 230
        height: 217
        source: "5.png"
        fillMode: Image.PreserveAspectFit
    }



}
/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
