#pragma once

#define LENGTH 256 // фикс длина контейнера
using namespace std;
/*
L2 список и класс Arr
*/
class Arr;
// class CTmpArr
// {
// Arr *v;int i; 
// public:
// CTmpArr(Arr *v,int i){this->v=v;this->i=i;} 
// operator char();
// CTmpArr &operator=(const char &b);
// };
//==========================================
class Arr
{
private:
  int n, nreal, space;
  char v[LENGTH]; 
  char* t;
public:
  Arr(){SetZero();}
  Arr(int num) {
	  if(num<LENGTH){
	  	n = num; 
	  	nreal = 0;
	  	space = LENGTH - 1 - num;
	  	memset(v,0, num*sizeof(char) );} 
	  else {
		  n = num;
		  nreal = 0;
		  space = LENGTH - 1 - num%LENGTH;
		  memset(v,0, LENGTH*sizeof(char) );}}
  Arr(const Arr&b){
	  CopyOnly(b);
	  }
  ~Arr(){
	  Clean();
	  }
  void SetN(int num) {
	  Clean();
	   n=num;
	   space = LENGTH - 1 - num;
	   memset(v,0, num*sizeof(char) );}
  int GetN(){
	  return n;
	  }
  int GetSp(){
	  return space;
	  }
  int GetNreal(){
	  return nreal;
	  }
  void addStr(char*str);
  Arr &operator=(const Arr&b){
	  if(this!=&b){
		  Clean();
		  CopyOnly(b);
		}return *this;} 
  void Clean(){
	  /*if(v)delete[] v; 
	  v=NULL;*/
	 n = 0;
	 nreal = 0;
	 space = LENGTH;
	 } 
  void SetZero(){
	  memset(v,0, LENGTH*sizeof(char) );/*!!!*/n=0;nreal=0; space=LENGTH; }
  void CopyOnly(const Arr &b);
//   CTmpArr operator[](int i){CTmpArr t(this,i);return t;} 
 // char& operator[](int index) {return arr[index];}
  char* getArr() {return v;}
  void setArr(char*array) ;
  
  friend ostream& operator << (ostream& cout, Arr a);
  friend istream& operator >> (istream& cin, Arr& a);
//   friend class CTmpArr;
  friend class Container;
};



template<class T> class CList2Node{ 
	public: T v;
	CList2Node<T> *prev, *next;
	CList2Node(){
		prev = next = NULL;}
};

template<class T> class CList2{
	CList2Node<T> *cur, *first, *last;
public:
	class iterator{
		CList2Node<T> *cur;
	public:
		iterator(){
			cur=NULL;}
		iterator(CList2Node<T> *cur){
			this->cur = cur;}
		bool operator!=(const iterator &rhs){
			return cur!=rhs.cur;
			}
		bool operator==(const iterator &rhs){
			return cur==rhs.cur;}
		void operator++(){
			if(cur)cur=cur->next;
			}
		void operator++(int){
			if(cur)cur=cur->next;
			}
		T operator*(){
			return cur->v;
		}
	};
		CList2(){
			SetZero();
	    }
		CList2(const CList2 &rhs){
			SetZero();
			CopyOnly(rhs);
		}
		~CList2(){
			Clean();
		}

		void Clean(){
			GoToBegin();
			while(DelCur());
			SetZero();
		}
		void SetZero(){
			cur=first=last=NULL;
		}
		void CopyOnly(const CList2 &rhs){
			if(IsEmpty()){
				for(iterator it=rhs.first; it!=NULL; ++it){
					GoToEnd(); AddAfter(*it); }
			}
		}

		void GoToBegin(){
			cur=first;
		}
		void GoToEnd(){
			cur=last;
		}
		void GoToPos(int pos){
			if(pos < 0||pos > GetLen())
			   throw -1;
			   GoToBegin();
			   for(int i = 0;i < pos; i++)GoToNext();
		}

		int GetLen(){
			iterator it=first;
			int i;
			for(i = 0; it!=NULL; ++it) 
			  i++; 
			  return i;
		}
		int GetCurPos(){
			iterator it=first;
			int i=0;
			while(it!=cur){++i;++it;}
			return i;
		}
                T& GetCur(){
                if(cur==NULL)throw -1; 
                return cur->v;
				}
		bool GoToNext(){
			if(IsEmpty())
			return false;
			if(cur -> next == NULL) 
			return false;
			cur=cur->next;
			return true;}
		bool GoToPrev(){
			if(IsEmpty())
			return false;
			if(cur->prev==NULL)
			return false;
			cur=cur->prev;
			return true;
		}

		bool IsEmpty()const{
			return cur == NULL;
		}

		void AddList(CList2 &rhs){
			last -> next=rhs.first;
			last = rhs.last;
		}
		void AddAfter(const T&x);
		void AddBefore(const T&x);
		void AddToEnd(const T&x){
			CList2Node<T> *n=new CList2Node<T>();
			n->v=x;
			n->prev=last;
			last->next=n;
			last=n;
		}
		void AddToPos(const T&x, int pos);

		void DelPos(int pos){
			CList2Node<T>* tmp=cur;
			GoToPos(pos);
			DelCur();
			cur=tmp;
		}
		bool DelCur();
		iterator begin(){
			return iterator(first);
		}
		iterator end(){
			return iterator(NULL);
		}
		
		CList2 &operator=(const CList2&b){
			if(this!=&b){
				Clean();
				CopyOnly(b);
			}
		return *this;
	 } 
                friend ostream& operator << (ostream&cout, CList2 l) {
					l.GoToBegin();
					for(;l.GoToNext();){
						cout<<l.GetCur();
						} 
					return cout;}
	};


