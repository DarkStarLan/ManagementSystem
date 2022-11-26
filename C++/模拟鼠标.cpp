#include<iostream>
using namespace std;
#include<windows.h>
#include<conio.h>

#define UPTIME 10

//#define fScreenWidth 1920
//#define fScreenHeight 1080
// #define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

void TopWindow(HWND &hWnd)
{
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

int main()
{
	START:
    int now = 0, i = 0, time = 20, click = 10;
    char ch;
    double runtime = 0.00;
    bool isRun = false;
    //int fx = (1892 + 0) * (65535 / fScreenWidth);
    //int fy = (924 + 0) * (65535 / fScreenHeight);
    //cout << fx << "  " << fy << endl;
    
    while(true)
    {
    	cout << "间隔时间:" << endl;
  		cin >> time;
  		if(time < 20)
		{
   	 		time = 20;
  	  		cout << "[ERROR]数值过小" << endl;
		}
		else if(time > 2000)
		{
			time = 2000;
			cout << "[ERROR]数值过大" << endl;
		}
		else
		{
			break;
		}
	}
    while(true)
    {
    	cout << "点击次数:" << endl;
    	cin >> click;
   		if(click < 1)
   		{
    		click = 1;
 	   		cout << "至少需要点击一次" << endl;
		}
		else if(click > 500)
		{
			click = 500;
			cout << "点击次数过多" << endl;
		}
		else
		{
			break;
		}
	}
    
    system("cls");
	cout << "每秒点击 " << 1000 / time << " 次" << endl;
	cout << "点击次数 " << click << endl;
	cout << "按下Q键重新设置属性" << endl;  
	cout << "按下空格开始模拟鼠标点击" << endl;  
    
    int num = 1; 
    
    while(true)
    {
        if(_kbhit())
		{
			if(isRun) break;
            ch = _getch();
            if(ch == ' ')
			{
				now = 1;
				cout << endl;
				cout << "开始运行---第 " << num << " 次运行" << endl;
				isRun = true;
				runtime = 0;
			}
			if(ch == 'q')
			{
				system("cls"); 
				goto START;
			}
        }
        if(now == 1)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            Sleep(UPTIME);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            //HWND hWnd = GetForegroundWindow();
			//TopWindow(hWnd);
            ++i;
            if(i == click)
            {
            	isRun = false;
            	if(runtime == 0)
            	{
            		runtime += UPTIME / 1000.0f;
				}
				else
				{
					runtime += click * (UPTIME / 1000.0f);
				}
            	cout << "终止运行<" << num << "> / 共计用时 " << runtime << " 秒" << endl;
            	i = 0;
            	now = 0;
            	++num;
			}
        }
        Sleep(time);
        if(isRun)
        {
        	runtime += time / 1000.0f;
		}
    }
    return 0;
}
