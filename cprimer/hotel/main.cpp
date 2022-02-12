#include <iostream>
#include <vector>
#include <string>
#include "fun.hpp"
#include "number.hpp"

using namespace std;

int main()
{
    string start_msg ="Start! ......\n";
    string end_msg="End! ......\n";
  程序清单9.9 usehotel.c控制模块
/* usehotel.c -- 房间费率程序 */
/* 与程序清单9.10一起编译 */
#include <stdio.h>
#include "hotel.h" /* 定义符号常量，声明函数 */
int main(void)
{
int nights;
double hotel_rate;
int code;
while ((code = menu()) != QUIT)
{
switch (code)
{
case 1: hotel_rate = HOTEL1;
break;
case 2: hotel_rate = HOTEL2;
break;
case 3: hotel_rate = HOTEL3;
break;
case 4: hotel_rate = HOTEL4;
break;
default: hotel_rate = 0.0;
printf("Oops!\n");
break;
}
nights = getnights();
showprice(hotel_rate, nights);
}
printf("Thank you and goodbye.\n");
return 0;
}
程序清单9.10 hotel.c函数支持模块
/* hotel.c -- 酒店管理函数 */
#include <stdio.h>
#include "hotel.h"
int menu(void)
{
int code, status;
printf("\n%s%s\n", STARS, STARS);
printf("Enter the number of the desired hotel:\n");
printf("1) Fairfield Arms 2) Hotel Olympic\n");
printf("3) Chertworthy Plaza 4) The Stockton\n");
printf("5) quit\n");
printf("%s%s\n", STARS, STARS);
while ((status = scanf("%d", &code)) != 1 ||
(code < 1 || code > 5))
{
if (status != 1)
scanf("%*s"); // 处理非整数输入
printf("Enter an integer from 1 to 5, please.\n");
}
return code;
}
int getnights(void)
{
int nights;
printf("How many nights are needed? ");
while (scanf("%d", &nights) != 1)
{
scanf("%*s"); // 处理非整数输入
printf("Please enter an integer, such as 2.\n");
}
return nights;
}
void showprice(double rate, int nights)
{
int n;
double total = 0.0;
double factor = 1.0;
for (n = 1; n <= nights; n++, factor *= DISCOUNT)
total += rate * factor;
printf("The total cost will be $%0.2f.\n", total);
}
程序清单9.11 hotel.h头文件
/* hotel.h -- 符号常量和 hotel.c 中所有函数的原型 */
#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARS "**********************************"
// 显示选择列表
int menu(void);
// 返回预订天数
int getnights(void);
// 根据费率、入住天数计算费用
// 并显示结果
void showprice(double rate, int nights);
  x=sizeof(start_msg);
    cout << start_msg;
    
    int t=0;
    print_size(t);

    cout << end_msg;
    return 0;
}
