#pragma once
#include <string>
#include <iostream>
#include<fstream>
using namespace std;
class Nhanvien {
	typedef struct {
		int ngay;
		int thang;
		int nam;
	}Ngaysinh;

private:
	char maso[3];
	char ten[100];
	char gioitinh[5];
	Ngaysinh ngaysinh;
	char cmnd[12];
	char diachi[100];
	char sdt[11];
	char chucvu[50];
	float luong;
public:
	// Setter & Getter
	void setmaso(char*);
	char* getmaso();
	void setten(char*);
	char* getten();
	void setgioitinh(char*);
	char* getgioitinh();
	void setngaysinh(int ngayIn, int thangIn, int namIn);
	Ngaysinh getngaysinh();
	void setcmnd(char*);
	char* getcmnd();
	void setdiachi(char*);
	char* getdiachi();
	void setsdt(char*);
	char* getsdt();
	void setchucvu(char*);
	char* getchucvu();
	void setluong(float luongIn);
	float getluong();
	// End Get Set.....................................//
	void nhap();
	void hienthi();
	
};
void ghifilenv(Nhanvien*);
void docfilenv();
void timnv(char*);
void xoanv(char*);
void chinhsuanv(char*);
void thongkenv();