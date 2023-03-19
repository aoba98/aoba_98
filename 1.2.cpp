#include <bits/stdc++.h>
using namespace std;
void Switch(int& a, int& b, int& c);
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	Switch(a, b, c);//调用Switch使abc为升序序列
	cout << a << " " << b << " " << c;
	return 0;
}
void Switch(int& a, int& b, int& c) {//引用传递修改值；由于只需要排序三个数，3次if判断进行交换就保证a，b，c为升序
	if(a<b<c) return;//如果本来就有序，函数结束
	else {
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (b > c) {
		int temp = b;
		b = c;
		c = temp;
	}
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	}
	return;
}