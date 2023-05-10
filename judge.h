//
// Created by 北辰 on 2023/4/10.
//

using namespace std;

#ifndef LEXICAL_ANALYZER_JUDGE_H
#define LEXICAL_ANALYZER_JUDGE_H



#endif //LEXICAL_ANALYZER_JUDGE_H


string read();
void analyze(const string& sentence);
void judge_state0(const string& sentence,int index,int &flag);
void judge_state1(const string& sentence,int index,int &flag);
void judge_state2(const string& sentence,int index,int &flag);
void judge_state3(const string& sentence,int index,int &flag);
void judge_state4(const string& sentence,int index,int &flag);