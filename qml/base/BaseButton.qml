import QtQuick
import QtQuick.Controls

Button {
    id: control

    // 只保留最基础的自定义外观属性
    property color buttonColor: "#2196F3"   // 统一背景色
    property color textColor: "#FFFFFF"     // 文字颜色
    property int borderRadius: 4            // 圆角半径

    font.pixelSize: 14
    implicitWidth: 100
    implicitHeight: 40

    // 1. 文本样式：仅绑定文字内容和颜色
    contentItem: Text {
        text: control.text
        font: control.font
        color: control.textColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    // 2. 背景样式：直接赋值固定颜色，没有任何逻辑判断
    background: Rectangle {
        color: control.buttonColor
        radius: control.borderRadius
    }
}
