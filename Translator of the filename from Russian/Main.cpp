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
//������ ��� �������� �� wstring � string
string from_wstring(const wstring& ustr)
{
  if (ustr.empty()) return std::string();
  int size_needed = WideCharToMultiByte(CP_UTF8, 0, &ustr[0], (int)ustr.size(), NULL, 0, NULL, NULL);
  string strTo(size_needed, 0);
  WideCharToMultiByte(CP_UTF8, 0, &ustr[0], (int)ustr.size(), &strTo[0], size_needed, NULL, NULL);
  return strTo;
}
//������ ��� �������� �� string � wstring
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
  cout << "��������� ��� �������� ���� ������ ��������� �� ��������." << endl;
  cout << "�����: ������ �.�." << endl;
  cout << "������� ���� � ����������, � ������� ������ ������������� �����, � ����� ��������/*." << endl;
  cout << "���� �� ������ ��������� ������� ���������!" << endl;
  string exitt = { "1" };
  do
  {
    translate();
    cout << "��� ���������� ������ ������� 0! ��� ����������� 1!" << endl;
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

  // ������� � unique, ����� � ��� ���� �����
  unique_ptr<char16_t[]> buf = make_unique<char16_t[]>(path.size() + 1);
  // ����������� � std::wstring
  wstring wpath = to_wstring(path);
  // ������� � �����
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
        case '�': strcat(newname, "a"); break;
        case '�': strcat(newname, "b"); break;
        case '�': strcat(newname, "v"); break;
        case '�': strcat(newname, "g"); break;
        case '�': strcat(newname, "d"); break;
        case '�': strcat(newname, "e"); break;
        case '�': strcat(newname, "ye"); break;
        case '�': strcat(newname, "zh"); break;
        case '�': strcat(newname, "z"); break;
        case '�': strcat(newname, "i"); break;
        case '�': strcat(newname, "y"); break;
        case '�': strcat(newname, "k"); break;
        case '�': strcat(newname, "l"); break;
        case '�': strcat(newname, "m"); break;
        case '�': strcat(newname, "n"); break;
        case '�': strcat(newname, "o"); break;
        case '�': strcat(newname, "p"); break;
        case '�': strcat(newname, "r"); break;
        case '�': strcat(newname, "s"); break;
        case '�': strcat(newname, "t"); break;
        case '�': strcat(newname, "u"); break;
        case '�': strcat(newname, "f"); break;
        case '�': strcat(newname, "ch"); break;
        case '�': strcat(newname, "z"); break;
        case '�': strcat(newname, "ch"); break;
        case '�': strcat(newname, "sh"); break;
        case '�': strcat(newname, "ch"); break;
        case '�': strcat(newname, "''"); break;
        case '�': strcat(newname, "y"); break;
        case '�': strcat(newname, "''"); break;
        case '�': strcat(newname, "e"); break;
        case '�': strcat(newname, "yu"); break;
        case '�': strcat(newname, "ya"); break;
        case '�': strcat(newname, "A"); break;
        case '�': strcat(newname, "B"); break;
        case '�': strcat(newname, "V"); break;
        case '�': strcat(newname, "G"); break;
        case '�': strcat(newname, "D"); break;
        case '�': strcat(newname, "E"); break;
        case '�': strcat(newname, "Ye"); break;
        case '�': strcat(newname, "Zh"); break;
        case '�': strcat(newname, "Z"); break;
        case '�': strcat(newname, "I"); break;
        case '�': strcat(newname, "Y"); break;
        case '�': strcat(newname, "K"); break;
        case '�': strcat(newname, "L"); break;
        case '�': strcat(newname, "M"); break;
        case '�': strcat(newname, "N"); break;
        case '�': strcat(newname, "O"); break;
        case '�': strcat(newname, "P"); break;
        case '�': strcat(newname, "R"); break;
        case '�': strcat(newname, "S"); break;
        case '�': strcat(newname, "T"); break;
        case '�': strcat(newname, "U"); break;
        case '�': strcat(newname, "F"); break;
        case '�': strcat(newname, "Ch"); break;
        case '�': strcat(newname, "Z"); break;
        case '�': strcat(newname, "Ch"); break;
        case '�': strcat(newname, "Sh"); break;
        case '�': strcat(newname, "Ch"); break;
        case '�': strcat(newname, "''"); break;
        case '�': strcat(newname, "Y"); break;
        case '�': strcat(newname, "''"); break;
        case '�': strcat(newname, "E"); break;
        case '�': strcat(newname, "Yu"); break;
        case '�': strcat(newname, "Ya"); break;
        default: { char ctmp[2] = { oldname[i], 0 }; strcat(&newname[0], &ctmp[0]); }
        }
        i++;
      } while (i < strlen(oldname));

      strcat(fullnewname, newname);
      cout << "oldname=" << oldname << endl;
      cout << "fullname=" << fullname << endl;
      cout << "fullnewname=" << fullnewname << endl;

      //�������������� ������ 
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