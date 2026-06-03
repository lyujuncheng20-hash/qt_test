// BaseButton.qml
import QtQuick
import QtQuick.Controls

Button {
    id: control

    // 1. 添加自定义属性（扩展新功能）
    property color defaultColor: "#3498db"
    property color hoveredColor: "#2980b9"
    property color pressedColor: "#1c5980"

    // 2. 隐式定义或修改原有属性
    text: "Base Button" // 默认文本
    implicitWidth: 120
    implicitHeight: 40

    // 3. 重写内容样式（文字/图标）
    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#ffffff" : "#f5f5f5"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    // 4. 重写背景样式
    background: Rectangle {
        implicitWidth: control.implicitWidth
        implicitHeight: control.implicitHeight
        radius: 4

        // 动态切换颜色（利用 Button 内置的 hovered 和 pressed 状态）
        color: control.pressed ? control.pressedColor :
               control.hovered ? control.hoveredColor : control.defaultColor

        border.color: "#ffffff"
        border.width: control.visualFocus ? 2 : 0
    }
}
