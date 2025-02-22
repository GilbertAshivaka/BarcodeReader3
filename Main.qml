import QtQuick
import QtQuick.Window
import QtMultimedia
import com.frameprocessor 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("BarcodeReader")

    FrameProcessor{
        id: frameProcessor
        videoSink: viewFinder.videoSink
        onBarcodeDetected: function(text){
            barcodeText.text = text
        }
    }

    CaptureSession{
        id: captureSession
        camera: Camera{
            id: camera
        }

        videoOutput: viewFinder
    }

    VideoOutput{
        id: viewFinder
        visible: true
        anchors.fill: parent
    }


    Text{
        id: barcodeText
        anchors{
            left: parent.left
            right: parent.right
            bottom:  parent.bottom
            margins: 20
        }

        color: "white"
        font.pixelSize: 16
        wrapMode: Text.WordWrap

        Rectangle{
            anchors.fill: parent
            color: "black"
            opacity: 0.5
            z: -1
        }
    }

    Component.onCompleted: {
        camera.start()
    }
}
