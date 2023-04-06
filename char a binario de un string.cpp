#include<iostream>
#include <string>
#include <bitset>

using namespace std;

string charToBinary(char c) {
    return bitset<8>(c).to_string();
}
int main(){
	string hola = "FRANKLIN";
	for(int i =0 ; hola[i]!= '\0'; i++ ){
		cout<< charToBinary(hola[i])<<"\t"
		;
	}
}