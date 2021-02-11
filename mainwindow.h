#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>

#include "paddle/config.h"
#include "paddle/ocr_det.h"
#include "paddle/ocr_rec.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SetImage();

private:
    Ui::MainWindow *ui;

    QString m_imgPath;
    QLabel* m_label;
    PaddleOCR::DBDetector* m_det;
    PaddleOCR::CRNNRecognizer* m_rec;

};

#endif // MAINWINDOW_H
