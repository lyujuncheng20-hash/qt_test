// BaseButton.qml
import QtQuick
import QtQuick.Controls

Button {
    id: control

    // 自定义亮色系配色方案（清爽、明亮风格）
    property color defaultColor: "#f5f6fa"   // 常态：浅浅的灰白色
    property color hoveredColor: "#dcdde1"   // 悬浮：稍微加深的浅灰色
    property color pressedColor: "#ced6e0"   // 按下：柔和的灰色
    property color accentColor: "#2f3542"    // 文字颜色：深色（保证清晰度）
    property color highlightColor: "#3498db" // 悬浮/聚焦时的亮蓝色边框

    text: "Base Button"
    implicitWidth: 120
    implicitHeight: 40

    // 【QML动效】：按下时自动微缩至 0.95，松开自动恢复。
    // 使用 Behavior on scale，硬件加速自动跑完动画，不占用外部 onClicked！
    scale: control.pressed ? 0.95 : 1.0
    Behavior on scale { NumberAnimation { duration: 100 } }

    contentItem: Text {
        text: control.text
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight

        // 使用标准的大括号组语法来定义字体属性，规避点运算符报错
        font {
            pixelSize: 14
        }

        // 状态驱动文字颜色：按下时文字变成亮蓝色，平时为深色
        color: control.pressed ? control.highlightColor : control.accentColor
        Behavior on color { ColorAnimation { duration: 100 } }
    }

    background: Rectangle {
        implicitWidth: control.implicitWidth
        implicitHeight: control.implicitHeight
        radius: 6

        // 状态驱动背景色切换（全是纯色切换，绝无 gradient 冲突报错）
        color: control.pressed ? control.pressedColor :
               control.hovered ? control.hoveredColor : control.defaultColor

        // 鼠标悬浮时亮起醒目的蓝色边框，平时为淡淡的灰色边框
        border.color: control.hovered ? control.highlightColor : "#dcdde1"
        border.width: control.hovered ? 2 : 1

        // 只要颜色发生改变，底层就会自动执行淡入淡出过渡
        Behavior on color { ColorAnimation { duration: 150 } }
        Behavior on border.color { ColorAnimation { duration: 150 } }
    }
}
