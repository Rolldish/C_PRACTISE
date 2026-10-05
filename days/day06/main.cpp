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

void addDevice(Device devices[], int& count);
void showDevices(const Device devices[], int count);
void showMenu();
int  findDeviceIndex(const Device devices[], int count, int id);
void searchDevice(const Device devices[], int count);
void modifyDevice(Device devices[], int count);
void deleteDevice(Device devices[], int& count);

const int MAX_DEVICES = 100;
int main()
{

	Device devices[MAX_DEVICES];
	int deviceCount = 0;

	bool running = true;
	int choice;




	while (running)
	{
		showMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			addDevice(devices, deviceCount);

			break;// 根据选项调用函数
		case 2:
			showDevices(devices, deviceCount);
			break;
		case 3:
			searchDevice(devices, deviceCount);
			break;
		case 0:
			cout << "Program exited." << endl;
			running = false;
			break;
		case 4:
			modifyDevice(devices, deviceCount);
			break;
		case 5:
			deleteDevice(devices, deviceCount);
			break;
		default:
			cout << "Invalid choice." << endl;
			break;
		}
	}
	return 0;

}

void addDevice(Device devices[], int& count)
{
	if (count >= MAX_DEVICES)
	{
		cout << "Device list is full." << endl;
		return;
	}

	int newId;

	cout << "Enter device ID:";
	cin >> newId;

	int index = findDeviceIndex(devices, count, newId);


	if (index != -1)
	{
		cout << "Device ID already exists. Please enter a unique ID." << endl;
		return;
	}


	cout << "正在添加第 " << count + 1 << " 台设备\n";
	devices[count].id = newId;

	cout << "Enter device name: ";
	cin >> devices[count].name;

	cout << "Enter device type: ";
	cin >> devices[count].type;

	cout << "Enter device price: ";
	cin >> devices[count].price;

	devices[count].borrowed = false;
	count++;

	cout << "Device added successfully." << endl;
}

void showDevices(const Device devices[], int count)
{
	if (count == 0)
	{
		cout << "No devices." << endl;
		return;
	}

	cout << "\n====== All Devices ======\n";
	for (int i = 0;i < count;i++)
	{
		cout << "\n======Device Information======\n"
			<< "Device ID: " << devices[i].id << endl
			<< "Device Name: " << devices[i].name << endl
			<< "Device Type: " << devices[i].type << endl
			<< "Device Price: " << devices[i].price << endl;
		/*<< "Device Borrowed: " << (device.borrowed ? "Yes" : "No") << endl;*/
		if (devices[i].borrowed)
		{
			cout << "已借出";// 输出：Device Borrowed: 已借出
		}
		else
		{
			cout << "未借出";// 输出：Device Borrowed: 未借出
		}
	}
	cout << "\nDevice count: " << count << endl;


}
void showMenu()
{
	cout << "\n====== Device Management System ======\n";
	cout << "1. Add device\n";
	cout << "2. Show all devices\n";
	cout << "3. Search device by ID\n";
	cout << "4. Modify device\n";
	cout << "5. Delete device\n";
	cout << "0. Exit\n";
	cout << "Please select: ";
}

int  findDeviceIndex(const Device devices[], int count, int id)
{
	for (int i = 0;i < count;i++)
	{
		if (devices[i].id == id)
		{
			return i;
		}
	}
	return -1;
}

void searchDevice(const Device devices[], int count)
{
	// 1. 提示并读入要查询的编号
	int id;
	cout << "Enter device ID to search: ";
	cin >> id;

	// 2. 调用查找函数，结果存到 index
	int index = findDeviceIndex(devices, count, id);

	// 3. 先判断 index == -1
	if (index == -1)
	{
		cout << "未找到该设备" << endl;
		return;                    // ← 直接结束本次查询，回到菜单
	}

	// 4. 只有走到这里才访问 devices[index]
	cout << "\n======Device Information======\n"
		<< "Device ID: " << devices[index].id << endl
		<< "Device Name: " << devices[index].name << endl
		<< "Device Type: " << devices[index].type << endl
		<< "Device Price: " << devices[index].price << endl;

	// 5. 借用状态，沿用 showDevices 里的格式
	if (devices[index].borrowed)
	{
		cout << "已借出";// 输出：Device Borrowed: 已借出
	}
	else
	{
		cout << "未借出";// 输出：Device Borrowed: 未借出
	}
}



void modifyDevice(Device devices[], int count)
{
	int id;

	cout << "Enter device ID to modify: ";
	cin >> id;

	int index = findDeviceIndex(devices, count, id);

	if (index == -1)
	{
		cout << "Device not found." << endl;
		return;
	}

	cout << "Current name: " << devices[index].name << endl;
	cout << "Current type: " << devices[index].type << endl;
	cout << "Current price: " << devices[index].price << endl;

	cout << "Enter new name: ";
	cin >> devices[index].name;// TODO：修改找到的设备名称

	cout << "Enter new type: ";
	cin >> devices[index].type;// TODO：修改找到的设备类型

	cout << "Enter new price: ";
	cin >> devices[index].price;// TODO：修改找到的设备价格

	cout << "Device modified successfully." << endl;
}

void deleteDevice(Device devices[], int& count)
{
	int id;
	cout << "Enter device ID to delete: ";
	cin >> id;
	int index = findDeviceIndex(devices, count, id);
	if (index == -1)
	{
		cout << "Device not found." << endl;
		return;
	}
	for (int i = index;i < count - 1;i++)
	{
		devices[i] = devices[i + 1];
	}
	count--;
	cout << "Device deleted successfully." << endl;


}
