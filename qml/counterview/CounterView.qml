// CounterView.qml
import QtQuick
import QtQuick.Controls
import "../base"
import CounterModule 1.0
import LoggerModule 1.0

Item {
    id: counterPage

    Counter {
        id: myCounter
        count: 0

        onCountChanged: (value) => {
            Logger.onCountChanged(value)
            numberAnimation.restart()
        }
    }

    BaseButton {
        text: "⬅ back"
        anchors {
            top: parent.top
            left: parent.left
        }
        onClicked: {
            mainStack.pop()
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 15

        CheckBox {
            id: heavyModeCheckBox
            text: "高負荷計算を有効にする"
            anchors.horizontalCenter: parent.horizontalCenter

            checked: myCounter.isHeavy
            onCheckedChanged: {
                myCounter.isHeavy = checked
            }
        }

        Item {
            width: 100
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter

            BusyIndicator {
                anchors.centerIn: parent
                running: myCounter.isCalculating
                visible: myCounter.isCalculating
            }

            Text {
                id: countText
                text: myCounter.count
                font.pixelSize: 40
                font.bold: true
                anchors.centerIn: parent
                transformOrigin: Item.Center

                opacity: myCounter.isCalculating ? 0.2 : 1.0
                Behavior on opacity { NumberAnimation { duration: 150 } }
				// 順番に実行（Sequential）と同時に実行（Parallel）を組み合わせたアニメーション
                SequentialAnimation {
                    id: numberAnimation

                    // ステップ1：80ミリ秒で「拡大」と「赤色への変化」を同時に行う
                    ParallelAnimation {
                        PropertyAnimation { target: countText; property: "scale"; to: 1.3; duration: 80; easing.type: Easing.OutQuad }
                        PropertyAnimation { target: countText; property: "color"; to: "#e74c3c"; duration: 80 }
                    }
                    // ステップ2：200ミリ秒で元に戻す（Easing.OutBack で弾むような動きを演出）
                    ParallelAnimation {
                        PropertyAnimation { target: countText; property: "scale"; to: 1.0; duration: 200; easing.type: Easing.OutBack }
                        PropertyAnimation { target: countText; property: "color"; to: "#2c3e50"; duration: 200 }
                    }
                }
            }
        }

        Row {
            spacing: 10

            BaseButton{
                text: "+"
                enabled: !myCounter.isCalculating
                onClicked: myCounter.increment()
            }

            BaseButton {
                text: "-"
                enabled: !myCounter.isCalculating
                onClicked: myCounter.decrement()
            }
        }

        BaseButton {
            text: "Reset"
            enabled: !myCounter.isCalculating
            onClicked: myCounter.reset()
        }
    }
}
