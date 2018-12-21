//implementation of my_string class

#include<iostream>
#include<cstring>
using namespace std;
class my_string
{
	char *s;
	public :
	my_string()                              //default constructor
	{
		s=new char[100];
	}
	my_string(const char *p)                 //copy constructor
	{
		s=new char[strlen(p)+1];
		strcpy(s,p);
	}
	void operator=(const my_string &temp)    //assign operator and string copy
	{
		this->s=temp.s;
	}
	my_string  operator+(my_string & temp)   //string concatnate 
	{
		my_string ret;
		strcat(ret.s,this->s);
		strcat(ret.s,temp.s);
		return ret;
	}
	bool operator>(my_string &temp)          //greater than
	{
		if(strcmp(this->s,temp.s)>0)
			return true;
		else
			return false;
	}
	bool operator<(my_string &temp)         //less than
	{
		if(strcmp(this->s,temp.s)<0)
			return true;
		else
			return false;
	}
	bool operator>=(my_string &temp)        //greater than or equal to
	{
		if(strcmp(this->s,temp.s)>=0)
			return true;
		else
			return false;
	}
	bool operator<=(my_string &temp)       //less than or equal to
	{
		if(strcmp(this->s,temp.s)<=0)
			return true;
		else
			return false;
	}
	bool operator==(my_string &temp)       //equal to
	{
		if(strcmp(this->s,temp.s)==0)
			return true;
		else
			return false;
	}
	bool operator!=(my_string &temp)       //not equal to
	{
		if(strcmp(this->s,temp.s)!=0)
			return true;
		else
			return false;
	}
	int my_size()                         //size of string
	{
		return strlen(this->s);
	}
	int my_length()                       //length of string
	{
		return strlen(this->s);
	}
	friend ostream & operator<<(ostream & out,my_string & temp);
	friend istream & operator>>(istream & in,my_string & temp);
};
ostream & operator<<(ostream & out,my_string & temp)      //insertion operator - cout
{
	out<<temp.s;
	return out;
}
istream & operator>>(istream & in,my_string & temp)      //extraction operator - cin
{
	in>>temp.s;
	return in;
}
main()
{
	cout<<"*default constructor, insertion operator and extraction operator"<<endl;
	my_string obj;                                             //default constructor
	cout<<" enter the obj string"<<endl;	
	cin>>obj;                                                  //extracrtion operator overloading
	cout<<" obj string : ";	
	cout<<obj<<endl;                                           //insertion operator overloading
	cout<<"*copy constructor"<<endl;
	my_string obj1("embedded"),obj2(obj1);                     //copy constructor
	cout<<" obj1 string : ";	
	cout<<obj1<<endl;
	cout<<" obj2 string : ";	
	cout<<obj2<<endl;
	cout<<"*(strcpy) - assign '=' operator overloading"<<endl;
	my_string obj3; 
	obj3=obj2;                                                 //strcpy (string copy) - '=' (assign) operator overloading
	cout<<" obj2 string : ";	
	cout<<obj2<<endl;
	cout<<" obj3 string : ";	
	cout<<obj3<<endl;
	cout<<"*(strcat) - plus '+' operator overloading"<<endl;
	my_string obj4;
	obj4=obj+obj1;                                             //strcat (string covatnaton) - '+' (plus) operator overloading
	cout<<" obj string : ";	
	cout<<obj<<endl;
	cout<<" obj1 string : ";	
	cout<<obj1<<endl;
	cout<<" obj4 string : ";	
	cout<<obj4<<endl;
	cout<<"*(strcmp) - relational operator overloading"<<endl;
	cout<<" obj string : "<<obj<<"   obj1 string : "<<obj1<<endl;
	cout<<" 1.'>' - (greater than) operator overloading"<<endl<<" result : ";
	cout<<(obj>obj1)<<endl;                                    //strcmp (string compare) - '>' (greater than) operator overloading
	cout<<" 2.'<' - (less than) operator overloading"<<endl<<" result : ";
	cout<<(obj<obj1)<<endl;                                    //strcmp (string compare) - '<' (less than) operator overloading
	cout<<" 3.'>=' - (greater than and equal to) operator overloading"<<endl<<" result : ";
	cout<<(obj>=obj1)<<endl;                                   //strcmp (string compare) - '>=' (greater than and equal) operator overloading
	cout<<" 4.'<=' - (less than and equal to) operator overloading"<<endl<<" result : ";
	cout<<(obj<=obj1)<<endl;                                   //strcmp (string compare) - '>=' (less than and equal) operator overloading
	cout<<" 1.'==' - (equal to) operator overloading"<<endl<<" result : ";
	cout<<(obj==obj1)<<endl;                                   //strcmp (string compare) - '==' (equal to) operator overloading
	cout<<" 1.'!=' - (not equal to) operator overloading"<<endl<<" result : ";
	cout<<(obj!=obj1)<<endl;                                   //strcmp (string compare) - '!=' (not equal to) operator overloading
	cout<<"*size() and length() function in string class"<<endl;
	cout<<" size of string obj : "<<obj<<" : ";	
	cout<<obj.my_size()<<endl;                                 //size of string function
	cout<<" length of string obj : "<<obj<<" : ";	
	cout<<obj.my_length()<<endl;                               //length of string function
}
