#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
#include "MD5.h"
int main()
{
	MD5 n;
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //Address = localhost (this pc)
	addr.sin_port = htons(1111); //Port = 1111
	addr.sin_family = AF_INET; //IPv4 Socket

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0)
	{
		MessageBoxA(NULL, "Failed to Connect", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}
	std::cout << "Connected!" << std::endl;
	std::string a;
	//char b[] = "Hash and socket test";
	char b[30];
	std::cin.getline(b, 30);
	a = b;
	send(Connection, b, 30, NULL);
	std::cout << "Test string hash" << std::endl;
	std::cout << n.get_md5(a) << std::endl;
	system("pause");
	//while (true)
	//{
		//Sleep(10);
	//}
	closesocket(Connection);
	WSACleanup();
	return 0;
}

