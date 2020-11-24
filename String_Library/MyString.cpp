#include "MyString.h"
#include <iostream>
#include <fstream>

using namespace std;

int MyString::STRLEN(const char* p)const
{

	int length = 0;

	for (int i = 0; p[i] != '\0'; i++)
	{
		length++;
	}

	return length;

}

void MyString::STRCOPY(char* p1, const char* p)
{

	for (int i = 0; p[i] != '\0'; i++)
	{
		p1[i] = p[i];
	}

}

MyString::MyString()
{
	ptr = nullptr;
	size = 1;
}

void MyString::InitializePtr(char* p, int size)
{

	for (int i = 0; i < size; i++)
	{
		p[i] = 0;
	}

	p[size] = '\0';

}

void MyString::InitializePtrInt(int* p, int size)
{

	for (int i = 0; i < size; i++)
	{
		p[i] = 0;
	}

	p[size] = '\0';

}

MyString::MyString(const char* s)
{

	this->size = STRLEN(s);
	this->ptr = new char[this->size - 1];

	InitializePtr(this->ptr, this->size);

	this->SetString(s);

}

MyString::MyString(const MyString& MS)
{

	this->size = MS.size;
	this->ptr = MS.ptr;

}

MyString::MyString(int num)
{

	int rSize = 1;
	int* r = new int[rSize];
	InitializePtrInt(r, rSize);

	while (num != 0)
	{
		r[rSize - 1] = num % 10;
		num /= 10;
		rSize++;
		growArrayInt(r, rSize);
	}

	rSize--;
	r[rSize] = '\0';

	ReverseInt(r, rSize);

	this->size = rSize;
	this->ptr = new char[this->size];
	InitializePtr(this->ptr, this->size);

	for (int i = 0; i < rSize; i++)
		this->ptr[i] = r[i] + 48;

}

void MyString::FileInput()
{

	ifstream fin;
	fin.open("file.txt");

	int size = 0;
	char* ch = new char [100];

	if (!fin.is_open())
		cout << "\nFile does not exist!";
	else
		fin >> size;

	this->size = size;
	this->ptr = new char[size];
	InitializePtr(this->ptr, this->size);

	fin.ignore();
	fin.getline (this->ptr, this->size + 1);

	cout << this->size;

	fin.close();

}

void MyString::UserInput(int size)
{

	this->size = size;
	InitializePtr(this->ptr, this->size);

	int count = 0;

	cout << "\nEnter the elements for the array (max: 20 elements): ";
	for (int i = 0; i < size; i++)
	{
		cin >> this->ptr[i];
		count++;

		if (this->ptr[i] == -99)
		{
			this->ptr[i] = '\0';
			count--;
			this->size = count;
			break;
		}

	}

}

void MyString::SetString(const char* p)
{

	for (int i = 0; i < this->size; i++)
	{
		this->ptr[i] = p[i];
	}

}

MyString MyString::TOUPPER(const MyString& s)
{

	this->size = STRLEN(s.ptr);
	this->ptr = new char[this->size];

	for (int i = 0; i < this->size; i++)
	{
		if (s.ptr[i] >= 'a' && s.ptr[i] <= 'z')
			this->ptr[i] = s.ptr[i] - 32;
		else
			this->ptr[i] = s.ptr[i];
	}

	this->ptr[this->size] = '\0';

	return *this;

}

bool MyString::Equal(const MyString& s)const
{

	MyString word1;
	word1.TOUPPER(s);
	MyString word2;
	word2.TOUPPER(this->ptr);

	if (word2.size != word1.size)
		return 0;

	for (int i = 0; word1.ptr[i] != '\0'; i++)
	{
		if (word1.ptr[i] != word2.ptr[i])
			return 0;
	}

	return 1;

}

int MyString::Cmp(const MyString& s)const
{

	int length1 = this->size;
	int length2 = s.size;

	if (length1 > length2)
		return 1;
	else if (length1 < length2)
		return -1;
	else
	{
		if (this->Equal(s))
			return 0;
		else
			return -1;
	}


}

void MyString::Initialize(char* subText)
{

	this->size = STRLEN(subText);
	this->ptr = new char[this->size - 1];

	InitializePtr(this->ptr, this->size);

	this->SetString(subText);

}

void MyString::Trim()
{

	char* temp = new char[this->size];
	int j = 0;

	for (int i = 0; i < this->size; i++)
	{
		if (this->ptr[i] != ' ' || this->ptr[i + 1] != ' ')
		{
			temp[j] = this->ptr[i];
			j++;
		}
	}

	for (int i = 0; i < this->size; i++)
	{
		temp[i] = temp[i + 1];
	}

	j -= 2;

	temp[j] = '\0';

	int count = 0;

	for (int i = 0; temp[i] != '\0'; i++)
		count++;

	this->size = count;

	for (int i = 0; i < count; i++)
		this->ptr[i] = temp[i];

}

int* MyString::SubStringSearch(const char* substr, int& count)
{

	int length = STRLEN(substr);
	int j = 0;
	int index = 0;
	int sizes = 2;
	int* indexes = new int[sizes];

	InitializePtrInt(indexes, sizes);

	for (int i = 0; i < this->size; i++)
	{
		if (substr[j] == this->ptr[i])
		{
			if (j == 0)
				index = i;
			j++;
		}
		else
		{
			j = 0;
		}

		if (j == length)
		{
			indexes[count] = index;
			count++;
			sizes++;
			growArrayInt(indexes, sizes);
			j = 0;
		}

	}

	return indexes;

}

int* MyString::SubStringSearch(const MyString& substr, int& count)
{

	int length = STRLEN(substr.ptr);
	int j = 0;
	int index = 0;
	int sizes = 2;
	int* indexes = new int[sizes];

	InitializePtrInt(indexes, sizes);

	for (int i = 0; i < this->size; i++)
	{
		if (substr.ptr[j] == this->ptr[i])
		{
			if (j == 0)
				index = i;
			j++;
		}
		else
		{
			j = 0;
		}

		if (j == length)
		{
			indexes[count] = index;
			count++;
			sizes++;
			growArrayInt(indexes, sizes);
			j = 0;
		}

	}

	return indexes;

}

MyString MyString::Concati(const MyString& s2)
{

	int j = 0;

	MyString s3;

	s3.size = this->size + s2.size;
	s3.ptr = new char[this->size + s2.size];

	int i = 0;

	for (i = 0; i < this->size; i++)
	{
		s3.ptr[i] = this->ptr[i];
	}

	for (; i < this->size + s2.size; i++)
	{
		s3.ptr[i] = s2.ptr[j];
		j++;
	}

	return s3;

}

MyString MyString::Concati(char c)
{

	int j = 0;

	MyString s3;

	s3.size = this->size;
	s3.ptr = new char[this->size + 1];

	s3.ptr[0] = c;

	for (int i = 1; i < this->size + 1; i++)
	{
		s3.ptr[i] = this->ptr[j];
		j++;
	}

	return s3;

}

void MyString::growArrayInt(int* arr, int size)
{

	int* temp = NULL;

	temp = arr;
	arr = new int[size];

	for (int i = 0; i < size - 1; i++)
		arr[i] = temp[i];

}

void MyString::growArrayChar(char* arr, int size)
{

	char* temp = NULL;

	temp = arr;
	arr = new char[size];

	for (int i = 0; i < size - 1; i++)
		arr[i] = temp[i];

}

void MyString::growArrayString(MyString* arr, int size)
{

	MyString* temp = NULL;

	temp = arr;
	arr = new MyString[size];

	for (int i = 0; i < size - 1; i++)
		arr[i] = temp[i];

}

MyString* MyString::Split(char d, int& count)
{

	int sizes = 2;
	int splitSize = 2;
	MyString* splitWord = new MyString[splitSize];
	MyString word;
	int wordSize = 2;
	word.size = wordSize;
	word.ptr = new char[word.size];

	int j = 0;

	this->ptr[this->size] = d;

	for (int i = 0; i < splitSize + 1; i++)
	{
		splitWord[i].size = splitSize;
		splitWord[i].ptr = new char[splitSize];
	}

	InitializePtr(word.ptr, wordSize);

	for (int i = 0; i < this->size + 1; i++)
	{
		if (this->ptr[i] != d)
		{
			word.ptr[j] = this->ptr[i];
			if (j > 1)
			{
				wordSize++;
				growArrayChar(word.ptr, wordSize);
			}
			j++;
		}
		else
		{
			if (j != 0)
			{
				if (count > 2)
				{
					splitSize++;
					growArrayString(splitWord, splitSize);
				}
				splitWord[count].size = wordSize;
				splitWord[count].ptr = new char[wordSize];

				for (int i = 0; i < splitWord[count].size; i++)
					splitWord[count].ptr[i] = word.ptr[i];

				count++;
				j = 0;
				InitializePtr(word.ptr, wordSize);
				wordSize = 2;
			}
		}

	}

	return splitWord;

}

MyString* MyString::Tokenize(char ds, int& count)
{

	int sizes = 2;
	int splitSize = 2;
	MyString* splitWord = new MyString[splitSize];
	MyString word;
	int wordSize = 2;
	word.size = wordSize;
	word.ptr = new char[word.size];

	int j = 0;

	this->ptr[this->size] = ds;

	for (int i = 0; i < splitSize + 1; i++)
	{
		splitWord[i].size = splitSize;
		splitWord[i].ptr = new char[splitSize];
	}

	InitializePtr(word.ptr, wordSize);

	for (int i = 0; i < this->size + 1; i++)
	{
		if (this->ptr[i] != ds)
		{
			word.ptr[j] = this->ptr[i];
			if (j > 1)
			{
				wordSize++;
				growArrayChar(word.ptr, wordSize);
			}
			j++;
		}
		else
		{
			if (j != 0)
			{
				if (count > 2)
				{
					splitSize++;
					growArrayString(splitWord, splitSize);
				}
				splitWord[count].size = wordSize;
				splitWord[count].ptr = new char[wordSize];

				for (int i = 0; i < splitWord[count].size; i++)
					splitWord[count].ptr[i] = word.ptr[i];

				count++;
				j = 0;
				InitializePtr(word.ptr, wordSize);
				wordSize = 2;
			}
		}

	}

	return splitWord;

}

char MyString::Index(int i)
{
	return this->ptr[i];
}

int MyString::Find_First(char ch)
{

	for (int i = 0; i < this->size; i++)
		if (this->ptr[i] == ch)
		{
			return i;
		}

	return -1;

}

int MyString::Find_Last(char ch)
{

	for (int i = this->size; i >= 0; i--)
		if (this->ptr[i] == ch)
		{
			return i;
		}

	return -1;

}

int* MyString::Find_All(char ch, int& C)
{

	int tempSize = 1;
	int* temp = new int[tempSize];
	int j = 0;

	InitializePtrInt(temp, tempSize);

	for (int i = 0; i < this->size; i++)
	{
		if (this->ptr[i] == ch)
		{
			C++;
			tempSize++;
			growArrayInt(temp, tempSize);
			temp[j] = i;
			j++;
		}
	}

	return temp;

}

void MyString::ShrinkArr(int index)
{

	int temp = 0;

	for (int i = index; i < this->size; i++)
	{
		this->ptr[i] = this->ptr[i + 1];

	}

}

void MyString::Remove_First(char ch)
{

	for (int i = 0; i < this->size; i++)
		if (this->ptr[i] == ch)
		{
			ShrinkArr(i);
			break;
		}

}

void MyString::Remove_Last(char ch)
{

	for (int i = this->size; i >= 0; i--)
		if (this->ptr[i] == ch)
		{
			ShrinkArr(i);
			break;
		}

}

void MyString::Remove_All(char ch)
{

	for (int i = 0; i < this->size; i++)
		if (this->ptr[i] == ch)
		{
			ShrinkArr(i);
		}

}

void MyString::Print()
{
	for (int i = 0; i < this->size; i++)
		cout << this->ptr[i];

}

void MyString::Remove_At(int i)
{

	ShrinkArr(i);

}

void MyString::ExtendArr(int index, int ch)
{

	this->size++;
	growArrayChar(this->ptr, this->size);

	int temp = 0;

	for (int i = this->size; i > index; i--)
	{
		temp = this->ptr[i];
		this->ptr[i] = this->ptr[i - 1];
		this->ptr[i - 1] = temp;
	}

	this->ptr[index] = ch;

}

void MyString::Insert_At(int i, char ch)
{

	ExtendArr(i, ch);

}

void MyString::Insert_At(int i, MyString sub)
{

	char ch = '~';

	int l = i;

	for (int j = 0; j < sub.size; j++)
	{
		ExtendArr(i, ch);
		i++;
	}

	int k = 0;

	for (int j = l; k < sub.size; j++)
	{
		this->ptr[j] = sub.ptr[k];
		k++;
	}

}

void MyString::Clear()
{

	this->size = 1;

	for (int i = 0; i < this->size; i++)
		this->ptr[i] = '\0';

}

int MyString::Length()
{

	return this->size;

}

int MyString::Atoi()
{

	int r = 0;

	for (int i = 0; i < this->size; i++)
	{
		r = r * 10 + this->ptr[i] - '0';
	}

	return r;

}

void MyString::Reverse()
{

	MyString temp;
	temp.size = this->size;
	temp.ptr = new char[temp.size];

	int j = this->size;

	InitializePtr(temp.ptr, temp.size);

	for (int i = 0; i < this->size; i++)
	{
		temp.ptr[j] = this->ptr[i];
		j--;
	}

}

void  MyString::ReverseInt(int* arr, int size)
{

	int tempSize = size;
	int* temp = new int[tempSize];

	int j = size - 1;

	InitializePtrInt(temp, tempSize);

	for (int i = 0; i < size; i++)
	{
		temp[j] = arr[i];
		j--;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = temp[i];
	}

}

MyString MyString::Itoa(int num)
{

	int rSize = 1;
	int* r = new int[rSize];
	InitializePtrInt(r, rSize);

	while (num != 0)
	{
		r[rSize - 1] = num % 10;
		num /= 10;
		rSize++;
		growArrayInt(r, rSize);
	}

	rSize--;
	r[rSize] = '\0';

	ReverseInt(r, rSize);

	this->size = rSize;
	this->ptr = new char[this->size];
	InitializePtr(this->ptr, this->size);

	for (int i = 0; i < rSize; i++)
		this->ptr[i] = r[i] + 48;

	return *this;

}

MyString::~MyString()
{
}