#include<iostream>
#include<string.h>
#include<fstream>
#define MAX 5

using namespace std;

class firma{
	
	int osnovna_plata;
	
public:
	
	firma(int op){
		osnovna_plata=op;
	}
	virtual double ukupna_plata() = 0;
		
	virtual void citaj(){
		cout << "Unesite osnovnu platu: ";
		cin >> osnovna_plata;
	}
	virtual void pisi(){
		cout << "Osnovna plata: " << osnovna_plata << endl;

		fstream f;
		f.open("zaposleni.txt", ios::app);
		if(!f){
			cout << "Greska!\n";	
		}
		f << "Osnovna plata je: " << osnovna_plata << endl;
		f.close();
	}
};

class rukovodilac : public firma{
	
	int dodatak1;
	
public:
	rukovodilac(int op, int ddtk1) : firma(op){
		dodatak1=ddtk1+op;
	}
	
	double ukupna_plata(){
		return dodatak1;
	}
	
	void pisi(){
		firma::pisi();
		cout << "Dodatak rukovodioca je: " << dodatak1 << endl;
		cout << "Ukupna plata rukovodioca je: " << ukupna_plata() << endl;
		fstream f;
		f.open("zaposleni.txt", ios::app);
		if(!f){
			cout << "Greska!\n";	
		}
		f << "Dodatak rukovodioca je: " << dodatak1 << endl;
		f << "Ukupna plata rukovodioca je: " << ukupna_plata() << endl;
	}
	
	void citaj(){
		cout << "Unesite dodatak rukovodioca: ";
		cin >> dodatak1;
	}
};

class radnik : public firma{
	
	int dodatak2;
	
public:
	radnik(int op, int ddtk2) : firma(op){
		dodatak2=ddtk2+op;
	}
	
	double ukupna_plata(){
		return dodatak2;
	}
	
	void pisi(){
		firma::pisi();
		cout << "Dodatak radnika je: " << dodatak2 << endl;
		cout << "Ukupna plata radnika je: " << ukupna_plata() << endl;
		fstream f;
		f.open("zaposleni.txt", ios::app);
		if(!f){
			cout << "Greska!\n";	
		}
		f << "Dodatak radnika je: " << dodatak2 << endl;
		f << "Ukupna plata radnika je: " << ukupna_plata() << endl;
	}
	
	void citaj(){
		cout << "Unesite dodatak rukovodioca: ";
		cin >> dodatak2;
	}
};

int main(){
	
	int brojUpisanih=0, dodatak1, dodatak2, osnovna_plata, opcija;
	firma *niz[MAX];
	
	while(1){
		if(brojUpisanih>19)
			break;//upisano je 20 radnika
			
		do{
			cout<<"1. Rukovodilac\n2. Radnik\n3. Kraj\n";
			opcija = getchar();
			cin.ignore();
		}while(opcija!='1' && opcija!='2' && opcija!='3');
		
		if(opcija == '1'){
			cout <<"Unesite osnovnu platu: ";
			cin >> osnovna_plata;

			cout<<"Dodatak1: ";
			cin>>dodatak1;
			cin.ignore();

			niz[brojUpisanih] = new rukovodilac(osnovna_plata, dodatak1);
		}
		else if(opcija == '2'){
			cout <<"Unesite osnovnu platu: ";
			cin >> osnovna_plata;

			cout<<"Dodatak2: ";
			cin>>dodatak2;
			cin.ignore();

			niz[brojUpisanih] = new radnik(osnovna_plata, dodatak2);
		}
		else if(opcija == '3'){
			cout << "Kraj programa.\n";
			break;
		}
		else
			continue;
		brojUpisanih++;
	}
	
	//upis u datoteku
	for(int i=0; i < brojUpisanih; i++){
		niz[i]->pisi();
	}
	
	system("pause");
	return 0;
}
