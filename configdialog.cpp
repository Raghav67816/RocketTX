#include <QSettings>
#include <QFileDialog>
#include <QtMqtt/QMqttClient>
#include "ui_configdialog.h"
#include "headers/configdialog.h"
#include "headers/settings_manager.h"

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    checkConnStatus();
    set_to_prev_params();
    connect(ui->cancelBtn, &QPushButton::clicked, this, &ConfigDialog::reject);
    connect(ui->applyBtn, &QPushButton::clicked, this, [this](){
        QStringList params = getAllParams();
         updateSettings(params.at(0), params.at(1), params.at(2), params.at(3), params.at(4), params.at(5));
        qDebug() << "Updated";
        ConfigDialog::accept();
    });
    connect(ui->browse_btn, &QToolButton::clicked, this, [this](){
        QFileDialog file_dialog;
        QString out_dir = file_dialog.getExistingDirectory(this,
                                                           "Select Output Folder",
                                         "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        qDebug() << out_dir;
        ui->output_folder_val->setText(out_dir);
    });
}

int ConfigDialog::showDialog(){
    ConfigDialog configDialog;
    configDialog.setWindowTitle("Preferences");
    configDialog.setModal(true);
    configDialog.show();
    int status = configDialog.exec();
    return status;
}

void ConfigDialog::checkConnStatus(){
    QString conn_status = ui->status_val->text();
    if (conn_status == "Disconnected"){
        ui->status_val->setStyleSheet("QLabel{ color: red }");
    }
    else{
        ui->status_val->setStyleSheet("QLabel{ color: green }");
    }
}

QStringList ConfigDialog::getAllParams(){
    QStringList params;
    QString host, port, motor_name, propellant_name, output_folder, motor_mass;
    host = ui->host_val->text();
    port = ui->port_val->text();
    motor_mass = ui->motor_mass_val->text();
    motor_name = ui->motor_name_val->text();
    propellant_name = ui->prop_name_val->text();
    output_folder = ui->output_folder_val->text();

    params << host << port << motor_mass << motor_name << propellant_name << output_folder;
    return params;
}

void ConfigDialog::set_to_prev_params(){
    QStringList params;
    QStringList prev_params;
    params << "host" << "port" << "motor_mass" << "motor_name" << "propellent_name" << "output_folder";
    for (int i=0; i<params.length(); i++){
        prev_params.append(getParam(params.at(i)));
    }
    ui->host_val->setText(prev_params.at(0));
    ui->port_val->setText(prev_params.at(1));
    ui->motor_mass_val->setText(prev_params.at(2));
    ui->motor_name_val->setText(prev_params.at(3));
    ui->prop_name_val->setText(prev_params.at(4));
    ui->output_folder_val->setText(prev_params.at(5));
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}
