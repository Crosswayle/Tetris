// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once




#include "targetver.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <utility>
#include <functional>


#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'
#define ROTATE 'w'

#define FieldWidth 14
#define FieldHeight 24

#define PositionsCount 4 // count of possible rotate positions
#define FigureWidth 4
#define FigureHeight 4

#define FiguresCount 7	 

HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
