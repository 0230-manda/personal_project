#include<iostream>
#include<windows.h>
#include"Farm.cpp"

using namespace std;

int day = 0;

int main()
{
	node  list;
	node list1;
	node list2;
	node list3;
	add_random_pig(&list3);
	add_random_pig(&list1);
	add_random_pig(&list1);
	add_random_pig(&list1);
	add_random_pig(&list1);
	add_random_pig(&list2);
	add_random_pig(&list2);
	add_random_pig(&list2);
	add_random_pig(&list2);
	//out_put_chain(&list1);
	cout<<'\n'<<'\n'<<'\n';
	//out_put_chain(&list2);
	link_chain(&list1,&list2);
	cout<<'\n';
	add_pig(&list1,&list3,*list1.next_node);
	out_put_chain(&list3);
	//main_farm.show_all_info();
	//main_farm.get_all_pigs(&list);
	//main_farm.show_all_info();
	//out_put_chain(&list);
	cout<<'\n'<<'\n';
	main_farm.update_pig_num();
	//cout<<main_farm.b_p_num<<' '<<main_farm.l_p_num<<' '<<main_farm.b_w_p_num<<'\n';
	main_farm.pig_distributor();
	cout<<'\n';
	//-----------------------------------------------------------------------------------------------------
	// control sequence :
	//
	//
	// inputs :
	//
	print_line();
	cout<<"Welcome to use the farm simulation program !";
	cout<<'\n'<<"Please enter the target weight (in kg) & age (in day) :"<<'\n';
	cin>>main_rule.weight>>main_rule.age;
	print_line();
	cout<<'\n'<<'\n';
	Sleep(1000);
	refresh_screen();
	print_line();
	cout<<"Now we have three varieties of pig to captive ."<<'\n';
	cout<<"They are Black_pig , Little_pig and Big_white_pig ."<<'\n';
	cout<<"We need to know their price per kg ."<<'\n';
	cout<<"Please enter them in order ."<<'\n';
	cout<<"Black_pig :";
	cin>>main_rule.price_of_black_pig;
	cout<<"Little_pig :";
	cin>>main_rule.price_of_little_pig;
	cout<<"Big_white_pig :";
	cin>>main_rule.price_of_big_white_pig;
	print_line();
	refresh_screen();
	
	//
	//-----------------------------------------------------------------------------------------------------
	//
	// loop :
	while(true)
	{
		
	}
	
	return 0;
}
