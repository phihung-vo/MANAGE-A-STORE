#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Sanpham
{
private:
	char maso[3];
	char ten[100];
	char hangsanxuat[100];
	int soluong;
	int baohanh;
	int dongia;

public:
	void setmaso(char *msIn);
	char* getmaso();
	void setten(char *tenIn);
	char* getten();
	void sethangsx(char *hangsxIn);
	char* gethangsx();
	void setsoluong(int slIn);
	int getsoluong();
	void setbaohanh(int bhIn);
	int getbaohanh();
	void setdongia(int dongiain);
	int getdongia();
	//End Get Set...........................................
	void nhap();
	void hienthi();
	void hienthi_mua();
	
	
};
void ghifilesp(Sanpham*);
void docfilesp();
void timsp(char *maso);
void xoasp(char *maso);
void chinhsuasp(char *maso);
void thongkesp();
