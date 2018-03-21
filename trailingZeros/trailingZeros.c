
/*
 * n阶乘后面的零是5的次方数
 * temp = 5^1 + 5^2 + 5^3 .......
 * 所以只要n/每个5的次方数
 * result获取每个被5的倍数除的值加起来就是尾部后面的零
 * */

long long trailingZeros(long long n)
{
	long long temp = 5;	//5的倍数值
	long long result = 0;	//结果

	while (temp <= n)	//只要n小于5的倍数值
	{
		result += n / temp;
		temp *= 5;
	}
	return result;
}
