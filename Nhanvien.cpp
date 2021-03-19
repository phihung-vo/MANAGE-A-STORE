#include "Nhanvien.h"
// Start Get Set ....................................//
void Nhanvien::setmaso(char *masoIn)
{
	strcpy_s(maso, masoIn);
}
char* Nhanvien::getmaso()
{
	return maso;
}
void Nhanvien::setten(char *tenIn)
{
	strcpy_s(ten, tenIn);
}
char* Nhanvien::getten()
{
	return ten;
}
void Nhanvien::setgioitinh(char *gtIn)
{
	strcpy_s(gioitinh, gtIn);
}
char* Nhanvien::getgioitinh()
{
	return gioitinh;
}
void Nhanvien::setngaysinh(int ngayIn, int thangIn, int namIn)
{
	ngaysinh.ngay = ngayIn;
	ngaysinh.thang = thangIn;
	ngaysinh.nam = namIn;
}
Nhanvien::Ngaysinh Nhanvien::getngaysinh()
{
	return ngaysinh;
}
void Nhanvien::setcmnd(char *cmndIn)
{
	strcpy_s(cmnd, cmndIn);
}
char* Nhanvien::getcmnd()
{
	return cmnd;
}
void Nhanvien::setdiachi(char *diachiIn)
{
	strcpy_s(diachi, diachiIn);
}
char* Nhanvien::getdiachi()
{
	return diachi;
}
void Nhanvien::setsdt(char *sdtIn)
{
	strcpy_s(sdt, sdtIn);
}
char* Nhanvien::getsdt()
{
	return sdt;
}
void Nhanvien::setchucvu(char *cvIn) {
	strcpy_s(chucvu, cvIn);
}
char* Nhanvien::getchucvu() {
	return chucvu;
}
void Nhanvien::setluong(float luongIn) {
	luong = luongIn;
}
float Nhanvien::getluong() {
	return luong;
}
//End Get Set ...................................//
void Nhanvien::nhap() {
	//char buff[100];
	cout << "\nNhap ten: "; gets_s(ten); 
	cout << "\nNhap ma so: "; gets_s(maso);
	cout << "\nNhap gioi tinh: "; gets_s(gioitinh);
	cout << "\nNhap ngay sinh: "; cin >> ngaysinh.ngay;
	cout << "\nNhap thang sinh: "; cin >> ngaysinh.thang;
	cout << "\nNhap nam sinh: "; cin >> ngaysinh.nam;
	cin.ignore();
	cout << "\nNhap cmnd: ";  gets_s(cmnd);
	cout << "\nNhap dia chi: "; gets_s(diachi);
	cout << "\nNhap so dien thoai: "; gets_s(sdt);
	cout << "\nNhap chuc vu: "; gets_s(chucvu);
	cout << "\nNhap luong ($): "; cin >> luong;
}// Nhap vao thong tin cua nhan vien va thong tin do da duoc luu vao doi tuong 

void ghifilenv(Nhanvien *nv) {
	fstream f("Nhanvien.dat", ios::app | ios::binary);
	f.write(reinterpret_cast<char*>(nv), sizeof(Nhanvien));
	f.close();
}// Truyen vao doi tuong va ghi vao file thong tin cua doi tuong do

void Nhanvien::hienthi() {
	cout << "Ma so: " << maso << endl
		<< "Ten: " << ten << endl
		<< "Gioi tinh:  " << gioitinh << endl
		<< "Ngay sinh: " << ngaysinh.ngay << "/" << ngaysinh.thang << "/" << ngaysinh.nam << endl
		<< "So cmnd: " << cmnd << endl
		<< "Dia chi: " << diachi << endl
		<< "So dien thoai: " << sdt << endl
		<< "Chuc vu: " << chucvu << endl
		<< "Luong: " << luong <<"$" <<endl;
}

void docfilenv()
{
	Nhanvien nv;
	fstream f("Nhanvien.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
	while (f) {
		nv.hienthi();
		cout << "____________________________________________________________" << endl;
		f.read(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
	}
	f.close();
}//doc trong file ra thong tin va luu vao doi tuong nv sau do hien thi thong tin cua nv ra man hinh

void timnv(char *maso) {
	bool success = false;
	Nhanvien nv;
	fstream f("Nhanvien.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
	while (f) {
		if (strcmp(maso, nv.getmaso()) == 0)
		{
			cout << "DA TIM THAY 1 NHAN VIEN\n";
			nv.hienthi();
			success = true;
			break;
		}
		f.read(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
	}
	f.close();
	if (success == false)
	{
		cout << "KHONG TIM THAY NHAN VIEN NAO CO MA SO " << maso << endl;
	}
}//truyen vao ma so cua nv can tim sau do ham se hien thi thong tin cua nhan vien do

void xoanv(char *maso) {
	Nhanvien nv;
	fstream f("Nhanvien.dat", ios::in | ios::binary);
	fstream fn("abc.dat", ios::app | ios::binary);
	f.read(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
	while (f) {
		if (strcmp(maso, nv.getmaso()) != 0)
		{
			fn.write(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
		}
		f.read(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
	}
	f.close();
	fn.close();
	remove("Nhanvien.dat");
	rename("abc.dat", "Nhanvien.dat");
}// Truyen vao ma so nv can xoa

void chinhsuanv(char*maso) {
	bool success = false;
	Nhanvien nv;
	char buff[100];
	fstream f("Nhanvien.dat", ios::in | ios::binary);
	fstream fn("abc.dat", ios::app | ios::binary);
	f.read(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
	while (f) {
		if (strcmp(maso, nv.getmaso()) == 0)
		{

			nv.hienthi();
			cout << "Ban muon chinh sua thong tin nao ??\n0.Bo qua\n1.Ten\n2.Dia chi\n3.So dien thoai\n4.Chuc vu\n5.Luong\n";
			int choice;
			cin >> choice;
			cin.ignore();
			if (choice == 1)
			{
				cout << "Nhap ten moi: ";
				gets_s(buff);
				nv.setten(buff);
				cout << "____________________SUA THONG TIN NHAN VIEN THANH CONG____________________\n";
				success = true;
			}
			else if (choice == 2)
			{
				cout << "Nhap dia chi moi: ";
				gets_s(buff);
				nv.setdiachi(buff);
				cout << "____________________SUA THONG TIN NHAN VIEN THANH CONG____________________\n";
				success = true;
			}
			else if (choice == 3)
			{
				cout << "Nhap so dien thoai moi: ";
				gets_s(buff);
				nv.setsdt(buff);
				cout << "____________________SUA THONG TIN NHAN VIEN THANH CONG____________________\n";
				success = true;
			}
			else if (choice == 4)
			{
				cout << "Nhap chuc vu moi: ";
				gets_s(buff);
				nv.setchucvu(buff);
				cout << "____________________SUA THONG TIN NHAN VIEN THANH CONG____________________\n";
				success = true;
			}
			else if (choice == 5)
			{
				cout << "Nhap so luong moi: ";
				float  lnew;
				cin >> lnew;
				nv.setluong(lnew);
				cout << "____________________SUA THONG TIN NHAN VIEN THANH CONG____________________\n";
				success = true;
			}
			else if (choice == 0) {
				cout << "BAN DA CHON BO QUA, NHAN NUT BAT KI DE QUAY LAI\n";
				success = true;
			}
			else {}
			
		}
		fn.write(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
		f.read(reinterpret_cast<char*>(&nv), sizeof(Nhanvien));
	}
	f.close();
	fn.close();
	remove("Nhanvien.dat");
	rename("abc.dat", "Nhanvien.dat");
	if (success == false) {
		cout << "KHONG TIM THAY MA SO, NHAN NUT BAT KI DE QUAY LAI\n";
	}
	
}//Truyen vao tham so cua nhan vien muon chinh sua thong tin

void thongkenv()
{

	Nhanvien *nv = new Nhanvien[30];
	fstream f("Nhanvien.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&nv[0]), sizeof(Nhanvien));
	int idx=0;
	while (f) {
		idx++;
		f.read(reinterpret_cast<char*>(&nv[idx]), sizeof(Nhanvien));
	}
	f.close();
	cout << "\nSo luong nhan vien:  " << idx ;
	// in ra nhan vien co luong cao nhat
	Nhanvien nvmax = nv[0];
	for (int i = 0; i < idx-1; i++)
	{
		if (nv[i].getluong() > nvmax.getluong())
		{
			nvmax = nv[i];
		}
	}
	cout << "\nNhan vien co luong cao nhat: \n";
	for (int i = 0; i < idx - 1; i++)
	{
		if (nv[i].getluong() == nvmax.getluong())
		{
			nv[i].hienthi();
		}
	}
}