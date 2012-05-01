/*
PROB : fence3
ID :  mfs.dev2
LANG : C++
*/
//éä¼ ç®æ³ huyuanming
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
#define inf 10000000000000.0
#define maxn 155
#define pn 200
int n;
 
struct line {
	double x1, y1, x2, y2;
};
 
struct point {
	double x, y, sum;
};
 
line l[maxn];
point p[pn + 1];
point bp;
 
inline double dis(double x1, double y1, double x2, double y2) {
	return hypot(x1 - x2, y1 - y2);
}
 
inline double min(double a, double b) {
	return a < b ? a : b;
}
 
double count(double x, double y) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		if (l[i].y1 == l[i].y2)
			if (l[i].x1 <= x && x <= l[i].x2 || l[i].x1 >= x && x >= l[i].x2)
				sum += fabs(l[i].y1 - y);
			else
				sum += min(dis(x, y, l[i].x1, l[i].y1),
						   dis(x, y, l[i].x2, l[i].y2));
		else
			if (l[i].y1 <= y && y <= l[i].y2 || l[i].y1 >= y && y >= l[i].y2)
				sum += fabs(l[i].x1 - x);
			else
				sum += min(dis(x, y, l[i].x1, l[i].y1),
						   dis(x, y, l[i].x2, l[i].y2));
	}
	return sum;
}
 
void init() {
	for (int i = 1; i <= pn; i++) {
		p[i].x = (double)(rand() % 100);
		p[i].y = (double)(rand() % 100);
		p[i].sum = count(p[i].x, p[i].y);
	}
	bp.sum = inf;
	p[0].sum = inf;
}
 
int choose() {
	int b = 0;
	for (int i = 1; i <= 10; i++) {
		int k = rand() % pn + 1;
		if (p[k].sum < p[b].sum)
			b = k;
	}
	return b;
}
 
double rate() {
	return (rand() % 140 - 70) / 100.0;
}
 
void mix(int a, int b) {
	point na, nb;
	na.x = (p[a].x + p[b].x) / 2 + (fabs(p[a].x - p[b].x) + 0.1) * rate();
	na.y = (p[a].y + p[b].y) / 2 + (fabs(p[a].y - p[b].y) + 0.1) * rate();
	na.sum = count(na.x, na.y);
	p[rand() % pn + 1] = na;
	if (na.sum < bp.sum)
		bp = na;
}
 
void sim() {
	int a, b;
	a = choose();
	b = choose();
	mix(a, b);
}
 
int main() {
	freopen("fence3.in", "r", stdin);
	freopen("fence3.out", "w", stdout);
	srand(time(NULL));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf%lf%lf", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
	init();
	for (int i = 1; i <= 1000; i++)
		sim();
	printf("%.1lf %.1lf %.1lf\n", bp.x, bp.y, bp.sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
