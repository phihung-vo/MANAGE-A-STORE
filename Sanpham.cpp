#include "Sanpham.h"
void Sanpham::setmaso(char *msIn) {
	strcpy_s(maso, msIn);
}
char* Sanpham::getmaso() {
	return maso;
}
void Sanpham::setten(char *tenIn) {
	strcpy_s(ten, tenIn);
}
char* Sanpham::getten() {
	return ten;
}
void Sanpham::sethangsx(char *hangsxIn) {
	strcpy_s(hangsanxuat, hangsxIn);
}
char* Sanpham::gethangsx() {
	return hangsanxuat;
}
void Sanpham::setsoluong(int slIn) {
	soluong = slIn;
}
int Sanpham::getsoluong() {
	return soluong;
}
void Sanpham::setbaohanh(int bhIn) {
	baohanh = bhIn;
}
int Sanpham::getbaohanh() {
	return baohanh;
}
void Sanpham::setdongia(int dongiain) {
	dongia = dongiain;
}
int Sanpham::getdongia() {
	return dongia;
}
// End Get Set .........................................

void Sanpham::nhap()
{
	cout << "\nNhap ten: "; gets_s(ten);
	cout << "\nNhap ma so: "; gets_s(maso);
	cout << "\nNhap hang san xuat: "; gets_s(hangsanxuat);
	cout << "\nNhap so luong: ";
	cin >> soluong ;
	cout << "\nNhap bao hanh (thang): "; cin >> baohanh;
	cout << "\nNhap gia thanh san pham ($): "; cin >> dongia;
	cin.ignore();

}
void ghifilesp(Sanpham *sp)
{
	fstream f("Sanpham.dat", ios::app | ios::binary);
	f.write(reinterpret_cast<char*>(sp), sizeof(Sanpham));
	f.close();
}
void Sanpham::hienthi() {
	cout << "Ma so: " << maso << endl
		<< "Ten: " << ten << endl
		<< "Hang san xuat:  " << hangsanxuat << endl
		<< "So luong: " << soluong << endl
		<< "Bao hanh: " << baohanh << endl
		<< "Gia thanh: " << dongia <<"$"<< endl;
}
void Sanpham::hienthi_mua() {
	cout << "Ma so: " << maso << endl
		<< "Ten: " << ten << endl
		<< "Hang san xuat:  " << hangsanxuat << endl
		<< "Bao hanh: " << baohanh << " thang" << endl
		<< "Gia thanh: " << dongia << "$" << endl;
}

void docfilesp() {
	Sanpham sp;
	fstream f("Sanpham.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
	while (f) {
		sp.hienthi();
		cout << "____________________________________________________________" << endl;
		f.read(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
	}
	f.close();
}
void timsp(char *maso) {
	bool success = false;
	Sanpham sp;
	fstream f("Sanpham.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
	while (f) {
		if (strcmp(maso, sp.getmaso()) == 0)
		{
			cout << "DA TIM THAY 1 HANG HOA\n";
			sp.hienthi();
			success = true;
			break;
		}
		f.read(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
	}
	f.close();
	if (success == false)
	{
		cout << "KHONG TIM THAY HANG HOA NAO CO MA SO " << maso << endl;
	}
}
void xoasp(char *maso) {
	Sanpham sp;
	fstream f("Sanpham.dat", ios::in | ios::binary);
	fstream fn("abc.dat", ios::app | ios::binary);
	f.read(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
	while (f) {
		if (strcmp(maso, sp.getmaso()) != 0)
		{
			fn.write(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
		}
		f.read(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
	}
	f.close();
	fn.close();
	remove("Sanpham.dat");
	rename("abc.dat", "Sanpham.dat");
}
void chinhsuasp(char*maso) {
	bool success = false;
	Sanpham sp;
	fstream f("Sanpham.dat", ios::in | ios::binary);
	fstream fn("abc.dat", ios::app | ios::binary);
	f.read(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
	while (f) {
		if (strcmp(maso, sp.getmaso()) == 0)
		{
			sp.hienthi();
			cout << "Ban muon chinh sua thong tin nao ??\n0.Bo qua\n1.So luong\n2.Bao hanh\n3.Don gia";
			int choice;
			cin >> choice;
			cin.ignore();
			if (choice == 1)
			{
				cout << "Nhap so luong moi: ";
				int sln;
				cin >> sln;
				sp.setsoluong(sln);
				success = true;
			}
			else if (choice == 2)
			{
				cout << "Nhap han bao hanh moi: ";
				int bhn;
				cin >> bhn;
				sp.setbaohanh(bhn);
				success = true;
			}
			else if (choice == 3)
			{
				cout << "Nhap don gia moi: ";
				int dgn;
				cin >> dgn;
				sp.setdongia(dgn);
				success = true;
			}
			else if (choice == 0) {
				cout << "BAN DA CHON BO QUA, NHAN NUT BAT KI DE QUAY LAI\n";
				success = true;
			}
			else {}

		}
		fn.write(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
		f.read(reinterpret_cast<char*>(&sp), sizeof(Sanpham));
	}
	f.close();
	fn.close();
	remove("Sanpham.dat");
	rename("abc.dat", "Sanpham.dat");
	if (success == false) {
		cout << "KHONG TIM THAY MA SO, NHAN NUT BAT KI DE QUAY LAI\n";
	}
}
void thongkesp()
{

	Sanpham *sp = new Sanpham[30];
	fstream f("Sanpham.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&sp[0]), sizeof(Sanpham));
	int idx = 0;
	while (f) {
		idx++;
		f.read(reinterpret_cast<char*>(&sp[idx]), sizeof(Sanpham));
	}
	f.close();
	cout << "\nSo luong san pham:  " << idx <<endl;
	// in ra so luong cua tung san pham
	cout << "So luong ton kho cua tung san pham:\n";
	for (int i = 0; i < idx; i++)
	{
		cout << sp[i].getten() << ": " << sp[i].getsoluong() << endl;
	}
}
