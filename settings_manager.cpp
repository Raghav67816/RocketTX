#include <QSettings>
#include "headers/settings_manager.h"

QSettings settingsObj("settings.ini", QSettings::Format::IniFormat);

QString getParam(QString key){
    QString val = settingsObj.value(key).toString();
    return val;
}

void updateSettings(QString host, QString port, QString motor_mass, QString motor_name, QString propellent_name, QString output_folder){
    QStringList keys;
    QStringList vals;
    keys << "host" << "port" << "motor_mass" << "motor_name" << "propellent_name" << "output_folder";
    vals << host << port << motor_mass << motor_name << propellent_name << output_folder;

    int keys_len = keys.length();
    for (int i=0; i<keys_len; i++){
        settingsObj.setValue(keys.at(i), vals.at(i));
    }
}
