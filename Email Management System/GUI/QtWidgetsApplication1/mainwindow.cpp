#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect����
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(start()));
}

void MainWindow::start()
{
    // ����������ǰ�滺��Ľ��
    ui->textBrowser->clear();

    //  ��ȡ����������
    QString content = ui->textEdit->toPlainText();
    char* content_char = content.toLatin1().data(); // ��QStringת��Ϊchar�ַ�����

   //�м䴦����̡���������������

   //  ����ȡ��������append�����TextBrowser
    QString result;
    // ����result
    ui->textBrowser->append(result);    // �����������������
}

MainWindow::~MainWindow()
{
    delete ui;
}
