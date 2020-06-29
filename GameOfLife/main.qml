import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import GameModel 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 760
    height: 810
    minimumWidth: 475
    minimumHeight: 300
    title: qsTr("Conway’s Game of Life")


    TableView {
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        //clip: true

        model: GameModel {
            id: gameOfLife
        }

        delegate: Rectangle {
            id: cell
            implicitWidth: 15
            implicitHeight: 15
            color: model.value ? "#f3f3f4" : "#b5b7bf"

            MouseArea {
                anchors.fill: parent
                id: mouseArea
                onClicked: {
                    model.value = !model.value
                }
            }
        }
        contentX: (contentWidth - width) / 2;
        contentY: (contentHeight - height) / 2;

    }


    footer: Rectangle {
        //signal iterate

        id: footer
        height: 50
        color: "#F3F3F4"

        RowLayout {
            anchors.centerIn: parent

            Button {
                text: qsTr("Next")
                onClicked: gameOfLife.iterate()
            }

            Slider {
                id: slider
                from: 0
                to: 1
                value: 0.9
            }

            Button {
                text: timer.running ? "❙❙" : "▶️"
                onClicked: timer.running = !timer.running
            }

        }
        Timer {
            id: timer
            interval: 1000 - (999 * slider.value)
            running: false
            repeat: true

            onTriggered: gameOfLife.iterate()
        }
    }

}
