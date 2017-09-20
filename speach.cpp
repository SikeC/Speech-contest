
#include "speach.h"
#include "algorithm"
#include "functional"
#include "numeric"
using namespace std;

void Speaker::printfSpeaker_score()
{
	cout << "选手ID：" << this->s_id << "\t" << "选手姓名：" << this->s_name << "选手成绩：" << this->arg_score << endl;
}

void Speaker::printfSpeaker_Roster()
{
	cout << "选手ID：" << this->s_id << "\t" << "选手姓名：" << this->s_name << endl;
}

bool GreatSpeaker(const Speaker& s1,const Speaker& s2)
{
	return s1.arg_score > s2.arg_score;
}
vector<Speaker> CreatSpeaker(int num)
{
	vector<Speaker> Speaker_Roster;
	Speaker tmp;
	string str = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());
	for (int i = 0,j = 0; i < num; i++,j++)
	{
		tmp.s_name = str[j];
		if (j == 23)
		{
			j = 0;
		}
		tmp.s_id = i+100;
		Speaker_Roster.push_back(tmp);
	}
	cout << "参赛选手名单：" << endl;
	for (vector<Speaker>::iterator it = Speaker_Roster.begin(); it != Speaker_Roster.end(); it++)
	{
		it->printfSpeaker_Roster();
	}
	return Speaker_Roster;
}

pair<int, multimap<int, Speaker>> SpeakerGrouping(vector<Speaker> &roster)
{
	multimap<int, Speaker> Grops;
	pair<int, Speaker> tmp;
	int index = 1;
	int count = -1;
	pair<int, multimap<int, Speaker>>  back;
	if (roster.size() <= 3)
	{
		back.first = 0;
		back.second = Grops;
		return back;
	}
	random_shuffle(roster.begin(), roster.end());
	for (vector<Speaker>::iterator it = roster.begin(); it != roster.end(); it++)
	{
		count++;
		if (count == 6)
		{
			index++;
			count = 0;
		}
		tmp.first = index;
		tmp.second = *it;
		Grops.insert(tmp);
	}
	back.first = index;
	back.second = Grops;
	return back;
}
vector<Speaker> Speech_Contest(pair<int, multimap<int, Speaker>> &grops)
{
	vector<Speaker> Winner_Roster;
	vector<Speaker> tmp;
	deque<int> dscore;
	multimap<int, Speaker>::iterator it;
	if (grops.first < 1)
	{
		tmp[0].s_name = "Erro";
		Winner_Roster.push_back(tmp[0]);
		return Winner_Roster;
	}
	for (int i = 1; i <= grops.first; i++)
	{
		it = grops.second.find(i);
		for(int count_i=0;count_i<grops.second.count(i);count_i++,it++)
		{
			for (int j = 0; j < 10; j++)
			{
				dscore.push_back(50 + rand() % 50);
			}
			dscore.pop_front();
			dscore.pop_back();
			it->second.arg_score = accumulate(dscore.begin(), dscore.end(), 0) / dscore.size();
			tmp.push_back(it->second);
			dscore.clear();
		}
		sort(tmp.begin(), tmp.end(), GreatSpeaker);
		cout << "第" << i << "小组成绩排名：" << endl;
		for (vector<Speaker>::iterator it_print = tmp.begin(); it_print != tmp.end(); it_print++)
		{
			it_print->printfSpeaker_score();
		}
		if (tmp.size() > 3)
		{
			Winner_Roster.push_back(tmp[0]);
			Winner_Roster.push_back(tmp[1]);
			Winner_Roster.push_back(tmp[2]);
		}
		else
		{
			for (int k = 0; k < tmp.size(); k++)
			{
				Winner_Roster.push_back(tmp[k]);
			}
		}
		tmp.clear();
	}
	cout << "比赛晋级名单：" << endl;
	for (vector<Speaker>::iterator it_win = Winner_Roster.begin(); it_win !=Winner_Roster.end() ; it_win++)
	{
		it_win->printfSpeaker_Roster();
	}
	return Winner_Roster;
}