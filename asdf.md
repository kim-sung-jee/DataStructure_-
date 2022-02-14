# 최적화 문제 결정 문제로 바꿔 풀기

> 최적화 문제를 결정문제로 바꾼 뒤, 이것을 이분법을 이용해 해결하는 방법

* 최적화 문제의 반환 값은 대개 실수나 정수이므로 답의 경우의 수가 무한한 데 반해,
* 결정 문제는 두 가지 답만이 있을 수 있다.

다음은 여행하는 외판원 문제(TSP)를 최적화 문제와 결정 문제로 표현한 예시이다.

* optimize(G)=그래프 G의 모든 정점을 한 번씩 방문하고 시작점으로 돌아오는 *최단 경로의 길이*를 반환한다.(최적화 문제)
* decision(G,x)= 그래프 G의 모든 정점을 한 번씩 방문하고 시작점으로 돌아오면서 길이가 *x 이하인 경로의 존재 여부*를 반환한다.(결정 문제)

> optimize()는 가장 짧은 경로의 길이를 실수로 반환, decision()은 x보다 짧은 경로가 있는지 여부를 반환


# 최적화 문제와 결정 문제의 관계

> 같은 문제를 최적화문제 형태와 결정 문제 형태로 만들었을 때 비교

1. 두 문제 형태가 똑같이 어려운 경우
2. 최적화 문제가 더 어려운 경우

> 결정문제 난이도 <= 최적화문제 난이도


# 어떤 질문을 할 것인가?

1. "카메라들 간의 최소 간격이 **gap 이상인 방법**이 있는가?
2. "카메라들 간의 최소 간격이 **gap인 방법**이 있는가?



# 예제: DARPA Grand Challenge

optimize(locations,cameras)= 카메라를 설치할 수 있는 위치 locations과 카메라의 수 cameras가 주어질 때, 카메라 간 최소 간격의 최대치를 반환.

결정문제로 바꾸면

decision(locations, cameras, gap)=카메라를 설치할 수 있는 위치 locations와 카메라의 수 cameras가 주어질 때, 이들을 적절히 배치해 모든 카메라의 간격이 **gap 이상**이 되도록 하는 방법
이 있는지 판단
```cpp
bool decision(const vector<double>& location, int cameras, double gap) {
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(); i++) {
		if (limit <= location[i])
			++installed;
		limit = location[i] + gap;
	}
	return installed >= cameras;
}

double optimize(const vector<double>& location, int cameras) {
	double lo = 0, hi = 241;
	for (int it = 0; it < 100; it++) {
		double mid = (lo + hi) / 2.0;
		if (decision(location, cameras, mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}
```


> ** location이 정렬되어 있어야만 448p 의 그림 12.1 (a)와 같은 형태가 성립한다**


> 카메라 설치할지 말지 선택하는 decision은 탐욕법이다

# 이분법의 함정
이 문제의 답은 항상 입력으로 주어진 두 장소 간의 거리이기 때문에, 존재할 수 있는 답의 후보들은 최대 (n-1)n/2 가지 이다.

만약  (n-1)n/2 가지를 답의 후보를 두고 이 목록에서 이분탐색을 시도하면 오차가 커질 수 있다.

탐색 범위를 좀더 넓게? 유연하게 두고 해야된다.

# 최적화 문제 결정 문제로 바꾸기 레시피

1. "가장 좋은 답은 무엇인가?"라는 최적화 문제를 "x 혹은 그보다 좋은 답이 있는가?"라는 결정 문제 형태로 바꾼다.
2. 결정 문제를 쉽게 풀 수 있는 방법이 있는지 찾아본다.
3. 결정 문제를 내부적으로 이용하는 이분법 알고리즘을 작성한다.

# 12.2 문제:남극 기지

```cpp
int n;
double dist[101][101];
bool decision(double d) {
	vector<bool> visited(n, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		++seen;
		for(int there =0; there <n ;++there)
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				q.push(there);
		}
	}
	return seen == n;
}

double optimize() {
	double lo = -0, hi = 1416.00;
	for (int it = 0; it < 100; it++) {
		double mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}
```

*  optimize(P)=P에 주어진 기지들을 모두 연결하는 연락망을 구축할 때 가능한 최소 무전기 반경은 얼마인가?(최적화 문제)
*  결정 문제로 바꾸면
*  decision(P,d)= 모든 기지를 하나로 연결하되, 가장 먼 두 기지 간의 거리가 d이하인 연락망이 있는가?


> 너비 우선 탐색을 이용한다. if문 내의 dist[here][there]<=d 가 성립할 때 탐색을 이어나감에 유의한다



# 12.4 문제 : 캐나다 여행

최적화 문제는 아니지만 문제를 푸는 방식은 원래 문제를 결정 문제로 바꾸는 데 있다.

> K번째 표지판의 위치는 어디인가라는 문제를 다음과 같이 바꿔봅니다.

* decision(x)=시작점부터 x미터 지점까지 가면서 K개 이상의 표지판을 만날 수 있는가?
* decision(D-1)=false, decision(D)=true 여야 한다는 뜻이다
```cpp
int n, k;
int l[5000], m[5000], g[5000];
bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < n; i++)
  // 표지판을 볼 수 있는 dist 라면
  // 몇개의 표지판을 볼 수 있는지 계산한다.
		if (dist >= l[i] - m[i])
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
      //t or f 리턴
	return ret >= k;
}

int optimize1() {
	int lo = -1, hi = 8030001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}
```
* optimize에서 if(decision(mid))가 참이라면 상한을 줄여주고
* false 라면 하한을 늘려준다


# 문제 12.6 : 수강 철회


> decision(x) = 적절히 과목들을 철회해 누적 등수 x 이하가 될 수 있을까?
> 
