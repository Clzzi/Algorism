#include<iostream>
#include<queue>

using namespace std;
void printQ(queue<int> q) {
	queue<int> qq = q;
	while (!qq.empty()) {
		cout << "\t" << qq.front();
		qq.pop();
	}
	cout << "\n";
}

int main() {
	queue<int> myQ;
	myQ.push(10);
	myQ.push(20);
	myQ.push(30);
	cout << "ť �����ʹ� ";
	printQ(myQ);
	cout << "\nť�� ������ : " << myQ.size();
	cout << "\nť�� front : " << myQ.front();
	cout << "\nť�� back : " << myQ.back();
	cout << "\n�� ��ɾ� ��� �� ���";
	myQ.pop();
	printQ(myQ);
// iterator
	for (auto i = myQ.front(); i != myQ.back(); i++)
		cout << i << " ";
	return 0;

}
