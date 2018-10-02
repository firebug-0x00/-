#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;


class control {									//控制类
public:
	void menu();
	void base16();
	void base32();
	void base32_out(int a);
	void base64();
	void base64_out(int b);
};

//函数名：menu
//功能：提供菜单选项
//无参数	无返回值
void control::menu()							//菜单函数
{
	int flag = 0;
	system("cls");
	cout << "\n\t1.base操作（16位）";
	cout << "\n\t2.base操作（32位）";
	cout << "\n\t3.base操作(64位)";
	cout << "\n\t4.退出程序";
	cout << "\n\t请输入你需要的操作：";
	cin >> flag;
	switch(flag)
	{
	case 1:base16(); break;
	case 2:base32(); break;
	case 3:base64(); break;
	case 4:system("cls");
		cout << "\n\t感想使用";
		Sleep(1200);
		exit(0);
		break;
	default:system("cls");
		cout << "\n\t请输入正确选项";
		Sleep(1200);
		break;
	}
}

//函数名：base
//功能：提供base16的编码与解码
//无参数	无返回值
void control::base16()							//base16函数
{
	while (1)
	{
		int flag = 3;
		system("cls");
		cout << "\n\t0.返回菜单";
		cout << "\n\t1.base16->字符串（ASCⅡ）";
		cout << "\n\t2.字符串（ASCⅡ）->base16";
		cout << "\n\t请输入你需要的操作：";
		cin >> flag;
		if (0 == flag)							//返回菜单
		{
			return;
		}
		else if (1 == flag)						//base16转字符串
		{
			while (1)
			{
				int choice = 0;
				vector<char>data;
				char ch;
				system("cls");
				cout << "\n\t请输入base16数据：\n\t";
				getchar();
				while (ch = cin.get())
				{
					if (ch == '\n')
					{
						break;
					}
					data.push_back(ch);
				}
				int length = data.size();
				int i;
				vector<int>temp(length, 0);
				for (i = 0; i < length; i++)
				{
					switch (data[i])
					{
					case '0': temp[i] = 0; break;
					case '1': temp[i] = 1; break;
					case '2': temp[i] = 2; break;
					case '3': temp[i] = 3; break;
					case '4': temp[i] = 4; break;
					case '5': temp[i] = 5; break;
					case '6': temp[i] = 6; break;
					case '7': temp[i] = 7; break;
					case '8': temp[i] = 8; break;
					case '9': temp[i] = 9; break;
					case 'A': temp[i] = 10; break;
					case 'B': temp[i] = 11; break;
					case 'C': temp[i] = 12; break;
					case 'D': temp[i] = 13; break;
					case 'E': temp[i] = 14; break;
					case 'F': temp[i] = 15; break;
					}
				}
				int j = 0;
				vector<long>data_1((length / 2) + 1, 0);
				for (i = 0; i < length; i++)
				{
					int a = 0;
					data_1[j] = data_1[j] << 4;
					a = temp[i] & 15;
					data_1[j] = data_1[j] | a;
					if (0 == ((i + 1) % 2))
					{
						j++;
					}
				}
				length = data_1.size();
				cout << "\n\t";
				for (i = 0; i < length; i++)
				{
					cout << (char)data_1[i];
				}
				cout << "\n";
				cout << "\n\t1.返回上一级";
				cout << "\n\t2.返回主菜单";
				cout << "\n\t3.继续解码";
				cout << "\n\t请选择：";
				cin >> choice;
				if (1 == choice)					//返回上一级
				{
					data.clear();
					temp.clear();
					data_1.clear();
					break;
				}
				else if (2 == choice)				//返回主菜单
				{
					data.clear();
					temp.clear();
					data_1.clear();
					return;
				}
				else if (3 == choice)				//继续解码
				{
					data.clear();
					temp.clear();
					data_1.clear();
					continue;
				}
				else                                //当输入非提示内容时所采取措施
				{	
					data.clear();
					temp.clear();
					data_1.clear();
					cout << "\n\t自动返回上一级";
					Sleep(1200);
					break;
				}
			}

		}
		else if (2 == flag)							//字符串转base16
		{
			while (1)
			{
				int choice = 0;
				vector<char>data;
				char ch;
				system("cls");
				cout << "\n\t请输入字符串：\n\t";
				getchar();
				while (ch = cin.get())
				{
					if (ch == '\n')
					{
						break;
					}
					data.push_back(ch);
				}
				int length = data.size();
				int i;
				vector<int>temp(length, 0);
				for (i = 0; i < length; i++)
				{
					temp[i] = (int)data[i];
				}
				vector<long>data_1(length * 2, 0);
				int j = 0;
				for (i = 0; i < length; i++)
				{
					int a = 0;
					int b = 0;
					int c = temp[i];
					a = c & 15;
					c = c >> 4;
					b = c & 15;
					data_1[j] = b;
					data_1[j + 1] = a;
					j += 2;
				}
				length = data_1.size();
				cout << "\n\t";
				for (i = 0; i < length; i++)
				{
					switch (data_1[i])
					{
					case 0:cout << "0"; break;
					case 1:cout << "1"; break;
					case 2:cout << "2"; break;
					case 3:cout << "3"; break;
					case 4:cout << "4"; break;
					case 5:cout << "5"; break;
					case 6:cout << "6"; break;
					case 7:cout << "7"; break;
					case 8:cout << "8"; break;
					case 9:cout << "9"; break;
					case 10:cout << "A"; break;
					case 11:cout << "B"; break;
					case 12:cout << "C"; break;
					case 13:cout << "D"; break;
					case 14:cout << "E"; break;
					case 15:cout << "F"; break;
					}
				}
				cout << "\n";
				cout << "\n\t1.返回上一级";
				cout << "\n\t2.返回主菜单";
				cout << "\n\t3.继续编码";
				cout << "\n\t请选择：";
				cin >> choice;
				if (1 == choice)					//返回上一级
				{
					data.clear();
					temp.clear();
					data_1.clear();
					break;
				}
				else if (2 == choice)				//返回主菜单
				{
					data.clear();
					temp.clear();
					data_1.clear();
					return;
				}
				else if (3 == choice)				//继续解码
				{
					data.clear();
					temp.clear();
					data_1.clear();
					continue;
				}
				else                                //当输入非提示内容时所采取措施
				{
					data.clear();
					temp.clear();
					data_1.clear();
					cout << "\n\t自动返回上一级";
					Sleep(1200);
					break;
				}
			}
		}
		else
		{
			system("cls");
			cout << "\n\t请输入正确选项";
			Sleep(1200);
		}
	}
}

//函数名：base32
//功能：提供base32的编码与解码
//无参数	无返回值
void control::base32()								//base32函数
{
	while (1)
	{
		int flag = 3;
		system("cls");
		cout << "\n\t0.返回菜单";
		cout << "\n\t1.base32->字符串（ASCⅡ）";
		cout << "\n\t2.字符串（ASCⅡ）->base32";
		cout << "\n\t请输入你需要的操作：";
		cin >> flag;
		if (0 == flag)							//返回菜单
		{
			return;
		}
		else if (1 == flag)						//base32转字符串
		{
			while (1)
			{
				int choice = 0;
				vector<char>data;
				char ch;
				system("cls");
				cout << "\n\t请输入base32数据：\n\t";
				getchar();
				while (ch = cin.get())
				{
					if (ch == '\n')
					{
						break;
					}
					data.push_back(ch);
				}
				int length = data.size();
				int i;
				vector<int>temp(length, 0);
				for (i = 0; i < length; i++)
				{
					switch (data[i])
					{
					case 'A': temp[i] = 0; break;
					case 'B': temp[i] = 1; break;
					case 'C': temp[i] = 2; break;
					case 'D': temp[i] = 3; break;
					case 'E': temp[i] = 4; break;
					case 'F': temp[i] = 5; break;
					case 'G': temp[i] = 6; break;
					case 'H': temp[i] = 7; break;
					case 'I': temp[i] = 8; break;
					case 'J': temp[i] = 9; break;
					case 'K': temp[i] = 10; break;
					case 'L': temp[i] = 11; break;
					case 'M': temp[i] = 12; break;
					case 'N': temp[i] = 13; break;
					case 'O': temp[i] = 14; break;
					case 'P': temp[i] = 15; break;
					case 'Q': temp[i] = 16; break;
					case 'R': temp[i] = 17; break;
					case 'S': temp[i] = 18; break;
					case 'T': temp[i] = 19; break;
					case 'U': temp[i] = 20; break;
					case 'V': temp[i] = 21; break;
					case 'W': temp[i] = 22; break;
					case 'X': temp[i] = 23; break;
					case 'Y': temp[i] = 24; break;
					case 'Z': temp[i] = 25; break;
					case '2': temp[i] = 26; break;
					case '3': temp[i] = 27; break;
					case '4': temp[i] = 28; break;
					case '5': temp[i] = 29; break;
					case '6': temp[i] = 30; break;
					case '7': temp[i] = 31; break;
					}
				}
				int j = 0;
				vector<long long>data_1((length / 8) + 1, 0);
				for (i = 0; i < length; i++)
				{
					int a = 0;
					data_1[j] = data_1[j] << 5;
					a = temp[i] & 31;
					data_1[j] = data_1[j] | a;
					if (0 == ((i + 1) % 8))
					{
						j++;
					}
				}
				length = data_1.size();
				cout << "\n\t";
				for (i = 0; i < length; i++)
				{
					int a = 0;
					int b = 0;
					int c = 0;
					int d = 0;
					int e = 0;
					long long f = 0;
					f = data_1[i];
					a = f & 255;
					f = f >> 8;
					b = f & 255;
					f = f >> 8;
					c = f & 255;
					f = f >> 8;
					d = f & 255;
					f = f >> 8;
					e = f & 255;
					cout << (char)e << (char)d << (char)c << (char)b << (char)a;
				}
				cout << "\n";
				cout << "\n\t1.返回上一级";
				cout << "\n\t2.返回主菜单";
				cout << "\n\t3.继续解码";
				cout << "\n\t请选择：";
				cin >> choice;
				if (1 == choice)					//返回上一级
				{
					data.clear();
					temp.clear();
					data_1.clear();
					break;
				}
				else if (2 == choice)				//返回主菜单
				{
					data.clear();
					temp.clear();
					data_1.clear();
					return;
				}
				else if (3 == choice)				//继续解码
				{
					data.clear();
					temp.clear();
					data_1.clear();
					continue;
				}
				else                                //当输入非提示内容时所采取措施
				{
					data.clear();
					temp.clear();
					data_1.clear();
					cout << "\n\t自动返回上一级";
					Sleep(1200);
					break;
				}
			}

		}
		else if (2 == flag)							//字符串转base32
		{
		int count = 0;
			while (1)
			{
				int choice = 0;
				vector<char>data;
				char ch;
				system("cls");
				cout << "\n\t请输入字符串：\n\t";
				getchar();
				while (ch = cin.get())
				{
					if (ch == '\n')
					{
						break;
					}
					data.push_back(ch);
				}
				int length = data.size();
				int i;
				vector<int>temp(length, 0);
				for (i = 0; i < length; i++)
				{
					temp[i] = (int)data[i];
				}
				vector<long long>data_1((length/5)+1, 0);
				int j = 0;
				int k = 0;
				if (length % 5 == 0)
				{
					k = length;
				}
				else 
				{
					k = length + (5 - (length % 5));
				}
				for (i = 0; i < k; i++)
				{
					data_1[j] = data_1[j] << 8;
					int a;
					if (i < length)
					{
						a = temp[i] & 255;
					}
					else
					{
						a = 0;
						count++;
					}
					data_1[j] = data_1[j] | a;
					if ((i + 1) % 5 == 0)
					{
						j++;
					}
				}
				length = data_1.size();
				for (i = 0; i < length; i++)
				{
					int num[8] = { 0 };
					long long a = data_1[i];
					num[0] = a & 31;
					a = a >> 5;
					num[1] = a & 31;
					a = a >> 5;
					num[2] = a & 31;
					a = a >> 5;
					num[3] = a & 31;
					a = a >> 5;
					num[4] = a & 31;
					a = a >> 5;
					num[5] = a & 31;
					a = a >> 5;
					num[6] = a & 31;
					a = a >> 5;
					num[7] = a & 31;
					cout << "\n\t";
					base32_out(num[7]);
					base32_out(num[6]);
					base32_out(num[5]);
					base32_out(num[4]);
					base32_out(num[3]);
					base32_out(num[2]);
					base32_out(num[1]);
					base32_out(num[0]);
					int count_1 = 0;
					{
						count_1 = (count * 8) / 5;
					}
					for (i = 0; i < count_1; i++)
					{
						cout << "\b";
					}
					for (i = 0; i < count_1; i++)
					{
						cout << "=";
					}
					cout << "\n";
				}
				cout << "\n\t1.返回上一级";
				cout << "\n\t2.返回主菜单";
				cout << "\n\t3.继续编码";
				cout << "\n\t请选择：";
				cin >> choice;
				if (1 == choice)					//返回上一级
				{
					data.clear();
					temp.clear();
					data_1.clear();
					break;
				}
				else if (2 == choice)				//返回主菜单
				{
					data.clear();
					temp.clear();
					data_1.clear();
					return;
				}
				else if (3 == choice)				//继续解码
				{
					data.clear();
					temp.clear();
					data_1.clear();
					continue;
				}
				else                                //当输入非提示内容时所采取措施
				{
					data.clear();
					temp.clear();
					data_1.clear();
					cout << "\n\t自动返回上一级";
					Sleep(1200);
					break;
				}
			}
		}
		else
		{
			system("cls");
			cout << "\n\t请输入正确选项";
			Sleep(1200);
		}
	}
}

//函数名：base32_out
//功能：将计算好的数值转化为base32的标识符
//参数：计算好的整形数	
//无返回值
void control::base32_out(int a)
{
	switch (a)
	{
	case 0:cout << "A"; break;
	case 1:cout << "B"; break;
	case 2:cout << "C"; break;
	case 3:cout << "D"; break;
	case 4:cout << "E"; break;
	case 5:cout << "F"; break;
	case 6:cout << "G"; break;
	case 7:cout << "H"; break;
	case 8:cout << "I"; break;
	case 9:cout << "J"; break;
	case 10:cout << "K"; break;
	case 11:cout << "L"; break;
	case 12:cout << "M"; break;
	case 13:cout << "N"; break;
	case 14:cout << "O"; break;
	case 15:cout << "P"; break;
	case 16:cout << "Q"; break;
	case 17:cout << "R"; break;
	case 18:cout << "S"; break;
	case 19:cout << "T"; break;
	case 20:cout << "U"; break;
	case 21:cout << "V"; break;
	case 22:cout << "W"; break;
	case 23:cout << "X"; break;
	case 24:cout << "Y"; break;
	case 25:cout << "Z"; break;
	case 26:cout << "2"; break;
	case 27:cout << "3"; break;
	case 28:cout << "4"; break;
	case 29:cout << "5"; break;
	case 30:cout << "6"; break;
	case 31:cout << "7"; break;
	}
}

//函数名：base64
//功能：提供base64的编码与解码
//无参数	无返回值
void control::base64()							//base64函数
{
	while (1)
	{
		int flag = 3;
		system("cls");
		cout << "\n\t0.返回菜单";
		cout << "\n\t1.base64->字符串（ASCⅡ）";
		cout << "\n\t2.字符串（ASCⅡ）->base64";
		cout << "\n\t请输入你需要的操作：";
		cin >> flag;
		if (0 == flag)							//返回菜单
		{
			return;
		}
		else if (1 == flag)						//base64转字符串
		{
			while (1)
			{
				int choice = 0;
				vector<char>data;
				char ch;
				system("cls");
				cout << "\n\t请输入base64数据：\n\t";
				getchar();
				while (ch = cin.get())
				{
					if (ch == '\n')
					{
						break;
					}
					data.push_back(ch);
				}
				int length = data.size();
				int i;
				vector<int>temp(length, 0);
				for (i = 0; i < length; i++)
				{
					switch (data[i])
					{
					case 'A': temp[i] = 0; break;
					case 'B': temp[i] = 1; break;
					case 'C': temp[i] = 2; break;
					case 'D': temp[i] = 3; break;
					case 'E': temp[i] = 4; break;
					case 'F': temp[i] = 5; break;
					case 'G': temp[i] = 6; break;
					case 'H': temp[i] = 7; break;
					case 'I': temp[i] = 8; break;
					case 'J': temp[i] = 9; break;
					case 'K': temp[i] = 10; break;
					case 'L': temp[i] = 11; break;
					case 'M': temp[i] = 12; break;
					case 'N': temp[i] = 13; break;
					case 'O': temp[i] = 14; break;
					case 'P': temp[i] = 15; break;
					case 'Q': temp[i] = 16; break;
					case 'R': temp[i] = 17; break;
					case 'S': temp[i] = 18; break;
					case 'T': temp[i] = 19; break;
					case 'U': temp[i] = 20; break;
					case 'V': temp[i] = 21; break;
					case 'W': temp[i] = 22; break;
					case 'X': temp[i] = 23; break;
					case 'Y': temp[i] = 24; break;
					case 'Z': temp[i] = 25; break;
					case 'a': temp[i] = 26; break;
					case 'b': temp[i] = 27; break;
					case 'c': temp[i] = 28; break;
					case 'd': temp[i] = 29; break; 
					case 'e': temp[i] = 30; break;
					case 'f': temp[i] = 31; break;
					case 'g': temp[i] = 32; break;
					case 'h': temp[i] = 33; break;
					case 'i': temp[i] = 34; break;
					case 'j': temp[i] = 35; break;
					case 'k': temp[i] = 36; break;
					case 'l': temp[i] = 37; break;
					case 'm': temp[i] = 38; break;
					case 'n': temp[i] = 39; break;
					case 'o': temp[i] = 40; break;
					case 'p': temp[i] = 41; break;
					case 'q': temp[i] = 42; break;
					case 'r': temp[i] = 43; break;
					case 's': temp[i] = 44; break;
					case 't': temp[i] = 45; break;
					case 'u': temp[i] = 46; break;
					case 'v': temp[i] = 47; break;
					case 'w': temp[i] = 48; break;
					case 'x': temp[i] = 49; break;
					case 'y': temp[i] = 50; break;
					case 'z': temp[i] = 51; break;
					case '0': temp[i] = 52; break;
					case '1': temp[i] = 53; break;
					case '2': temp[i] = 54; break;
					case '3': temp[i] = 55; break;
					case '4': temp[i] = 56; break;
					case '5': temp[i] = 57; break;
					case '6': temp[i] = 58; break;
					case '7': temp[i] = 59; break;
					case '8': temp[i] = 60; break;
					case '9': temp[i] = 61; break;
					case '+': temp[i] = 62; break;
					case '/': temp[i] = 63; break;
					}
				}
				int j = 0;
				vector<long>data_1((length / 3) + 1, 0);
				for (i = 0; i < length; i++)
				{
					int a = 0;
					data_1[j] = data_1[j] << 6;
					a = temp[i] & 63;
					data_1[j] = data_1[j] | a;
					if (0 == ((i + 1) % 4))
					{
						j++;
					}
				}
				length = data_1.size();
				cout << "\n\t";
				for (i = 0; i < length; i++)
				{
					int a = 0;
					int b = 0;
					int c = 0;
					long f = 0;
					f = data_1[i];
					a = f & 255;
					f = f >> 8;
					b = f & 255;
					f = f >> 8;
					c = f & 255;
					cout << (char)c;
					cout << (char)b;
					cout << (char)a;
				}
				cout << "\n";
				cout << "\n\t1.返回上一级";
				cout << "\n\t2.返回主菜单";
				cout << "\n\t3.继续解码";
				cout << "\n\t请选择：";
				cin >> choice;
				if (1 == choice)					//返回上一级
				{
					data.clear();
					temp.clear();
					data_1.clear();
					break;
				}
				else if (2 == choice)				//返回主菜单
				{
					data.clear();
					temp.clear();
					data_1.clear();
					return;
				}
				else if (3 == choice)				//继续解码
				{
					data.clear();
					temp.clear();
					data_1.clear();
					continue;
				}
				else                                //当输入非提示内容时所采取措施
				{
					data.clear();
					temp.clear();
					data_1.clear();
					cout << "\n\t自动返回上一级";
					Sleep(1200);
					break;
				}
			}

		}
		else if (2 == flag)							//字符串转base64
		{
			while (1)
			{
				int choice = 0;
				int count = 0;
				vector<char>data;
				char ch;
				system("cls");
				cout << "\n\t请输入字符串：\n\t";
				getchar();
				while (ch = cin.get())
				{
					if (ch == '\n')
					{
						break;
					}
					data.push_back(ch);
				}
				int length = data.size();
				int i;
				vector<int>temp(length, 0);
				for (i = 0; i < length; i++)
				{
					temp[i] = (int)data[i];
				}
				vector<long>data_1((length /3)+1, 0);
				int j = 0;
				int k = 0;
				{
					if (length % 3 == 0)
					{
						k = length;
					}
					else
					{
						k = length + (3 - (length % 3));
					}
				}
				for (i = 0; i < k; i++)
				{
					int a = 0;
					data_1[j] = data_1[j] << 8;
					if (i < length)
					{
						a = temp[i] & 255;
					}
					else
					{
						a = 0;
						count++;
					}
					data_1[j] = data_1[j] | a;
					if (((i + 1) % 3) == 0)
					{
						j++;
					}
				}
				length = data_1.size();
				cout << "\n\t";
				for (i = 0; i < length; i++)
				{
					int num[4] = { 0 };
					long f = data_1[i];
					num[0] = f & 63;
					f = f >> 6;
					num[1] = f & 63;
					f = f >> 6;
					num[2] = f & 63;
					f = f >> 6;
					num[3] = f & 63;
					base64_out(num[3]);
					base64_out(num[2]);
					base64_out(num[1]);
					base64_out(num[0]);
				}
				int count_1 = 0;
				{
					count_1 = (count * 8) / 6;
				}
				for (i = 0; i < count_1; i++)
				{
					cout << "\b";
				}
				for (i = 0; i < count_1; i++)
				{
					cout << "=";
				}
				cout << "\n";
				cout << "\n\t1.返回上一级";
				cout << "\n\t2.返回主菜单";
				cout << "\n\t3.继续编码";
				cout << "\n\t请选择：";
				cin >> choice;
				if (1 == choice)					//返回上一级
				{
					data.clear();
					temp.clear();
					data_1.clear();
					break;
				}
				else if (2 == choice)				//返回主菜单
				{
					data.clear();
					temp.clear();
					data_1.clear();
					return;
				}
				else if (3 == choice)				//继续解码
				{
					data.clear();
					temp.clear();
					data_1.clear();
					continue;
				}
				else                                //当输入非提示内容时所采取措施
				{
					data.clear();
					temp.clear();
					data_1.clear();
					cout << "\n\t自动返回上一级";
					Sleep(1200);
					break;
				}
			}
		}
		else
		{
			system("cls");
			cout << "\n\t请输入正确选项";
			Sleep(1200);
		}
	}
}

//函数名：base64_out
//功能：将计算好的数值转化为base64的标识符
//参数：计算好的整形数	
//无返回值
void control::base64_out(int a)
{
	switch (a)
	{
	case 0:cout << "A"; break;
	case 1:cout << "B"; break;
	case 2:cout << "C"; break;
	case 3:cout << "D"; break;
	case 4:cout << "E"; break;
	case 5:cout << "F"; break;
	case 6:cout << "G"; break;
	case 7:cout << "H"; break;
	case 8:cout << "I"; break;
	case 9:cout << "J"; break;
	case 10:cout << "K"; break;
	case 11:cout << "L"; break;
	case 12:cout << "M"; break;
	case 13:cout << "N"; break;
	case 14:cout << "O"; break;
	case 15:cout << "P"; break;
	case 16:cout << "Q"; break;
	case 17:cout << "R"; break;
	case 18:cout << "S"; break;
	case 19:cout << "T"; break;
	case 20:cout << "U"; break;
	case 21:cout << "V"; break;
	case 22:cout << "W"; break;
	case 23:cout << "X"; break;
	case 24:cout << "Y"; break;
	case 25:cout << "Z"; break;
	case 26:cout << "a"; break;
	case 27:cout << "b"; break;
	case 28:cout << "c"; break;
	case 29:cout << "d"; break;
	case 30:cout << "e"; break;
	case 31:cout << "f"; break;
	case 32:cout << "g"; break;
	case 33:cout << "h"; break;
	case 34:cout << "i"; break;
	case 35:cout << "j"; break;
	case 36:cout << "k"; break;
	case 37:cout << "l"; break;
	case 38:cout << "m"; break;
	case 39:cout << "n"; break;
	case 40:cout << "o"; break;
	case 41:cout << "p"; break;
	case 42:cout << "q"; break;
	case 43:cout << "r"; break;
	case 44:cout << "s"; break;
	case 45:cout << "t"; break;
	case 46:cout << "u"; break;
	case 47:cout << "v"; break;
	case 48:cout << "w"; break;
	case 49:cout << "x"; break;
	case 50:cout << "y"; break;
	case 51:cout << "z"; break;
	case 52:cout << "0"; break;
	case 53:cout << "1"; break;
	case 54:cout << "2"; break;
	case 55:cout << "3"; break;
	case 56:cout << "4"; break;
	case 57:cout << "5"; break;
	case 58:cout << "6"; break;
	case 59:cout << "7"; break;
	case 60:cout << "8"; break;
	case 61:cout << "9"; break;
	case 62:cout << "+"; break;
	case 64:cout << "/"; break;
	}
}

int main()
{
	control user;
	while (1)
	{
		user.menu();
	}
	return 0;
}