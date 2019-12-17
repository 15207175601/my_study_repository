#include<stdio.h>
#include<math.h>
#define N 2.0          //n为湿度的加速率常数，一般介于2，3之间，一般取2
#define K 0.000086     //玻尔兹曼常数K=0.000086eV/k
#define EA 0.6         //激活能（电子产品）𝐸_𝑎=0.6𝑒𝑉
#define TU 293.0       //常态绝对温度𝑇𝑢=20℃=293K
#define RHU 50.0       //常态相对湿度𝑅𝐻𝑢=50% 𝑅𝐻
int main(void)
{
	double T, TS, RHS, AF;

	printf("温度：");
	scanf_s("%lf", &T);
	TS = 273.0 + T;
	printf("湿度：");
	scanf_s("%lf", &RHS);
	AF = pow((RHS / RHU), N)*exp((1 / TU - 1 / TS)*EA / K);
	printf("加速因子AF= %lf", AF);

	getchar();
	getchar();

	return 0;

}