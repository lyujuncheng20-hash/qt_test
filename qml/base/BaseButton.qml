// BaseButton.qml
import QtQuick
import QtQuick.Controls

Button {
    id: control

    // カスタムカラープロパティ（スタイルの拡張用）
    property color defaultColor: "#3498db"
    property color hoveredColor: "#2980b9"
    property color pressedColor: "#1c5980"

    text: "Base Button"
    implicitWidth: 120
    implicitHeight: 40

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#ffffff" : "#f5f5f5"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: control.implicitWidth
        implicitHeight: control.implicitHeight
        radius: 4

        // ボタンの状態（hovered / pressed）に応じて背景色を動的に切り替え
        color: control.pressed ? control.pressedColor :
               control.hovered ? control.hoveredColor : control.defaultColor

        border.color: "#ffffff"
        border.width: control.visualFocus ? 2 : 0
    }
}
