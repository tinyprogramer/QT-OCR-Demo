#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

namespace aip{
class Ocr;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setImage();

private:
    Ui::MainWindow *ui;
    QLabel* m_label;

    aip::Ocr * m_client;
};

#endif // MAINWINDOW_H
