#include "devicedetailsdialog.h"
#include "./ui_devicedetailsdialog.h"

#include "device.h"

DeviceDetailsDialog::DeviceDetailsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeviceDetailsDialog)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
}

DeviceDetailsDialog::~DeviceDetailsDialog()
{
    delete ui;
}

void DeviceDetailsDialog::setDevice(const Device &device)
{
    ui->nameLabel->setText(device.name);
    ui->macLabel->setText(device.macAddress);
    ui->ipLabel->setText(device.ipAddress);
    ui->onlineLabel->setText(device.online ? "Online" : "Offline");

    if(device.type == DeviceType::Switch){
        ui->typeLabel->setText("Switch");
    }else if (device.type == DeviceType::Sensor){
        ui->typeLabel->setText("Sensor");
    }
}
