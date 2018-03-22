/* 
 * 找出只含素因子2，3，5 的第 n 大的数
 *
 * 定义一个大小为n的数组u[n]用来存储有序丑数序列。
 * 三个游标u2,u3,u5分别表示乘以2或3或5取得过最新丑数。
 * 下一个丑数等于min(u[u2]*2, u[u3]*3, u[u5]*5)，并根据因子对u2或u3或u5递增。
*/

int min(int x,int y)
{
	return (x > y? y : x);
}

int
nthUglyNumber(int n)
{
	if (n < 1)
		return 0;
	int a,b,c;
	int u[n];
	int i;

	u[0] = 1;
       	a = b = c = 0; //声明三个索引值
	
	for (i = 1; i < n; i++)
	{
		u[i] = min(min(u[a]*2, u[b]*3), u[c]*4); //u[i] = 他们三个中最新的的最小值
		//当取得的值是新的丑数的时候，更新对应的索引值
		if ((u[i] / u[a]) == 2) 
			a++;
		if ((u[i] / u[b]) == 3)
			b++;
		if ((u[i] / u[c]) == 5)
			c++;
	}
	return u[n-1];
}
