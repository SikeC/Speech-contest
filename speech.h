
#pragma once
#define _SPEACH_H_
#include "iostream"
#include "set"
#include "list"
#include "vector"
#include "string"
#include "iterator"
#include "map"
#include "queue"

using namespace std;
/*参赛选手类*/
class Speaker
{
public:
	/*打印选手名称*/
	void printfSpeaker_score();
	void printfSpeaker_Roster();
public:
	string s_name;
	int s_id;
	int arg_score;
};
/*二元谓词用于自定义排序speaker类*/
bool GreatSpeaker(const Speaker& s1, const Speaker& s2);
/*创建参赛选手,返回一个vector包含所有的参赛选手Speaker*/
vector<Speaker> CreatSpeaker(int num);
/*进行随机分组,返回一个pair对，一个为整个roster的分组情况，一个是小组数量，如果分组错误则小组数量为0*/
pair<int, multimap<int, Speaker>> SpeakerGrouping(vector<Speaker> &roster);
/*进行比赛，并打印出成绩，比赛结束返回晋级新名单*/
vector<Speaker> Speech_Contest(pair<int, multimap<int, Speaker>> &grops);
