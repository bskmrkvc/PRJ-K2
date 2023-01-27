#include<iostream>
#include<fstream>
#include<string.h>
#define PI 3.1453
#define MAX 3

using namespace std;

class figura{
	char boja[20];
public:
	figura(char *bojaF){
		strcpy(boja, bojaF);
	}
	virtual void pisi(){
		cout << "Boja: " << boja << endl;
		
		fstream f;
		f.open("bosko.txt", ios::app);
		if(!f){
			cerr << "Greska prilikom otvaranja fajla bosko.txt\n";
			exit(1);
		}
		f << "Boja figure je: " << boja << endl;
		f.close();
	}
	virtual double p() = 0;
};

class krug : public figura{
	int r;
public:
	krug(char *bojaK, int rK) : figura(bojaK){
		r = rK;
	}
	void pisi(){
		figura::pisi();
		cout << "Poluprecnik je: " << r << endl;
		cout << "Povrsina je: "<< p() << endl;
		
		fstream f;
		f.open("bosko.txt", ios::app);
		if(!f){
			cerr << "Greska prilikom otvaranja fajla bosko.txt\n";
			exit(1);
		}
		f << "Poluprecnik je: " << r << endl;
		f << "Povrsina je: "<< p() << endl;
		f.close();
	}
	
	double p(){
		return r*r*PI;
	}
};

class kvadrat : public figura{
	int a;
public:
	kvadrat(char *bojaK, int aK) : figura(bojaK){
		a = aK;
	}
	void pisi(){
		figura::pisi();
		cout << "Stranica je: " << a << endl;
		cout << "Povrsina je: "<< p() << endl;
		
		fstream f;
		f.open("bosko.txt", ios::app);
		if(!f){
			cerr << "Greska prilikom otvaranja fajla bosko.txt\n";
			exit(1);
		}
		f << "Stranica je: " << a << endl;
		f << "Povrsina je: "<< p() << endl;
		f.close();
	}
	double p(){
		return a*a;
	}
};

int main(){
	
	int opcija, poluprecnik, stranica, brUpisanih=0;
	char boja[81];
	
	figura *niz[MAX];
	
	while(1){
		if(brUpisanih > MAX) break;
		do{
			cout << "1.Krug\n2.Kvadrat\n3.Kraj\n";
			cin >> opcija;
			cin.ignore();
		}while(opcija<1 || opcija>3);
		
		if(opcija == 1){
			cout << "Unesite boju: ";
			gets(boja);
			
			cout << "Poluprecnik: ";
			cin >> poluprecnik;
			cin.ignore();
			niz[brUpisanih]=new krug(boja,poluprecnik);
		}
		else if(opcija==2){
			cout << "Unesite boju: ";
			gets(boja);
			
			cout << "Stranica: ";
			cin >> stranica;
			cin.ignore();
			niz[brUpisanih]=new kvadrat(boja,stranica);
		}
		else{
			break;
		}
		brUpisanih++;
	}
	
	int min, max;
	cout << "Unesite min i max povrsine: ";
	cin >> min >> max;
	
	cout<<"Figure cije su povrsine u datom opsegu: "<<endl;
	for(int i = 0 ; i < brUpisanih; i++){
		if(niz[i]->p() >= min && niz[i]->p() <= max)
			niz[i]->pisi();
			cout << endl;
	}
	
	system("pause");
	return 0;
}
