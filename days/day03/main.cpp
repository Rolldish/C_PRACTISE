#include<iostream>
#include<string>
using namespace std;

struct Device 
{
	int id;
	string name;
	string type;
	double price;
	bool borrowed;
};

int main1() 
{
	const int MAX_DEVICES = 100;
	Device device[MAX_DEVICES];
	int deviceCount = 0;
	
	while (deviceCount < 2)
	{	
		cout << "正在添加第 "<< deviceCount + 1<< " 台设备\n";
		cout << "Enter device ID: ";
		cin >> device[deviceCount].id;

		cout << "Enter device name: ";
		cin >> device[deviceCount].name;

		cout << "Enter device type: ";
		cin >> device[deviceCount].type;

		cout << "Enter device price: ";
		cin >> device[deviceCount].price;

		device[deviceCount].borrowed = false;
		deviceCount++;
	}
	for (int i = 0;i < deviceCount;i++)
	{
		cout << "\n======Device Information======\n"
			<< "Device ID: " << device[i].id << endl
			<< "Device Name: " << device[i].name << endl
			<< "Device Type: " << device[i].type << endl
			<< "Device Price: " << device[i].price << endl;
		/*<< "Device Borrowed: " << (device.borrowed ? "Yes" : "No") << endl;*/
		if (device[i].borrowed)
		{
			cout << "已借出";// 输出：Device Borrowed: 已借出
		}
		else
		{
			cout << "未借出";// 输出：Device Borrowed: 未借出
		}
	}
	cout << "\nDevice count: " << deviceCount << endl;
	return 0;

}