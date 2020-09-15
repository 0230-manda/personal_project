#include<iostream>
#include<windows.h>
#include"Farm.cpp"

using namespace std;

int main()
{
	//-----------------------------------------------------------------------------------------------------
	// datas :
	char oprt;
	bool judge = false;
	bool is_exit = false;
	bool end_loop1 = false;
	int loop_num = 0;
	int oprt_num;
	int oprt_num2;
	int oprt_num3;
	//-----------------------------------------------------------------------------------------------------
	// control sequence :
	//
	//
	// inputs :
	//
	//=================================================
	print_line();
	print_string("Welcome to use the farm simulation program !");
	print_string("Please enter the target weight (in kg) & age (in day) :");
	cout<<"Weight:";
	cin>>main_rule.weight;
	cout<<"Age:";
	cin>>main_rule.age;
	print_line();
	refresh_screen();
	//=================================================
	print_line();
	print_string("Now we have three varieties of pig to captive .");
	print_string("They are Black_pig , Little_pig and Big_white_pig .");
	print_string("We need to know their price per kg .");
	print_string("Please enter them in order .");
	cout<<"Black_pig :";
	cin>>main_rule.price_of_black_pig;
	cout<<"Little_pig :";
	cin>>main_rule.price_of_little_pig;
	cout<<"Big_white_pig :";
	cin>>main_rule.price_of_big_white_pig;
	print_line();
	refresh_screen();
	//=================================================
	print_line();
	print_string("It's your first time to own the farm .");
	print_string("So ther has no pigs in any pigpen .");
	print_string("You can swan your first batch of pigs randomly .");
	print_string("You can choose to swan specified number of pigs .");
	print_string("Or just let it go randomly .");
	print_string("Enter Y/y to swan in a specified number .");
	print_string("Enter N/n to swan randomly");
	print_str("Please enter:");
	for(;;)
	{
		cin>>oprt;
		if(oprt == 'Y' || oprt == 'y')
		{
			judge = false;
			print_str("Now enter the specified number(less than 1000):");
			for(;;)
			{
				cin>>oprt_num;
				if(oprt_num <= 1000 && oprt_num > 0)
				{
					progress_bar();
					main_farm.first_generate_new_pigs(judge,oprt_num);
					main_farm.pig_distributor();
					print_tip("Successfully swaned pigs!");
					cout<<'\n';
					break;
				}
				else
				{
					print_tip("Invalid input!  Please enter less than 1000!");
				}
			}
			
			break;
		}
		else if(oprt == 'N' || oprt == 'n')
		{
			judge = true;
			main_farm.first_generate_new_pigs(judge);
			main_farm.pig_distributor();
			progress_bar();
			print_tip("Successfully swaned pigs!");
			cout<<'\n';
			break;
		}
		else
		{
			print_tip("Invalid input!  Please enter Y/y or N/n!");
		}
	}
	print_line();
	Sleep(500);
	refresh_screen();
	//=================================================
	print_line();
	print_string("Now let's start to keep these pigs!");
	print_string("(By the way , we asume that pigs will die in 10 days if they were ill.)");
	print_line();
	Sleep(3000);
	refresh_screen();
	//
	//
	//-----------------------------------------------------------------------------------------------------
	//
	// loop :
	while(true)
	{
		system("cls");
		if(main_rule.day % 90 == 0 && main_rule.day != 0 && loop_num == 0)
		{
			loop_num++;
			main_farm.sell_pigs();
			print_string("Now start swan new pigs.");
			progress_bar();
			print_line();
			Sleep(500);
			refresh_screen();
			main_farm.generate_new_pigs();
			main_farm.pig_distributor();
			Sleep(500);
			refresh_screen();
		}
		print_thick_line();
		show_basic_info();
		main_farm.show_pig_nums();
		print_thick_line();
		if(main_rule.dead_pig != 0)
		{
			print_line();
			cout<<"There are "<<main_rule.dead_pig<<" pigs died because disease."<<'\n';
			print_line();
			main_rule.dead_pig = 0;
		}
		loop_display();
		oprt = enter_char();
		switch(oprt)
		{
			case '1':
				main_farm.show_all_info();
				system("pause");
				break;
				
				
			case '2':
				for(;;)
				{
					print_string("Now enter the serial number of the pigpen:");
					oprt_num = enter_num();
					if(oprt_num > 100 || oprt_num < 0)
					{
						cout<<'\n'<<'\n';
						print_tip("Invalid input!  Please enter less than 100!");
						cout<<'\n'<<'\n';
					}
					else
					{
						break;
					}
				}
				main_farm.show_pigpen_info(oprt_num);
				system("pause");
				break;
				
				
			case '3':
				for(;;)
				{
					print_string("Now enter the serial number of the pigpen:");
					oprt_num = enter_num();
					if(oprt_num > 100 || oprt_num < 0)
					{
						cout<<'\n'<<'\n';
						print_tip("Invalid input!  Please enter less than 100!");
						cout<<'\n'<<'\n';
					}
					else
					{
						cout<<"There are "<<main_farm.get_pig_num(oprt_num)<<" pigs in the pigpen."<<'\n';
						for(;;)
						{
							print_string("Now enter the serial number of the pig:");
							oprt_num2 = enter_num();
							if(oprt_num2 < 0 || oprt_num2 > main_farm.get_pig_num(oprt_num))
							{
								cout<<'\n'<<'\n';
								print_tip("Invalid input!  Please enter less than ",main_farm.get_pig_num(oprt_num));
								cout<<'\n'<<'\n';
							}
							else
							{
								end_loop1 = true;
								break;
							}
						}
					}
					if(end_loop1)
					{
						end_loop1 = false;
						break;
					}
				}
				cout<<'\n';
				main_farm.show_pigpen_info(oprt_num,oprt_num2);
				system("pause");
				break;
				
				
			case '4':
				main_farm.end_day();
				loop_num = 0;
				break;
				
				
			case '5':
				for(int i = 0;i < 30;i++)
				{
					main_farm.end_day();
				}
				loop_num = 0;
				break;
			
			
			case '6':
				main_farm.set_pig_ill_rand();
				break;
			
			
			case '7':
				print_string("Please enter the variety:");
				print_string("(1 for B_P , 2 for L_P , 3 for B_W_P.)");
				oprt_num = enter_num();
				for(;;)
				{
					if(oprt_num != 1 && oprt_num != 2 && oprt_num != 3)
					{
						print_tip("Invalid input!  Please enter 1 , 2 or 3");
						cout<<'\n'<<'\n';
						oprt_num = enter_num();
					}
					else
					{
						break;
					}
				}
				switch(oprt_num)
				{
					case 1:
						main_farm.show_single_variety_info(Black_Pig);
						break;
						
					case 2:
						main_farm.show_single_variety_info(Little_Pig);
						break;
						
					case 3:
						main_farm.show_single_variety_info(Big_White_Pig);
						break;
				}
				break;
			
			
			default:
				is_exit = true;
				break;
			
		}
		if(is_exit)
		{
			is_exit = false;
			break;
		}
	}
	
	return 0;
}
