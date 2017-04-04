#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Slot for makeButton_clicked() signal.
 *
 * Note: You will need to change the directory here to match your file structure.
 *
 * */
void MainWindow::on_makeButton_clicked()
{
    QProcess *cMake = new QProcess(this);
    QString file = QDir::homePath() + "/csci3081/3081/group/repo-group-Chunky_Spaghetti/project/src/";
    QStringList args;

    args.append("-C");
    args.append(file);
    args.append("run-tests");

    cMake->setProgram("//usr//bin//make");
    cMake->setArguments(args);
    cMake->setProcessChannelMode(QProcess::MergedChannels); //directs both std::out and std::error output to the same channel for readAll()
    cMake->start();
    cMake->waitForFinished();

    QString output(cMake->readAll());
    this->ui->makeOutputDisplay->setPlainText(output);

    cMake->kill();
    delete cMake;
}

void MainWindow::on_pushButton_clicked()
{
    QProcess *cMake = new QProcess(this);
    QString file = QDir::homePath() + "/csci3081/3081/group/repo-group-Chunky_Spaghetti/project/src/";
    QStringList args;

    args.append("-C");
    args.append(file);
    args.append("clean");

    cMake->setProgram("//usr//bin//make");
    cMake->setArguments(args);
    cMake->setProcessChannelMode(QProcess::MergedChannels); //directs both std::out and std::error output to the same channel for readAll()
    cMake->start();
    cMake->waitForFinished();

    QString output(cMake->readAll());
    this->ui->makeOutputDisplay->setPlainText(output);

    cMake->kill();
    delete cMake;
}
