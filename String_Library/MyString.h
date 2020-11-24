#pragma once
class MyString
{

	char* ptr;
	int size;
	int STRLEN(const char* p)const;
	void STRCOPY(char* p1, const char* p);

public:
	MyString();
	MyString(const char* s);
	MyString(int num);
	MyString(const MyString& MS);
	void FileInput();
	void UserInput(int size);
	void InitializePtr(char* p, int size);
	void InitializePtrInt(int* p, int size);
	void growArrayInt(int* arr, int size);
	void growArrayChar(char* arr, int size);
	void growArrayString(MyString* arr, int size);
	MyString TOUPPER(const MyString& s);
	void ShrinkArr(int index);
	void ExtendArr(int index, int ch);
	void Reverse();
	void ReverseInt(int* arr, int size);
	void Initialize(char* subText);

	MyString* Split(char d, int& count);
	MyString* Tokenize(char ds, int& count);
	bool Equal(const MyString& s)const;
	int Cmp(const MyString& s)const;
	void SetString(const char* p);
	void Trim();
	int* SubStringSearch(const char* substr, int& count);
	int* SubStringSearch(const MyString& substr, int& count);
	MyString Concati(const MyString& S2);
	MyString Concati(char c);
	char Index(int i);
	int Find_First(char ch);
	int Find_Last(char ch);
	int* Find_All(char ch, int& C);
	void Remove_First(char ch);
	void Remove_Last(char ch);
	void Remove_All(char ch);
	void Remove_At(int i);
	void Insert_At(int i, char ch);
	void Insert_At(int i, MyString sub);
	void Clear();
	int Length();
	int Atoi();
	MyString Itoa(int num);

	void Print();

	~MyString();
};

