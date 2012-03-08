#ifndef DllHeader
#define DllHeader
#define DLLexport  __declspec(dllexport)
#include <iostream>

extern "C" {
// ���� � ��������, ���� ������ �� ��������, �� ����� �� ������� ������ (�������-true ,������-false)
struct Section {

double a,b;
bool empty;

};

DLLexport void Empty (Section &s);							 // ������� �� ������� ���� ������ � ���� � �������� ���������					
DLLexport bool IsEmpty (Section &s);						 //������� ������� �������� ��������, ��  ������ �� �������
DLLexport bool Correct (double a, double b);				 //������� �������� �� ��������� ����� ���� ������
DLLexport void Set (Section &s, double a, double b);		 // ���� �������� ����� ������
DLLexport Section* Intersection ( Section &t1, Section &t2); //���� ������� ���� ������
DLLexport void Print (Section &s);							 //����� ������ 
}

#endif