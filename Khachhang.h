#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "Sanpham.h"
using namespace std;
typedef struct {
		int ngay;
		int thang;
		int nam;
}Ngay;

class Khachhang
{
private:
	char maso[3];
	char ten[100];
	char gioitinh[5];
	Ngay ngaysinh;
	char cmnd[12];
	char diachi[100];
	char sdt[12];
	Sanpham sp[20];
	int soluong[20];
	Ngay ngaymua[20];
	/*vector<Sanpham> dssp;
	vector<int> soluong_sp;*/
public:
	// Setter & Getter
	void setmaso(char*);
	char* getmaso();
	void seten(char*);
	char* getten();
	void setgioitinh(char *);
	char* getgioitinh();
	void setngaysinh(int ngayIn, int thangIn, int namIn);
	Ngay getngaysinh();
	void setcmnd(char *);
	char* getcmnd();
	void setdiachi(char*);
	char* getdiachi();
	void setsdt(char*);
	char* getsdt();
	void setdssp(Sanpham[20]);
	Sanpham* getdssp();
	void setsoluong_sp(int[20]);
	int* getsoluong_sp();
	void setngaymua(Ngay[20]);
	Ngay* getngaymua();

	//End Get Set....................................................
	void nhapdssp(char buff[3], int soluong,Ngay temp, int i);
	void nhap();
	void hienthi();
};
void ghifilekh(Khachhang);
void docfilekh();
void timkh(char *maso);
void xoakh(char *maso);
void chinhsuakh(char *maso);
void thongkekh();