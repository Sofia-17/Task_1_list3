/*
 * Main.cpp
 */
#include <iostream>
#include "Container.h"

using namespace std;

void test6() //создает пустой контейнер 
{
try{
  cout << "\ntest6. AutoSet + writeStr\n";
   Container dyn;
   dyn.AutoSet();
  cout << dyn;
    } catch(...) {cout << "error" <<endl;}
}

void test9() // СОЗДАЕТ ДВА ПУСТЫХ ОБЬЕКТА КЛАССА И ВЫВОДИТ ИХ
{
    try{
  cout << "\ntest9. Create empty container\n";
   Container dyn; Arr a;
   cout<<"empty arr= "<<a;
   cout<<"empty cont= "<<dyn;
    } catch(...) {cout << "error" <<endl;}
}
void test10() // создает пустые обьекты и засовыает в них строку something 3 раза
{
    try{
  cout << "\ntest10. Container::writeStr + Arr::addStr\n";
   Container dyn;
  Arr a;
   char s1[10]="something";
   cout<<"empty a= " << a;
   a.addStr(s1);
   cout<<"a= " << a;
   cout<<"empty cont= " << dyn;
   
   //cout<<dyn.getList().GetCur();
   
    dyn.writeStr(s1);
    dyn.writeStr(s1);
    dyn.writeStr(s1);
  cout << "cont= " << dyn;
    } catch(...) {cout << "error" <<endl;}
}
void test11() // засовывает 100 раз
{
    try{
  cout << "\ntest11. Container::writeStr huge\n";
   Container dyn; Arr a;
   char s1[10]="something";
   cout << "empty a= " << a;
   a.addStr(s1);
   cout << "a= " << a;
   cout << "empty cont= " << dyn;
   
   //cout<<dyn.getList().GetCur();
   for(int i = 0;i < 100; i++)
   { dyn.writeStr(s1);}
   cout << "cont= " << dyn;
    } catch(...) {
      cout << "error" <<endl;
    }
}
void test12()
{
    try{
  cout << "\ntest12. Container::writeStrI huge + getM()\n";
   Container dyn; 
   char s1[10]="something";
   cout << "empty cont= " << dyn;
   for(int i = 0;i < 100;i++)
   {int pos = dyn.writeStrI(s1);
     printf("%d pos=%d\n",i,pos);}
   cout << "cont= " << dyn;
   cout << "ОБЩЕЕ КОЛИЧЕСТВО СТРОК В КОНТЕЙНЕРЕ: " << dyn.getM() << endl;
    } catch(...) {
      cout << "error" <<endl;
    }
}
void test13()
{
    try{
  cout << "\ntest13. user_input()\n";
   Container dyn; int n;
   cout << "Сколько строк введем? ";
   cin >> n;
   for(int i = 0;i < n + 1; i++)
   {cout << "Введите строку: ";
   cin >> dyn;}
   cout << "cont= " << dyn;
   cout << "ОБЩЕЕ КОЛИЧЕСТВО СТРОК В КОНТЕЙНЕРЕ: " << dyn.getM() << endl;
    } catch(...) {cout << "error" << endl;}
}
///////////////////////////////////////////
int main()
{   
  test6(); test9(); test10(); test11(); test12(); test13();
  
  return 0;
}
