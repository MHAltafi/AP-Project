import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2


Page {
    id: page

    anchors.fill: parent
    Rectangle{
        id:carlightcolorr
        color: "#33AFFF"
        anchors.fill: parent
    }

    RadioButton {
        id: radioButton
        x: 62
        y: 75
        text: qsTr("White")
        onCheckedChanged: if(checked) {manage1.lightcolorslot(1)}
    }

    RadioButton {
        id: radioButton1
        x: 62
        y: 121
        text: qsTr("Yellow")
        onCheckedChanged: if(checked) {manage1.lightcolorslot(2)}
    }

    RadioButton {
        id: radioButton2
        x: 62
        y: 167
        text: qsTr("Red")
        onCheckedChanged: if(checked) {manage1.lightcolorslot(3)}
    }

    RadioButton {
        id: radioButton3
        x: 62
        y: 213
        text: qsTr("Blue")
        onCheckedChanged: if(checked) {manage1.lightcolorslot(4)}
    }


    Text {
        id: element
        x: 62
        y: 48
        color: "#000000"
        text: qsTr("What color do you want?")
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
            if(radioButton.checked || radioButton1.checked || radioButton2.checked || radioButton3.checked)
            {
                pages.push("Carlightbrightness.qml")
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
        source: "5.png"
        fillMode: Image.PreserveAspectFit
    }



}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
