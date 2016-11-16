<img src=https://raw.githubusercontent.com/iamideas/Mql-for-MT4/master/readme.png >
#### 在使用visual studio编辑mq4文件时，会遇到的错误：
0. 这个库无法被编译

1. 无法实现兼容的预处理命令
  (1)#import
  #import 无法导入.ex4类型的库
  出现此错误的位置： WinUser32.h -> #import "user32.dll"

  (2)#property 
  #property 预处理命令是在mt4中拥有的,VS无法处理该预处理命令，需要注释或使用#if/#endif 控制

2. 在vs中不能处理类似 " "+非string字符串+" "的字符串运算会提示错误。

3. color和datetime的字符定义模式在VS中会提示错误
   color c = C'012,012,120';
   datetime d = D'2013 10 10 12:12';

4. void &variable/ Type &array[]
	在VS中引用数组（type &array[]）是无法被处理的，但在mt4中被用于预定义的入口函数OnCalculate()中。
	在mt4中对变量取地址或定义引用是不被支持的，无法通过编译 

5. 目前该辅助库无法用于编写mq5的indicator和expert,因为目前mt4editor支持的C++语法与标准的C++语法还有较大的区别，兼容性问题较大。
#### 如何使用？
1. 如果是首次使用：
  （1）依次打开 VS - 工具 - 选项 - 文本编辑器 - 文件扩展名 - 添加.mq4/.mqh，编辑器使用Microsoft C++
  （2）在MT4目录include\下创建MT4Library.mqh文件，添加下面一行到文件中
  	#include"实际MQLLibrary库目录/MQLLibrary.h"        
  （3）右键项目名 -> 属性 -> VC++目录 - > 包含 $MT4实际目录$\include

2. 新建空的C++工程，在源文件目录中新建源文件.mq4或引入某.mq4文件。
  在文件头部添加：
```
#ifndef _MSC_VER
一些#property属性定义
#else
#include "MQLLibrary.mqh"
#endif

//--- input parameters
input int      period = 5;
//+------------------------------------------------------------------+
//| Custom indicator initialization function                         |
//+------------------------------------------------------------------+

double buffer[];

int OnInit()
{
	...
	其它代码
```