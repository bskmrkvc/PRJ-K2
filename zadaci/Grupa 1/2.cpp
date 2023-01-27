#include<iostream>
#include<string.h>
#include<fstream>
#include<ctype.h>
#define BROJ 10
#define MAX 80

using namespace std;

int main(){
	
	int i, l, a, b, n, n2=0;
	char red[MAX+1];
	fstream f1, f2, f3;
	
	f1.open("dat1.txt", ios::out);
	if(!f1){
		cerr << "Greska prilikom otvaranja datoteke dat1.txt!\n";
		exit(1);
	}
	
	f1.open("dat2.bin", ios::out | ios::binary);
	if(!f2){
		cerr << "Greska prilikom otvaranja datoteke dat2.bin!\n";
		exit(1);
	}
	
	do{
		cout << "Unesite broj redova: ";
		cin >> n;
	}while(n<1 || n>BROJ);
	
	
	cout << "Unesite redove:\n";
	for(i = 0 ; i<n ; i++){
		cout << "Unesite " << i+1 << " red:";
		cin.ignore();
		cin.getline(red, MAX+1);
		f1 << red << endl;
		l = strlen(red);
		if(l != 0){
			f2.write((char *)&l, sizeof(int));
			f2.write((char *)red, l+1);
			n2++;
		}
	}
	f1.close();
	f2.close();
	
	f2.open("dat2.bin", ios::in | ios::binary);
	if(!f2){
		cerr << "Greska prilikom otvaranja datoteke dat2.bin!\n";
		exit(1);
	}
	
	f3.open("dat3.txt", ios::out);
	if(!f3){
		cerr << "Greska prilikom otvaranja datoteke dat3.txt!\n";
		exit(1);
	}
	
	do{
		cout <<"\nUnesite opseg: \n";
		cin >> a >> b;
	}while(a < 1 || a > n2 || b < 1 || b > n2 || a > b);
	
	for(i=0; i<(a-1); i++)
	{ 
		f2.read((char *)&l, sizeof(int));
		f2.read((char *)&red, l+1);
	}
	for(i=0; i<(b-(a-1)); i++)
	{ f2.read((char *)&l, sizeof(int));
		f2.read((char *)&red, l+1);
		f3<<red<<endl;
	}

	
	f2.close();
	f3.close();
	
	system("pause");
	return 0;
}
