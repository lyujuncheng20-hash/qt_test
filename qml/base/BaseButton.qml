// BaseButton.qml
import QtQuick
import QtQuick.Controls

Button {
    id: control

    property color defaultColor: "#f5f6fa"
    property color hoveredColor: "#dcdde1"
    property color pressedColor: "#ced6e0"
    property color accentColor: "#2f3542"
    property color highlightColor: "#3498db"

    text: "Base Button"
    implicitWidth: 120
    implicitHeight: 40

    // 押されたときにボタンを少し縮小させる（果冻感の演出）
    scale: control.pressed ? 0.95 : 1.0
    Behavior on scale { NumberAnimation { duration: 100 } }

    contentItem: Text {
        text: control.text
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight

        font {
            pixelSize: 14
        }

        color: control.pressed ? control.highlightColor : control.accentColor
        Behavior on color { ColorAnimation { duration: 100 } }
    }

    background: Rectangle {
        implicitWidth: control.implicitWidth
        implicitHeight: control.implicitHeight
        radius: 6

        // 状態（Pressed / Hovered）に応じて色を自動切り替え
        color: control.pressed ? control.pressedColor :
               control.hovered ? control.hoveredColor : control.defaultColor

        border.color: control.hovered ? control.highlightColor : "#dcdde1"
        border.width: control.hovered ? 2 : 1

        // 原理1：プロパティ（色や縮尺）の変更を検知し、自動で補間アニメーションを実行
        Behavior on color { ColorAnimation { duration: 150 } }
        Behavior on border.color { ColorAnimation { duration: 150 } }
    }
}
