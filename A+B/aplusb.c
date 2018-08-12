
/*
 * 求两个整数a和b的和，不使用+运算符
 * */
int aplusb(int a,int b)
{
        int carry = a & b; //检测是否有进位
        while (carry)
        {
            carry = (a & b) << 1; //处理进位
            a = a ^ b; //去除进位的值,
            b = carry;
        }
        return a | b;
}
