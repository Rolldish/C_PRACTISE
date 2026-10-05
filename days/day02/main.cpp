#include<iostream>
#include <string>
using namespace std;

void showMenu();
void showDevices(
	const int deviceIds[],
	const string deviceNames[],
	int count
);
bool isFull(int count, int capacity);

int main() {

	int choice = -1;
	
	int count = 0;
	const int MAX_DEVICES = 5;
	int deviceIds[MAX_DEVICES] = {};
	string deviceNames[MAX_DEVICES];
	while (choice!=0) 
	{
		showMenu();
		cin >> choice;
		
		switch (choice) {
		case 1: {
			
			if (!isFull(count,MAX_DEVICES)) {
				cout << "请输入设备编号（整数）：";
				cin >> deviceIds[count];
				cout << "请输入设备名称：";
				cin >> deviceNames[count];
				count++;
				cout << "添加成功，当前共有 "
					<< count << " 个编号\n";
			}
			else {
				cout << "设备编号已满，无法输入更多设备编号\n";
			}
			break;
		}
		case 2: {
			showDevices(deviceIds, deviceNames, count);
			break;
		}
		case 0:
			cout << "退出程序\n";
			break;
		default:
			cout << "无效选项，请重新输入\n";
			break;


		}
	
	}
	return 0;
}


// showMenu 函数定义
void showMenu()
{
	cout << "\n===== 设备管理 =====\n"
		<< "1. 输入设备\n"
		<< "2. 显示设备\n"
		<< "0. 退出\n"
		<< "请输入选项：";
}

// showDevices 函数定义
void showDevices(
	const int deviceIds[],
	const string deviceNames[],
	int count
) 
{
	if (count == 0) {
		cout << "当前没有设备编号\n";
	}
	else {
		cout << "当前设备编号如下：\n";
		for (int i = 0; i < count; i++) {
			cout << "设备编号：" << deviceIds[i]
				<< "，设备名称：" << deviceNames[i] << "\n";
		}
	}
}

bool isFull(int count, int capacity)
{
	return count >= capacity;
}