#include "PasswordProxy.h"
#include <iostream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* file, string password) : file(file), password(password) {}

PasswordProxy::~PasswordProxy(){
	delete file;
}

string PasswordProxy::passwordPrompt(){
	cout << "Enter password"<<endl;
	string p;
	getline(cin, p);
//	cin.ignore();

	/*
	while (p.find(" ") != string::npos){ //pw has space 
		cout << "Password can't contain a space" << endl;
		string p;
		cin >> p;
		cin.ignore();
	}
	*/
	return p;
}

bool PasswordProxy::passwordMatch(std::string s){
	return !(s.compare(password));
}

vector<char> PasswordProxy::read() {
	if(passwordMatch(passwordPrompt())){
		return file->read();
	}
	else {
		vector<char> v;
		return v;
	}
}

 int PasswordProxy::write(vector<char> vect){
	 if(passwordMatch(passwordPrompt())){
		return file->write(vect);
	}
	 else {
		 return returns::badPassword;
	 }
 }

 int PasswordProxy::append(vector<char> vect){
	 if(passwordMatch(passwordPrompt())){
		return file->append(vect);
	}
	 else {
		 return returns::badPassword;
	 }
 }

 string PasswordProxy::getName(){
	 return file->getName();
 }

 unsigned int PasswordProxy::getSize() {
	 return file->getSize();
 }

 void PasswordProxy::accept(AbstractFileVisitor* visitor){
	 if(passwordMatch(passwordPrompt())){
		file->accept(visitor);
	
	}
 }

 AbstractFile* PasswordProxy::clone(string newname) {

	//create new underlying file with file's clone method
	 AbstractFile* newFile = file->clone(newname);

	 //create new password proxy with same password
	 AbstractFile* cloned = new PasswordProxy(newFile, password);

	 return cloned;
 }