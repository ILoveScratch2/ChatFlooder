#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <WinUser.h>
using namespace std;


const int repeat = 100;
const int waiting_time_for_each = 20;
const int waiting_time_before_start = 4000;
bool add_random_characters = false;
const int waiting_time_for_type = 15;
unsigned int random_characters = 3;
const int word_list_length = 62;
const char char_lists[word_list_length] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0' };


void press(WORD key)
{
	keybd_event(key, 0, 0, 0);
	keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
}


void ctrl_down()
{
	keybd_event(VK_CONTROL, 0, 0, 0);
}


void ctrl_up()
{
	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}

int main()
{
	srand(time(0));
	Sleep(waiting_time_before_start);
	for (unsigned int i = 1; i <= repeat; i++)
	{
		ctrl_down();
		press('V');
		ctrl_up();
		if (add_random_characters)
		{
			for (unsigned int j = 1; j <= random_characters; j++)
			{
				press(char_lists[rand() % word_list_length]);
				Sleep(waiting_time_for_each);
			}
		}
		press(VK_RETURN);
		Sleep(waiting_time_for_each);
	}
	return 0;
}
