using namespace std;

struct node
{
	Pig pig;
	bool is_first_node;
	node* next_node;
	node* first_node;
	
	node()
	{
		pig;
		pig.set_pig_empty();
		is_first_node = false;
		next_node = nullptr;
		first_node = nullptr;
	}
	
	bool operator == (node p)
	{
		if(this->first_node == p.first_node && this->pig == p.pig && this->next_node == p.next_node)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
//=========================================================
// function table :
bool check_empty_node(node* p);
bool check_empty_chain(node *node_head);
bool check_conflict(node *node_head,Pig p);
bool check_ill(node *node_head);

int get_node_num(node *node_head);

void ill_in(node *node_head);
void ill_out(node *node_head);
void add_random_pig(node *node_head);
void add_pig(node *from_node,node *node_head,node *oprt_node);
void delete_node(node *node_head,node oprt_node);
void remove_node(node *node_head,node *oprt_node);
void sell_chain(node *node_head);
void sell_single(node *node_head,node oprt_node);
void out_put_chain(node *node_head);
void chain_end_day(node *node_head);
void link_chain(node *head_parent,node *head_son);
void clear_chain(node *node_head);
void show_single_info(node *node_head,int p);
void show_variety_info(node *node_head,_variety variety);
//=========================================================
node *head = nullptr;


bool check_empty_node(node* p)
{
	if(p == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_empty_chain(node *node_head)
{
	node *node_ = node_head;
	if(node_->next_node == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_conflict(node *node_head,Pig p) // return true if there has no conflict
{
	node *node_ = node_head;
	bool is_conflicted = false;
	if(node_head->next_node == nullptr) // if the chain list is empty
	{
		return false;
	}
	else
	{
		node_ = node_->next_node;
		if(p.get_variety() == Black_Pig)
		{
			for(;;)
			{
				if(node_->pig.get_variety() != Black_Pig)
				{
					is_conflicted = true;
				}
				if(node_->next_node != nullptr)
				{
					node_ = node_->next_node;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			for(;;)
			{
				if(node_->pig.get_variety() == Black_Pig)
				{
					is_conflicted = true;
				}
				if(node_->next_node != nullptr)
				{
					node_ = node_->next_node;
				}
				else
				{
					break;
				}
			}
		}
	}
	return is_conflicted;
}

bool check_ill(node *node_head)
{
	node *node_ = node_head;
	bool ill = false;
	node_ = node_->next_node;
	for(;;)
	{
		if(node_ != nullptr)
		{
			if(node_->pig.get_if_sick())
			{
				ill = true;
			}
			node_ = node_->next_node;
		}
		else
		{
			break;
		}
	}
	return ill;
}

void ill_in(node *node_head)
{
	int t = 0;
	node *node_ = node_head;
	for(;;)
	{
		if(node_ != nullptr)
		{
			t = Random_num.get_rand_num(Random_num.get_seed(),100);
			if(t >= 50)
			{
				node_->pig.set_sick(true);
			}
			node_ = node_->next_node;
		}
		else
		{
			break;
		}
	}
}

void ill_out(node *node_head)
{
	int t = 0;
	node *node_ = node_head;
	for(;;)
	{
		if(node_ != nullptr)
		{
			t = Random_num.get_rand_num(Random_num.get_seed(),100);
			if(t <= 15)
			{
				node_->pig.set_sick(true);
			}
			node_ = node_->next_node;
		}
		else
		{
			break;
		}
	}
}

void add_random_pig(node *node_head)
{
	
	head = node_head;
	head->first_node = head;
	head->is_first_node = true;
	
	node *node_ = new node;
	node_->pig;
	node_->pig.set_pig(Random_num.get_seed());
	node_->is_first_node = false;
	
	if(check_empty_node(head))
	{
		head = new node;
		head->pig;
		head->pig.set_pig(Random_num.get_seed());
		head->first_node = head;
	}
	else
	{
		for(;;)
		{
			if(head->next_node != nullptr)
			{
				head = head->next_node;
			}
			else
			{
				break;    // find the last node
			}
		}
		
		node_->first_node = head->first_node;
		head->next_node = node_;
		head = head->first_node;
	}
}

void add_pig(node *from_node,node *node_head,node *oprt_node)
{
	remove_node(from_node,oprt_node);
	node *node_ = node_head;
	node_->first_node = node_head;
	node *temp = node_;
	
	if(check_empty_node(node_->next_node))
	{
		node_->next_node = oprt_node;
		node_ = node_->next_node;
		node_->next_node = nullptr;
		node_->first_node = node_head;
	}
	else
	{
		node_ = node_->next_node;
		node_->first_node = temp->first_node;
		
		for(;;)
		{
			if(node_->next_node == nullptr) // if found the last node
			{
				node_->next_node = oprt_node;
				oprt_node->first_node = node_head;
				oprt_node->next_node = nullptr;
				break;
			}
			else
			{
				temp = node_;
				node_= node_->next_node;
				node_->first_node = temp->first_node;
			}
		}
	}
}

void delete_node(node *node_head,node oprt_node)
{
	node *node_ = node_head;
	node *temp = node_;
	if(node_->next_node == nullptr)
	{
		
	}
	else
	{
		node_ = node_->next_node;
		for(;;)
		{
			if(*node_ == oprt_node)
			{
				temp->next_node = node_->next_node;
				delete node_;
				break;
			}
			else
			{
				if(node_ != nullptr)
				{
					temp = node_;
					node_ = node_->next_node;
				}
				else
				{
					break;
				}
			}
		}
	}
}

void remove_node(node *node_head,node *oprt_node)
{
	node *node_ = node_head;
	node *temp = node_;
	if(node_->next_node == nullptr)
	{
		
	}
	else
	{
		node_ = node_->next_node;
		for(;;)
		{
			if(*node_ == *oprt_node)
			{
				temp->next_node = node_->next_node;
				oprt_node->next_node = nullptr;
				oprt_node->first_node = nullptr;
				break;
			}
			else
			{
				if(node_ != nullptr)
				{
					temp = node_;
					node_ = node_->next_node;
				}
				else
				{
					break;
				}
			}
		}
	}
}

void sell_chain(node *node_head)
{
	node *node_ = node_head;
	if(node_->next_node == nullptr)
	{
		
	}
	else
	{
		node_ = node_->next_node;
		for(;;)
		{
			if(node_ != nullptr)
			{
				switch(node_->pig.get_variety())
				{
					case Black_Pig:
						if(node_->pig.get_weight() > main_rule.weight || node_->pig.get_age() > main_rule.age)
						{
							if(node_->pig.get_if_sick() != true)
							{
								main_rule.sold_money += node_->pig.get_weight() * main_rule.price_of_black_pig;
								main_rule.sold_b_p++;
								delete_node(node_head,*node_);
							}	
						}
						
						break;
						
					case Little_Pig:
						if(node_->pig.get_weight() > main_rule.weight || node_->pig.get_age() > main_rule.age)
						{
							if(node_->pig.get_if_sick() != true)
							{
								main_rule.sold_money += node_->pig.get_weight() * main_rule.price_of_little_pig;
								main_rule.sold_l_p++;
								delete_node(node_head,*node_);
							}
						}
						
						break;
						
					case Big_White_Pig:
						if(node_->pig.get_weight() > main_rule.weight || node_->pig.get_age() > main_rule.age)
						{
							if(node_->pig.get_if_sick() != true)
							{
								main_rule.sold_money += node_->pig.get_weight() * main_rule.price_of_big_white_pig;
								main_rule.sold_b_w_p++;
								delete_node(node_head,*node_);
							}
						}
						
						break;
						
					default:
						break;
				}
				node_ = node_->next_node;
			}
			else
			{
				main_rule.sold_total = main_rule.sold_b_w_p + main_rule.sold_l_p + main_rule.sold_b_p;
				break;
			}
		}
	}
}

void sell_single(node *node_head,node oprt_node)
{
	node *node_ = node_head;
	node *temp = node_;
	if(node_head == nullptr)
	{
		
	}
	else
	{
		node_ = node_->next_node;
		for(;;)
		{
			if(node_->pig == oprt_node.pig && node_ != nullptr)
			{
				if(node_->pig.get_weight() > main_rule.weight)
				{
					switch(node_->pig.get_variety())
					{
						case Black_Pig:
							if(node_->pig.get_weight() > main_rule.weight)
							{
								main_rule.money += node_->pig.get_weight() * main_rule.price_of_black_pig;
							}
							
							break;
							
						case Little_Pig:
							if(node_->pig.get_weight() > main_rule.weight)
							{
								main_rule.money += node_->pig.get_weight() * main_rule.price_of_little_pig;
							}
							
							break;
							
						case Big_White_Pig:
							if(node_->pig.get_weight() > main_rule.weight)
							{
								main_rule.money += node_->pig.get_weight() * main_rule.price_of_big_white_pig;
							}
							
							break;
							
						default:
							break;
					}
					temp->next_node = node_->next_node;
					delete node_;
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(node_ != nullptr)
				{
					temp = node_;
					node_ = node_->next_node;
				}
				else
				{
					break;
				}
			}
		}
	}
}

void out_put_chain(node *node_head)
{
	node *node_ = node_head;
	int i = 1;
	if(node_->next_node == nullptr)
	{
		cout<<"this pigpen is empty"<<'\n';
	}
	else
	{
		node_ = node_->next_node;
		for(;;)
		{
			if(node_ != nullptr)
			{
				if(node_->is_first_node == false)
				{
					cout<<'#'<<i<<':';
					if(i != 10)
					{
						cout<<' ';
					}
					node_->pig.show_info();
					cout<<'\n';
					i++;
				}
				
				node_ = node_->next_node;
			}
			else
			{
				break;
			}
		}
	}
	
}

int get_node_num(node *node_head)
{
	int num = 0;
	node *node_ = node_head;
	if(node_head->next_node == nullptr)
	{
		return num;
	}
	else
	{
		for(;;)
		{
			if(node_->next_node != nullptr)
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

void chain_end_day(node *node_head)
{
	node *node_ = node_head;
	node *temp = node_;
	if(get_node_num(node_head) == 0)
	{
		
	}
	else
	{
		temp = node_;
		node_ = node_->next_node;
		for(;;)
		{
			if(temp != nullptr)
			{
				temp = node_;
				if(node_ != nullptr)
				{
					node_ = node_->next_node;
				}
				if(temp != nullptr)
				{
					temp->pig.gain_weight(Random_num.get_seed());
					if(temp->pig.get_if_sick())
					{
						temp->pig.sick_day_plus(1);
					}
					if(temp->pig.get_if_die())
					{
						remove_node(node_head,temp);
						main_rule.dead_pig++;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
}

void link_chain(node *head_parent,node *head_son) // link son chain to the end of parent chain
{
	node *parent = head_parent;
	node *son = head_son;
	if(check_empty_node(parent) && check_empty_node(son))
	{
		
	}
	else
	{
		if(check_empty_node(parent->next_node))
		{
			parent->next_node = son->next_node;
			son->next_node = nullptr;
			parent = head_parent->next_node;
			for(;;)
			{
				if(parent != nullptr)
				{
					parent->first_node = head_parent;
					parent = parent->next_node;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			for(;;)
			{
				if(parent->next_node != nullptr)
				{
					parent = parent->next_node; // find the last node
				}
				else
				{
					parent->next_node = son->next_node;
					son->next_node = nullptr;
					parent = head_parent->next_node;
					for(;;)
					{
						if(parent != nullptr)
						{
							parent->first_node = head_parent;
							parent = parent->next_node;
						}
						else
						{
							break;
						}
					}
					break;
				}
			}
		}
	}
}

void clear_chain(node *node_head)
{
	node *node_ = node_head->next_node;
	node *temp = node_;
	for(;;)
	{
		if(node_ == nullptr)
		{
			break;
		}
		else
		{
			temp = node_;
			node_ = node_->next_node;
			delete_node(node_head,*temp);
		}
	}
}

void show_single_info(node *node_head,int p)
{
	node *node_ = node_head;
	for(int i = 0;i < p;i++)
	{
		node_ = node_->next_node;
	}
	if(p != 10)
	{
		cout<<'#'<<p<<':'<<' ';
	}
	else
	{
		cout<<'#'<<p<<':';
	}
	node_->pig.show_info();
	cout<<'\n';
}

void show_variety_info(node *node_head,_variety variety)
{
	node *node_ = node_head;
	for(;;)
	{
		if(node_ != nullptr)
		{
			if(node_->pig.get_variety() == variety)
			{
				node_->pig.show_info();
				cout<<'\n';
			}
			node_ = node_->next_node;
		}
		else
		{
			break;
		}
	}
}
