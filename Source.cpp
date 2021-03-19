#include <iostream>
#include <string>
#include <vector>
#include "Nhanvien.h"
#include  "Sanpham.h"
#include "Khachhang.h"
using namespace std;
//____________________//
void Trangchu() // Xuat ra danh sach Menu
{
	system("cls");
	cout << "____________________QUAN LY CUA HANG DIEN THOAI____________________" <<endl;
	cout << "1.NHAN VIEN" << endl;
	cout << "2.KHACH HANG" << endl;
	cout << "3.HANG HOA" << endl;
	cout << "0.THOAT" << endl;
	cout << "____________________________________________________________" << endl;
}
int ChonMenuTC()
{
	int n = 0;
	cout << "\n\nMoi chon menu: ";
	cin >> n;
	if (n >= 0 && n <= 3)
		return n;
	else return ChonMenuTC();
}
void MenuNV() // Xuat ra menu Nhanvien
{
	system("cls");
	cout << "____________________QUAN LY NHAN VIEN____________________" << endl;
	cout << "1.XEM THONG TIN TAT CA NHAN VIEN" << endl;
	cout << "2.THEM NHAN VIEN MOI" << endl;
	cout << "3.CHINH SUA THONG TIN NHAN VIEN " << endl;
	cout << "4.TIM NHAN VIEN " << endl;
	cout << "5.XOA NHAN VIEN " << endl;
	cout << "6.THONG KE NHAN VIEN " << endl;
	cout << "0.QUAY LAI" << endl;
	cout << "____________________________________________________________" << endl;
}
int ChonMenuNV()
{
	int n = 0;
	cout << "\n\nMoi chon menu: ";
	cin >> n;
	if (n >= 0 && n <= 6)
		return n;
	else return ChonMenuNV();
}
void MenuKH() // Xuat ra menu Khachhang
{
	system("cls");
	cout << "____________________QUAN LY KHACH HANG____________________" << endl;
	cout << "1.XEM THONG TIN TAT CA KHACH HANG" << endl;
	cout << "2.THEM KHACH HANG MOI" << endl;
	cout << "3.CHINH SUA THONG TIN KHACH HANG " << endl;
	cout << "4.TIM KHACH HANG " << endl;
	cout << "5.XOA KHACH HANG " << endl;
	cout << "6.THONG KE KHACH HANG " << endl;
	cout << "0.QUAY LAI" << endl;
	cout << "____________________________________________________________" << endl;
}
void MenuHH() // Xuat ra menu Khachhang
{
	system("cls");
	cout << "____________________QUAN LY HANG HOA____________________" << endl;
	cout << "1.XEM THONG TIN TAT CA HANG HOA" << endl;
	cout << "2.THEM HANG MOI" << endl;
	cout << "3.CHINH SUA THONG TIN HANG HOA " << endl;
	cout << "4.TIM HANG HOA " << endl;
	cout << "5.XOA HANG HOA " << endl;
	cout << "6.THONG KE HANG HOA " << endl;
	cout << "0.QUAY LAI" << endl;
	cout << "____________________________________________________________" << endl;
}
int main()
{
MenuTC:
	Trangchu(); //In ra man hinh
	switch (ChonMenuTC())
	{
		case 0: exit(1);
		case 1: goto MenuNV; break;
		case 2: goto MenuKH; break;
		case 3: goto MenuHH; break;

	}
	
MenuNV:
	MenuNV(); // In ra man hinh
	switch (ChonMenuNV())
	{
		case 0: goto MenuTC; break;
		case 1: // Doc File Nhan Vien
			system("cls");
			cout << "____________________THONG TIN TAT CA NHAN VIEN____________________" << endl;
			docfilenv();
			cout << "NHAN NUT BAT KI DE QUAY LAI\n";
			system("pause");
			goto MenuNV;
			break;
		case 2: //Them Nhanvien moi vao file
			system("cls");
			cout << "____________________THEM THONG TIN NHAN VIEN____________________" << endl;
			cin.ignore();
			Nhanvien nv;
			nv.nhap();
			nv.hienthi();
			ghifilenv(&nv);
			cout << "____________________THEM NHAN VIEN THANH CONG____________________";
			system("pause");
			goto MenuNV;
			break;
		case 3: //Chinh sua thong tin Nhan vien
			system("cls");
			cout << "____________________CHINH SUA THONG TIN NHAN VIEN____________________" << endl;
			cin.ignore();
			char chinhsuaNV[3];
			cout << "NHAP VAO MA SO NHAN VIEN CAN CHINH SUA THONG TIN: "; gets_s(chinhsuaNV);
			chinhsuanv(chinhsuaNV);
			system("pause");
			goto MenuNV;
			break;
		case 4: // Tim nhan vien
			system("cls");
			cout << "____________________TIM THONG TIN NHAN VIEN____________________" << endl;
			cin.ignore();
			char timNV[3];
			cout << "NHAP VAO MA SO NHAN VIEN CAN TIM: "; gets_s(timNV);
			timnv(timNV);
			cout << "NHAN NUT BAT KI DE QUAY LAI\n";
			system("pause");
			goto MenuNV;
			break;
		case 5: //Xoa nhan vien
			system("cls");
			cout << "____________________XOA THONG TIN NHAN VIEN____________________" << endl;
			cin.ignore();
			char xoaNV[3];
			cout << "NHAP VAO MA SO NHAN VIEN CAN XOA: "; gets_s(xoaNV);
			timnv(xoaNV);
			cout << "BAN CO CHAC CHAN MUON XOA, DU LIEU XOA SE KHONG THE KHOI PHUC LAI!!\n";
			cout << "[1|Xoa] [0|Huy]\n";
			int xoa0NV; cin >> xoa0NV;
			if(xoa0NV == 1){
				xoanv(xoaNV); 
				cout << "XOA DU LIEU THANH CONG!!!";
			}
			cout << "NHAN NUT BAT KI DE QUAY LAI\n";
			system("pause");
			goto MenuNV;
			break;
		case 6: //Thong ke nhan vien
			system("cls");
			cout << "____________________BANG THONG KE NHAN VIEN____________________";
			thongkenv();
			cout << "NHAN NUT BAT KI DE QUAY LAI\n";
			system("pause");
			goto MenuNV;
			break;

	

	}
	//Khach Hang____________________________________________________________________________________
MenuKH:
	MenuKH(); //In ra man hinh
	switch (ChonMenuNV())
	{
	case 0: goto MenuTC; break;
	case 1: // Doc File Nhan Vien 
		system("cls");
		cout << "____________________THONG TIN TAT CA KHACH HANG____________________" << endl;
		docfilekh();
		cout << "NHAN NUT BAT KI DE QUAY LAI\n";
		system("pause");
		goto MenuKH;
		break;
	case 2: //Them Khachang moi vao file
		system("cls");
		cout << "____________________THEM THONG TIN KHACH HANG____________________" << endl;
		cin.ignore();
		Khachhang kh;
		kh.nhap();
		kh.hienthi();
		ghifilekh(kh);
		cout << "____________________THEM KHACH HANG THANH CONG____________________";
		system("pause");
		goto MenuKH;
		break;
	case 3: //Chinh sua thong tin Khachhang
		system("cls");
		cout << "____________________CHINH SUA THONG TIN KHACH HANG____________________" << endl;
		cin.ignore();
		char chinhsuaKH[3];
		cout << "NHAP VAO MA SO KHACH HANG CAN CHINH SUA THONG TIN: "; gets_s(chinhsuaKH);
		chinhsuakh(chinhsuaKH);
		system("pause");
		goto MenuKH;
		break;
	case 4: // Tim khach hang
		system("cls");
		cout << "____________________TIM THONG TIN KHACH HANG____________________" << endl;
		cin.ignore();
		char timKH[3];
		cout << "NHAP VAO MA SO KHACH HANG CAN TIM: "; gets_s(timKH);
		timkh(timKH);
		cout << "NHAN NUT BAT KI DE QUAY LAI\n";
		system("pause");
		goto MenuKH;
		break;
	case 5: //Xoa khach hang
		system("cls");
		cout << "____________________XOA THONG TIN KHACH HANG____________________" << endl;
		cin.ignore();
		char xoaKH[3];
		cout << "NHAP VAO MA SO KHACH HANG CAN XOA: "; gets_s(xoaKH);
		timkh(xoaKH);
		cout << "BAN CO CHAC CHAN MUON XOA, DU LIEU XOA SE KHONG THE KHOI PHUC LAI!!\n";
		cout << "[1|Xoa] [0|Huy]\n";
		int xoa0KH; cin >> xoa0KH;
		if (xoa0KH == 1) {
			xoakh(xoaKH);
			cout << "XOA DU LIEU THANH CONG!!!";
		}
		cout << "NHAN NUT BAT KI DE QUAY LAI\n";
		system("pause");
		goto MenuKH;
		break;
	case 6: //Thong ke khach hang
		system("cls");
		cout << "____________________BANG THONG KE KHACH HANG____________________";
		thongkekh();
		cout << "NHAN NUT BAT KI DE QUAY LAI\n";
		system("pause");
		goto MenuKH;
		break;


	}

MenuHH:
	MenuHH(); // In ra man hinh
	switch (ChonMenuNV())
	{
	case 0: goto MenuTC; break;
	case 1: // Doc File Nhan Vien 
		system("cls");
		cout << "____________________THONG TIN TAT CA HANG HOA____________________" << endl;
		docfilesp();
		cout << "NHAN NUT BAT KI DE QUAY LAI\n";
		system("pause");
		goto MenuHH;
		break;
	case 2: //Them Nhanvien moi vao file
		system("cls");
		cout << "____________________THEM THONG TIN HANG HOA MOI____________________" << endl;
		cin.ignore();
		Sanpham sp;
		sp.nhap();
		sp.hienthi();
		ghifilesp(&sp);
		cout << "____________________THEM HANG MOI THANH CONG____________________";
		system("pause");
		goto MenuHH;
		break;
	case 3: //Chinh sua thong tin Nhan vien
		system("cls");
		cout << "____________________CHINH SUA THONG TIN HANG HOA____________________" << endl;
		cin.ignore();
		char chinhsuaHH[3];
		cout << "NHAP VAO MA SO HANG HOA CAN CHINH SUA THONG TIN: "; gets_s(chinhsuaHH);
		chinhsuasp(chinhsuaHH);
		system("pause");
		goto MenuHH;
		break;
	case 4: // Tim nhan vien 
		system("cls");
		cout << "____________________TIM THONG TIN HANG HOA____________________" << endl;
		cin.ignore();
		char timHH[3];
		cout << "NHAP VAO MA SO HANG HOA CAN TIM: "; gets_s(timHH);
		timsp(timHH);
		cout << "NHAN NUT BAT KI DE QUAY LAI\n";
		system("pause");
		goto MenuHH;
		break;
	case 5: //Xoa nhan vien
		system("cls");
		cout << "____________________XOA THONG TIN HANG HOA____________________" << endl;
		cin.ignore();
		char xoaHH[3];
		cout << "NHAP VAO MA SO HANG HOA CAN XOA: "; gets_s(xoaHH);
		timsp(xoaHH);
		cout << "BAN CO CHAC CHAN MUON XOA, DU LIEU XOA SE KHONG THE KHOI PHUC LAI!!\n";
		cout << "[1|Xoa] [0|Huy]\n";
		int xoa0HH; cin >> xoa0HH;
		if (xoa0HH == 1) {
			xoasp(xoaHH);
			cout << "XOA DU LIEU THANH CONG!!!";
		}
		cout << "NHAN NUT BAT KI DE QUAY LAI\n";
		system("pause");
		goto MenuHH;
		break;
	case 6: //Thong ke nhan vien
		system("cls");
		cout << "____________________BANG THONG KE HANG HOA____________________";
		thongkesp();
		cout << "NHAN NUT BAT KI DE QUAY LAI\n";
		system("pause");
		goto MenuHH;
		break;
	}
	

	
	// TEST VECTOR.............................................
	/*vector <char*> dssp;
	vector <char*>::iterator sp;
	char sp1[] = "xiaomi";
	char sp2[] = "oppo";
	dssp.push_back(sp1);
	dssp.push_back(sp2);
	cout << dssp[0] << dssp.back();*/
	//............................................................
////	Nhan kh;
//	vector<char*> dsspin;
//	char sp1[] = "Xiaomi";
//	char sp2[] = "iphone";
//	char sp3[] = "Oppo";
//	dsspin.push_back(sp1);
//	dsspin.push_back(sp2);
//	dsspin.push_back(sp3);
//	cout << dsspin[0] << dsspin[1];
//	kh.setdssp(&dsspin);
//	vector<char*> op;
//	op = *kh.getdssp();
//	cout << op[0] << op[1] << op[2];*/
	// END TEST ................................................
	//Khachhang kh;
	//int temp[20] = {0};
	//kh.setsoluong_sp(temp);
	/*Sanpham sp;
	sp.nhap();
	ghifilesp(&sp);
	docfilesp();*/
	//kh.nhap();
	//kh.hienthi();
	//ghifilekh(kh);
	//docfilekh();
	//char buff[] = "1";
	//xoakh(buff); */
	//timkh(buff);
	//chinhsuakh(buff);
	//thongkenv();
	//cout << "hello";
	system("pause");
	return 0;
}