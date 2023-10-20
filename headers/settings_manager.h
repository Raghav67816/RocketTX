#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include <QSettings>

extern QSettings settingsObj;


QString getParam(QString key);
void updateSettings(QString host, QString port, QString motor_name, QString propellent_name, QString motor_mass, QString output_folder);

#endif // SETTINGS_MANAGER_H
