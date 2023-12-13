#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

//deklarasi struct bernama input 
struct Input
{
	float data;
	
}obj1, obj2; //objek dari struct Input


//deklarasi struct untuk hasil
struct Hasil
{
	float jumlah, kurang, kali, bagi;
} result; //objek dari struct hasil

void input(Input obj1, Input obj2)
{
	ofstream dataInput3("Input3.txt", ios::app);
	ofstream dataInput4("Input4.txt", ios::app);
	cout<<"\nMasukkan bilangan pertama : ";cin>>obj1.data;
	cout<<"Masukkan bilangan kedua   : ";cin>>obj2.data;
	
	//menyimpan ke KE FILE
	dataInput3.write((char *)&obj1, sizeof(obj1));
	dataInput4.write((char *)&obj2, sizeof(obj2));
	
	//menutup file
	dataInput3.close();
	dataInput4.close();
}
//fungsi
void hitung(Input obj1, Input obj2)
{
	float bil1,bil2;
	Hasil result;
	ofstream dataHasil("Hasil.txt", ios::in);
	
	
	ifstream bukaInput3("Input3.txt", ios::in);
	bukaInput3.read((char*)&obj1, sizeof(obj1));
	
	ifstream bukaInput4("Input4.txt", ios::in);
	bukaInput4.read((char *)&obj2, sizeof(obj2));
	
	bil1=obj1.data;
	
	//hasilnya akan disimpan kedalam objek struct ->"result"
	result.jumlah = bil1 + bil2;
	result.kurang = bil1 - bil2;
	result.kali = bil1 * bil2;
	result.bagi= bil1 / bil2;
	
	//menulis hasil berupa objek ke dalam FILE
	dataHasil.write((char *)&result, sizeof(result));
	
	//menutup File
	bukaInput3.close(); 
	bukaInput4.close();
	dataHasil.close();}

void hasil(Hasil result)
{
	//membaca data berupa objek yang ada didalam file "Hasil 1.txt"
	ifstream bukaHasil("Hasil.txt");
	
	bukaHasil.read((char *)&result, sizeof(result));
	
	//menampilklan hasil file yang diakses
	cout<<"\nHasil"<<endl;
	cout<<"-----------------"<<endl;
	cout<<"Hasil Penjumlahan = "<<result.jumlah<<endl;
	cout<<"Hasil Pengurangan = "<<result.kurang<<endl;
	cout<<"Hasil Perkalian = "<<result.kali<<endl;
	cout<<"Hasil Pembagian = "<<result.bagi<<endl;
	
	//menutup
	bukaHasil.close();
}
//fungsi main
int main()
{
	cout<<"OPERASI ARITMATIKA PEMDEK E"<<endl;
	cout<<"==========================="<<endl;
	
	input(obj1, obj2);
	hitung(obj1, obj2);
	hasil(result);
	
	//untuk memberi kita karakter tanpa menunggu tombol enter 
	_getch();
}
