#include "./ui_app.h"
#include <QMessageBox>
#include "headers/app.h"
#include "headers/configdialog.h"
#include "headers/settings_manager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("IDLE");

    ConfigDialog configDialog;

    if (!isConfigured){
        ui->startBtn->setText("Initialize");
    }

    else{
        ui->startBtn->setText("Start");
    }

    connect(ui->settingsBtn, &QPushButton::clicked, this, [this, &configDialog](){
        int val = configDialog.showDialog();
        if (val == 1){
            ui->propellent_name_val->setText(getParam("propellent_name"));
            ui->mass_of_motor_val->setText(getParam("motor_mass"));
        }
    });
    connect(ui->startBtn, &QPushButton::clicked, this, [this](){
        if (!isConnected && ui->startBtn->text() == "Initialize"){
            startMessage();
        }
        else{
            auto box = QMessageBox::warning(this, "Starting Recording", "This will start recording values. Are you sure you want to continue.");

        }
    });
    connect(&client, &QMqttClient::connected, this, [this](){
        if (isConnected == true){
            QMessageBox::information(this, "Connection", "Client is already connected to the host");
        }
        else{
            ui->startBtn->setText("Start");
            ui->statusbar->showMessage("Connected");
            QMessageBox::information(this, "Connection", "Client connected successfully");
            isConnected = true;
        }
    });
    connect(&client, &QMqttClient::disconnected, this, [this](){
        QMessageBox::critical(this, "Error", "Client disconnected from host unexpectedly, please try again.");
        ui->startBtn->setText("Initialize");
        isConnected = false;
    });
}

void MainWindow::updateHome(){
    qDebug() << "config dialog accepted";
    ui->propellent_name_val->setText(getParam("propellent_name"));
    ui->mass_of_motor_val->setText(getParam("motor_mass"));
}

void MainWindow::startMessage(){
    QMessageBox msg_box;
    msg_box.setText("Please note the following things.");
    msg_box.setInformativeText("Make sure to test connection using the tool. Make sure to turn on ignitor main switch.");
    msg_box.show();
    int status = msg_box.exec();
    if (status == QMessageBox::Ok){
        QString host = getParam("host");
        QString port = getParam("port");
        client.setHostname(host);
        client.setClientId("Test Stand Software");
        client.setPort(port.toUShort());
        client.connectToHost();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
