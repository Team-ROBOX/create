#ifndef RS232_H_INCLUDED
#define RS232_H_INCLUDED

#include <windows.h>
#include <stdio.h>
// #include "ftd2xx.h"

class RS232{
private:
	// 	FT_HANDLE fthandle;
	// 	FT_STATUS res;
	LONG COMPORT;

	char COMx[15];
	int n;

	DCB dcb;
	HANDLE hCommPort;
	HANDLE myHThread;    // �X���b�h�p�n���h�� 
	DWORD  myThreadId;   // �X���b�h ID
	BOOL fSuccess;

	static DWORD WINAPI RS232::ThreadFunc(LPVOID lpParameter);

public:
	char gStr[256];
	CRITICAL_SECTION cs;
	int reading = 0;

	RS232(int comNum, int baudrate, int bytesize, int parity, int stopbit);	// int parity, int stopbit ��<windows.h>�C���N���[�h�������`����Ă�}�N���Q�� ex.RS232 rs232(3, 115200, 8, NOPARITY, ONESTOPBIT);
	~RS232();
	void StartThread();
	void write(char* data_out);	// ��������ꂽ��OK
	void read();	// �����ς�
};

#endif
