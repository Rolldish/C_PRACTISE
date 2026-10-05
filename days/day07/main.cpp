#include<iostream>
#include<string>
#include <limits>
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
int readInt(const string& prompt);
int readPositiveInt(const string& prompt);
double readNonNegativePrice(const string& prompt);
string readNonEmptyLine(const string& prompt);

const int MAX_DEVICES = 100;

int main()
{

	Device devices[MAX_DEVICES];
	int deviceCount = 0;

	bool running = true;
	int choice=-1;




	while (running)
	{
		showMenu();
		choice = readInt("Please select: ");

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
	newId = readPositiveInt("Enter device ID : ");

	int index = findDeviceIndex(devices, count, newId);


	if (index != -1)
	{
		cout << "Device ID already exists. Please enter a unique ID." << endl;
		return;
	}


	cout << "正在添加第 " << count + 1 << " 台设备\n";
	devices[count].id = newId;

	devices[count].name = readNonEmptyLine("Enter device name: ");
	devices[count].type = readNonEmptyLine("Enter device type: ");

	devices[count].price = readNonNegativePrice("Enter device price: ");

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
{	cout << "\n====== Device Management System ======\n";
	cout << "1. Add device\n";
	cout << "2. Show all devices\n";
	cout << "3. Search device by ID\n";
	cout << "4. Modify device\n";
	cout << "5. Delete device\n";
	cout << "0. Exit\n";
	
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
	id = readPositiveInt("Enter device ID to search: ");

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
	id = readPositiveInt("Enter device ID to modify: ");

	int index = findDeviceIndex(devices, count, id);

	if (index == -1)
	{
		cout << "Device not found." << endl;
		return;
	}

	cout << "Current name: " << devices[index].name << endl;
	cout << "Current type: " << devices[index].type << endl;
	cout << "Current price: " << devices[index].price << endl;

	devices[index].name = readNonEmptyLine("Enter new name: ");
	devices[index].type = readNonEmptyLine("Enter new type: ");

	devices[index].price = readNonNegativePrice("Enter new price: ");

	cout << "Device modified successfully." << endl;
}
void deleteDevice(Device devices[], int& count)
{
	int id;
	id = readPositiveInt("Enter device ID to delete: ");
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
int readInt(const string& prompt)
{
	int value;
	while (true)
	{
		cout << prompt;
		cin >> value;
		if (cin.fail())
		{
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Invalid input. Please enter an integer." << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any remaining input
			return value;
		}
	}


}
int readPositiveInt(const string& prompt)
{
	while (true)
	{
		int value = readInt(prompt);

		if (value > 0)
		{
			return value;// 返回 value
		}

		cout << "Device ID must be greater than 0." << endl;// 提示设备编号必须大于 0
	}
}
double readNonNegativePrice(const string& prompt)
{
	double value;

	while (true)
	{
		cout << prompt;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();// 清除失败状态
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "Invalid input. Please enter a number." << endl;// 丢弃这一行
			// 提示用户必须输入数字
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// 丢弃这一行剩余内容

			if (value>=0)
			{
				return value;// 返回 value
			}

			cout << "Price must not be negative." << endl;// 提示价格不能为负数
		}
	}
}
string readNonEmptyLine(const string& prompt)
{
	while (true)
	{
		string value;

		cout << prompt;
		getline(cin, value);

		if (value.find_first_not_of(" \t") != string::npos)
		{
			return value;
		}

		cout << "Input must not be empty." << endl;
	}
}