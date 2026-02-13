#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "device.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadMockDevices();
    refreshDevicesTable();
    refreshDashboard();

    // this->setStyleSheet("QWidget { border: 1px solid white; }"); // debug border

    ui->devicesTable->setColumnCount(4);
    ui->devicesTable->setHorizontalHeaderLabels({"Device Name", "Online", "State", "Settings"});

    ui->devicesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // ui->devicesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addDeviceButton_clicked()
{
    qDebug() << "Add Device pressed";
}

void MainWindow::on_kitchenLightButton_clicked()
{
    qDebug() << "KitchenLightButton clicked";

    for(Device &d : devices)
    {
        if(d.name == "Kitchen Light")
        {
            d.value = !d.value;
            break;
        }
    }

    refreshDashboard();
    refreshDevicesTable();
}

void MainWindow::on_desktopLedButton_clicked()
{
    qDebug() << "DesktopLedButton clicked";

    for(Device &d : devices)
    {
        if(d.name == "Desktop LEDs")
        {
            d.value = !d.value;
            break;
        }
    }

    refreshDashboard();
    refreshDevicesTable();
}

void MainWindow::loadMockDevices()
{
    Device temperatureSensor;
    temperatureSensor.macAddress = "AA:BB:CC:DD:EE:FA";
    temperatureSensor.online = true;
    temperatureSensor.ipAddress = "192.168.4.2";
    temperatureSensor.name = "Temperature - Desktop";
    temperatureSensor.type= DeviceType::Sensor;
    temperatureSensor.sensorType= SensorType::Temperature;
    temperatureSensor.value = 22.0;
    devices.append(temperatureSensor);

    Device humiditySensor;
    humiditySensor.macAddress = "AA:BB:CC:DD:EE:FB";
    humiditySensor.online = true;
    humiditySensor.ipAddress = "192.168.4.3";
    humiditySensor.name = "Humidity - Desktop";
    humiditySensor.type= DeviceType::Sensor;
    humiditySensor.sensorType= SensorType::Humidity;
    humiditySensor.value = 40.0;
    devices.append(humiditySensor);

    Device desktopLED;
    desktopLED.macAddress = "AA:BB:CC:DD:EE:FC";
    desktopLED.online = true;
    desktopLED.ipAddress = "192.168.4.4";
    desktopLED.name = "Desktop LEDs";
    desktopLED.type= DeviceType::Switch;
    desktopLED.sensorType= SensorType::None;
    desktopLED.value = 1;
    devices.append(desktopLED);

    Device kitchenLight;
    kitchenLight.macAddress = "AA:BB:CC:DD:EE:FD";
    kitchenLight.online = false;
    kitchenLight.ipAddress = "-";
    kitchenLight.name = "Kitchen Light";
    kitchenLight.type= DeviceType::Switch;
    kitchenLight.sensorType= SensorType::None;
    kitchenLight.value = 0;
    devices.append(kitchenLight);
}

void MainWindow::refreshDevicesTable()
{
    ui->devicesTable->setRowCount(0);

    for(const Device &d : devices)
    {
        int row = ui->devicesTable->rowCount();
        ui->devicesTable->insertRow(row);

        // Device name
        ui->devicesTable->setItem(row, 0, new QTableWidgetItem(d.name));

        // Device online
        QString onlineText = d.online ? "Online" : "Offline";
        ui->devicesTable->setItem(row, 1, new QTableWidgetItem(onlineText));

        // Device status
        QString stateText;

        if(d.type == DeviceType::Switch)
        {
            stateText = d.value ? "ON" : "OFF";
        }

        switch(d.sensorType){
        case SensorType::Temperature:
            stateText = QString::number(d.value) + " °C";
            break;
        case SensorType::Humidity:
            stateText = QString::number(d.value) + " %";
            break;
        default:
            break;
        }

        ui->devicesTable->setItem(row, 2, new QTableWidgetItem(stateText));

        // Device settings button
        QPushButton *btn = new QPushButton("Settings");
        ui->devicesTable->setCellWidget(row, 3, btn);
    }
}

// dashboard widgets will be created dynamically
void MainWindow::refreshDashboard()
{
    for(Device &d : devices)
    {
        if(d.type == DeviceType::Sensor)
        {
            if(d.sensorType == SensorType::Temperature)
            {
                ui->temperatureSensorName->setText(d.name);
                ui->temperatureSensorValue->display(d.value);
            }
            else if(d.sensorType == SensorType::Humidity)
            {
                ui->humiditySensorName->setText(d.name);
                ui->humiditySensorValue->display(d.value);
            }
        }
        else if(d.type == DeviceType::Switch)
        {
            if(d.name.contains("Kitchen"))
            {
                ui->kitchenLightName->setText(d.name);
                ui->kitchenLightButton->setText(d.value ? "ON" : "OFF");
            }
            else if(d.name.contains("Desktop"))
            {
                ui->desktopLedName->setText(d.name);
                ui->desktopLedButton->setText(d.value ? "ON" : "OFF");
            }
        }
    }
}

