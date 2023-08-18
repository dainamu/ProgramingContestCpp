#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;
using ll = long long;

int count_report_num(vector<vector<int>> &children, int x) {

	if (children.at(x).size == 0) {
		return 1;
	}

	int sum = 0;
	for (int i = 0; i < children.at(x).size(); i++) {
		sum += count_report_num(children, children.at(x).at(i));
	}
	sum += 1;
	return sum;

}

int main_EX20() {

	int N;
	cin >> N;

	vector<int> p(N); // �e�g�Dk�̐e�g�D�������z��
	p.at(0) = -1; // 0�ԑg�D�̐e�g�D�͑��݂��Ȃ��̂�-1������Ă����B

	for (int i = 1; i < N; i++) {
		cin >> p.at(i);
	}

	// �g�D�̐��Ɖp����2�����z������
	vector<vector<int>> children(N); // ����g�D�̎q�g�D�̔ԍ��ꗗ
	
	for (int i = 1; i < N; i++) {
		int parent = p.at(i); // i�Ԃ̐e�]�؂̔ԍ�
		children.at(parent).push_back(i); // parent�̎q�g�D�ꗗ��i�Ԃ�ǉ�

	}

	for (int i = 0; i < N; i++) {
		cout << count_report_num(children, i) << "\n";
	}

	return 0;
}