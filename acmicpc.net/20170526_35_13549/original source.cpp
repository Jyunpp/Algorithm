//20170525 ~ 20170526 

//같은 깊이더라도 걸린 시간 초가 다르다.
//찾자마자 끝내도 될까 과연?
//3깊이에서 3초로 찾았지만,
//5깊이에서 2초로 찾을 수 있지 않을까?

//순간이동 한 방법보다 기어가서도착했을때 더 작은값이 나올수있는지 의심이 들면,
//순간이동해서 도착했을때 안끝내고 기어가서 도착할때까지 루프돌리다가 비교후 끝내면 된다!
//good
//근데 내생각엔 그냥 맞을듯
//=> 답은 그냥해도 맞음. 그리고 시간도 별로 안걸림.

//20170525 시간 초과
//시간 초과 원인은, 2배부분 범위 <=100000만 되면 q에 넣었는데, 
//사실 x가 0이었으면 무한루프.. 그게 문제★
//그리고, 그걸 개선 한 다음에도 문제가 안풀렸는데 원인은 연산의 우선순위문제★
//for문의 조건 부분 i <= 100000 && i != 0 로 적었지만, 연산의 우선순위때문에
// (i <= 100000) && (i != 0) 로 적어야 한다!!! ★★★
#include <iostream>
#include <queue>
using namespace std;
#define INF 654321

int n, k;
int dp[100001];

int main() {
	cin >> n >> k;
	if (n == k) { cout << 0 << endl; return 0; }
	if (n > k) { cout << n - k << endl; return 0; }
	for (int i = 0; i < 100001; i++) {
		dp[i] = INF;
	}
	queue<int> q;
	q.push(n);
	dp[n] = 0;
	while (!q.empty()) {
		int x = q.front();
		//cout << x << endl;
		q.pop();
		//처음에 2^n*x로 봤다가, 쓸모없는 연산이 너무 많아져서 2^n*x는 답인지만 확인하기로 . 
		//(2^n*x + 1) & (2^n*x - 1)
		//i!=0조건필요. 아니면 무한루프..
		for (int i = x * 2; (i <= 100000) && (i != 0); i *= 2) {
			//q에 넣진 말고 dp값만 바꿔주자. 재방문 방지.
			if (dp[i] > dp[x]) { dp[i] = dp[x]; }
			//2^n*x - 1 부분.
			if (dp[i - 1] > dp[x] + 1) {
				dp[i - 1] = dp[x] + 1;
				q.push(i - 1);
			}
			//2^n*x + 1 부분. 이 떄, 2*은 범위 속하지만 2*x +1 은 안속할 수 있음. 
			if (i != 100000 && dp[i + 1] > dp[x] + 1) {
				dp[i + 1] = dp[x] + 1;
				q.push(i + 1);
			}
		}
		//if (dp[k] != INF) { break; }
		//x-1
		if (x - 1 >= 0 && dp[x - 1] > dp[x] + 1) {
			dp[x - 1] = dp[x] + 1;
			q.push(x - 1);
		}
		//if (dp[k] != INF) { break; }
		//x+1
		if (x + 1 <= 100000 && dp[x + 1] > dp[x] + 1) {
			dp[x + 1] = dp[x] + 1;
			q.push(x + 1);
		}
		//if (dp[k] != INF) { break; }
	}
	cout << dp[k] << endl;
	/*cin >> n;*/
	return 0;
}