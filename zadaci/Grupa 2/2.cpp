#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>
#define MAX 20

using namespace std;

int main(){
	
	int a, b, n, n2=0, l, i=0;
	char rec[81];
	fstream f1, f2, f3;
	
	do{
		cout << "Unesite broj reci za unos: ";
		cin >> n;
	}while(n<0 || n>MAX);
	
	
	f1.open("prva.txt", ios::out | ios::trunc);
	if(!f1){
		cout << "Greska pri otvaranju fajla prva.txt!\n";
		exit(1);
	}
	f2.open("druga.bin", ios::out | ios::binary);
	if(!f2){
		cout << "Greska pri otvaranju fajla druga.bin!\n";
		exit(1);
	}
	
	for(i=0; i<n; i++){
		cout << "Unesite " << i+1 << ". rec: ";
		cin >> rec;
		f1 << rec << ' ';
		l = strlen(rec);
		if(isalpha(rec[0])){
			f2.write((char *)&l, sizeof(int));
			f2.write((char *)rec, l+1);
			n2++;
		}
	}
	f1.close();
	f2.close();
	
	f2.open("druga.bin", ios::in | ios::binary);  
	if(!f2){
		cout << "Greska pri otvaranju fajla druga.bin!\n";
		exit(1);
	}
	
	f3.open("treca.txt", ios::out | ios::trunc);
	if(!f3){
		cout << "Greska pri otvaranju fajla treca.txt!\n";
		exit(1);
	}
	
	do{
		cout << "Unesite opseg: ";
		cin >> a >> b;
	}while(a < 0 || b < 0 || a > b);
	
	for(i=0; i<(a-1); i++)
	{ 
		f2.read((char *)&l, sizeof(int));
		f2.read((char *)&rec, l+1);
	}
	for(i=0; i<=(b-(a-1)); i++)
	{
		f2.read((char *)&l, sizeof(int));
		f2.read((char *)&rec, l+1);
		f3<<rec<<' ';
	}
	
	f2.close();
	f3.close();
	
	system("pause");
	return 0;
}
