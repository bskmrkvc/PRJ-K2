#include<fstream>
#include<iostream>
#include<string.h>

using namespace std;

void citanje(char *ime);
void upis(char *ime);

int n;

int main(){
	
	char ime[20];
	
	cout << "Unesite ime datoteke: ";
	gets(ime);
	
	upis(ime);
	citanje(ime);
	
	system("pause");
	return 0;
}

void upis(char *ime){
	int i, *niz;
	
	cout << "Unesite broj elemenata niza: ";
	cin >> n;
	
	niz = new int[n];
	
	fstream f;
	f.open(ime, ios::out);
	if(!f){
		cerr << "Greska prilikom otvaranja fajla!\n";
		exit(1);
	}
	
	for(i=0;i<n;i++){
		cout << "Unesite " << i+1 << ". clan niza: ";
		cin >> niz[i];
	}
	
	f.write((char *)niz, n*sizeof(int));
	
	delete niz;
	f.close();
}

void citanje(char *ime){
	int *niz;
	
	niz = new int[n];
	
	fstream f;
	f.open(ime, ios::in);
	if(!f){
		cerr << "Greska prilikom otvaranja fajla!\n";
		exit(1);
	}
	
	f.read((char *)niz, n*sizeof(int));
	
	for(int i = 0; i < n; i++){
		cout << i+1 << ". " << niz[i] << endl;
	}
	
	delete niz;
	f.close();
}
