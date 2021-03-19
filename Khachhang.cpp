#include "Khachhang.h"
void Khachhang::setmaso(char *masoIn)
{
	strcpy_s(maso, masoIn);
}
char* Khachhang::getmaso()
{
	return maso;
}
void Khachhang::seten(char *tenIn)
{
	strcpy_s(ten, tenIn);
}
char* Khachhang::getten()
{
	return ten;
}
void Khachhang::setgioitinh(char *gtIn)
{
	strcpy_s(gioitinh, gtIn);
}
char* Khachhang::getgioitinh()
{
	return gioitinh;
}
void Khachhang::setngaysinh(int ngayIn, int thangIn, int namIn)
{
	ngaysinh.ngay = ngayIn;
	ngaysinh.thang = thangIn;
	ngaysinh.nam = namIn;
}
Ngay Khachhang::getngaysinh()
{
	return ngaysinh;
}
void Khachhang::setcmnd(char *cmndIn)
{
	strcpy_s(cmnd, cmndIn);
}
char* Khachhang::getcmnd()
{
	return cmnd;
}
void Khachhang::setdiachi(char *diachiIn)
{
	strcpy_s(diachi, diachiIn);
}
char* Khachhang::getdiachi()
{
	return diachi;
}
void Khachhang::setsdt(char *sdtIn)
{
	strcpy_s(sdt, sdtIn);
}
char* Khachhang::getsdt()
{
	return sdt;
}
void Khachhang::setdssp(Sanpham dsspin[20]) {
	for (int i = 0; i < 20; i++)
	{
		sp[i] = dsspin[i];
	}
}
Sanpham* Khachhang::getdssp() {
	return sp;
}
void Khachhang::setsoluong_sp(int soluongin[20]) {
	for (int i = 0; i < 20; i++)
	{
		soluong[i] = soluongin[i];
	}
}
int* Khachhang::getsoluong_sp() {
	return soluong;
}
void Khachhang::setngaymua(Ngay ngaymuain[20])
{
	for (int i = 0; i < 20; i++)
	{
		ngaymua[i] = ngaymuain[i];
	}
}
Ngay* Khachhang::getngaymua()
{
	return ngaymua;
}

//End Get Set....................................................................

void  Khachhang::nhapdssp(char buff[3], int soluongin,Ngay temp, int i)
{	
	bool success = false;
	Sanpham sp1;
	fstream f("Sanpham.dat", ios::in | ios::binary);
	fstream fn("abc.dat", ios::app | ios::binary);
	f.read(reinterpret_cast<char*>(&sp1), sizeof(Sanpham));
	while (f) {
		if (strcmp(buff, sp1.getmaso()) == 0) // neu ma so san pham trong file khop voi buff truyen vao
		{
			if (soluongin > sp1.getsoluong()) // Neu so luong mua hang nhieu hon so luong trong kho
			{
				cout << "\nTrong kho chi con " << sp1.getsoluong() << " san pham tuong ung. Khong du de ban !!!";
			}
			else // Neu so luong trong kho con du de dap ung
			{
				// Tru so luong trong kho
				sp1.setsoluong(sp1.getsoluong() - soluongin);
				//Tang so luong mua 
				sp[i] = sp1;
				soluong[i] = soluongin;
				ngaymua[i] = temp;
				system("cls");
				cout << "Giao dich hoan tat!";
				success = true;
			}
		}
		fn.write(reinterpret_cast<char*>(&sp1), sizeof(Sanpham));
		f.read(reinterpret_cast<char*>(&sp1), sizeof(Sanpham));
	}
	f.close();
	fn.close();
	remove("Sanpham.dat");
	rename("abc.dat", "Sanpham.dat");
	if (!success)
	{
		cout << "San pham nay trong kho da het!!!";
	}

} // Nhap vao ma so san pham mua va so luong -> them vao danh sach mua hang cua khach hang va tru so luong trong kho

void Khachhang::nhap() {
	//Nhap thong tin co ban
	for(int i = 0; i < 20; i++) {
		soluong[i] = 0;
	}
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
	//Nhap mat hang mua
	system("cls");
	cout << "________________________DANH SACH SAN PHAM________________________________\n";
	docfilesp();
	system("pause");
	cout << "NHAN NUT BAT KI DE TIEP TUC\n";
	system("cls");
	cout << "________________________NHAP THONG TIN SAN PHAM________________________________";
	cout << "\nNhap vao so luong mat hang: ";
	int n; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap ma so mat hang: ";
		char buff[3]; gets_s(buff);
		cout << "\nNhap so luong san pham cua mat hang nay: ";
		int soluong; cin >> soluong; cin.ignore();
		Ngay temp;
		cout << "\nNhap ngay mua: "; cin >> temp.ngay;
		cout << "\nNhap thang mua: "; cin >> temp.thang;
		cout << "\nNhap nam mua: "; cin >> temp.nam; cin.ignore();
		nhapdssp(buff,soluong,temp,i);
	}
	
}

void Khachhang::hienthi() {
	cout << "Ma so: " << maso << endl
		<< "Ten: " << ten << endl
		<< "Gioi tinh:  " << gioitinh << endl
		<< "Ngay sinh: " << ngaysinh.ngay << "/" << ngaysinh.thang << "/" << ngaysinh.nam << endl
		<< "So cmnd: " << cmnd << endl
		<< "Dia chi: " << diachi << endl
		<< "So dien thoai: " << sdt << endl;
	//Hien thi thong tin san pham da mua
	cout << "Thong tin san pham:..................................\n";
	for (int i = 0; soluong[i] != 0; i++)
	{
		sp[i].hienthi_mua();
		cout << "So luong: " << soluong[i] << endl;
		cout << "Ngay mua: " << ngaymua[i].ngay << "-" << ngaymua[i].thang << "-" << ngaymua[i].nam << endl;;
	}
}

void ghifilekh(Khachhang kh) {
	fstream f("Khachhang.dat", ios::app | ios::binary);
	f.write(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
	f.close();
}

void docfilekh()
{
	//char buff[100];
	Khachhang kh ;
	fstream f("Khachhang.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
	while (f) {
		kh.hienthi();
		cout << "____________________________________________________________" << endl;
		f.read(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
	}
	f.close();
}

void timkh(char *maso){
	bool success = false;
	Khachhang kh;
	fstream f("Khachhang.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
	while (f) {
		if (strcmp(maso, kh.getmaso()) == 0)
		{
			cout << "DA TIM THAY 1 KHACH HANG\n";
			kh.hienthi();
			success = true;
			break;
		}
		f.read(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
	}
	f.close();
	if (success == false)
	{
		cout << "KHONG TIM THAY KHACH HANG NAO CO MA SO " << maso << endl;
	}
}

void xoakh(char *maso) {
	Khachhang kh;
	fstream f("Khachhang.dat", ios::in | ios::binary);
	fstream fn("abc.dat", ios::app | ios::binary);
	f.read(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
	while (f) {
		if (strcmp(maso, kh.getmaso()) != 0)
		{
			fn.write(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
		}
		f.read(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
	}
	f.close();
	fn.close();
	remove("Khachhang.dat");
	rename("abc.dat", "Khachhang.dat");
}

void chinhsuakh(char*maso) {
	Khachhang kh;
	fstream f("Khachhang.dat", ios::in | ios::binary);
	fstream fn("abc1.dat", ios::app | ios::binary);
	f.read(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
	while (f) {
		if (strcmp(maso, kh.getmaso()) == 0)
		{
			char buff[100];
			kh.hienthi();
			cout << "Ban muon chinh sua thong tin nao ??\n0.Bo qua\n1.Ten\n2.Dia chi\n3.So dien thoai\n4.Them san pham\n5.Xoa san pham\n";
			int choice;
			cin >> choice;
			cin.ignore();
			system("cls");
			if (choice == 1)
			{
				cout << "Nhap ten moi: ";
				gets_s(buff);
				kh.seten(buff);
			}
			else if (choice == 2)
			{
				cout << "Nhap dia chi moi: ";
				gets_s(buff);
				kh.setdiachi(buff);
			}
			else if (choice == 3)
			{
				cout << "Nhap so dien thoai moi: ";
				gets_s(buff);
				kh.setsdt(buff);
			}
			else if (choice == 4)
			{
				cout << "________________________NHAP THONG TIN SAN PHAM________________________________";
				cout << "\nNhap vao so luong mat hang: ";
				int n; cin >> n; cin.ignore();
				for (int i = 0; i < n; i++)
				{
					cout << "\nNhap ma so mat hang: ";
					char buff[3]; gets_s(buff);
					cout << "\nNhap so luong san pham cua mat hang nay: ";
					int soluong; cin >> soluong; cin.ignore();
					Ngay temp;
					cout << "\nNhap ngay mua: "; cin >> temp.ngay;
					cout << "\nNhap thang mua: "; cin >> temp.thang;
					cout << "\nNhap nam mua: "; cin >> temp.nam;
					//cout << kh.getsoluong_sp()[i]; // here
					for (int j = 0; j < 20; j++) {
						//cout << kh.getsoluong_sp()[j];
						if (kh.getsoluong_sp()[j] == 0)
						{
							kh.nhapdssp(buff, soluong, temp,j);
							cout << "\n_____THEM SAN PHAM THANH CONG _____";
							break;
						}
					}
				}
			}
			else if (choice == 5)
			{
				cout << "\nNHAP VAO MA SO SAN PHAM CAN XOA: ";
				char buff[3]; gets_s(buff);
				for (int j = 0; j < 20; j++) {
					//cout << kh.getsoluong_sp()[j];
					if (strcmp(kh.getdssp()[j].getmaso(), buff) == 0) //Tim ra duoc san pham can xoa, j luc nay la stt cua phan tu nay
					{
						kh.getdssp()[j].hienthi_mua();
						cout << "\nBAN CO CHAC MUON XOA PHAN TU NAY ??? \n[1|Xoa] [2|Huy]";
						int n; cin >> n;
						if (n == 1) // Xoa
						{
							for (int i = j; i < 19; i++)
							{
								kh.getdssp()[i] = kh.getdssp()[i + 1];
								kh.getsoluong_sp()[i] = kh.getsoluong_sp()[i + 1];
								kh.getngaymua()[i] = kh.getngaymua()[i + 1];
							}
							Sanpham *temp = new Sanpham;
							Ngay *tempngay = new Ngay;
							kh.getdssp()[19] = *temp;
							kh.getsoluong_sp()[19] = 0;
							kh.getngaymua()[19] = *tempngay;

							cout << "\n_____XOA SAN PHAM THANH CONG _____";
							break;
						}
						else
						{ //Khong xoa
							break;
						}


					}
				}
			}
			else {}
		}

		fn.write(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
		f.read(reinterpret_cast<char*>(&kh), sizeof(Khachhang));
	}
	f.close();
	fn.close();
	remove("Khachhang.dat");
	rename("abc1.dat", "Khachhang.dat");
}

void thongkekh()
{
	Khachhang *kh = new Khachhang[20];
	fstream f("Khachhang.dat", ios::in | ios::binary);
	f.read(reinterpret_cast<char*>(&kh[0]), sizeof(Khachhang));
	int idx = 0;
	while (f) {
		idx++;
		f.read(reinterpret_cast<char*>(&kh[idx]), sizeof(Khachhang));
	}
	f.close();
	cout << "\nSO LUONG KHACH HANG:  " << idx;
	cout << "\nNHAN NUT BAT KI DE TIEP TUC\n";
	system("pause");
	//IN RA KHACH HANG MUA NHIEU SAN PHAM NHAT
	Khachhang khmax = kh[0];
	int max = 0;
	for (int i = 0; i < idx ; i++)
	{
		int dem = 0;
		for (int j = 0; j < 20; j++) {
			if (kh[i].getsoluong_sp()[j] == 0) //{1,1,1,0,0,0,0...}
			{
				dem = dem + j;
				break;
			}
		}
		if (dem > max)
		{
			max = dem;
			khmax = kh[i];
		}
	}
	// Da co khach hang max 
	cout << "\n______________________KHACH HANG MUA NHIEU SAN PHAM NHAT__________________\n ";
	//khmax.hienthi();
	for (int i = 0; i < idx ; i++) {
		int dem = 0;
		for (int j = 0; j < 20; j++) {
			if (kh[i].getsoluong_sp()[j] == 0) //{1,1,1,0,0,0,0...}
			{
				dem = dem + j;
				break;
			}
		}
		if (dem == max)
		{
			kh[i].hienthi();
		}
	}
	cout << "NHAN NUT BAT KI DE TIEP TUC";
	system("pause");
	// IN RA KHACH HANG CHI TIEU NHIEU NHAT
	khmax = kh[0];
	max = 0;
	for (int i = 0; i < idx; i++)
	{
		int dem=0;
		for (int j = 0; j < 20; j++) {
			if (kh[i].getsoluong_sp()[j] != 0) //{1,1,1,0,0,0,0...}
			{
				dem = dem + (kh[i].getdssp()[j].getdongia());
			}
		}
		if (dem > max)
		{
			max = dem;
			khmax = kh[i];
		}
	}
	// Da co khach hang max 
	system("cls");
	cout << "\n_____________________KHACH HANG CO CHI TIEU CAO NHAT____________________\n ";
	for (int i = 0; i < idx; i++) {
		int dem = 0;
		for (int j = 0; j < 20; j++) {
			if (kh[i].getsoluong_sp()[j] != 0) //{1,1,1,0,0,0,0...}
			{
				dem = dem + kh[i].getdssp()[j].getdongia();
			}
		}
		if (dem == max)
		{
			kh[i].hienthi();
		}
	}
	
}
