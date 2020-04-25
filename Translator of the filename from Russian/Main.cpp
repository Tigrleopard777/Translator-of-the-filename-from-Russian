//
/*
Contact: Vlasov R.E.
mail: ryslanvlasov@mail.ru
github: Tigrleopard777
Programm: Translator of the filename from Russian into transliteration
*/
//
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
//Функци для перевода из wstring в string
string from_wstring(const wstring& ustr)
{
  if (ustr.empty()) return std::string();
  int size_needed = WideCharToMultiByte(CP_UTF8, 0, &ustr[0], (int)ustr.size(), NULL, 0, NULL, NULL);
  string strTo(size_needed, 0);
  WideCharToMultiByte(CP_UTF8, 0, &ustr[0], (int)ustr.size(), &strTo[0], size_needed, NULL, NULL);
  return strTo;
}
//Функци для перевода из string в wstring
wstring to_wstring(const std::string& str)
{
  if (str.empty()) return wstring();
  int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
  wstring wstrTo(size_needed, 0);
  MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
  return wstrTo;
}

void translate();

int main()
{
  setlocale(LC_ALL, "Russian");
  SetConsoleOutputCP(1251);
  SetConsoleCP(1251);
  cout << "Программа для перевода имен файлов срусского на транслит." << endl;
  cout << "Автор: Власов Р.Э." << endl;
  cout << "Введите путь к директории, в которой хотите переименовать файлы, в конец добавьте/*." << endl;
  cout << "Путь не должен содержать символы Кириллицы!" << endl;
  string exitt = { "1" };
  do
  {
    translate();
    cout << "Для завершения работы введите 0! Для продолжения 1!" << endl;
    fflush(stdin);
    fflush(stdout);
    getline(cin, exitt);
    system("cls");
  } while (exitt[0] != '0');
  return 0;
}

void translate()
{
  string path;
  getline(cin, path);

  char cpath[255];
  strcpy(cpath, path.c_str());
  cpath[strlen(cpath)] = 0;
  cpath[strlen(cpath) - 1] = '\0';
  for (int j = 0; j < strlen(cpath); j++)
  {
    cout << cpath[j];
  }

  // положим в unique, чтобы с ним было проще
  unique_ptr<char16_t[]> buf = make_unique<char16_t[]>(path.size() + 1);
  // преобразуем к std::wstring
  wstring wpath = to_wstring(path);
  // положим в буфер
  lstrcpyW((wchar_t*)buf.get(), wpath.data());

  WIN32_FIND_DATAW wfd;

  LPCWSTR Lpath[100];

  HANDLE const hFind = FindFirstFileW((wchar_t*)buf.get(), &wfd);
  cout << Lpath;
  //HANDLE const hFind = FindFirstFileW(L"D:\\test\\*", &wfd);
  setlocale(LC_ALL, "");
  int i = 0;

  if (INVALID_HANDLE_VALUE != hFind)
  {
    do
    {
      std::wcout << &wfd.cFileName[0] << std::endl;
      char oldname[100] = {};
      char newname[100] = {};
      char fullnewname[100] = {};
      char fullname[100]{};
      size_t len = wcstombs(oldname, &wfd.cFileName[0], wcslen(&wfd.cFileName[0]));
      if (len > 0u)
        oldname[len] = '\0';
      strcat(fullname, cpath);
      strcat(fullnewname, cpath);
      strcat(fullname, oldname);
      i = 0;
      do
      {
        switch (oldname[i])
        {
        case 'а': strcat(newname, "a"); break;
        case 'б': strcat(newname, "b"); break;
        case 'в': strcat(newname, "v"); break;
        case 'г': strcat(newname, "g"); break;
        case 'д': strcat(newname, "d"); break;
        case 'е': strcat(newname, "e"); break;
        case 'ё': strcat(newname, "ye"); break;
        case 'ж': strcat(newname, "zh"); break;
        case 'з': strcat(newname, "z"); break;
        case 'и': strcat(newname, "i"); break;
        case 'й': strcat(newname, "y"); break;
        case 'к': strcat(newname, "k"); break;
        case 'л': strcat(newname, "l"); break;
        case 'м': strcat(newname, "m"); break;
        case 'н': strcat(newname, "n"); break;
        case 'о': strcat(newname, "o"); break;
        case 'п': strcat(newname, "p"); break;
        case 'р': strcat(newname, "r"); break;
        case 'с': strcat(newname, "s"); break;
        case 'т': strcat(newname, "t"); break;
        case 'у': strcat(newname, "u"); break;
        case 'ф': strcat(newname, "f"); break;
        case 'х': strcat(newname, "ch"); break;
        case 'ц': strcat(newname, "z"); break;
        case 'ч': strcat(newname, "ch"); break;
        case 'ш': strcat(newname, "sh"); break;
        case 'щ': strcat(newname, "ch"); break;
        case 'ъ': strcat(newname, "''"); break;
        case 'ы': strcat(newname, "y"); break;
        case 'ь': strcat(newname, "''"); break;
        case 'э': strcat(newname, "e"); break;
        case 'ю': strcat(newname, "yu"); break;
        case 'я': strcat(newname, "ya"); break;
        case 'А': strcat(newname, "A"); break;
        case 'Б': strcat(newname, "B"); break;
        case 'В': strcat(newname, "V"); break;
        case 'Г': strcat(newname, "G"); break;
        case 'Д': strcat(newname, "D"); break;
        case 'Е': strcat(newname, "E"); break;
        case 'Ё': strcat(newname, "Ye"); break;
        case 'Ж': strcat(newname, "Zh"); break;
        case 'З': strcat(newname, "Z"); break;
        case 'И': strcat(newname, "I"); break;
        case 'Й': strcat(newname, "Y"); break;
        case 'К': strcat(newname, "K"); break;
        case 'Л': strcat(newname, "L"); break;
        case 'М': strcat(newname, "M"); break;
        case 'Н': strcat(newname, "N"); break;
        case 'О': strcat(newname, "O"); break;
        case 'П': strcat(newname, "P"); break;
        case 'Р': strcat(newname, "R"); break;
        case 'С': strcat(newname, "S"); break;
        case 'Т': strcat(newname, "T"); break;
        case 'У': strcat(newname, "U"); break;
        case 'Ф': strcat(newname, "F"); break;
        case 'Х': strcat(newname, "Ch"); break;
        case 'Ц': strcat(newname, "Z"); break;
        case 'Ч': strcat(newname, "Ch"); break;
        case 'Ш': strcat(newname, "Sh"); break;
        case 'Щ': strcat(newname, "Ch"); break;
        case 'Ъ': strcat(newname, "''"); break;
        case 'Ы': strcat(newname, "Y"); break;
        case 'Ь': strcat(newname, "''"); break;
        case 'Э': strcat(newname, "E"); break;
        case 'Ю': strcat(newname, "Yu"); break;
        case 'Я': strcat(newname, "Ya"); break;
        default: { char ctmp[2] = { oldname[i], 0 }; strcat(&newname[0], &ctmp[0]); }
        }
        i++;
      } while (i < strlen(oldname));

      strcat(fullnewname, newname);
      cout << "oldname=" << oldname << endl;
      cout << "fullname=" << fullname << endl;
      cout << "fullnewname=" << fullnewname << endl;

      //переименование файлов 
      int return_code = rename(fullname, fullnewname);
      if (return_code == 0)
      {
        cout << oldname << " was renamed to " << newname << endl << endl;
      }
      else
      {
        cout << oldname << " was not renamed" << endl << endl;
      }
      i++;
    } while (NULL != FindNextFileW(hFind, &wfd));

    FindClose(hFind);
  }
}