#include<iostream>
#include"Pig.cpp"
#include"Data_Manipulation.cpp"

using namespace std;

class Pigpen
{
	private:
		//----------------------------------------------
		// datas:
		node pigs;
		
	public:
		bool going_to_ill;
		bool has_ill;
		
		//---------------------------------------------
		// set functions:
		
		void set_ill_rand()
		{
			node *node_ = &pigs;
			int k = Random_num.get_rand_num(Random_num.get_seed(),Pigpen::get_pig_num());
			for(int i = 0;i < k;i++)
			{
				node_ = node_->next_node;
			}
			node_->pig.set_sick(true);
		}
		
		void set_random(int i)
		{
			for(int j = 0;j < i;j++)
			{
				add_random_pig(&pigs);
			}
		}
		
		void set_ill_in()
		{
			ill_in(&pigs);
		}
		
		void set_ill_out()
		{
			ill_out(&pigs);
		}
		
		//---------------------------------------------
		// get functions:
		
		int get_pig_num(_variety variety)
		{
			int num = 0;
			node *node_ = &pigs;
			if(node_->next_node == nullptr)
			{
				return num;
			}
			else
			{
				node_ = node_->next_node;
				for(;;)
				{
					if(node_ != nullptr) // if current node isn't empty
					{
						if(node_->pig.get_variety() == variety)
						{
							num++;
						}
						node_ = node_->next_node;
					}
					else
					{
						break;
					}
				}
				return num;
			}
		}
		
		int get_pig_num()
		{
			int num = 0;
			node *node_ = &pigs;
			if(node_->next_node == nullptr)
			{
				return num;
			}
			else
			{
				node_ = node_->next_node;
				for(;;)
				{
					if(node_ != nullptr) // if current node isn't empty
					{
						num++;
						node_ = node_->next_node;
					}
					else
					{
						break;
					}
				}
				return num;
			}
		}
		
		void get_all_pigs(node *p)
		{
			link_chain(p,&pigs);
		}
		
		//---------------------------------------------
		// check functions:
		
		bool check_if_ill()
		{
			return check_ill(&pigs);
		}
		
		//---------------------------------------------
		// construct functions:
		Pigpen()
		{
			going_to_ill = false;
			has_ill = false;
		}
		Pigpen(int i)
		{
			for(int j = 0;j < i;j++)
			{
				add_random_pig(&pigs);
			}
		}
		//---------------------------------------------
		// other functions:
		void show_info(int No)
		{
			print_thick_line();
			cout<<"The info of No."<<No<<" Pigpen are as below :"<<'\n';
			cout<<'\n';
			out_put_chain(&pigs);
			print_thick_line();
			cout<<'\n'<<'\n';
		}
		
		void sell_pig()
		{
			sell_chain(&pigs);
		}
		
		void show_info_single(int No,int p)
		{
			print_thick_line();
			cout<<"The info of No."<<p<<" Pig in No"<<No<<" Pigpen is as below :"<<'\n';
			cout<<'\n';
			show_single_info(&pigs,p);
			print_thick_line();
		}
		
		void add_pig_to(node *from,node *oprt)
		{
			add_pig(from,&pigs,oprt);
		}
		
		void end_day()
		{
			chain_end_day(&pigs);
		}
		
		void show_variety(_variety vari)
		{
			show_variety_info(&pigs,vari);
		}
};
