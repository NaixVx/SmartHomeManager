#ifndef DEVICEDETAILSDIALOG_H
#define DEVICEDETAILSDIALOG_H

#include <QDialog>

#include "device.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DeviceDetailsDialog;
}
QT_END_NAMESPACE

class DeviceDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    DeviceDetailsDialog(QWidget *parent = nullptr);
    ~DeviceDetailsDialog();

    void setDevice(const Device &device);

private slots:


private:
    Ui::DeviceDetailsDialog *ui;

};

#endif // DEVICEDETAILSDIALOG_H
