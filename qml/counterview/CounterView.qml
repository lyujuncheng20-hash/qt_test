// CounterView.qml
import QtQuick
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
            // 触发数字跳动动画
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
            // 前の画面に戻る
            mainStack.pop()
        }
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        // 包含文本的容器，用来安全地进行缩放动画
        Item {
            width: 100
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: countText
                text: myCounter.count
                font.pixelSize: 40
                font.bold: true
                anchors.centerIn: parent
                transformOrigin: Item.Center // 以中心为缩放原点

                // 定义跳动动画
                SequentialAnimation {
                    id: numberAnimation
                    // 1. 快速放大并微调颜色
                    ParallelAnimation {
                        PropertyAnimation { target: countText; property: "scale"; to: 1.3; duration: 80; easing.type: Easing.OutQuad }
                        PropertyAnimation { target: countText; property: "color"; to: "#e74c3c"; duration: 80 }
                    }
                    // 2. 带有弹性地恢复原状
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
                onClicked: myCounter.increment()
            }

            BaseButton {
                text: "-"
                onClicked: myCounter.decrement()
            }
        }

        BaseButton {
            text: "Reset"
            onClicked: myCounter.reset()
        }
    }
}
