/*
  Container.h
  Задание 1.15. Динамический массив чисел с возможностью сортировки.
  
 Контейнер строк.

Требуется построить контейнер для размещения текстовых строк без операции удаления. 
Для хранения выделяется блок памяти, в котором последовательно размещаются поступающие 
строки. Если очередная строка не помещается в остатке блока,
то выделяется следующий блок. Все блоки завязываются в список для осуществимости 
операции очистки контейнера.

Реализация класса должна поддерживать следующие возможности:
+создание пустого контейнера; 44 строка - конструктор
+очистка всего контейнера; деструктор 46 строка
+добавление строки в контейнер (на выходе — указатель на место размещения строки); 3 метода writestr , ...i,...A
+получение количества строк, хранящихся в контейнере; getM 49 строка

Формальное определение интерфейса не задается и должно быть разработано студентом.
Тесты должны включать заполнение контейнера некоторым набором строк и проверку 
работы всех реализованных методов в различных корректных и некорректных ситуациях.
       
 */
#pragma once
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include "CList2.h"
using namespace std;
//--------------------------------------------------------------
//----------- Определение класса -------------------------------
//--------------------------------------------------------------
class Container
 {
   private:
    int n;             //Размер суммарный блоков - равен m*LENGTH
    int m;             //Количество блоков всего
    int n_real;
    CList2<Arr> arrList;
   // Arr cheatArr;
   public:
    Container (const Container&v) {CopyOnly(v);}
    Container(){ SetZero(); }
    Container(int num)   { m = num/5 +1;
     n_real=num; 
     for(int i = 0; i < m; i++)
     arrList.GoToNext();
    }
    ~Container(){ Clean(); }
    Container(Container&& r) {
      n=r.n;
      m=r.m;
      n_real=r.n_real;
      arrList.CopyOnly(r.arrList); 
      r.SetZero(); } 	//move constructor
    
    int getM() 
    { return m; }                    
    int getLength()
    { return n_real; } 
    void setLength(int length) 
    { m = length/5 +1; n_real=length; 
      for(int i = 0; i < m; i++)
      arrList.GoToNext(); 
    }   
    
    CList2<Arr> &getList()
    { return arrList; }
    
    void SetZero()
     {arrList.GoToBegin(); 
      if(!arrList.IsEmpty())
       for(;arrList.GoToNext();){
      arrList.GetCur().SetZero();}  
      arrList.SetZero(); 
      n = 0;
      m = 0;
      n_real = 0;
     }
    void Clean() {
      arrList.Clean();
      SetZero();
      }
    void CopyOnly(const Container &v);
    
    int writeStrI(char* str); //возращает позицию на которую пишeтся строка
    void writeStr(char* str); // 
    void writeStrA(char* str, int size); // записывает строку фиксированой длины для autoset
    void AutoSet();
    Container& operator=(const Container& v);  
    
    friend char *user_input();
    friend ostream &operator<<(ostream& cout, Container &v);
    friend istream &operator>>(istream& cin, Container &v );
  };
  
