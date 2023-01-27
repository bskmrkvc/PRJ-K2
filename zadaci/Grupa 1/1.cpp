#include<iostream>
#include<string.h>
#include<fstream>
#define MAX 10

using namespace std;

typedef struct mobilni{
	char model[30];
	int kolicina, cena;
};

int main(){
	mobilni *niz, pomocna;
	
	niz = new typeof(mobilni)[MAX];
	
	cout << "Unesite podatke o mobilnim telefonima\n";
	
	ofstream f;
	
	f.open("katalog.txt", ios::trunc);
	
	if(!f){
		cout << "Greska pri otvaranju fajla!\n";
		system("pause");
		exit(1);
	}
	
	for(int i = 0 ; i < MAX; i++){
		cout << "Unesite ime modela: ";
		gets(niz[i].model);
		cout << "Unesite kolicinu datog modela: ";
		cin >> niz[i].kolicina;
		cout << "Unesite cenu datog modela: ";
		cin >> niz[i].cena;
		cin.ignore();
		
		if(niz[i].kolicina > 0){
			f << niz[i].model <<" "<< niz[i].kolicina <<" "<< niz[i].cena << endl;
		}
		
	}
	f.close();
	
	ifstream f1;
	char ime[30];
	
	f1.open("katalog.txt");
	if(!f1){
		cout << "Greska pri otvaranju fajla! 2\n";
		system("pause");
		exit(1);
	}
	
	cout << "Unesite ime modela koji se trazi: ";
	gets(ime);
	while(f1.peek()!=EOF){
		f1 >> pomocna.model >> pomocna.kolicina >> pomocna.cena;
		if(strcmp(pomocna.model, ime) == 0){
			cout << "\nIme modela: " << pomocna.model;
			cout << "\nKolicina tog modela: " << pomocna.kolicina;
			cout << "\nCena tog modela: " << pomocna.cena;
		}
	}
	
	f1.close();
	
	delete niz;
	
}
