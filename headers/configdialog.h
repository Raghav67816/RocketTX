#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QCloseEvent>
#include <QtMqtt/QMqttClient>

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDialog(QWidget *parent = nullptr);
    ~ConfigDialog();
    int showDialog();
    void closeDialog();
    void checkConnStatus();
    void set_to_prev_params();
    QStringList getAllParams();

signals:
    void configDialogAccepted();

private:
    Ui::ConfigDialog *ui;
};

#endif // CONFIGDIALOG_H
