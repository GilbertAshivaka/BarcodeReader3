#ifndef FRAMEPROCESSOR_H
#define FRAMEPROCESSOR_H

#include <QObject>
#include <QVideoSink>
#include <QVideoFrame>

class FrameProcessor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVideoSink *videoSink READ videoSink WRITE setVideoSink NOTIFY videoSinkChanged)
public:
    explicit FrameProcessor(QObject *parent = nullptr);

    QVideoSink *videoSink() const;
    void setVideoSink(QVideoSink *sink);

signals:
    void videoSinkChanged();
    void newFrameAvailable(const QImage &image);
    void barcodeDetected(const QString &out);

private slots:
    void processFrame(const QVideoFrame &frame);

public slots:
    void onImageProcessed(const QString &out);

private:
    QVideoSink *m_videoSink;
    bool m_isAvailable;
    QString m_displayString;

};

#endif // FRAMEPROCESSOR_H
