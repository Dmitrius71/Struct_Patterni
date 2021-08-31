#include <iostream>
#include "FaringateSensor.h"

// ������� ������� � ����������

using namespace std;

class Sensor                                   
{

public:
	virtual ~Sensor(){}
	virtual float GetTemperature() = 0;
};


class CelsiusAdapter : public Sensor         // �������
{
	FaringateSensor* _sensor;


public:

	CelsiusAdapter(FaringateSensor* sensor) : _sensor(sensor) {}
	~CelsiusAdapter() 
	{
		delete _sensor;
	}

	float GetTemperature() override
	{
		return (_sensor->GetFahrengateTemp() - 32.0) * 5.0 / 9.0;
	}
};



int main()
{

	Sensor* sensor = new CelsiusAdapter(new FaringateSensor());

	cout << sensor->GetTemperature();

	return 0;
}
