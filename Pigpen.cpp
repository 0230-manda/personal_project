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
		//---------------------------------------------
		// set functions:
		
		void set_random(int i)
		{
			for(int j = 0;j < i;j++)
			{
				add_random_pig(&pigs);
			}
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
		
		void get_all_pigs(node *p)
		{
			link_chain(p,&pigs);
		}
		
		//---------------------------------------------
		// check functions:
		
		
		
		//---------------------------------------------
		// construct functions:
		Pigpen()
		{			
			
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
		
		void end_day()
		{
			chain_end_day(&pigs);
		}
};
