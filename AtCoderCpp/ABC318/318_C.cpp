#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

int main() {

	int n, d, p;
	cin >> n >> d >> p;

	vector<int> f(n);

	rep(i, n) cin >> f[i];

	// f���\�[�g
	sort(f.begin(), f.end());

	// f�̗ݐϘa�����߂Ă���
	vector<ll> s(n + 1);

	rep(i, n) s[i + 1] = s[i] + f[i];

	ll ans = 1e18; // ������傫�����ŏ�����
	// ���V�p�X�������V�~�����[�V����
	rep(i, 1e9) { // �\���ɑ傫������

		// �������ق�����ʏ헿�����g�������@d��1�Z�b�g�̖���
		int r = max(0, n - i * d);

		ll now = s[r] + (ll)p * i; // s�͗ݐϘa�������Ă��� + ���V�p�X�̒l�i * �Z�b�g��
		ans = min(now, ans);

		if (r == 0) break;
	}

	cout << ans << endl;

	return 0;

}