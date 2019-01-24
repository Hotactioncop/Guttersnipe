// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include "Header.h"
#include "Point.h"

#include <iostream>

using namespace std;

#define stop __asm nop

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	stack<int> stFirst;
	stFirst.push(1);
	stFirst.push(2);
	stFirst.push(3);
	stFirst.push(4);
	stFirst.push(5);
	Show_me(stFirst);



	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
		
	vector<int> vSecond{ 9,8,7,6,5,4,3,2,1,0 };
	stack<int,vector<int>> stSecond(vector<int>(vSecond.rbegin(),vSecond.rend()));
	//vector<int>::reverse_iterator rit = vSecond.rbegin();
	//cout << endl;
	//while (rit != vSecond.rend())
	//{
	//	stSecond.push(*rit);
	//	++rit;
	//}
	Show_me(stSecond);
	Show_cont(vSecond);


	
	


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	
	queue<Point> quFirst;
	quFirst.push(Point(1, 1));
	quFirst.push(Point(2, 2));
	quFirst.push(Point(3, 3));
	quFirst.push(Point(4, 4));
	quFirst.push(Point(5, 5));
	Show_me(quFirst);

	Point a = move(quFirst.front());
	quFirst.front() = move(quFirst.back());
	quFirst.back() = move(a);

	Show_me(quFirst);
	while (!quFirst.empty())
		quFirst.pop();
	Show_me(quFirst);

	queue<Point*> quSecond;
	quSecond.push(&Point(1, 1));
	quSecond.push(&Point(2, 2));
	quSecond.push(&Point(3, 3));
	quSecond.push(&Point(4, 4));
	quSecond.push(&Point(5, 5));
	Show_me(quSecond);

	cout << *quSecond.front();
	Point *aP = quSecond.front();
	quSecond.front() = quSecond.back();
	quSecond.back() = aP;
	Show_me(quSecond);
	cout << *quSecond.front();






	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?
	const char* arr[] = { "Let", "this", "programm", "rock" };
	priority_queue<const char*,vector<const char*>, cmp> pqFirst(&arr[0], &arr[4]);
	Show_me(pqFirst);

	




	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)
	Point ar[8] = { Point(1,1), Point(2,2), Point(3,3), Point(4,4), Point(5,5), Point(6,6), Point(7,7), Point(8,8), };
	set<Point> sPo{ ar, ar + 8 };
	Show_set(sPo);

	vector<int> var { 1,2,3,4,5,6,7,8 };
	set<int> sFirst(var.begin(), var.end());
	set<int> sSecond(var.rbegin(), var.rend());
	Show_set(sFirst);
	Show_set(sSecond);

	for (int i = 0; i < 8; i++)
	{
		sFirst.insert(var[i]);
	}
	Show_set(sFirst);



	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
	map <const char*, int> myMap;
	
	myMap.insert(pair <const char*, int>("Honda", 300));
	myMap["Ford"] = 500;
	myMap["Иванова"] = 40000;
	map <const char*, int>::iterator mip = myMap.begin();
	map <const char*, int>::iterator mipe = myMap.end();
	cout << endl;
	myMap["Петрова"] = myMap["Иванова"];
	myMap.erase("Иванова");
	while (mip != mipe)
	{
		cout << (*mip).first << "\t" << mip->second << endl;
		++mip;
	}


	stop




		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
		vector<string> vStr{ "Give", "it", "the", "way", "Give", "it", "the", "way", "Give", "it", "the", "way", "now!"};
	multiset<string> msStr{ vStr.begin(), vStr.end() };
	Show_set(msStr);
	map<string, int> maStr;

	multiset<string>::iterator msit = msStr.begin();
	multiset<string>::iterator msit2 = msStr.begin();
	++msit2;
	multiset<string>::iterator msite = msStr.end();
	int number = 1;
	while (msit != msite)
	{
	BEGIN:
		if (msit2!=msite && (*msit == *msit2))
		{
			++number;
			++msit;
			++msit2;
			goto BEGIN;
		}
		else {
			maStr[*msit] = number;
			++msit;
			if (msit2 == msite)
			{
			}
			else ++msit2;
			number = 1;
		}
	}
	map<string, int>::iterator maIt1 = maStr.begin();
	map<string, int>::iterator maIt2 = maStr.end();
	while (maIt1 != maIt2)
	{
		cout << (*maIt1).first << "\t" << maIt1->second << endl;
		++maIt1;
	}

	stop;





		//е) 
		//задан массив:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки
	
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty", "Bandersnatch", "Donna", "Devil", "Cassandra", "Cool"};
	map<const char, vector<const char*>> myMap2;
	for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++)
	{
		int j = i + 1;
		while ((j < sizeof(words) / sizeof(words[0])) && words[i][0] == words[j][0])
		{
			j++;
		}
		myMap2.emplace(words[i][0], vector<const char*>(words+i, words + j));
		i = j-1;
	}

	map<const char, vector<const char*>>::iterator mapIt1 = myMap2.begin();
	map<const char, vector<const char*>>::iterator mapIt2 = myMap2.end();
	while (mapIt1 != mapIt2)
	{
		cout << "\n" << (*mapIt1).first << "\t";
		Show_cont(mapIt1->second);
		++mapIt1;
	}

	stop

		//ж)
		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		//
		//номера 
		map<const int, multiset<string>> students;
	const char* words1[] = { "Абрамов", "Алисова", "Гершенкоп", "Каледин", "Краснов", "Лямин", "Орлов", "Стеблина", "Юсубов","Стеблина", "Ярмушов", "Ларин", "Лебедев", "Лебедев", "Ярмушов" };
	int j = 1;
	for (int i = 0; i < sizeof(words1) / sizeof(words1[0]); i++)
	{
		students.emplace(j, multiset<string>(words1 + i, words1 +i+5));
		++j;
		i += 4;
	}
	map<const int, multiset<string>>::iterator mapIt3 = students.begin();
	map<const int, multiset<string>>::iterator mapIt4 = students.end();
	while (mapIt3 != mapIt4)
	{
		cout << "\n" << (*mapIt3).first << "\t";
		Show_cont(mapIt3->second);
		++mapIt3;
	}

	stop


		////////////////////////////////////////////////////////////////////////////////////
		//multimap
		//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
		//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
		//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
		//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
		//в) Выведите все содержимое словаря на экран
		//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
		//		итераторов можно использовать методы lower_bound() и upper_bound()

		multimap<string, multiset<string>> Dictionary;
	pair< string, multiset<string>> first_pair("strange", multiset<string>{"чужой", "странный"});
	Dictionary.insert(first_pair);
	pair< string, multiset<string>> second_pair = make_pair("cool", multiset<string>{"холодно", "классно"});
	Dictionary.insert(second_pair);
	Dictionary.emplace("rock", multiset<string>{"скала", "рок"});
	multimap<string, multiset<string>>::iterator dict_b = Dictionary.begin();
	multimap<string, multiset<string>>::iterator dict_e = Dictionary.end();
	Show_map(Dictionary, "print_full"); // используйте "print_full", чтобы вывести весь список
	Show_map(Dictionary, "cool");
	cout << Dictionary;
  stop

	return 0;
}

