#include <iostream>
#include <string>
#include <vector>

int numOpen = 0;
int numClose = 0;

int getPriority(string ope)
{
  if (ope == "*" || ope == "/") return 2;
  else if (ope == "+" || ope == "-") return 1;
  else return 0;
}

void Normalization(string& exp)
{
  for (int i = 0; i < exp.length(); i++)
  {
    if (exp[i] == ' ') exp = exp.erase(i, 1); 
  }
 
}

int isOperator(string ope)
{
  if (getPriority(ope) == 0)
  {
    if (ope != "(" && ope != ")") return 0;
    else return 1;
  }
  return 2;
}

vector<string> ConvertToPostfix(string exp)
{
  vector<string> Stack;
  vector<string> Output;
  string number = "";
  for (int i = 0; i < exp.length(); i++) 
  { 
    string s(1, exp[i]);
    if (isOperator(s) == 0) number += s;
    else
    {
      if (number.length() > 0)
      {
        Output.push_back(number);
        number = "";
      }
      if (isOperator(s) == 1)
      {
        if (s == "(") 
        {
          numOpen ++;
          Stack.push_back("(");
        }
        else if (s == ")")
        {
          numClose ++;
          string pop = Stack.pop_back();
          while (pop != "(")
          {
            Output.push_back(pop);
            pop = Stack.pop_back();
          }
        }
      }
      else
      {
        while (!Stack.empty() && getPriority(Stack.back()) >= getPriority(s))
          Output.push_back(Stack.pop_back());
        Stack.push_back(s);
      }
    }
  }
  if (number.length() > 0)
  {
    Output.push_back(number);
    number = "";
  }
  while (!Stack.empty()) 
    Output.push_back(Stack.pop_back());
  return Output;
}

float Calc(vector<string> Input)
{
  vector<string> Stack;
  for (int i = 0; i < Input.size(); i++)
  {
    if (isOperator(Input[i]) == 0) Stack.push_back(Input[i]);
    else
    {
      float b = stof(Stack.pop_back());
      float a = stof(Stack.pop_back());
      if (Input[i] == "+") Stack.push_back(a + b);
      else if (Input[i] == "-") Stack.push_back(a - b);
      else if (Input[i] == "*") Stack.push_back(a * b);
      else if (Input[i] == "/") Stack.push_back(a / b);
    }
  }
  return stof(Stack.pop_back());
}

int main()
{
  ifstream getFile ("input.txt");
  ofstream putFile ("output.txt" , ios::out);
  string temp;
  while(getline(getFile,temp))
  {
    Normalization(temp);
    vector <string> Input = ConvertToPostfix(temp);
    if(numOpen != numClose)
      putFile << "Thieu ngoac" << endl;
    else
    {
      for (int i =0; i < Input.size(); i++)
      {
        putFile << Input.size();
      }
      putFile << "\t";
      float result = Calc(Input);
      putFile << result << endl;
    }
  }
  return 0;
}