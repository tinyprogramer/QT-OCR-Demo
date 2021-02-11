#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QImage>
#include <QFileDialog>

#include <string>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter->widget(0)->resize(512,512);
    m_label=new QLabel(ui->widget);
    //PaddleOCR::OCRConfig config("E:/qtproject/paddleOCRDemo/config.txt");
    PaddleOCR::OCRConfig config("./config.txt");

    //cv::Mat srcimg = cv::imread("E:/github/paddle/PaddleOCR/doc/imgs/11.jpg", cv::IMREAD_COLOR);

    m_det=new PaddleOCR::DBDetector(config.det_model_dir, config.use_gpu, config.gpu_id,
                     config.gpu_mem, config.cpu_math_library_num_threads,
                     config.use_mkldnn, config.max_side_len, config.det_db_thresh,
                     config.det_db_box_thresh, config.det_db_unclip_ratio,
                     config.visualize, config.use_tensorrt, config.use_fp16);

    m_rec=new PaddleOCR::CRNNRecognizer(config.rec_model_dir, config.use_gpu, config.gpu_id,
                       config.gpu_mem, config.cpu_math_library_num_threads,
                       config.use_mkldnn, config.char_list_file,
                       config.use_tensorrt, config.use_fp16);
    QObject::connect(ui->pushButton_setImage,&QPushButton::clicked,this,&MainWindow::SetImage);
    //std::vector<std::vector<std::vector<int>>> boxes;
    //m_det->Run(srcimg, boxes);
    //std::vector<std::string> res=m_rec->Run(boxes, srcimg, nullptr);
    //for(auto s:res)
    //{
    //    ui->textBrowser->append(s.data());
    //}
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_det;
    delete m_rec;
}

void MainWindow::SetImage()
{
    ui->textBrowser->clear();
    m_imgPath=QFileDialog::getOpenFileName(this,"Choose Image","","Image File(*.png *.jpg *.bmp)");
    if(m_imgPath.size()==0)
    {
        return;
    }
    m_label->resize(ui->widget->size());
    m_label->setPixmap(QPixmap::fromImage(QImage(m_imgPath).scaled(m_label->size(),Qt::KeepAspectRatio)));
    m_label->show();
    cv::Mat srcimg = cv::imread(m_imgPath.toStdString(), cv::IMREAD_COLOR);
    std::vector<std::vector<std::vector<int>>> boxes;
    m_det->Run(srcimg, boxes);
    std::vector<std::string> res=m_rec->Run(boxes, srcimg, nullptr);
    for(auto s:res)
    {
        ui->textBrowser->append(s.data());
    }
}
