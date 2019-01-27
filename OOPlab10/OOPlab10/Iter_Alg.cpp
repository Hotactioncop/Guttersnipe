// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include "Point.h"
#include "Header.h"
#include <iterator>
#include <algorithm>
#include "Rect.h"

using namespace std;	
#define	  stop __asm nop


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию
	set<Point> Point_1;
	int i = 0;
	int j = 1;
	while (i < 10)
	{
		Point_1.insert(Point(i, j));
		++i;
		++j;
	}

	vector<Point> Set_back;
	set<Point>::reverse_iterator rit = Point_1.rbegin();
	set<Point>::reverse_iterator rite = Point_1.rend();
	while (rit != rite)
	{
		Set_back.push_back(*rit);
		++rit;
	}
	Show_me(Set_back);
	Show_me(Point_1);

	stop
		//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
		//vector и set из предыдущего задания на экран.
		cout << endl;
		ostream_iterator<Point> os(cout, "*");
		copy(Set_back.begin(), Set_back.end(), os);

		cout << endl;
		copy(Point_1.begin(), Point_1.end(), os);


	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.
		back_insert_iterator<vector<Point>> it = back_inserter(Set_back);
		*it = Point(11, 12);
		Show_me(Set_back);

		list<Point> list_1;
		rit = Point_1.rbegin();
		while (rit != rite)
		{
			list_1.push_back(*rit);
			++rit;
		}

		front_insert_iterator<list<Point>> it2 = front_inserter(list_1);
		*it2 = Point(0, 1);
		Show_me(list_1);

		insert_iterator<set<Point>> it3 = inserter(Point_1, Point_1.end());
		it3 = Point(100, 100);
		Show_me(Point_1);




///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон
		cout << endl;
		cout << endl;
		for_each(Point_1.rbegin(), Point_1.rend(), Print_it<Point>);
		cout << endl;
		for_each(Set_back.begin(), Set_back.end(), Print_it<Point>);


	stop

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката

		for_each(Set_back.begin(), Set_back.end(), Change_it<Point>);     //Почему нельзя изменить элементы типа SET???????
		cout << endl;
		for_each(Set_back.rbegin(), Set_back.rend(), Print_it<Point>);

	stop
	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
		set<Point>::iterator it_found = find(Point_1.begin(), Point_1.end(),Point(4,5));

	cout << endl << "I've fount it:" << *it_found <<endl;
	stop

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	
	rit = Point_1.rbegin();
	int z = 0;
	while (rit != rite)
	{
		Set_back[z] = *rit;
		++rit;
		++z;
	}
	Show_me(Set_back);
	sort(Set_back.begin(), Set_back.end());
	Show_me(Set_back);
	stop

		//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
		//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
		//[-n, +m].
		vector<Point> Cool;
	vector<Point>::iterator find_all;
	vector<Point>::iterator vit = Set_back.begin();
	vector<Point>::iterator vite = Set_back.end();
	while (vit != vite)
	{
		find_all = find_if(vit, Set_back.end(), Find_point);
		if (find_all == vite)
			break;
		Cool.push_back(*find_all);
		++vit;
	}
	Show_me(Cool);
	stop
		//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.

		vector<Rect> vRect{ Rect(5,5,7,7), Rect(1,1,3,3), Rect(11,11,15,15), Rect(4,4,6,6) };
		Show_me(vRect);
		sort(vRect.begin(), vRect.end());
		Show_me(vRect);
	stop

	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()
		string WOW = "WONDERFULL";
		transform(WOW.begin(), WOW.end(), WOW.begin(), tolower);
		cout << WOW;
		stop

		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
	
			list<string> lString {"WHAT", "A", "WONDERFULL", "LIFE"};
		set<string> empty_Set;
		transform(lString.begin(), lString.end(), inserter(empty_Set, empty_Set.begin()), to_lower);
		Show_me(empty_Set);





		stop
	// map
		
		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	
		vector<string> str_Vect;
		copy(lString.begin(), lString.end(), back_inserter(str_Vect));
		str_Vect.push_back("what");
		str_Vect.push_back("life");

		Show_me(str_Vect);
		map<string, int> si_Map;
		transform(str_Vect.begin(), str_Vect.end(), inserter(si_Map, si_Map.begin()), trans_map);
		Show_map(si_Map);

		stop
	}

	return 0;
}

