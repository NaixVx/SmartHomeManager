#ifndef DEVICE_H
#define DEVICE_H

#include <QString>

// classes yet to be determied, currently only for mocking
enum class DeviceType
{
    Sensor,
    Switch,
};

enum class SensorType
{
    None,
    Temperature,
    Humidity,
};

// currently generic one for mocking values
class Device
{
public:
    Device();
    QString macAddress;
    QString ipAddress;
    QString name;
    DeviceType type;
    SensorType sensorType;
    bool online;

    double value = 0.0;
};

#endif // DEVICE_H
