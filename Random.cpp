using namespace std;

class Random
{
	private:
		unsigned long long seed;
	public:
		void set_seed(int i = 1)
		{
			seed = i;
		}
		
		int get_seed()
		{
			seed += get_rand_num(seed,13);
			return seed;
		}
		
		int get_rand_num(int _seed_,int digit)
		{
			unsigned seed_;
			int rand_num = 0;
			seed_ = getpid();
			srand(seed_ + _seed_);
			rand_num = rand() % digit + 1;
			return rand_num;
		}
		
		Random(int i = 1)
		{
			seed = i;
		}
};

Random Random_num;
