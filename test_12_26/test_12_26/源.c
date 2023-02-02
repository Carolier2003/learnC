#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>

#include<Windows.h>



int main()

{

	int Message = 100;

	FindWindow(NULL, "Lee EQueen");//和QQ进行连接

	while (Message > 0)

	{

		SendMessage(FindWindow(NULL, "Lee EQueen"), WM_PASTE, NULL, NULL);//粘贴

		//发送

		SendMessage(FindWindow(NULL, "Lee EQueen"), WM_KEYDOWN, VK_RETURN, NULL);



		Message--;

	}



	return 0;

}
