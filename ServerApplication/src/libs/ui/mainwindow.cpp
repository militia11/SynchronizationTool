#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *aParent) :
  QMainWindow(aParent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  on_mPushButtonRun_clicked();
  connect(mServer, SIGNAL(newConnection()), this,
         SLOT(ClientConnected())) ;
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::DisplayData(QByteArray aData)
{
    ui->mListWidget->insertItem(0, aData);
    ui->mTextEdit->setText(aData);
}

void MainWindow::on_mPushButtonRun_clicked()
{
  mServer = new CServer(this);
  mServer->Run();
// później dołożyć tu ma byc nie w konsturktorze !!!!!!!!!
//  connect(mServer->getClient(), SIGNAL(ReadData(QByteArray)), this,
  //         SLOT(DisplayData(QByteArray))) ;
}

void MainWindow::ClientConnected()
{
    connect(mServer->GetClient(), SIGNAL(ReadData(QByteArray)), this,
           SLOT(DisplayData(QByteArray))) ;
}
