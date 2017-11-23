#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

///////////////////////////////////////
/////// DEFINE FUNCTION HERE///////////
///////////////////////////////////////

///////// Rabin-Karp Function /////////

// Hash Function
double hashFunc(string needHash, int posBegin, int lengHash)
{
	double sum = 0;
	int code, numExe=0;
	while (numExe < lengHash)
	{
		code = needHash.at(posBegin);
		sum = sum + code*pow(3.0,(lengHash-numExe-1));
		numExe++;
		posBegin++;
	}
	return sum;	
}
// rabinkarp

int rabinKarpSearch(string data, string needFind)
{
	int lengHash = needFind.size();
	double hashData, hashFind;
	hashFind = hashFunc(needFind,0,lengHash);
	for (int i= 0; i < (data.size() - lengHash + 1);i++)
	{
		hashData = hashFunc(data,i,lengHash);
		if(hashData == hashFind)
			return i;
	}
	return -1;
}
void numExecuteRabin(string &data, string &needFind, int &numExe, int &numHash)
{
	int lengHash = needFind.size();
	double hashData, hashFind;
	numHash = 0;
	numExe =0;
	hashFind = hashFunc(needFind,0,lengHash);
	for (int i= 0; i < (data.size() - lengHash + 1);i++)
	{
		numHash++;
		hashData = hashFunc(data,i,lengHash);
		if(hashData == hashFind)
			numExe++;
	}
}

//////////////// KMP Function //////////////

// init Next array Function
void initNext(string &needFind, int &m, int *next)
{
	int len = 0;

	next[0] = -1;

	int i = 0;
	int j = next[0] = -1;

	while (i < m - 1)
	{
		if (j == -1 || needFind.at(i) == needFind.at(j))
		{
			i++;
			j++;

			if (needFind.at(i) != needFind.at(j))
			{
				next[i] = j;
			}

			else
			{
				next[i] = next[j];
			}
		}
		else
			j = next[j];
	}
}
// KMP Function
int KMP(string &needFind, string &data, int *next)
{
	int m = needFind.size();
	int n = data.size();
	initNext(needFind, m, next);
	int i = 0;
	int k = 0;
	while (i < n)
	{
		if (k == -1)
		{
			i++;
			k = 0;
		}
		else if (data.at(i) == needFind.at(k))
		{
			i++;
			k++;
			if (k == m)
				return i - k;
		}
		else
			k = next[k];
	}
	return -1;

}

void redirectInFile(string fileData, string fileAccess, string fileResult)
{
	string temp;
	string data;
	string access[10];
	ifstream getFileData (fileData.c_str());
	if(getFileData.is_open())
	{
		while(getline(getFileData,temp))
		{
			data = temp;
		}
	}	
	getFileData.close();
	ifstream getFileAccess (fileAccess.c_str());
	int numAccess =0;
	if(getFileAccess.is_open())
	{
		while(getline(getFileAccess,temp))
		{
			temp.erase(temp.size()-1);
			access[numAccess] = temp;
			numAccess ++;
		}
	}
	getFileAccess.close();
	ofstream putFileResult (fileResult.c_str(),ios::out);
	putFileResult << "RABIN - KARP" << endl;
	for(int i =0; i<numAccess; i++)
	{
		int posRabin = rabinKarpSearch(data, access[i]);
		putFileResult << "1. ";
		putFileResult << access[i] <<": " ;
		if(posRabin != -1)
		{
			putFileResult << "true, ";
			putFileResult << "Pos: " << posRabin;
			int numExe = 0, numHash =0;
			numExecuteRabin(data,access[i],numExe,numHash);
			putFileResult << ", " << numExe <<", " << numHash <<endl;
		}
		else
		{
			putFileResult << "false" <<endl;
		}
	}
	putFileResult << endl;
	putFileResult << "KMP" << endl;
	for(int i = 0; i<numAccess;i++)
	{
		int lengAccess = access[i].size();
		int *next = new int[lengAccess];
		initNext(access[i],lengAccess, next);
		int posKMP = KMP(access[i],data, next);
		putFileResult << "1. " << access[i] << ": ";
		if(posKMP != 1)
		{
			putFileResult << "true ,Pos: " << posKMP << endl;
			
		}
		else
		{
			putFileResult << "false"<<endl;
		}
		putFileResult << "-> NEXT: ";
		for(int i = 0; i< lengAccess; i++)
		{
			putFileResult << next[i] << "\t";
		}
		putFileResult << endl;
		delete[] next;
	}
	putFileResult.close();
}

///////////////////////////////////////
////// MAIN FUNCTION //////////////////
///////////////////////////////////////

int main(int argc,char *argv[])
{
	string fileData,fileAccess,fileResult;
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << "   ";
	}
	if (argc > 2)
	{
		fileAccess = argv[1];
		fileData = argv[2];
		fileResult = argv[3];
		redirectInFile(fileData,fileAccess,fileResult);
	}
	return 0;
}
