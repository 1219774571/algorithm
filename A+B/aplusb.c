
/*
 * 求两个整数a和b的和，不使用+运算符
 * */
int aplusb(int a,int b)
{
	int c;
	if ((a & b) == 0)//说明是正数
	{
		return (a | b);
	}
	//其他是负数的可能
	while ((a & b) != 0)
	{
		c = a ^ b;//获取他们的补位，就是除去进位的值
		b = (a & b) << 1;//获取他们的进位，然后左移一位
		a = c;
	}
	return (a | b);
}
