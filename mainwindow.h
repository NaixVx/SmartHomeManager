#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "device.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addDeviceButton_clicked();
    void on_kitchenLightButton_clicked();
    void on_desktopLedButton_clicked();

private:
    Ui::MainWindow *ui;

    QVector<Device> devices;
    void loadMockDevices();
    void refreshDevicesTable();
    void refreshDashboard();
};
#endif // MAINWINDOW_H
