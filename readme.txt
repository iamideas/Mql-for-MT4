#### ��ʹ��visual studio�༭mq4�ļ�ʱ���������Ĵ���
0. ������޷�������
1. �޷�ʵ�ּ��ݵ�Ԥ��������
  (1)#import
  #import �޷�����.ex4���͵Ŀ�
  ���ִ˴����λ�ã� WinUser32.h -> #import "user32.dll"

  (2)#property 
  #property Ԥ������������mt4��ӵ�е�,VS�޷������Ԥ���������Ҫע�ͻ�ʹ��#if/#endif ����

2. �����ַ��������������vs�л�����ʾ����
3. color��datetime���ַ�����ģʽ��VS�л���ʾ����
   color c = C'012,012,120';
   datetime d = D'2013 10 10 12:12';
4. void &variable/ Type &array[]
	��VS���������飨type &array[]�����޷�������ģ�����mt4�б�����Ԥ�������ں���OnCalculate()�С�
	��mt4�жԱ���ȡ��ַ���������ǲ���֧�ֵģ��޷�ͨ������

#### ���ʹ�ã�
1. ������״�ʹ�ã�
  ��1�����δ� VS - ���� - ѡ�� - �ı��༭�� - �ļ���չ�� - ���.mq4/.mqh���༭��ʹ��Microsoft C++
  ��2����MT4Ŀ¼include\�´���MT4Library.mqh�ļ����������һ�е��ļ���
  	#include"ʵ��MQLLibrary��Ŀ¼/MQLLibrary.h"        
			
  ��3���Ҽ���Ŀ�� -> ���� -> VC++Ŀ¼ - > ���� $MT4ʵ��Ŀ¼$\include
2. ��ĳmq4�ļ������ļ�ͷ����ӣ�
   #include"MT4Library.mqh"
   $MT4ʵ��Ŀ¼$\include\�µ�����mqh�ļ�