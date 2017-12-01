#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
#include "MD5.h"
int main()
{
	MD5 b;
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		MessageBoxA(NULL, "WinSock startup failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111); //Port
	addr.sin_family = AF_INET; //IPv4 Socket

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen);
	if (newConnection == 0)
	{
		std::cout << "Failed to accept the client's connection." << std::endl;
	}
	else
	{
		//std::string f;
		std::cout << "Client Connected!" << std::endl;
		char a[30];
		recv(newConnection, a, sizeof(a), NULL);
		int i = 0;
		while (a[i] >= 0)
			i++;
		a[i] = '\0';
		std::string f = string(a);
		std::cout << b.get_md5(f) << std::endl;
	}
	closesocket(sListen);
	closesocket(newConnection);
	WSACleanup();
	system("pause");
	return 0;
}