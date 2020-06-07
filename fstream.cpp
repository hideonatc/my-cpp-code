#include<iostream>
#include<fstream>
using namespace std;
void arithmetic(){
	string s;
	cin>>s;
	ofstream fout("temp.cpp");
	fout<<"#include<iostream>"<<endl;
	fout<<"using namespace std;"<<endl;
	fout<<"int main(){"<<endl;
	fout<<"std::cout<<("<<s<<")<<endl;"<<endl;
	fout<<"return 0;"<<endl;
	fout<<"}"<<endl;
	fout.close();
	system("g++ temp.cpp -o temp");
	system("/home/hideonatc/Documents/temp");
	system("rm temp.cpp temp");
}
int main(){
	arithmetic();
}