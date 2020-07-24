/*-------------------------------------------------------
  HelloMsg.c -- Displays "Hello, Windows 98!" in a message box 
				(c) Charles Petzold, 1998
  -------------------------------------------------------*/

/*-------------------------------------------------------
	1. ��File�˵���ѡ��New����New�˶Ի����ѡ��Projectѡ���ѡ��Win32 Application��
	��Location����ѡ��һ����Ŀ¼����Project Name�ֶ��м�����Ŀ�����ڱ����м�HelloMsg��
	��Ҳ����ΪLocation��������ʾĿ¼����Ŀ¼����ʱCreate New Workspace��ťӦ���Ѿ���ѡ��,
	Platforms����Ӧ����ʾΪWin32������OK��
	2. ��ʱ������һ������ΪWin32 Application - Step 1 of 1�˶Ի���ѡ��An empty project
	��ʾ���뽨��һ������Ŀ��Ȼ�󵥻�Finish��ť��
	3. �ٴδ�File�˵���ѡ��Newѡ���New�Ի����ѡ��Filesѡ���ѡ��C++ Source File��
	��ʱAdd to Project��ѡ��Ӧ���Ѿ���ѡ�У�����ʾHelloMsg����File��������HelloMsg.c��Ȼ�󵥻�OK��
  ------------------------------------------------------- */

#include <windows.h>

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	MessageBox (NULL, TEXT ("Hello, Windows 98!"), TEXT ("HelloMsg"), 0);

	return 0;
}