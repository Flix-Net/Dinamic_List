#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
	Node* prev;
	int position;
	int key;
};

void Print_List_Start(struct Node* pHead);
void Print_List_End(struct Node* pHead);
void Add_Tail_List(struct Node* pHead, int& last_del_key, int value);
void Add_List_Position(struct Node* pHead, int& last_del_key, int value, int cin_position);
void Add_List_Before(struct Node* pHead, int& last_del_key, int cin_value, struct Node* t);
void Add_List_After(struct Node* pHead, int& last_del_key, int cin_value, struct Node* t);
void Dell_List_Position(struct Node* pHead, int& last_del_key, int cin_position);
void Dell_List_Value(struct Node* pHead, int& last_del_key, struct Node* current);
void Dell_List_Before(struct Node* pHead, int& last_del_key, Node* current);
void Dell_List_After(struct Node* pHead, int& last_del_key, Node* current);
Node* Refresh_Position(struct Node* pHead);
Node* Clear_List(struct Node* pHead);
int Set_Key(int& last_del_key, int& count);
void Find_Key(struct Node* pHead);
void Find_Position(struct Node* pHead, struct Node* t);
Node* Find_Tail(struct Node* pHead);
Node* Find_value(struct Node* pHead, int& cin_value);
bool Find_Copy(struct Node* pHead, struct Node* current);
Node* Find_Current_By_Key(struct Node* pHead, int key);


int main()
{
	setlocale(0, "");

	Node* pHead = NULL;

	int value = 0, key = 0;

	int last_del_key = 0;
	int* plast_del_key = &last_del_key;

	int cin_menu = 0;

menu: cout << "1 - Создание списка;\n"
<< "2 - Вывод списка с начала;\n"
<< "-------------------------------------\n"
<< "3 - Добавление в конец списка;\n"
<< "4 - Добавление по позиции;\n"
<< "5 - Добавление перед ;\n"
<< "6 - Добавление после ;\n"
<< "-------------------------------------\n"
<< "7 - Удаление по позиции;\n"
<< "8 - Удаление по значению;\n"
<< "9 - Удаление перед ;\n"
<< "10 - Удаление после ;\n"
<< "-------------------------------------\n"
<< "11 - Очистка списка;\n"
<< "-------------------------------------\n"
<< "12 - Поиск элемента\n"
<< "Выбор: ";
cin >> cin_menu;


switch (cin_menu)
{

case 1:
{
	pHead = new (Node);
	pHead->value = NULL;
	pHead->next = NULL;
	pHead->prev = NULL;
	pHead->key = NULL;
	pHead->position = NULL;

	cout << "\n\t\tСписок создан!\n\n";
	system("pause");
	system("cls");
	goto menu;
}

case 2:
{
	system("cls");

	if (pHead == NULL)
	{
		cout << "\n\t\tСписок не создан!\n\n";
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пустой!\n" << endl;
		}
		else
		{
			cout << "1 - Вывод списка с начала\n"
				<< "2 - Вывод списка с конца\n"
				<< "Выбор: "; cin >> cin_menu;

			switch (cin_menu)
			{
			case 1:
			{
				Print_List_Start(pHead);
				break;
			}
			case 2:
			{
				Print_List_End(pHead);
				break;
			}
			default: cout << "\n\t\tОшибка выбора!\n\n";
			}
		}
		system("pause");
		system("cls");
		goto menu;
	}
}

case 3:
{
	system("cls");
	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n\n";
	}
	else
	{
		cout << "Введите значение: "; cin >> value;
		Add_Tail_List(pHead, *plast_del_key, value);
	}
	system("pause");
	system("cls");
	goto menu;
}

case 4:
{
	system("cls");
	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n" << endl;
	}
	else
	{
		int cin_position = 0;
		cout << "Введите позицию: "; cin >> cin_position;

		if (cin_position < 0 || cin_position > pHead->value)
		{
			cout << "\n\t\tВведена не верная позиция!\n\n";
		}
		else
		{
			cout << "Введите значение: "; cin >> value;
			Add_List_Position(pHead, *plast_del_key, value, cin_position);
			cout << "\n\t\tДобавление успешно завершено!\n\n";
		}
	}
	system("pause");
	system("cls");
	goto menu;
}

case 5:
{
	system("cls");
	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n" << endl;
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пустой!\n" << endl;
		}
		else
		{
			cout << "1 - Перед указанной позицией;\n"
				<< "2 - Перед указанным значением\n";
			cin >> cin_menu;
			switch (cin_menu)
			{
			case 1:
			{
				int cin_position = 0;
				cout << "Укажите позицию перед которой нужно добавить элемент: ";
				cin >> cin_position;

				if (cin_position < 0 || cin_position >= pHead->value)
				{
					cout << "\n\t\tВведена не верная позиция!\n\n";
				}
				else
				{
					if (cin_position != NULL)
					{
						cin_position--;
					}
					cout << "Введите значение: "; cin >> value;
					Add_List_Position(pHead, *plast_del_key, value, cin_position);
					cout << "\n\t\tДобавление успешно завершено!\n\n";
				}
				system("pause");
				system("cls");
				goto menu;
			}

			case 2:
			{
				int cin_value = 0; Node* current;
				cout << "Укажите значение перед которым нужно добавить элемент: ";
				cin >> cin_value;
				current = Find_value(pHead, cin_value);
				if (current != NULL)
				{
					if (Find_Copy(pHead, current))
					{
						cout << "\nВведите ключ элемента, перед которым нужно добавить элемент: ";
						cin >> key;
						current = Find_Current_By_Key(pHead, key);
					}
					if (current != NULL)
					{
						cout << "Введите значение: "; cin >> cin_value;
						Add_List_Before(pHead, *plast_del_key, cin_value, current);
					}
				}
				else
				{
					cout << "\n\t\tУказанное значение не найдено!\n\n";
				}
				system("pause");
				system("cls");
				goto menu;
			}

			default:
			{
				cout << "\n\t\tНе верный выбор!\n\n";
				system("pause");
				system("cls");
				goto menu;
			}
			}
		}
	}
}

case 6:
{
	system("cls");
	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n" << endl;
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пустой!\n" << endl;
		}
		else
		{
			cout << "1 - После указанной позиции;\n"
				<< "2 - После указанного значения\n";
			cin >> cin_menu;
			switch (cin_menu)
			{
			case 1:
			{
				int cin_position = 0;
				cout << "Укажите позицию после которой нужно добавить элемент: ";
				cin >> cin_position;

				if (cin_position < 0 || cin_position >= pHead->value)
				{
					cout << "\n\t\tВведена не верная позиция!\n\n";
				}
				else
				{
					cin_position++;
					cout << "Введите значение: "; cin >> value;
					Add_List_Position(pHead, *plast_del_key, value, cin_position);
					cout << "\n\t\tДобавление успешно завершено!\n\n";
				}
				system("pause");
				system("cls");
				goto menu;
			}

			case 2:
			{
				int cin_value = 0; Node* current;
				cout << "Укажите значение после которого нужно добавить элемент: ";
				cin >> cin_value;
				current = Find_value(pHead, cin_value);
				if (current != NULL)
				{
					if (Find_Copy(pHead, current))
					{
						cout << "\nВведите ключ элемента, перед которым нужно добавить элемент: ";
						cin >> key;
						current = Find_Current_By_Key(pHead, key);
					}
					if (current != NULL)
					{
						cout << "Введите значение: "; cin >> cin_value;
						Add_List_After(pHead, *plast_del_key, cin_value, current);
					}

				}
				else
				{
					cout << "\n\t\tУказанное значение не найдено!\n\n";
				}
				system("pause");
				system("cls");
				goto menu;
			}

			default:
			{
				cout << "\n\t\tНе верный выбор!\n\n";
				system("pause");
				system("cls");
				goto menu;
			}
			}
		}
	}
}

case 7:
{
	system("cls");
	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n" << endl;
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пуст!\n" << endl;
		}
		else
		{
			int cin_position = 0;
			cout << "Введите позицию: "; cin >> cin_position;

			if (cin_position < 0 || cin_position >= pHead->value)
			{
				cout << "\n\t\tВведена не верная позиция!\n\n";
			}
			else
			{
				Dell_List_Position(pHead, *plast_del_key, cin_position);
			}
		}
	}
	system("pause");
	system("cls");
	goto menu;
}

case 8:
{
	system("cls");
	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n" << endl;
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пуст!\n" << endl;
		}
		else
		{
			int cin_value = 0; Node* current;
			cout << "Введите значение: "; cin >> cin_value;

			current = Find_value(pHead, cin_value);

			if (current != NULL)
			{
				if (Find_Copy(pHead, current))
				{
					cout << "\nВведите ключ удаляемого элемента: ";
					cin >> key;
					current = Find_Current_By_Key(pHead, key);
				}
				Dell_List_Value(pHead, *plast_del_key, current);
			}
			else
			{
				cout << "\n\n\tУказанное значение не найдено!\n\n";
			}
		}
	}
	system("pause");
	system("cls");
	goto menu;
}

case 9:
{
	system("cls");

	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n" << endl;
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пуст!\n" << endl;
		}
		else
		{
			cout << "1 - Перед указанной позицией;\n"
				<< "2 - Перед указанным значением\n";
			cin >> cin_menu;
			switch (cin_menu)
			{
			case 1:
			{
				int cin_position = 0;
				cout << "Укажите позицию перед которой нужно удалить элемент: ";
				cin >> cin_position;

				if (cin_position < 0 || cin_position >= pHead->value)
				{
					cout << "\n\t\tВведена не верная позиция!\n\n";
				}
				else
				{
					if (cin_position != NULL)
					{
						cin_position--;
						Dell_List_Position(pHead, *plast_del_key, cin_position);
					}
					else
					{
						cout << "\n\t\tПеред указанной позицией удалять нечего!\n\n";
					}
				}
				system("pause");
				system("cls");
				goto menu;
			}

			case 2:
			{
				int cin_value = 0; Node* current;
				cout << "Укажите значение перед которым нужно удалить элемент: ";
				cin >> cin_value;
				current = Find_value(pHead, cin_value);
				if (current != NULL)
				{
					if (Find_Copy(pHead, current))
					{
						cout << "\nВведите ключ, перед которым нужно удалить элемент: ";
						cin >> key;
						current = Find_Current_By_Key(pHead, key);
					}
					if (current != NULL)
					{
						Dell_List_Before(pHead, *plast_del_key, current);
					}
					system("pause");
					system("cls");
					goto menu;
				}
				else
				{
					cout << "\n\t\tУказанное значение не найдено!\n\n";
					system("pause");
					system("cls");
					goto menu;
				}
			}

			default:
			{
				cout << "\n\t\tНе верный выбор!\n\n";
			}
			}
		}
	}
	system("pause");
	system("cls");
	goto menu;
}

case 10:
{
	system("cls");

	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n" << endl;
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пуст!\n" << endl;
		}
		else
		{
			cout << "1 - После указанной позиции;\n"
				<< "2 - После указанного значения\n";
			cin >> cin_menu;

			switch (cin_menu)
			{
			case 1:
			{
				int cin_position = 0;
				cout << "Укажите позицию после которой нужно удалить элемент: ";
				cin >> cin_position;

				if (cin_position < 0 || cin_position >= pHead->value)
				{
					cout << "\n\t\tВведена не верная позиция!\n\n";
				}
				else
				{

					if (cin_position != pHead->value - 1)
					{
						cin_position++;
						Dell_List_Position(pHead, *plast_del_key, cin_position);
					}
					else
					{
						cout << "\n\t\tПосле указанной позиции удалять нечего!\n\n";
					}
				}
				system("pause");
				system("cls");
				goto menu;
			}

			case 2:
			{
				int cin_value = 0; Node* current;
				cout << "Укажите значение после которого нужно удалить элемент: ";
				cin >> cin_value;
				current = Find_value(pHead, cin_value);
				if (current != NULL)
				{
					if (Find_Copy(pHead, current))
					{
						cout << "\nВведите ключ, после которого нужно удалить элемент: ";
						cin >> key;
						current = Find_Current_By_Key(pHead, key);
					}
					if (current != NULL)
					{
						Dell_List_After(pHead, *plast_del_key, current);
					}
				}
				else
				{
					cout << "\n\t\tУказанное значение не найдено!\n\n";
				}
				system("pause");
				system("cls");
				goto menu;
			}

			default:
			{
				cout << "\n\t\tНе верный выбор!\n\n";
				system("pause");
				system("cls");
				goto menu;
			}
			}
		}
	}
}

case 11:
{
	system("cls");
	pHead = Clear_List(pHead);
	system("pause");
	system("cls");
	goto menu;
}

case 12:
{
	system("cls");
	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n" << endl;
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пуст!\n" << endl;
		}
		else
		{
			cout << "1 - Поиск элемента после указанной позиции;\n"
				<< "2 - Поиск элемента после указанного значения\n"
				<< "3 - Поиск элемента перед указанной позицией\n"
				<< "4 - Поиск элемента перед указанным значением\n";
			cin >> cin_menu;
			switch (cin_menu)
			{
				case 1:
				{

				}
			}
		}
	}
}

default:
{
	cout << "Происходит выход...\n";
	system("pause");
}
}


	
}



void Print_List_Start(struct Node* pHead)
{
	Node* current = pHead->next;
	while (current != NULL)
	{
		cout << "Значение = " << current->value << "\tПозиция " << current->position << "\tАдрес = " << current << "\tКлюч = " << current->key << endl;
		current = current->next;
	}
	cout << "\n\tАдрес заголовочного элемента               = " << pHead << endl << endl;
	cout << "\n\tАдрес 1-го элемента в списке               = " << pHead->next << endl << endl;
	current = Find_Tail(pHead);
	cout << "\n\tАдрес последнего элемента                  = " << current << endl << endl;
	cout << "\n\tКоличество элементов в списке    = " << pHead->value << endl << endl;
}

void Print_List_End(struct Node* pHead)
{
	Node* current = Find_Tail(pHead);
	while (current != NULL)
	{
		cout << "Значение = " << current->value << "\tПозиция " << current->position << "\tАдрес = " << current << "\tКлюч = " << current->key << endl;
		current = current->prev;
	}
	cout << "\n\tАдрес заголовочного элемента               = " << pHead << endl << endl;
	cout << "\n\tАдрес 1-го элемента в списке               = " << pHead->next << endl << endl;
	current = Find_Tail(pHead);
	cout << "\n\tАдрес последнего элемента                  = " << current << endl << endl;
	cout << "\n\tКоличество элементов в списке    = " << pHead->value << endl << endl;
}

Node* Refresh_Position(struct Node* pHead)
{
	Node* current = pHead->next;
	int i = 0;

	while (i < pHead->value)
	{
		current->position = i;
		i++;
		current = current->next;
	}
	return 0;
}

void Add_Tail_List(struct Node* pHead, int& last_del_key, int value)
{
	Node* current;
	if (pHead->next == NULL)
	{
		current = new (Node);
		current->value = value;
		current->position = pHead->value;
		current->key = Set_Key(last_del_key, pHead->value);
		pHead->next = current;
		current->next = NULL;
		current->prev = NULL;
		pHead->value++;
	}
	else
	{
		Node* LastValue = Find_Tail(pHead);
		current = LastValue;
		current->next = new (Node);
		current = current->next;
		current->value = value;
		current->position = pHead->value;
		current->key = Set_Key(last_del_key, pHead->value);
		current->next = NULL;
		current->prev = LastValue;
		Refresh_Position(pHead);
		pHead->value++;
		cout << "\n\t\tЭлемент Добавлен!\n\n";
	}
}

void Add_List_Position(struct Node* pHead, int& last_del_key, int value, int cin_position)
{
	Node* current;
	if (cin_position == 0)
	{
		current = pHead->next;
		if (pHead->next != NULL)
		{
			current->prev = new(Node);
			current = current->prev;
		}
		else
		{
			current = new(Node);
		}
		current->value = value;
		current->next = pHead->next;
		current->prev = NULL;
		pHead->next = current;
		current->key = Set_Key(last_del_key, pHead->value);
		pHead->value++;
		Refresh_Position(pHead);
	}
	else if (cin_position == pHead->value) //cin_pos. == кол-ву знач.
	{
		current = Find_Tail(pHead);
		current->next = new (Node);
		Node* PrevEl = current;
		current = current->next;
		current->value = value;
		current->next = NULL;
		current->prev = PrevEl;
		current->key = Set_Key(last_del_key, pHead->value);
		pHead->value++;
		Refresh_Position(pHead);
	}
	else
	{
		current = pHead->next;
		for (int i = 0; i <= pHead->value; i++)
		{
			if (current->position == cin_position)
			{
				current = current->prev;
				Node* NextEl = current->next;
				current->next = new (Node);
				Node* PrevEl = current;
				current = current->next;
				current->value = value;
				current->next = NextEl;
				current->prev = PrevEl;
				current->key = Set_Key(last_del_key, pHead->value);
				NextEl->prev = current;
				pHead->value++;
				Refresh_Position(pHead);
				break;
			}
			current = current->next;
		}
	}
}

void Add_List_Before(struct Node* pHead, int& last_del_key, int cin_value, struct Node* current)
{
	Node* NextEl = current;
	Node* PrevEl = current->prev;
	current->prev = new (Node);
	current = current->prev;
	current->value = cin_value;
	current->next = NextEl;
	if (PrevEl != NULL)
	{
		PrevEl->next = current;
	}
	else
	{
		pHead->next = current;
	}
	current->prev = PrevEl;
	current->key = Set_Key(last_del_key, pHead->value);
	pHead->value++;
	Refresh_Position(pHead);
}

void Add_List_After(struct Node* pHead, int& last_del_key, int cin_value, struct Node* current)
{
	Node* NextEl = current->next;
	Node* PrevEl = current;

	PrevEl->next = new(Node);
	current = PrevEl->next;
	current->value = cin_value;
	current->next = NextEl;
	current->prev = PrevEl;
	current->key = Set_Key(last_del_key, pHead->value);
	if (NextEl != NULL)
	{
		NextEl->prev = current;
	}
	pHead->value++;
	Refresh_Position(pHead);
}

void Dell_List_Position(struct Node* pHead, int& last_del_key, int cin_position)
{
	Node* current = pHead->next;
	if (cin_position == 0)
	{
		last_del_key = current->key;
		pHead->next = current->next;
		if (current->next != NULL)
		{
			current->next->prev = NULL;
		}

		cout << "\nУдаляемое значение: " << current->value << "\tАдрес: " << current
			<< "\tКлюч: " << current->key << "\tПозиция: " << current->position << endl << endl;
		delete current;
		pHead->value--;
		Refresh_Position(pHead);
		cout << "\n\t\tУдаление успешно завершено!\n\n";
	}
	else
	{
		for (int i = 0; i < cin_position + 1; i++)
		{
			if (current->position == cin_position)
			{
				last_del_key = current->key;
				current->prev->next = current->next;
				if (current->next != NULL)
				{
					current->next->prev = current->prev;
				}
				cout << "\nУдаляемое значение: " << current->value << "\tАдрес: " << current
					<< "\tКлюч: " << current->key << "\tПозиция: " << current->position << endl << endl;
				delete current;
				pHead->value--;
				Refresh_Position(pHead);
				cout << "\n\t\tУдаление успешно завершено!\n\n";
				break;
			}
			current = current->next;
		}
	}
}

void Dell_List_Value(struct Node* pHead, int& last_del_key, struct Node* current)
{
	if (current->prev == NULL)
	{
		pHead->next = current->next;
	}
	else
	{
		current->prev->next = current->next;
	}
	if (current->next != NULL)
	{
		current->next->prev = current->prev;
	}
	last_del_key = current->key;
	delete current;
	pHead->value--;
	Refresh_Position(pHead);
	cout << "\n\t\tУдаление успешно завершено!\n\n";
}

void Dell_List_Before(struct Node* pHead, int& last_del_key, Node* current)
{
	if (current == pHead->next)
	{
		cout << "\n\t\tПеред указанным значением нет элемента!\n\n";
	}
	else
	{
		current = current->prev;
		if (current->prev != NULL)
		{
			current->prev->next = current->next;
		}
		current->next->prev = current->prev;
		last_del_key = current->key; // запоминает ключ удаляемого элемента
		cout << "\n\t\tУдаляемое значение = " << current->value
			<< "\tЕго адрес = " << current << "\tКлюч = " << current->key << endl;
		if (current == pHead->next)
		{
			pHead->next = current->next;
		}
		delete current;
		pHead->value--;
		Refresh_Position(pHead);
		cout << "\n\t\tУдаление успешно завершено!\n\n";
	}
}

void Dell_List_After(struct Node* pHead, int& last_del_key, Node* current)
{
	if (current->next == NULL)
	{
		cout << "\n\t\tПосле этого элемента удалять нечего!\n\n";
	}
	else
	{
		current = current->next;
		current->prev->next = current->next;
		if (current->next != NULL)
		{
			current->next->prev = current->prev;
		}
		last_del_key = current->key; // запоминает ключ удаляемого элемента
		cout << "\n\t\tУдаляемое значение = " << current->value
			<< "\tЕго адрес = " << current << "\tКлюч = " << current->key << endl;
		delete current;
		pHead->value--;
		Refresh_Position(pHead);
		cout << "\n\t\tУдаление успешно завершено!\n\n";
	}
}

int Set_Key(int& last_del_key, int& count)
{
	int key = 0;
	if (last_del_key != 0)
	{
		key = last_del_key;
		last_del_key = 0;
	}
	else
	{
		key = count + 1 + 100;
	}
	return key;
}

Node* Clear_List(struct Node* pHead)
{
	if (pHead == NULL)
	{
		cout << "\n\t\tСписок не создан!\n\n";
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пустой!\n" << endl;
		}
		else
		{
			Node* current, * del_value;
			current = pHead->next;
			while (current != NULL)
			{
				del_value = current;
				current = current->next;
				pHead->next = current;
				delete del_value;
			}
			pHead = NULL;
			cout << "\n\t\tСписок очищен!\n\n";
		}
	}
	return pHead;
}

void Find_Key(struct Node* pHead)
{
	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n\n";
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пуст!\n\n";
		}
		else
		{
			int cin_key = 0;
			Node* t;
			bool find_key = false;
			cout << "\n\t\tВведите ключ: "; cin >> cin_key;

			for (t = pHead->next; t != NULL; t = t->next)
			{
				if (t->key == cin_key)
				{
					cout << "\n\t\tЭлемент найден!\n"
						<< "\n\t\tЗначение = " << t->value << "\tПозиция = " << t->position << "\tКлюч = " << t->key << "\tАдрес = " << t << endl << endl;
					find_key = true;
				}
			}
			if (find_key == false)
			{
				cout << "\n\t\tКлюч не найден!\n\n";
			}
		}
	}
}

void Find_Position(struct Node* pHead, struct Node* t)
{
	if (pHead == NULL)
	{
		cout << "\n\t\tСоздайте список!\n\n";
	}
	else
	{
		if (pHead->next == NULL)
		{
			cout << "\n\t\tСписок пуст!\n\n";
		}
		else
		{
			cout << "\n\t\tЭлемент найден!\n"
				<< "\n\t\tЗначение = " << t->value << "\tПозиция = " << t->position << "\tКлюч = " << t->key << "\tАдрес = " << t << endl << endl;
		}
	}
}

Node* Find_Tail(struct Node* pHead)
{
	Node* Tail;

	Tail = pHead->next;
	while (Tail->next != NULL)
	{
		Tail = Tail->next;
	}
	return Tail;
}

Node* Find_value(struct Node* pHead, int& cin_value)
{
	Node* current = pHead->next;
	while (current != NULL)
	{
		if (current->value == cin_value)
		{
			return current;
		}
		current = current->next;
	}
	return 0;
}

bool Find_Copy(struct Node* pHead, struct Node* current)
{
	bool find_copy = false;
	Node* t = pHead->next;
	while (t != NULL)
	{
		if (current->value == t->value && current->key != t->key)
		{
			cout << "\n\t\tЕсть копия!\n\n";
			cout << "Значение = " << current->value << "\tПозиция " << current->position << "\tАдрес = " << current << "\tКлюч = " << current->key << endl;
			cout << "\t\t\tИ\n";
			cout << "Значение = " << t->value << "\tПозиция " << t->position << "\tАдрес = " << t << "\tКлюч = " << t->key << endl;
			find_copy = true;
		}
		t = t->next;
	}
	return find_copy;
}

Node* Find_Current_By_Key(struct Node* pHead, int key)
{
	Node* current = pHead->next;
	while (current->key != key)
	{
		current = current->next;
		if (current == NULL)
		{
			cout << "\n\t\tУказан не верный ключ!\n\n";
			return 0;
		}
	}
	return current;
}