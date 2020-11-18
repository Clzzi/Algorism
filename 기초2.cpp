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
	cout << "큐 데이터는 ";
	printQ(myQ);
	cout << "\n큐이 사이즈 : " << myQ.size();
	cout << "\n큐의 front : " << myQ.front();
	cout << "\n큐의 back : " << myQ.back();
	cout << "\n팝 명령어 사용 후 출력";
	myQ.pop();
	printQ(myQ);
// iterator
	for (auto i = myQ.front(); i != myQ.back(); i++)
		cout << i << " ";
	return 0;

}
