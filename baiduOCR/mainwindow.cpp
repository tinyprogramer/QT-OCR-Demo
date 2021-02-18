#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ocr.h>
#include <json/json.h>

#include <string>

#include <QImage>
#include <QString>
#include <QFileDialog>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_label=new QLabel(ui->widget);
    QObject::connect(ui->pushButton_setImage,&QPushButton::clicked,this,&MainWindow::setImage);

    std::string app_id="23661685";
    std::string api_key = "Z59HtGUGgW0iVVDA0rfwGmQ9";
    std::string secret_key = "LTzVGg3HRRHwy1E2Ou082gVC8HSkla0G";

    m_client=new aip::Ocr(app_id, api_key, secret_key);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_client;
}

void MainWindow::setImage()
{

    QString imgPath=QFileDialog::getOpenFileName(this,"Choose Image","","Image File(*.png *.jpg *.bmp)");
    if(imgPath.size()==0)
    {
        return;
    }
    ui->textBrowser->clear();


    Json::Value result;

    std::string image;
    aip::get_file_content(imgPath.toLocal8Bit().toStdString().data(),&image);
    qDebug()<<image.size();
    result=m_client->general_basic(image,aip::null);
    //result=m_client->accurate_basic(image,aip::null);
    qDebug()<<result.toStyledString().data();

    if(result["words_result"])
    {
        for(unsigned int i=0;i<result["words_result"].size();++i)
        {
            ui->textBrowser->append(result["words_result"][i]["words"].asString().data());
        }
    }

    QImage q(imgPath);
    m_label->resize(ui->widget->size());
    m_label->setPixmap(QPixmap::fromImage(q.scaled(m_label->size(),Qt::KeepAspectRatio)));
    m_label->show();


}
