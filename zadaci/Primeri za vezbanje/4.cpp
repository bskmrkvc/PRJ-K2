#include<fstream>
#include<iostream>
#include<string.h>

using namespace std;

struct stan{
	int redni_broj, broj_ulaza, broj_stana, broj_stanara;
	char ime_ulice[81];
};

int main(){
	
	int n;
	stan *niz, pomocna;
	
	do{
		cout << "Unesite broj stanova: ";
		cin >> n;
	}while(n<0 || n>10);
	
	niz = new stan[n];
	
	fstream f;
	f.open("stanovi.txt", ios::out | ios::in | ios::trunc);
	if(!f){
		cerr << "Greska prilikom otvaranja datoteke stanovi.txt\n";
		exit(1);
	}
	
	for(int i = 0 ; i < n ; i++){
		cout << "Unesite podatke o " << i+1 << ". stanu\n";
		cout << "Redni broj: ";
		cin >> (niz + i)->redni_broj;
		cout << "Broj ulaza: ";
		cin >> (niz + i)->broj_ulaza;
		cout << "Broj stana: ";
		cin >> (niz + i)->broj_stana;
		cout << "Broj stanara: ";
		cin >> (niz + i)->broj_stanara;
		cin.ignore();
		cout << "Ime ulice: ";
		gets((niz+i)->ime_ulice);
		
		f << (niz + i)->redni_broj <<" "<<(niz + i)->broj_ulaza<<" "<<(niz + i)->broj_stana<<" "<<(niz + i)->broj_stanara<<" "<<(niz+i)->ime_ulice<<endl;
		
	}
	
	f.seekg(0);
	
	while(f.peek()!=EOF){
		f >> pomocna.redni_broj >>pomocna.broj_ulaza >> pomocna.broj_stana >> pomocna.broj_stanara >> pomocna.ime_ulice;
		cout << "Redni broj: ";
		cout << pomocna.redni_broj << endl;
		cout << "Broj ulaza: ";
		cout << pomocna.broj_ulaza << endl;
		cout << "Broj stana: ";
		cout << pomocna.broj_stana << endl;
		cout << "Broj stanara: ";
		cout << pomocna.broj_stanara << endl;
		cin.ignore();
		cout << "Ime ulice: ";
		cout << pomocna.ime_ulice << endl;
	}
		
	f.close();
	for(int i =0 ; i < n; i++){
		delete (niz+i);
	}
	system("pause");
	return 0;
}
