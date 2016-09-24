/*-------------------------------------------------------
  HelloMsg.c -- Displays "Hello, Windows 98!" in a message box 
				(c) Charles Petzold, 1998
  -------------------------------------------------------*/

/*-------------------------------------------------------
	1. 从File菜单下选择New。在New人对话框里，选择Project选项卡。选中Win32 Application。
	在Location栏里选择一个子目录。在Project Name字段中键入项目名，在本例中即HelloMsg。
	这也将成为Location栏中所显示目录的子目录。这时Create New Workspace按钮应该已经被选中,
	Platforms部分应该显示为Win32。单击OK。
	2. 这时候会出现一个标题为Win32 Application - Step 1 of 1人对话框。选择An empty project
	表示你想建立一个空项目，然后单击Finish按钮。
	3. 再次从File菜单下选择New选项。在New对话框里，选择Files选项卡。选中C++ Source File。
	这时Add to Project复选框应该已经被选中，并提示HelloMsg。在File框中输入HelloMsg.c，然后单击OK。
  ------------------------------------------------------- */

#include <windows.h>

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	MessageBox (NULL, TEXT ("Hello, Windows 98!"), TEXT ("HelloMsg"), 0);

	return 0;
}