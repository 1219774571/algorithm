
//递归版本

int aplusb_dg(int a,int b)
{
	if ((a & b) == 0)
		return (a | b);
	return aplusb_dg(a ^ b, (a & b) << 1);
}
