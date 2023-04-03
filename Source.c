#include <stdio.h>
#include <stdlib.h>
#define size 100

void copy_word(char* dst, char* scr, int start, int end) { // копирует из строки scr в dst символы с позиции start до end
	int i = 0, j = 0;
	for (i = start; i < end; i++) {
		dst[j] = scr[i];
		j++;
	}
	dst[j] = 0;
}

int my_strcmp(char* s1, char* s2) { // сравнивает строки
	int i = 0, j = 0;
	while ((s1[i] != '\0')&&(s1[i] != '\n'))
	{
		if (((s1[i] == 'a') || (s1[i] == 'e') || (s1[i] == 'o') || (s1[i] == 'i') || (s1[i] == 'y') || (s1[i] == 'u') || (s1[i] == 'A') || (s1[i] == 'E') || (s1[i] == 'O') || (s1[i] == 'I') || (s1[i] == 'Y') || (s1[i] == 'U')) && (s1[i] != '\0'))
		{
			i++;
		}
		else
		{
			i++;
		}
	}
	while ((s2[j] != '\0')&&(s2[j] != '\n'))
	{
		if (((s2[j] == 'a') || (s2[j] == 'e') || (s2[j] == 'o') || (s2[j] == 'i') || (s2[j] == 'y') || (s2[j] == 'u') || (s2[j] == 'A') || (s2[j] == 'E') || (s2[j] == 'O') || (s2[j] == 'I') || (s2[j] == 'Y') || (s2[j] == 'U')) && (s2[j] != '\0'))
		{
			j++;
		}
		else
		{
			j++;
		}
	}
	return i - j;
}
	
void my_swap(char** s1, char** s2) { // поменять строки местами
	char* tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int main() { // Ввести строку. Вывести пословно в порядке возрастания количества гласных букв. (привет = 2 < работа = 3)
	char* words[size] = { 0 };
	char s[size] = { 0 };
	int i = 0, start_w = 0, end_w = 0, in_word = 0, word_count = 0, j = 0;

	printf("Enter your words: \n");
	fgets(s, size, stdin);
	while (s[i] != 0) {
		if (s[i] != ' ') {
			if (in_word == 0) start_w = i;
			in_word = 1;
		}
		else {
			if (in_word == 1) {
				end_w = i;
				words[word_count] = (char*)malloc((end_w - start_w + 1) * sizeof(char));
				copy_word(words[word_count], s, start_w, end_w);
				word_count++;
			}
			in_word = 0;
		}
		i++;
	}
	if (in_word == 1) {
		end_w = i;
		words[word_count] = (char*)malloc(end_w - start_w + 1);
		copy_word(words[word_count], s, start_w, end_w);
		word_count++;
	}
	for (int j = 0; j < word_count; j++)
	{
		for (i = 0; i < word_count - 1; i++)
		{
			if (my_strcmp(words[i], words[i + 1]) > 0)
				my_swap(&words[i], &words[i + 1]);

		}
	}
	printf("Result: \n");

	for (i = 0; i < word_count; i++)
	puts(words[i]);

	for (i = 0; i < word_count; i++)
		free(words[i]);

	return 0;
}
/*
Ввести строку. Вывести пословно в порядке возрастания количества гласных букв.


1) разбить на слова 
	2-мерный массив
	одно слово - одна строка
	
2) сортировка
	сравнение
	обмен

	// малоков не надо
	// ** не надо, т.к. не используем malloc
	// в цикле my swap нужно написать циклы, которые меняют по символьно в двух строчках

	//void split (char* s)
			char w[100][51]
			char[][51] // одиннаковое с предыдущим, т.к. с 100 не считает
			w[0][0] = 'A'
			/////////
			w[5][3]
			//*(w + 5 * 51 + 3)



char words [100][51] (51 т.к. + 0) (100 строчек длинной 51)


/////////////////////////
ЛАБА 5
/////////////////////////
В 5 лабе нет допущений
т.е. если на лекции было
	char* words[100]
, то им пользоваться уже нельзя.
А если на лабах, то нужно сделать массив:
	char** words;
	words_count - расчёт
Здесь каждый элемент массива является указателем (char*). Далее 
	words = (char**)malloc(sizeof(char*) * word_count) // двумерный массив выделен динамически, где каждая строчка своего размера.

В пятой лабе нужно будет пройтись по строке и почтитаьть кол-во слов, чтобы знать на сколько выделять malloс, в 4 лабе такого нету.

...........
my_swap
...........
Функция делается легче: нужно просто менять адреса
	void f(char** w) // размерность передавать не нужно, т.к. строчки не лежат последовательно (malloc выделяет в разных местах). Если писать
																w[i][j] ,то
																* (w+i*sizeof(char*)) + j

1) char words [50][100]
2) words = (char**)malloc(sizeof(char*) * 50)
   for (i=0; i<50; i++)
	words[i] = (char*)malloc(sizeof(char) * 100) // 2 cпособ работает дольше, т.к. malloc вызывается 51 раз (1 раз общий и 50 раз в цикле) 



*/
