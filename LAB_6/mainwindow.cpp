#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QFontDialog>
#include <QtWidgets>
#include <QAction>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      path("")
{
    ui->setupUi(this);
    ui->textEdit->setAutoFillBackground(false);
    ui->textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(109, 255, 99);"));
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_as_triggered()
{
    auto text = ui->textEdit->toPlainText();

    auto fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                   "save.txt");
       QFile saveFile(fileName);
       if (!saveFile.open(QIODevice::WriteOnly)) {
               qWarning("Couldn't open save file.");
               return ;
           }

           QTextStream stream(&saveFile);
           stream << text;

           saveFile.close();
}

void MainWindow::on_actionOpen_file_triggered()
{
    auto fileName = QFileDialog::getOpenFileName(this,
                                                      tr("Open .txt File"));
    QFile loadFile(fileName);
    if (!loadFile.open(QIODevice::ReadOnly))
    {
            qWarning("Couldn't open save file.");
            return ;
    }

    QTextStream in(&loadFile);

    ui->textEdit->clear();
    while(!in.atEnd()) {
        QString line = in.readLine();
        ui->textEdit->append(line);
    }

    loadFile.close();

      qDebug() << fileName;
}

void MainWindow::on_actionSave_2_triggered()
{
    if(path == "")
    {
        on_actionSave_as_triggered();
        return;
    }

    auto text = ui->textEdit->toPlainText();

       QFile saveFile(path);
       if (!saveFile.open(QIODevice::WriteOnly)) {
               qWarning("Couldn't open save file.");
               return ;
           }

           QTextStream stream(&saveFile);
           stream << text;

           saveFile.close();
}


void MainWindow::on_actionChange_size_triggered()
{
    int value = ui->spinBox->value();

    QFont font = ui->textEdit->font();
    font.setPointSize(value);

    ui->textEdit->setFont(font);
}


void MainWindow::on_actionFont_triggered()
{
    bool ok = true;
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);

    ui->textEdit->setFont(font);
}


void MainWindow::on_actionNewForm_triggered()
{
    QWidget *wdg = new QWidget;
    wdg->resize(500, wdg->height());

    QPushButton *pushButton = new QPushButton(wdg);
    pushButton->setText(tr("something"));
    pushButton->move(300, 300);
    pushButton->show();

    connect(pushButton, &QPushButton::clicked, wdg, &QWidget::hide);

   wdg->show();
}

