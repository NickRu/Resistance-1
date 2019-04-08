#pragma once
class OrderAgent
{
private:
	int _orderNumber;				//порядок в игре после перемешивания
public:
	OrderAgent();
	~OrderAgent();

	int GetOrderNumber();
	void SetOrderNumber(int ordNumb);

	virtual int GetNumberOfAgent();

};

