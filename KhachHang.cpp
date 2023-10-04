#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct NS{
	int day,month,year;
};
class KH{
	private:
		string ht,cmt,hk;
		NS ns;
	public:
		void import();
		void display();
		void listImport(KH* khs[], int n);
		void listDisplay(KH* khs[], int n);
		void listSort(KH* khs[], int n);
		void listBirthday12(KH* khs[], int n);
		bool static checkCmt(KH* khs[], int n,string cmt);
		string getHt();
		int getMonth();
		string getCmt();
		void setCmt(string cmt);
};
string KH::getHt(){
	return this->ht;
}
int KH::getMonth(){
	return this->ns.month;
}
string KH::getCmt(){
	return this->cmt;
}
void KH::setCmt(string cmt){
	this->cmt = cmt;
}
void KH::import(){
	fflush(stdin);
	cout << "-Nhap ho va ten: ";getline(cin,this->ht);
	cout << "-Nhap ngay thang nam sinh(dd/mm/yyyy): "<< endl;
	cout << "\t+Nhap ngay: "; cin >> this->ns.day;
	cout << "\t+Nhap thang: "; cin >> this->ns.month;
	cout << "\t+Nhap nam: "; cin >> this->ns.year;
	fflush(stdin);
	cout << "-Nhap so chung minh thu: "; getline(cin,this->cmt);
	cout << "-Nhap ho khau: ";getline(cin,this->hk);
}
void KH::display(){
	cout << "\t\t[+]Ho va ten: " << this->ht << endl;
	cout << "\t\t[+]Ngay sinh: "<< this->ns.day << "/" << this->ns.month << "/" << this->ns.year << endl;
	cout << "\t\t[+]So chung minh thu: " << this->cmt << endl;
	cout << "\t\t[+]Ho khau: " << this->hk << endl;
}
bool KH::checkCmt(KH* khs[], int n,string cmt){
	for(int i = 0; i < n;i++){
		if(khs[i]->getCmt() == cmt) return false;
	}
	return true;
}
void KH::listImport(KH* khs[], int n){
	cout << "\t\t\tNHAP THONG TIN KHACH HANG\n" << endl;
	for(int i = 0; i < n;i++){
		cout << "[-]Nhap thong tin khach hang thu " << i + 1 << endl;
		khs[i] = new KH();
		khs[i] -> import();
		while(!checkCmt(khs,i,khs[i]->getCmt())){
			cout << "\t[!]So chung minh thu ban da bi trung!" << endl;
			cout << "\t[=>]Vui long nhap lai: ";string cmt; getline(cin,cmt);
			khs[i]->setCmt(cmt);
		}
	}
}
void KH::listDisplay(KH* khs[], int n){
	cout << "\t\t\tXUAT THONG TIN KHACH HANG\n" << endl;
	for(int i = 0; i < n;i++){
		cout << "\t[=>]Thong tin khach hang thu " << i + 1 << endl;
		khs[i] -> display();
	}
}
bool cmp(KH* other1, KH* other2){
	return other1->getHt() < other2->getHt();
}
void KH::listSort(KH* khs[], int n){
	cout << "\n\t\t\tTHONG TIN KHACH HANG SAU SAP XEP\n" << endl;
	sort(khs,khs + n,cmp);
	for(int i = 0; i < n;i++){
		cout << "\t[=>]Thong tin khach hang thu " << i + 1 << endl;
		khs[i] -> display();
	}
}

void KH::listBirthday12(KH* khs[], int n){
	cout << "\n\t\t\tTHONG TIN KHACH HANG SINH THANG 12\n" << endl;
	bool check = false;
	for(int i = 0; i < n;i++){
		if(khs[i]->getMonth() == 12){
			cout << "\t[=>]Thong tin khach hang thu " << i + 1 << endl;
			khs[i] -> display();
			check = true;
		}
	}
	if(!check) {
		cout << "\t\t=>Khong co khach hang sinh nhat thang 12" << endl;
	}
}
int main(){
	cout << "[*]Nhap so luong khach hang: ";
	int n;cin >> n;
	KH * khs[n];
	KH*kh = new KH();
	kh->listImport(khs,n);
	kh->listDisplay(khs,n);
	kh->listSort(khs,n);
	kh->listBirthday12(khs,n);
	for(int i = 0; i < n;i++){
		delete khs[i];
	}
	delete kh;
	return 0;
}


