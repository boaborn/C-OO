#ifndef A2P1_H
#define A2P1_H

#include <iostream>
#include <fstream>
using namespace std;


void info(){
	cout<<"***********************************"<<endl;
	cout<<"*   Michael Zhao  *"<<endl;
	cout<<"*   polymorphism         *"<<endl;
	cout<<"***********************************"<<endl<<endl<<endl;
}

class Movie{
	public:
		Movie();
		virtual ~Movie(){}
		void setTitle(const string& t);
		void setDirector(const string& d);
		void setTime(int t=0);
		void setQuality(int q=0);
		virtual void display() const;
		virtual void getData(ifstream& fin);
		static bool readFromFile(string fname, Movie*Movies[], int n);
	protected:
		string title;
		string director;
		int time;
		int quality;
		string empty;
};

class Revised : public Movie{
	public:
		Revised();
		~Revised();
		void display() const;
		void getData(ifstream& fin);
		void revised_time(int t=0);
		void revised_changes(const string& str);
	private:
		int revisedTime; 
		string changes;
};

class Foreign : public Movie{
	public:
		Foreign();
		~Foreign();
		void display() const;
		void getData(ifstream& fin);
		void setLanguage(const string& l);
	private:
		string language;
};

//*********Movie member function definitions**********
//variable empty is just for helping printing format
//it will be changed if the object type is Revised and Foreign
Movie :: Movie(){
	empty='\n';
}

void Movie :: setTitle(const string& t){
	title=t;
}

void Movie :: setDirector(const string& d){
	director=d;
}

void Movie :: setTime(int t){
	time=t;
}

void Movie :: setQuality(int q){
	quality=q;
}

void Movie :: display() const{
	cout<<"Title: "<<title<<endl<<"Director: "<<director<<endl<<"Time: "<<time<<" mins"<<endl<<"Quality: ";
	for(int i=0;i<quality;++i){
		cout<<"*";
	}
	cout<<empty;
}

void Movie :: getData(ifstream& fin){
	string line;
	for(int i=0;i<4;++i){
		getline(fin,line);
		if(i==0){this->setTitle(line);}
		if(i==1){this->setDirector(line);}
		if(i==2){this->setTime(atoi(line.c_str()));}
		if(i==3){this->setQuality(atoi(line.c_str()));}
	}
}

// this function read key words from .txt file and auto create the correct responding type of object
//then save the address into Movies array
//funtion returns false if cannot open file, otherwise return true;
bool Movie :: readFromFile(string fname, Movie*Movies[], int n){
	string buffer;
	ifstream openFile(fname.c_str(),ios_base::in);
	if(!openFile.is_open()){return false;}
	for(int i=0;i<n;i++){
		getline(openFile,buffer);
		if(buffer == "Movie"){
			Movie *m = new Movie();
			m->getData(openFile);
			Movies[i] = m;
		}
		if(buffer == "Revised"){
			Revised *r = new Revised();
			r->getData(openFile);
			Movies[i] = r;
		}
		if(buffer == "Foreign"){
			Foreign *f = new Foreign();
			f->getData(openFile);
			Movies[i] = f;
		}
	}
	openFile.close();
	return true;
}

//*********Revised member function definitions**********
Revised::Revised(){
	empty=' ';
}

Revised::~Revised(){
	
}

void Revised :: display() const{
	Movie :: display();
	cout<<endl;
	cout<<"Revised time: "<<revisedTime<<endl;
	cout<<"Changes: "<<changes<<endl;
}

void Revised :: getData(ifstream& fin){
	Movie :: getData(fin);
	string line;
	getline(fin,line);
	this->revised_time(atoi(line.c_str()));
	getline(fin,line);
	this->revised_changes(line);
}

void Revised::revised_time(int t){
	revisedTime = t;
}

void Revised::revised_changes(const string& str){
	changes = str;
}

//*********Foreign member function definitions**********
Foreign ::Foreign(){
	empty=' ';
}

Foreign :: ~Foreign(){
	
}

void Foreign :: display() const{
	Movie :: display();
	cout<<endl;
	cout<<"Language: "<<language<<endl;
}

//function call getData from base class first 
void Foreign :: getData(ifstream& fin){
	Movie :: getData(fin);
	string line;
	getline(fin,line);
	this->setLanguage(line);
}

void Foreign :: setLanguage(const string& l){
	language=l;
}

/************* makefile*******************
//this is for makefile, and not supposed to put in header file
//I put in here, just in case you might need this code

main.exe		: main.o   
	g++ -Wl,-s -o main.exe main.o  

main.o		:  main.cpp A2P1.h 
	g++ -c -fpermissive -fconserve-space main.cpp
A2P1.o		:    A2P1.h 
	g++ -c -fpermissive -fconserve-space 

*****************************************/

#endif
