#include "iostream"
#include "set"
#include "list"
#include "vector"
#include "string"
#include "iterator"
#include "map"
#include "queue"
#include "speach.h"

using namespace std;

void main()
{

	vector<Speaker>                       Speaker_Roster;
	pair<int, multimap<int, Speaker>>     Grops;
	int                                   num;
	
	cout << "请输入参赛人数：" << endl;
	cin >> num;
	Speaker_Roster = CreatSpeaker(num);
	cin.get();
	while (true)
	{
		Grops = SpeakerGrouping(Speaker_Roster);
		if (Grops.first == 0)
		{
			goto end;
		}
		cout << "\n\n\n按下任意键开始下一轮比赛" << endl;
		cin.get();
		Speaker_Roster = Speech_Contest(Grops);
		if (Speaker_Roster[0].s_name == "Erro")
		{
			goto end;
		}
	}
end:
	cout << "程序结束！" << endl;
}