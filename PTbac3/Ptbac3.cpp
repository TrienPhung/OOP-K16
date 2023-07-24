#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
using ll = long long;
#define pi 3,14159
//Giai pt A.X^3 + B.X^2 + C.X + D = 0
class pt{
	private : 
		float a,b,c,d;
	public :
		void import();
		void display();
		void giai();
};
void pt:: import(){
	cout << "\n\t\t\t\tPT BAC 3 CO DANG: AX^3 + BX^2 + CX + D = 0\n";
	cout << "Nhap he so a: ";
	cin >> this->a;
	cout << "Nhap he so b: ";
	cin >> this -> b;
	cout << "Nhap he so c: ";
	cin >> this -> c;
	cout << "Nhap he so d: ";
	cin >> this -> d;
}
void pt::display(){
	cout << "PT Bac 3: " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0\n"; 
}
void pt::giai(){
	if(a==0){	
		//PT BAC 2 CO DANG: bx^2 + cx + d = 0
		if(b==0){
			//PT BAC 1 CO DANG: cx + d = 0
			if(c == 0){
				if(d == 0){
					cout << "\nPhuong trinh vo so nghiem";
				}else{
					
					cout << "\nPhuong trinh vo nghiem";
				}
			}else{
				cout << "Phuong trinh co 1 nghiem : ";
				cout << "\nx = " << -d/c << endl;
			}	
		}else{
				float delta = c*c - 4*b*d;
			
				if(delta > 0){
					cout << "Phuong trinh co 2 nghiem phan biet: ";
					float x1 = (-c + sqrt(delta)) / (2*b);
					float x2 = (-c - sqrt(delta)) / (2*b);
					cout << "\nx1 = " << x1;
					cout << "\nx2 = " << x2;
				}else 
					if(delta == 0){
						cout << "Phuong trinh co nghiem kep: ";
						cout << "\nx1 = x2 = " << -c/(2*b);
					}
				else{
					cout << "Phuong trinh vo nghiem!" << endl;
				}
			}
		
	}else{
		float delta = (b*b) - (3*a*c);
		float k = ((9*a*b*c) - (2*b*b*b) - (27*a*a*d)) / (2*sqrt(pow(fabs(delta),3)));
		if(delta > 0){
			if(delta > 0){
				if(fabs(k) <= 1){
					cout << "Phuong trinh co 3 nghiem: ";
					float x1 = (2*sqrt(delta)*cos(acos(k)/3) - b)/ (3*a);
					float x2 = (2*sqrt(delta)*cos(acos(k)/3 - (2*pi)/3) - b)/ (3*a);
					float x3 = (2*sqrt(delta)*cos(acos(k)/3 + (2*pi)/3) - b)/ (3*a);
					cout << "\nx1 = " << x1;
					cout << "\nx2 = " << x2;
					cout << "\nx3 = " << x3; 
				}
				else if(fabs(k) > 1){
					cout << "Phuong trinh co 1 nghiem duy nhat: ";
					float x = ((sqrt(delta) * fabs(k))/ 3*a*k)*(pow(fabs(k) + sqrt(k*k - 1),1/3) + pow(fabs(k) - sqrt(k*k - 1),1/3)) - (b/(3*a));
					cout << "\nx = " << x;
				}
			}
		}else if(delta == 0){
				cout << "Phuong trinh co mot nghiem boi: ";
				float x = (-b + pow(b*b*b - (27*a*a*d),1/3)) /(3*a);
				cout << "\nx = " << x;
		}
		else
		{
			cout << "\nPhuong trinh co 1 nghiem duy nhat : ";
			float x = (sqrt(fabs(delta))*(pow((k + sqrt(k*k + 1)),1/3) + pow((k - sqrt(k*k + 1)),1/3)) - b)/(3*a);
			cout << "\nx = " << (sqrt(fabs(delta))*(pow((k + sqrt(k*k + 1)),1/3) + pow((k - sqrt(k*k + 1)),1/3)) - b)/(3*a);
		}
	}
}
int main(){
	pt a;
	a.import();
	a.display();
	a.giai();
	return 0;
}


