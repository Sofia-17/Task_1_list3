/*
 * CFunctions.cpp

 */
#include<iostream>
#include<string.h>
#include <ctime>
#include <cstdlib>
#include "CList2.h"
#include "Container.h"
using namespace std;
//////////////////CLASS METHODS///////////////////////////

///////////////Arr
void Arr::setArr(char*array)  { 
      memcpy(v, array, GetN()*sizeof(char));
      
      } 
      
void Arr::addStr(char*str)  {
  //  cout<<"adding str: "<<str<<endl;
   if(int(strlen(str))<=space)
   {strcat(v,str); n=strlen(str); space=LENGTH-n;}
   //cout<<"v= "<<v<<endl;
  }
      

void Arr::CopyOnly(const Arr &b) {
       //if(reinterpret_cast<void*>(this)==NULL){cout<<"!\n";return;}
       //printf("%p\n",reinterpret_cast<void*>(this));
       if(this!=&b)
	{SetZero();
	nreal=b.nreal; //GetNreal();
	n=b.n; 
	space=b.space;
	//if(v)delete[]v; //!
	//v=NULL;
	if(b.v)memcpy(v,b.v, strlen(b.v))/*b.n*sizeof(char))*/;}
       } 
         
////////////Container

void Container::writeStrA(char* str, int size) //ислючительно чтобы избежать ругань на strlen() в методе AutoSet()
  {
  arrList.GoToBegin();
 // cout<<arrList.GetCur();
   if (size>=LENGTH) {cout<<"too huge string..\n"; throw -1;}
   if ((arrList.IsEmpty())&&(size<LENGTH)) 
   {
    Arr tmp ;
    arrList.AddAfter(tmp);
    //cout<<tmp.getArr();
    char s[256];  
    memset(s,0,255);
    //memcpy(s,tmp.getArr(),255);
    strncat(s,str,size);
    //cout<<"adding str: "<<str<<endl;
    tmp.SetN(strlen(s));
    tmp.setArr(s);
    //cout<<tmp;
    arrList.AddAfter(tmp);
    m++;
    //cout<<arrList;
    //delete[] s;
   }
   else{
   //while(arrList.GoToNext()){}
   arrList.GoToEnd();
   if(int(size)<=LENGTH-arrList.GetCur().GetN())//.GetSp())
   {
    //strncat(arrList.GetCur().getArr(),str,strlen(str));  
    Arr tmp = arrList.GetCur();
    //cout<<tmp.getArr();
    char s[256];  
    memset(s,0,255);
    memcpy(s,tmp.getArr(),255);
    strncat(s,str,size);
    //cout<<"adding str: "<<str<<endl;
    //cout<<s;
    tmp.SetN(strlen(s));
    tmp.setArr(s);
    //cout<<tmp;
    arrList.DelCur();
    arrList.AddAfter(tmp);
    //delete[] s;
   }
   else if(int(size)>LENGTH-arrList.GetCur().GetN()) //for?
   {
    arrList.GoToNext();
    Arr tmp ;
    char s[256];  
    memset(s,0,255);
    strncat(s,str,size);
    //cout<<"adding str: "<<str<<endl;
    //printf("adding str: %s\n",str);
    tmp.SetN(strlen(s));
    tmp.setArr(s);
    //cout<<tmp;
    arrList.AddAfter(tmp);
    m++;
   }
   else {cout<<"String is too huge!"<<endl; throw -1;}
  }
  }

int Container::writeStrI(char* str) //на выходе — указатель на место размещения строки
  {
  arrList.GoToBegin();
 // cout<<arrList.GetCur();
   if (strlen(str)>=LENGTH) {cout<<"too huge string..\n"; throw -1;}
   if ((arrList.IsEmpty())&&(strlen(str)<LENGTH)) 
   {
    Arr tmp ;
    arrList.AddAfter(tmp);
    //cout<<tmp.getArr();
    char s[256];  
    memset(s,0,255);
    //memcpy(s,tmp.getArr(),255);
    strncat(s,str,strlen(str));
    //cout<<"adding str: "<<str<<endl;
    tmp.SetN(strlen(s));
    tmp.setArr(s);
    //cout<<tmp;
    arrList.AddAfter(tmp);
    m++;
    return 0;
    //cout<<arrList;
    //delete[] s;
   }
   else{
   //while(arrList.GoToNext()){}
   arrList.GoToEnd();
   if(int(strlen(str))<=LENGTH-arrList.GetCur().GetN())//.GetSp())
   {
    //strncat(arrList.GetCur().getArr(),str,strlen(str));  
    Arr tmp = arrList.GetCur();
    //cout<<tmp.getArr();
    int pos=strlen(tmp.getArr());
    char s[256];  
    memset(s,0,255);
    memcpy(s,tmp.getArr(),255);
    strncat(s,str,strlen(str));
    //cout<<"adding str: "<<str<<endl;
    //cout<<s;
    tmp.SetN(strlen(s));
    tmp.setArr(s);
    //cout<<tmp;
    arrList.DelCur();
    arrList.AddAfter(tmp);
    return pos;
    //delete[] s;
   }
   else if(int(strlen(str))>LENGTH-arrList.GetCur().GetN()) //for?
   {
    arrList.GoToNext();
    Arr tmp ;
    char s[256];  
    memset(s,0,255);
    strncat(s,str,strlen(str));
    //cout<<"adding str: "<<str<<endl;
    tmp.SetN(strlen(s));
    tmp.setArr(s);
    //cout<<tmp;
    arrList.AddAfter(tmp);
    m++;
    return 0;
   }
   else {cout<<"String is too huge!"<<endl; throw -1;}
  }
  }

void Container::writeStr(char* str) // Самый главный метод записывает строки
  {
  arrList.GoToBegin();
 
   if (strlen(str)>=LENGTH) {cout<<"too huge string..\n"; throw -1;}
   if ((arrList.IsEmpty())&&(strlen(str)<LENGTH)) 
   {
    Arr tmp ;
    arrList.AddAfter(tmp);
    
    char s[256];  
    memset(s,0,255);
    
    strncat(s,str,strlen(str));
    
    tmp.SetN(strlen(s));
    tmp.setArr(s);
   
    arrList.AddAfter(tmp);
    m++; // увеличиваем переменную длины списка
  
   }
   else{
   //while(arrList.GoToNext()){}
   arrList.GoToEnd();
   if(int(strlen(str))<=LENGTH-arrList.GetCur().GetN())//.GetSp())
   {
    //strncat(arrList.GetCur().getArr(),str,strlen(str));  
    Arr tmp = arrList.GetCur();
    //cout<<tmp.getArr();
    char s[256];  
    memset(s,0,255); // чтобы обьект был не NULL
    memcpy(s,tmp.getArr(),255); //копирует в s tmp на 255
    strncat(s,str,strlen(str)); // к строке s дописывает str
    // cout<<"adding str: "<<str<<endl;
    //cout<<s;
    tmp.SetN(strlen(s));
    tmp.setArr(s);
    //cout<<tmp;
    arrList.DelCur();
    arrList.AddAfter(tmp);
    //delete[] s;
   }
   else if(int(strlen(str))>LENGTH-arrList.GetCur().GetN()) //for?
   {
    arrList.GoToNext();
    Arr tmp ;
    char s[256];  
    memset(s,0,255);
    strncat(s,str,strlen(str));
    // cout<<"adding str: "<<str<<endl;
    tmp.SetN(strlen(s));
    tmp.setArr(s);
    //cout<<tmp;
    arrList.AddAfter(tmp);
    m++;
   }
   else {cout<<"String is too huge!"<<endl; throw -1;}
  }
  }
  
void Container::CopyOnly(const Container &v)    
    {
     CList2<Arr> arrList;
     if(this!=&v)
     //{memcpy(&arrList, &v.arrList, v.m*sizeof(Arr); 
    { Clean();
    n=v.n; m=v.m;n_real=v.n_real;
     arrList=(v.arrList);
     }
    }
     

Container& Container::operator=(const Container& v)
    {
        if(this!=&v) 
        {Clean(); CopyOnly(v);}
        return *this;
    }

char rand_d(char b, char e){ return b + (rand() % static_cast<unsigned int>((e - b) * 1000)) / 1000.;  }
     
void Container::AutoSet()     
    {
    srand( time(0) ); // автоматическая рандомизация
     for(int c=0;c<15;c++)
     { 
     int ran=1 + rand() % 100;
    // char *tmp=new char[ran];
    char *tmp=(char*)malloc(ran*sizeof(char));
      // cout << "Random size = " << ran << endl;
      
      for(int i=0;i<ran;i++) {tmp[i]=rand_d('a', 'z');}
      //cout<<strlen(tmp);
      //writeStr(tmp);
      writeStrA(tmp,ran-1);
     free(tmp); tmp=NULL;
       // delete [] tmp;  
     }
    } 
////////////CList2
template<class T> void CList2<T>::AddToPos(const T&x, int pos){
	CList2Node<T>* tmp=cur;
	GoToPos(pos);
	AddBefore(x);
	cur=tmp;

}
template<class T> bool CList2<T>::DelCur(){
	if(IsEmpty()) return false;
	auto *x=cur;
	if(cur->prev) {cur->v.Clean();cur->prev->next=cur->next;} else first=cur->next;
	if(cur->next) {cur->v.Clean();cur->next->prev=cur->prev;} else last=cur->prev;
	if(cur->prev) {cur->v.Clean();cur=cur->prev;} else cur=cur->next;
	delete x;
	return true;
}

template<class T> void CList2<T>::AddAfter(const T &x){
	CList2Node<T> *n=new CList2Node<T>(); n->v=x;
	if(IsEmpty()){cur=first=last=n;}
	else{
		n->next=cur->next;
		n->prev=cur;
		cur->next=n;
		if(n->next)
			n->next->prev=n;
		else last=n;
	}
}

template<class T> void CList2<T>::AddBefore(const T &x){
	CList2Node<T> *n=new CList2Node<T>(); n->v=x;
	if(IsEmpty()){cur=first=last=n;}
	else{
		n->prev=cur->prev;
		n->next=cur;
		cur->prev=n;
		if(n->prev)
			n->prev->next=n;
		else first=n;
	}
}   
////////////CTmpArr
// CTmpArr::operator char()
// {if(i>=0&&i<v->n)return v->v[i];return 0;}

// CTmpArr &CTmpArr::operator=(const char &b)
// {
// printf("exit in =\n");
// if(i>=0)
// {
// if(i>=v->n)
// {int n2=(i+1)*2; //char w[n2]; memset(w,0,sizeof(char)*n2); 
// memcpy(v->v,&b,1); 
// /*delete[] v->v; v->v=w;*/ v->n=n2;
// }
// if(v->nreal<i+1) {v->nreal=i+1;} v->v[i]=b;
// }
// return *this;
// }

//////////////////FRIEND FUNCTIONS////////////////////////

char *user_input()
{
    char str[100];
    int ch;
    size_t len = 0;

    //str = new char[100];
    if(!str)return str;
    while(EOF!=(ch=fgetc(stdin)) && ch != '\n'){
        str[len++]=ch;
       /* if(len==BLOCK_SIZE){
            strcat(str, blocks[CHAR_FLAG++]);
            if(!str)return str;
        }*/
    }
    str[len++]='\0';
    //str=(char*)realloc(str, sizeof(char)*len);
    //delete [] str;
    return str;
}

ostream& operator<<(ostream& cout, Arr a)
{
//cout<<a.GetN()<<" "<<a.GetSp();
for(int i=0;i<a.GetN();i++)
{cout<<a.v[i];/*cout<<a[i]<<" ";*/} cout<<endl; 
return cout;
} 

istream& operator>>(istream& cin, Arr& a)
{
char p;
for(int i=0;i<a.GetN();i++)
 {
        cout << "Введите элемент массива Arr № " << (i+1) << ": ";
        cin >> p; 
        a.v[i] = p;    
 }
 return cin;
}

ostream &operator<<(ostream& cout, Container &v) 
{
   cout << "Строки :";
   v.getList().GoToBegin();
   for(int i=1;v.getList().GoToNext();i++)
    { 
     cout<<i<<") "<<v.getList().GetCur();

     }
   cout << "\n";

return cout;
}

istream &operator>>(istream& cin , Container &v) 
{
 char *tmp; 
   tmp=user_input();
   v.writeStr(tmp);
   delete[] tmp;
        
return cin;
}


