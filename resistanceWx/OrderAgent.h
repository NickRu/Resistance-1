#pragma once
class OrderAgent
{
private:
	int _orderNumber;				//������� � ���� ����� �������������
public:
	OrderAgent();
	~OrderAgent();

	int GetOrderNumber();
	void SetOrderNumber(int ordNumb);

	virtual int GetNumberOfAgent();

};

