#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSave_as_triggered();

    void on_actionOpen_file_triggered();

    void on_actionSave_2_triggered();

    void on_actionChange_size_triggered();

    void on_actionFont_triggered();

    void on_actionNewForm_triggered();

private:
    Ui::MainWindow *ui;

    QString path;
};
#endif // MAINWINDOW_H
