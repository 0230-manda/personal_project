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
		
		void sort_pig(node *node_head)
		{
			node *node_ = node_head;
			node *temp = node_;
			node_ = node_->next_node;
			node *a = &b_p;
			node *b = &n_b_p;
			for(;;)
			{
				if(check_empty_node(node_->next_node))
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
						add_pig(node_head,a,*temp);
					}
					else
					{

						add_pig(node_head,b,*temp);
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
				pigpens[i].end_day();
				main_rule.day++;
			}
		}
		
		void generate_new_pigs(int max_num = 100)
		{
			int i = Random_num.get_rand_num(Random_num.get_seed(),max_num);
			for(int j = 0;j < i;j++)
			{
				add_random_pig(&new_pigs);
			}
		}
		
		void first_generate_new_pigs(int max_num = 500)
		{
			int i = Random_num.get_rand_num(Random_num.get_seed(),max_num);
			for(int j = 0;j < i;j++)
			{
				add_random_pig(&all_pigs);
			}
		}
		
		void pig_distributor()
		{
			int b_p_cage_num = 0;
			int not_b_p_cage_num = 0;
			get_all_pigs(&all_pigs,&new_pigs);
			update_pig_num_chain(&all_pigs);
			cout<<b_p_num<<' '<<l_p_num<<' '<<b_w_p_num<<'\n';
			
			b_p_cage_num = (int)((b_p_num / total) * 100);
			not_b_p_cage_num = 100 - b_p_cage_num;
			clear_chain(&b_p);
			clear_chain(&n_b_p);
			sort_pig(&all_pigs);
			
			cout<<b_p_cage_num<<"  "<<not_b_p_cage_num;
		}
};
Farm main_farm(2);
