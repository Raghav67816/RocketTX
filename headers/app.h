#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMqttClient>

#define WINDOW_TITLE "Rocket Motor Test"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMqttClient client;
    void updateHome();
    void startMessage();
    bool isConnected = false;
    bool isConfigured = false;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
