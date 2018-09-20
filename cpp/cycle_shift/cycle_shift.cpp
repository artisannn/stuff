#include <vector>
#include <memory>
#include <iostream>

void reverse(auto start, auto end)
{
	auto size = end-start;
	end--;
	std::cout <<" reverse (" << *start << ", " << *end << ")"<<std::endl;
	for (int i = 0; i<size/2; ++i)
	{
		std::cout << "swap between : " <<*start << ", " << *end << std::endl;
		auto temp = *start;
		*start = *end;
		*end = temp;
		--end; ++start;
	}
}

void print_vec(auto vec)
{
	for (auto i : vec)
	{
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}

void cycle_shift(auto& vec, int n)
{
	reverse(vec.begin(), vec.begin()+n);
	reverse(vec.begin()+n, vec.end());
	reverse(vec.begin(), vec.end());
}

int main ()
{
	std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
	print_vec(vec);
	//reverse(vec.begin(),vec.end());
	print_vec(vec);
	cycle_shift(vec,3);
	print_vec(vec);
}
