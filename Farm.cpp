#include<iostream>
#include"Pigpen.cpp"


using namespace std;

class Farm
{
	private:
		Pigpen pigpens[100];
		node new_pigs;
		node all_pigs;
		node b_p;
		node n_b_p;
	public:
		int b_p_num;
		int l_p_num;
		int b_w_p_num;
		int total;
		
		//-----------------------------------------
		// get functions :
		
		int get_pig_num(_variety variety)
		{
			int num = 0;
			for(int i = 0;i < 100;i++)
			{
				num += pigpens[i].get_pig_num(variety);
			}
			return num;
		}
		
		int get_pig_num(node *node_head,_variety variety)
		{
			int num = 0;
			node *node_ = node_head;
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
		
		int get_pig_num(int No)
		{
			return pigpens[No - 1].get_pig_num();
		}
		
		void get_all_pigs(node *node_head)
		{
			for(int i = 0;i < 100;i++)
			{
				pigpens[i].get_all_pigs(node_head);
			}
		}
		
		void get_all_pigs(node *node_head,node *new_pig)
		{
			get_all_pigs(node_head);
			link_chain(node_head,new_pig);
		}
		//-----------------------------------------
		// set functions :
		
		void set_pig_ill_rand()
		{
			int i = Random_num.get_rand_num(Random_num.get_seed(),100);
			if(total != 0)
			{
				pigpens[i].set_ill_rand();
			}
		}
		
		//-----------------------------------------
		// check functions :
		
		bool check_full()
		{
			update_pig_num();
			if(total >= 1000)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		//-----------------------------------------
		// construct functions :
		
		Farm()
		{
			for(int i = 0;i < 100;i++)
			{
				pigpens[i];
			}
		}
		
		Farm(int k)
		{
			for(int i = 0;i < 100;i++)
			{
				pigpens[i];
				pigpens[i].set_random(k);
			}
		}
		
		//-----------------------------------------
		// other functions :
		
		int check_float(float f)
		{
			int int_f = (int)f;
			float t = f - int_f;
			if(t > 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		void sort_pig(node *node_head)
		{
			node *node_ = node_head;
			node *temp = node_;
			node_ = node_->next_node;
			for(;;)
			{
				if(check_empty_node(node_))
				{
					break;
				}
				else
				{
					temp = node_;
					if(check_empty_node(temp))
					{
						break;
					}
					else
					{
						node_ = temp->next_node;
					}
					if(temp->pig.get_variety() == Black_Pig)
					{
						add_pig(node_head,&b_p,temp);
					}
					else
					{
						add_pig(node_head,&n_b_p,temp);
					}
				}
			}
		}
		
		void update_pig_num()
		{
			b_p_num = get_pig_num(Black_Pig);
			l_p_num = get_pig_num(Little_Pig);
			b_w_p_num = get_pig_num(Big_White_Pig);
			total = b_p_num + l_p_num + b_w_p_num;
		}
		
		void show_pig_nums()
		{
			update_pig_num();
			cout<<"-- B-P:"<<b_p_num<<"  L-P:"<<l_p_num<<"  B-W-P:"<<b_w_p_num<<"  Total:"<<total<<" --"<<'\n';
		}
		
		void update_pig_num_chain(node *node_head)
		{
			b_p_num = get_pig_num(node_head,Black_Pig);
			l_p_num = get_pig_num(node_head,Little_Pig);
			b_w_p_num = get_pig_num(node_head,Big_White_Pig);
			total = b_p_num + l_p_num + b_w_p_num;
		}
		
		void show_pigpen_info(int No)
		{
			cout<<'\n';
			pigpens[No - 1].show_info(No);
			cout<<'\n';
		}
		
		void show_pigpen_info(int No,int p)
		{
			cout<<'\n';
			pigpens[No - 1].show_info_single(No,p);
			cout<<'\n';
		}
		
		void show_all_info()
		{
			for(int i = 0;i < 100;i++)
			{
				cout<<'\n';
				pigpens[i].show_info(i + 1);
				cout<<'\n';
			}
		}
		
		void end_day()
		{
			for(int i = 0;i < 100;i++)
			{
				if(i == 0)
				{
					if(pigpens[99].check_if_ill() || pigpens[1].check_if_ill())
					{
						if(pigpens[i].has_ill != true)
						{
							pigpens[i].going_to_ill = true;
						}
						else
						{
							pigpens[i].going_to_ill = false;
						}
					}
				}
				else if(i == 99)
				{
					if(pigpens[0].check_if_ill() || pigpens[98].check_if_ill())
					{
						if(pigpens[i].has_ill != true)
						{
							pigpens[i].going_to_ill = true;
						}
						else
						{
							pigpens[i].going_to_ill = false;
						}
					}
				}
				else
				{
					if(pigpens[i - 1].check_if_ill() || pigpens[i + 1].check_if_ill())
					{
						if(pigpens[i].has_ill != true)
						{
							pigpens[i].going_to_ill = true;
						}
						else
						{
							pigpens[i].going_to_ill = false;
						}
					}
				}
			}
			for(int i = 0;i < 100;i++)
			{
				if(pigpens[i].going_to_ill && !pigpens[i].has_ill)
				{
					pigpens[i].set_ill_out();
				}
				else if(!pigpens[i].going_to_ill && pigpens[i].has_ill)
				{
					pigpens[i].set_ill_in();
				}
			}
			for(int i = 0;i < 100;i++)
			{
				pigpens[i].end_day();
			}
			main_rule.day++;
		}
		
		void generate_new_pigs(int max_num = 500)
		{
			int i = Random_num.get_rand_num(Random_num.get_seed(),max_num);
			for(int j = 0;j < i;j++)
			{
				add_random_pig(&new_pigs);
			}
			update_pig_num_chain(&new_pigs);
			print_tip("       Successfully swaned!");
			cout<<'\n'<<'\n';
			print_line();
			cout<<"   Total "<<total<<" pigs swaned!"<<'\n';
			cout<<"     Black_Pig: "<<b_p_num<<" swaned."<<'\n';
			cout<<"     Little_Pig: "<<l_p_num<<" swaned."<<'\n';
			cout<<"     Big_White_Pig: "<<b_w_p_num<<" swaned."<<'\n';
			print_line();
			system("pause");
			refresh_screen();
		}
		
		void first_generate_new_pigs(bool is_rand,int max_num = 500)
		{
			if(!is_rand)
			{
				for(int j = 0;j < max_num;j++)
				{
					add_random_pig(&all_pigs);
				}
			}
			else
			{
				int i = Random_num.get_rand_num(Random_num.get_seed(),max_num);
				for(int j = 0;j < i;j++)
				{
					add_random_pig(&all_pigs);
				}
			}
		}
		
		void sell_pigs()
		{
			main_rule.clear_sold_num();
			for(int i = 0;i < 100;i++)
			{
				pigpens[i].sell_pig();
			}
			print_line();
			if(main_rule.sold_total == 0)
			{
				print_string("---     There has no pig can be sold     ---");
				print_line();
				main_rule.clear_sold_num();
			}
			else
			{
				print_string("---     Pigs sold!     ---");
				cout<<"          Total sold:"<<main_rule.sold_total<<"pigs!"<<'\n';
				cout<<"          Black_Pig: "<<main_rule.sold_b_p<<"sold."<<'\n';
				cout<<"          Little_Pig: "<<main_rule.sold_l_p<<"sold."<<'\n';
				cout<<"          Big_White_Pig: "<<main_rule.sold_b_w_p<<"sold."<<'\n';
				cout<<"          "<<main_rule.sold_money<<"$ earned."<<'\n';
				print_line();
				cout<<'\n'<<'\n';
				main_rule.money += main_rule.sold_money;
				main_rule.clear_sold_num();
				system("pause");
				refresh_screen();
			}
		}
		
		void show_single_variety_info(_variety vari)
		{
			for(int i = 0;i < 100;i++)
			{
				pigpens[i].show_variety(vari);
			}
			system("pause");
		}
		
		void pig_distributor()
		{
			float b_p_cage_num = 0;
			float not_b_p_cage_num = 0;
			get_all_pigs(&all_pigs,&new_pigs);
			update_pig_num_chain(&all_pigs);
			
			b_p_cage_num = (((float)b_p_num / (float)total) * 100.0f);
			b_p_cage_num = check_float(b_p_cage_num) + (int)b_p_cage_num;
			not_b_p_cage_num = 100 - b_p_cage_num;
			
			clear_chain(&b_p);
			clear_chain(&n_b_p);
			
			sort_pig(&all_pigs);
			
			for(;;)
			{
				for(int i = 0;i < b_p_cage_num;i++)
				{
					if(!check_empty_chain(&b_p) && !check_full())
					{
						pigpens[i].add_pig_to(&b_p,b_p.next_node);
					}
					else
					{
						break;
					}
				}
				if(check_empty_chain(&b_p))
				{
					break;
				}
			}
			
			for(;;)
			{
				for(int i = b_p_cage_num;i < 100;i++)
				{
					if(!check_empty_chain(&n_b_p) && !check_full())
					{
						pigpens[i].add_pig_to(&n_b_p,n_b_p.next_node);
					}
					else
					{
						break;
					}
				}
				if(check_empty_chain(&n_b_p))
				{
					break;
				}
			}
		}
};
Farm main_farm;
