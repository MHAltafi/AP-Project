import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

Page {
    anchors.fill: parent
    Rectangle{
        color: "#33AFFF"
        anchors.fill: parent




    }
    Grid
    {
        anchors.centerIn: parent
        spacing: 3
        columns: 2
        RoundButton
        {
            id: buyscrewdriverbutton
            width: 50
            height: 50
            radius: 5

            Image
            {
                anchors.fill: parent
                id: screwimage
                source: "2.jpg"
            }
            onClicked: {
                pages.push("Screwdriverheadtype.qml")
            }

        }

        Text
        {
            id: buyscrewdrivertext
            text: "Buy a Screwdriver"
        }
        //--------------------------------------------------------------------------------------

        RoundButton
        {
            id: buycarlightbutton
            width: 50
            height: 50
            radius: 5
            Image
            {
                anchors.fill: parent
                id: carlightimage
                source: "3.jpg"
            }
            onClicked: pages.push("Carlighttype.qml")
        }

        Text
        {
            id: carlighttext
            text: "Buy a Carlight"
        }
        //-----------------------------------------------------------------------------------------

        RoundButton
        {

            id:boughtscrewdrivers
            width: 50
            height: 50
            radius: 5
            Image
            {
                anchors.fill: parent
                id:boughtscrewdriversimage
                source: "4.png"
            }
            onClicked: pages.push("Boughtscrewdrivers.qml")
        }

        Text
        {
            id: boughtscrewdriverstext
            text: "Bought Screwdrivers"
        }

        //----------------------------------------------------------------------------------------

        RoundButton
        {
            id:boughtcarlights
            width:50
            height:50
            radius:5
            Image
            {
                anchors.fill: parent
                id:boughtcarlightsimage
                source: "5.png"
            }
            onClicked: pages.push("Boughtcarlights.qml")
        }

        Text
        {
            id: boughtcarlightstext
            text: "Bought Carlights"
        }

        //---------------------------------------------------------------------------------------

        RoundButton
        {
            id:allbought
            width:50
            height:50
            radius:5
            Image
            {
                anchors.fill:  parent
                id:allboughtimage
                source: "6.png"
            }
            onClicked: pages.push("Allboughttools.qml")
        }

        Text
        {
            id: allboughttext
            text: "All bought tools"
        }


        //----------------------------------------------------------------------------------------

        RoundButton
        {
            id:increment
            width: 50
            height: 50
            radius: 5
            Image
            {
                anchors.fill: parent
                id:incrementimage
                source: "7.png"
            }
            onClicked: {
                pages.push("Incrementbalance.qml")
            }
        }

        Text
        {
            id: incrementtext
            text: "Increment Your Balance"
        }

        //-----------------------------------------------------------------------------------------

        RoundButton
        {
            id:exit
            width: 50
            height: 50
            radius: 5
            Image
            {
                anchors.fill: parent
                id:exitimage
                source: "8.png"
            }
            onClicked: manage1.endapp();
        }


        Text
        {
            id: exittext
            text: "Exit"
        }


    }

    Image {
        id: image
        x: 8
        y: 8
        width: 43
        height: 39
        source: "9.png"
        fillMode: Image.PreserveAspectFit

    }
    Text {
        id: element
        x: 54
        y: 19
        text: qsTr(manage1.showbalance())
        font.pixelSize: 12
    }

}
