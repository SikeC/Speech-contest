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
	
	cout << "���������������" << endl;
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
		cout << "\n\n\n�����������ʼ��һ�ֱ���" << endl;
		cin.get();
		Speaker_Roster = Speech_Contest(Grops);
		if (Speaker_Roster[0].s_name == "Erro")
		{
			goto end;
		}
	}
end:
	cout << "���������" << endl;
}