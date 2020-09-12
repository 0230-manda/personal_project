#include<iostream>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
#include"Random.cpp"
#include"Format.cpp"

using namespace std;

enum _variety
{
	Empty,
	Black_Pig,
	Little_Pig,
	Big_White_Pig
};

class Pig
{
	private:
		//---------------------------------------------------
		// datas:
		//
		float weight;
		int age;
		_variety variety;
		bool is_sick;
		//
		//---------------------------------------------------
		// private functions:
		
		float random_num(int i)
		{
			unsigned seed_;
			int rand_num = 0;
			seed_ = getpid();
			srand(seed_ + i);
			rand_num = rand() % 100 + 1;
			return rand_num / 100.0f;
		}
		
		_variety random_vari(int i)
		{
			unsigned seed_;
			_variety temp_var;
			int rand_num = 0;
			seed_ = getpid();
			srand(seed_ + i);
			rand_num = rand() % 3 + 1;
			
			switch(rand_num)
			{
				case 1:
					temp_var = Black_Pig;
					break;
				case 2:
					temp_var = Little_Pig;
					break;
				case 3:
					temp_var = Big_White_Pig;
					break;
				default:
					temp_var = Empty;
			}
			
			return temp_var;
		}
		
	public:
		
		
		//---------------------------------------------------
		// set-functions:
		
		void set_sick(bool i)
		{
			this->is_sick = i;
		}
		
		void set_weight(float weight)
		{
			this->weight = weight;
		}
		
		void set_age(int age)
		{
			this->age = age;
		}
		
		void set_variety(_variety variety_)
		{
			this->variety = variety_;
		}
		
		void set_pig(int seed_)
		{
			this->age = 0;
			this->weight = 20 + 30 * random_num(seed_);
			this->variety = random_vari(seed_);
		}
		
		void set_pig_empty()
		{
			age = 0;
			weight = 0;
			variety = Empty;
		}
		
		//---------------------------------------------------
		// get-functions:
		
		bool get_if_sick()
		{
			return is_sick;
		}
		
		float get_weight()
		{
			return weight;
		}
		
		int get_age()
		{
			return age;
		}
		
		_variety get_variety()
		{
			return variety;
		}
		
		//---------------------------------------------------
		// check-functions:
		
		bool check_weight(float wei_)
		{
			if(weight > wei_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		bool check_age(int age_)
		{
			if(age > age_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		bool check_empty()
		{
			if(variety == Empty)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		bool check_conflict_pigs(Pig p)
		{
			// return true when there has conflict.
			_variety vari_p;
			vari_p = p.get_variety();
			if(variety == Black_Pig)
			{
				if(vari_p == Black_Pig)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			if(variety != Black_Pig)
			{
				if(vari_p != Black_Pig)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		
		//---------------------------------------------------
		// constructor
		
		Pig()
		{
			weight = 0;
			age = 0;
			is_sick = false;
			variety = Empty;
		}
		
		Pig(int i,_variety vari,int seed_)
		{
			float temp = random_num(seed_);
			weight = 20 + 30 * temp;
			age = i;
			variety = vari;
			is_sick = false;
		}
		
		Pig(int seed_,bool is_rand)
		{
			if(is_rand)
			{
				weight = 20 + 30 * random_num(seed_);
				age = 0;
				variety = random_vari(seed_);
				is_sick = false;
			}
			else
			{
				weight = 0;
				age = 0;
				variety = Empty;
				is_sick = false;
			}
		}
		
		//---------------------------------------------------
		// other-functions:
		
		void gain_weight(int seed_)
		{
			if(this->variety != Empty)
			{
				float temp = random_num(seed_);
				weight += temp * 1.2;
				age++;
			}
		}
		
		void show_info()
		{
			cout<<"Variety: ";
			switch(variety)
			{
				case Empty:
					cout<<"Null ";
					break;
				case Black_Pig:
					cout<<"B-P  ";
					break;
				case Little_Pig:
					cout<<"L-P  ";
					break;
				case Big_White_Pig:
					cout<<"B-W-P";
					break;
			}
			if(variety != Empty)
			{
				cout<<", Weight: "<<weight<<"kg , Age: "<<age<<"day ";
				if(is_sick)
				{
					cout<<" Sick";
				}
				else
				{
					cout<<" Healthy";
				}
			}
		}
		
		bool operator == (Pig p)
		{
			if(this->age == p.get_age() && this->variety == p.get_variety() && this->weight == p.get_weight() && this->is_sick == p.get_if_sick())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

