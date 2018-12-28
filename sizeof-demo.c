/* *
* 2018年12月29日00:40:23
* sizeof关键字含义
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
	char buf0[10];
	char buf1[2][5];
	char *buf2[]={"12345","12345","12345","12345","12345","12345"};
	char **tmp = buf2;
	

	char *p = buf0;
	
    // sizeofI(数组) 返回数组所有元素占有的内存空间字节数       
	printf("sizeof(buf0)=%d,sizeof(p)=%d\r\n",sizeof(buf0),sizeof(p));
	printf("sizeof(buf1)=%d,sizeof(buf1[1])=%d\r\n",sizeof(buf1),sizeof(buf1[1]));
    // buf2是指针数组。sizeof(指针) 返回计算机系统的地址字节数。32位系统，返回4。
	printf("sizeof(buf2)=%d,sizeof(buf2[1])=%d\r\n",sizeof(buf2),sizeof(buf2[1]));
	printf("sizeof(tmp)=%d\r\n",sizeof(tmp));
	
    //对于“”中的字符串，默认后面还有一个\0，所以实际的长度要+1
    printf("len=%d\r\n",sizeof("123456"));
	return 0;
}