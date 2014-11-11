如何使用？
 1. 如果是首次使用。
    （1）依次打开 VS - 工具 - 选项 - 文本编辑器 - 文件扩展名 - 添加.mq4/.mqh，编辑器使用Microsoft C++
    （2）在MT4目录\..\include\下创建MT4Library.mqh文件，添加下面一行到文件中
	 	#include"实际MT4Library库目录/MT4Library.h"
		
		PS：#include "" 查找包含文件的方式             
			当前文件目录
			当前文件的上一目录            
			    
		我们添加的文件全部在MT4的include、experts、indicators目录中，这些目录的上一层目录是MT4程序目录。
	VS无法在这些目录中查找到MT4Library.h文件。所以，我们需要在当前目录下包含一个头文件指明应该包含的文件在
	什么地方。
		引用过程：
		添加要编辑的mt4文件，
				  |
		#include "MT4Library.mqh" -> #include "MT4library项目目录\MT4library.h" 
																		 |
															      包含所有需要的头文件)
																		 |
		成功将MT4项目源文件包含到MT4项目以外的目录下 <--------------------------
		          |
		在MT4项目中使用项目内的源文件编辑项目以外的MT4源文件。
			
	（3）右键项目名 -> 属性 -> VC++目录 - > 包含 $MT4实际目录$\experts\include
 2. 打开 MT4Library项目，添加 - 现有项 - .mq4 或者 .mq4 到头文件区域
 3. 打开该mq4文件，在文件头部添加：
		#include"MT4Library.mqh"
		$MT4实际目录$\experts\include\下的其它mt4头文件