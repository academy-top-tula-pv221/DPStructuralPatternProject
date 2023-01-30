#pragma once
#include <iostream>
using namespace std;

class SensorAdapter
{
public:
	virtual float GetSensorData() = 0;
	virtual ~SensorAdapter() {}
};

class SensorÑelsius
{
public:
	virtual float GetTemperature()
	{
		return 36.6;
	}
	// other code
};

class SensorFahrenheit
{
public:
	float GetTemperatureFahrenheit()
	{
		return 25.5;
	}
};

class AdapterCelsius : public SensorAdapter
{
	SensorÑelsius* sensor;
public:
	AdapterCelsius(SensorÑelsius* sensor) : sensor{ sensor } {};
	~AdapterCelsius() { delete sensor; }

	float GetSensorData() override
	{
		return sensor->GetTemperature();
			//sensorF->GetTemperatureFahrenheit() - 32) * 5.0 / 9.0;
	}
};

class AdapterFahrenheit : public SensorAdapter
{
	SensorFahrenheit* sensor;
public:
	AdapterFahrenheit(SensorFahrenheit* sensor) : sensor{ sensor } {};
	~AdapterFahrenheit() { delete sensor; }

	float GetSensorData() override
	{
		return (sensor->GetTemperatureFahrenheit() - 32) * 5.0 / 9.0;
	}
};


class Client
{
public:
	void ClientMethod()
	{
		SensorAdapter* sensor = new AdapterCelsius(new SensorÑelsius());
		std::cout << sensor->GetSensorData() << "\n";
		
		delete sensor;

		sensor = new AdapterFahrenheit(new SensorFahrenheit());
		std::cout << sensor->GetSensorData() << "\n";
	}
};