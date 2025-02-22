#include "frameprocessor.h"
#include "DynamsoftBarcodeReader.h"
#include "imageprocessor.h"

#include <QThread>
FrameProcessor::FrameProcessor(QObject *parent)
    : QObject{parent}
{
    m_isAvailable = true;
    char errorMsgBuffer[512];

    DBR_InitLicense("t0068lQAAABa8p7d6vIsLzXULX4XjMq689SBDTTjrc+ysij5GMVzyfNu0DF7yMUPWY+FmrDMolnhZSBqdHn9nzwVElDQ/8aY=;t0068lQAAAGXVdR0NdbdrG3GmOSmy5GOkKEP4v8XG+qCXVenT2I9CHYIDns4ZHJc0FE+BxPXzC1tbsOMkKlWxRCbz3F7dCqE=", errorMsgBuffer, 512);
    printf("DBR_InitLicence: %s \n",errorMsgBuffer);
    const char *version = DBR_GetVersion();
    m_displayString = QString(version);

    ImageProcessor *processor = new ImageProcessor();
    QThread *workerThread = new QThread();

    processor->moveToThread(workerThread);

    connect(workerThread, &QThread::finished, processor, &QObject::deleteLater);
    connect(this, &FrameProcessor::newFrameAvailable, processor, &ImageProcessor::processImage);
    connect(processor, &ImageProcessor::imageProcessed, this, &FrameProcessor::onImageProcessed);

    workerThread->start();
}

QVideoSink *FrameProcessor::videoSink() const
{
    return m_videoSink;
}

void FrameProcessor::setVideoSink(QVideoSink *sink){
    if (m_videoSink != sink){
        m_videoSink = sink;
        connect(m_videoSink, &QVideoSink::videoFrameChanged, this, &FrameProcessor::processFrame);
    }
}

void FrameProcessor::processFrame(const QVideoFrame &frame){
    // image processing
    if (!frame.isValid() || !m_isAvailable)
        return;

    m_isAvailable = false;
    QImage image = frame.toImage().copy();
    emit newFrameAvailable(image);
}

void FrameProcessor::onImageProcessed(const QString &out)
{
    emit barcodeDetected(out);
    m_isAvailable = true;
}














