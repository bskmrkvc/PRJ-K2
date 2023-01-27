#include<string.h>
#include<fstream>
#include<iostream>
#include<string>
#define MAX 3

using namespace std;

struct student{
	char ime[50], smer[20];
	int br_indeksa;
};

int main(){
	student *niz;
	int n=0;
	niz = new student[MAX];
	
	fstream f;
	f.open("studenti.txt", ios::out | ios::in | ios::trunc);
	if(!f){
		cerr << "Greska prilikom otvaranja fajla!\n";
		exit(1);
	}
	//upis
	for(int i = 0; i < MAX; i++){
		cout << "Unesite podatke o " << i+1 << ". studentu\n";
		
		cout << "Ime: ";
		gets(niz[i].ime);
		cout << "Smer: ";
		gets(niz[i].smer);
		cout << "Broj indeksa: ";
		cin >> niz[i].br_indeksa;
		
		if(niz[i].br_indeksa < 100){
			f << niz[i].ime << endl;
			f << niz[i].smer << endl;
			f << niz[i].br_indeksa << endl;
			n++;
		}
		cin.ignore();
	}
	
	//citanje
	f.seekg(0);
	
	char trazeniSmer[20];
	student pomocna;
	cout << "Unesite trazeni smer: ";
	gets(trazeniSmer);
	
	for(int i = 0 ; i < n; i++){
		f >> pomocna.ime >> pomocna.smer >> pomocna.br_indeksa;
		if(strcmp(pomocna.smer, trazeniSmer) == 0){
			cout << "Ime: " << pomocna.ime << endl;
			cout << "Smer: " << pomocna.smer << endl;
			cout << "Broj indeksa: " << pomocna.br_indeksa << endl;
		}
	}
	
	f.close();
	delete niz;
	
	system("pause");
	return 0;
}
