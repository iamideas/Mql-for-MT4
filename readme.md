<img src=https://raw.githubusercontent.com/iamideas/Mql-for-MT4/master/readme.png >
#### ��ʹ��visual studio�༭mq4�ļ�ʱ���������Ĵ���
0. ������޷�������

1. �޷�ʵ�ּ��ݵ�Ԥ��������
  (1)#import
  #import �޷�����.ex4���͵Ŀ�
  ���ִ˴����λ�ã� WinUser32.h -> #import "user32.dll"

  (2)#property 
  #property Ԥ������������mt4��ӵ�е�,VS�޷������Ԥ���������Ҫע�ͻ�ʹ��#if/#endif ����

2. ��vs�в��ܴ������� " "+��string�ַ���+" "���ַ����������ʾ����

3. color��datetime���ַ�����ģʽ��VS�л���ʾ����
   color c = C'012,012,120';
   datetime d = D'2013 10 10 12:12';

4. void &variable/ Type &array[]
	��VS���������飨type &array[]�����޷�������ģ�����mt4�б�����Ԥ�������ں���OnCalculate()�С�
	��mt4�жԱ���ȡ��ַ���������ǲ���֧�ֵģ��޷�ͨ������ 

5. Ŀǰ�ø������޷����ڱ�дmq5��indicator��expert,��ΪĿǰmt4editor֧�ֵ�C++�﷨���׼��C++�﷨���нϴ�����𣬼���������ϴ�
#### ���ʹ�ã�
1. ������״�ʹ�ã�
  ��1�����δ� VS - ���� - ѡ�� - �ı��༭�� - �ļ���չ�� - ���.mq4/.mqh���༭��ʹ��Microsoft C++
  ��2����MT4Ŀ¼include\�´���MT4Library.mqh�ļ����������һ�е��ļ���
  	#include"ʵ��MQLLibrary��Ŀ¼/MQLLibrary.h"        
  ��3���Ҽ���Ŀ�� -> ���� -> VC++Ŀ¼ - > ���� $MT4ʵ��Ŀ¼$\include

2. �½��յ�C++���̣���Դ�ļ�Ŀ¼���½�Դ�ļ�.mq4������ĳ.mq4�ļ���
  ���ļ�ͷ����ӣ�
```
#ifndef _MSC_VER
һЩ#property���Զ���
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
	��������
```