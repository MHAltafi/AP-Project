import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2


Page {
    id: page

    anchors.fill: parent
    Rectangle{
        id:headsize
        color: "#33AFFF"
        anchors.fill: parent
    }

    RadioButton {
        id: radioButton
        x: 62
        y: 75
        text: qsTr("Small")
        onCheckedChanged: if(checked) {manage1.headsizeslot(1)}
    }

    RadioButton {
        id: radioButton1
        x: 62
        y: 121
        text: qsTr("Medium")
        onCheckedChanged: if(checked) {manage1.headsizeslot(2)}
    }

    RadioButton {
        id: radioButton2
        x: 62
        y: 167
        text: qsTr("Large")
        onCheckedChanged: if(checked) {manage1.headsizeslot(3)}
    }

    Text {
        id: element
        x: 62
        y: 48
        color: "#000000"
        text: qsTr("What type of headsize do you want?")
        font.pixelSize: 17
    }

    Button {
        id: button
        x: 474
        y: 402
        width: 82
        height: 40
        text: qsTr("Next")
        onClicked:
        {
            if(radioButton.checked || radioButton1.checked || radioButton2.checked)
            {
                pages.push("Screwdriverlength.qml")
            }
            else
            {
                dialog1.open();
            }

        }
    }
    Dialog{
        id: dialog1
        Text {
            id: dlg
            text: qsTr("Choose an option!")
        }
    }


    Image {
        id: image
        x: 359
        y: 93
        width: 230
        height: 217
        fillMode: Image.PreserveAspectFit
        source: "10.png"
    }



}
