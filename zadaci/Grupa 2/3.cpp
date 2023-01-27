#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class osoba{
	char ime[81];
public:
	osoba(){
		strcpy(ime,"");
	}
	virtual void citaj(){
		cout << "Unesite ime osobe: ";
		gets(ime);
	}
	virtual void pisi(char *dat){
		cout <<"Ime osobe: "<<ime<<endl;
		fstream f;
		f.open(dat, ios::app);
		if(!f){
			cerr << "Greska pri otvaranju fajla podaci.txt\n";
			exit(1);
		}
		f <<"Ime osobe: "<<ime<<";";
		f.close();
	}
};

class student : public osoba{
	int br_indeksa;
public:
	student() : osoba(){
		br_indeksa = 0;
	}
	void citaj(){
		osoba::citaj();
		cout << "Unesite broj indeksa studenta: ";
		cin >> br_indeksa;
	}
	void pisi(char *dat){
		osoba::pisi(dat);
		cout <<"Broj indeksa studenta: "<<br_indeksa<<endl;
		fstream f;
		f.open(dat, ios::app);
		if(!f){
			cerr << "Greska pri otvaranju fajla podaci.txt\n";
			exit(1);
		}
		f <<"Broj indeksa studenta: "<<br_indeksa<<endl;
		f.close();
	}
};

class predavac : public osoba{
	char zvanje[81];
public:
	predavac() : osoba(){
		strcpy(zvanje, "");
	}
	void citaj(){
		osoba::citaj();
		cout << "Unesite zvanje predavaca: ";
		gets(zvanje);
	}
	void pisi(char *dat){
		osoba::pisi(dat);
		cout <<"Zvanje predavaca: "<<zvanje<<endl;
		fstream f;
		f.open(dat, ios::app);
		if(!f){
			cerr << "Greska pri otvaranju fajla podaci.txt\n";
			exit(1);
		}
		f <<"Zvanje predavaca: "<<zvanje<<endl;
		f.close();
	}
};

int main(){
	
	int opcija, br=0;
	osoba *niz[3];
	
	while(1){
		if(br >= 3) break;
		do{
			cout << "Unesite opciju\n";
			cout<<"1.Student\n2.Predavac\n3.Kraj   :";
			cin >> opcija;
			cin.ignore();
		}while(opcija < 1 || opcija > 3);
		
		if(opcija==1){
			niz[br] = new student();
			niz[br]->citaj();
			niz[br++]->pisi("podaci.txt");
		}
		else if(opcija==2){
			niz[br] = new predavac();
			niz[br]->citaj();
			niz[br++]->pisi("podaci.txt");
		}
		else{
			break;
		}
	}
	
	for(int i = 0 ; i < br; i++){
		delete niz[i];
	}
	
	system("pause");
	return 0;
}
