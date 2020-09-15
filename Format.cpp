using namespace std;


//---------------------------------------------------------

struct rule
{
	int age;
	float weight;
	
	int price_of_black_pig;
	int price_of_little_pig;
	int price_of_big_white_pig;
	
	int sold_total;
	int sold_b_p;
	int sold_l_p;
	int sold_b_w_p;
	float sold_money;
	
	int dead_pig;
	
	int day;
	float money;
	
	int max_rand_per_time;
	//=========
	rule()
	{
		age = 365;
		weight = 75;
		price_of_black_pig = 15;
		price_of_little_pig = 7;
		price_of_big_white_pig = 6;
		day = 0;
		money = 0;
		dead_pig = 0;
		max_rand_per_time = 100;
	}
	
	void clear_sold_num()
	{
		sold_total = 0;
		sold_b_p = 0;
		sold_l_p = 0;
		sold_b_w_p = 0;
		sold_money = 0;
	}
};
rule main_rule;

//---------------------------------------------------------


void print_line()
{
	for(int i = 0;i < 70;i++)
	{
		cout<<'-';
	}
	cout<<'\n';
}

void print_thick_line()
{
	for(int i = 0;i < 70;i++)
	{
		cout<<'=';
	}
	cout<<'\n';
}

void refresh_screen()
{
	Sleep(500);
	system("cls");
}

void print_string(string str)
{
	int i = str.size();
	for(int k = 0;k < i;k++)
	{
		cout<<str[k];
		Sleep(12);
	}
	cout<<'\n';
}

void print_str(string str)
{
	int i = str.size();
	for(int k = 0;k < i;k++)
	{
		cout<<str[k];
		Sleep(25);
	}
}

void print_tip(string str)
{
	print_thick_line();
	cout<<str<<'\n';
	print_thick_line();
}

void print_tip(string str,int k)
{
	print_thick_line();
	cout<<str<<k<<'!'<<'\n';
	print_thick_line();
}

void progress_bar()
{
	cout<<'\n'<<"Please wait:";
	for(int i = 0;i < 40;i++)
	{
		Sleep(30);
		cout<<'#';
	}
	cout<<'\n'<<'\n';
}

void show_basic_info()
{
	cout<<"--day "<<main_rule.day<<"--  --"<<main_rule.money<<"$--  ";
}

void loop_display()
{
	cout<<"   "<<"Please choose your operate:"<<'\n';
	cout<<"      "<<"1. Show all the info of this farm."<<'\n';
	cout<<"      "<<"2. Show the info of a pigpen in specify serial number."<<'\n';
	cout<<"      "<<"3. Show the info of a pig in specify serial number."<<'\n';
	cout<<"      "<<"4. Into the next day."<<'\n';
	cout<<"      "<<"5. Into the next month(30 days)"<<'\n';
	cout<<"      "<<"6. Randomly set one pig sick"<<'\n';
	cout<<"      "<<"7. Check status by variety"<<'\n';
	cout<<"      "<<"Other input: exit the program"<<'\n';
}

int enter_num()
{
	int i;
	print_thick_line();
	print_str("Please enter:");
	cin>>i;
	print_thick_line();
	Sleep(500);
	return i;
}

char enter_char()
{
	char i;
	print_thick_line();
	print_str("Please enter:");
	cin>>i;
	print_thick_line();
	Sleep(500);
	return i;
}
