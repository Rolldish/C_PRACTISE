#include<iostream>
using namespace std;

int main()
{
	int choice = -1;
	const double PRICE__LIMIT = 1000.0;
	double b = 0;
	
	while (choice) {

		cout << "\n==========设备价格检查==============\n"
			<< "1.输入设备名称和价格\n"
			<< "0.退出\n"
			<< "====================================\n"
			<< "请选择(0-1):";
		cin >> choice;

		switch (choice) {

		case 1: {
			cout << "请输入设备名称:";
			string c;
			cin >> c;
			cout << "请输入设备价格:";
			cin >> b;
			if (b > PRICE__LIMIT) {
				cout << "贵重物品" << endl;
			}
			else {
				cout << "普通物品" << endl;
			}
			break;
		}
		case 0:
			cout << "退出程序" << endl;
			
			break;

		default:
			cout << "输入错误，请重新输入!" << endl;
			break;

		}
	}


	return 0;
}