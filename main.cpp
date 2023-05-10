#include <iostream>
#include "judge.h"
using namespace std;


string read()
{
    string s;
    getline(cin,s);
    return s;
}

void analyze(const string& sentence)
{
    int flag = -1;
    judge_state0(sentence,0,flag);
    if (flag == 1) cout<<sentence<<" Acceptable"<<endl;
    else cout<<sentence<<" Unacceptable"<<endl;
}

void judge_state0(const string& sentence,int index,int &flag)
{
    char op = sentence[index];
    if (op=='a') judge_state1(sentence,index+1,flag);
    else if (op=='b') judge_state2(sentence,index+1,flag);
    else flag=-1;
}

void judge_state1(const string& sentence,int index,int &flag)
{
    char op = sentence[index];
    if (op=='a') judge_state1(sentence,index+1,flag);
    else if (op=='b') judge_state2(sentence,index+1,flag);
    else flag = -1;
}
void judge_state2(const string& sentence,int index,int &flag)
{
    char op = sentence[index];
    if (op=='a') judge_state1(sentence,index+1,flag);
    else if (op=='b') judge_state3(sentence,index+1,flag);
    else flag = -1;
}
void judge_state3(const string& sentence,int index,int &flag)
{
    char op = sentence[index];
    char next_char = (index + 1 < sentence.size()) ? sentence[index + 1] : '\0';
    if (op=='a') judge_state1(sentence,index+1,flag);
    else if (op=='b') judge_state3(sentence,index+1,flag);
    else if ((op=='>'||op=='<'||op=='='||op=='!') && next_char=='=' ) judge_state4(sentence,index+2,flag);
    else if (op=='>'||op=='<') judge_state4(sentence,index+1,flag);
    else flag = -1;
}
void judge_state4(const string& sentence,int index,int &flag)
{
    char op = sentence[index];
    if (op=='1') flag=1;
    else flag=-1;
}

//词法分析器-通过DFA图实现
int main() {
    string sentence = read();
    analyze(sentence);
    return 0;
}
