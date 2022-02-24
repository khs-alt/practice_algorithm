#include<iostream>

namespace Hybrid
{
	void HybFunc()
	{
		std::cout << "hello" << std::endl;
		std::cout << "hello121" << std::endl;

	}
}

int main()
{
	using Hybrid::HybFunc;
		HybFunc();
	return 0;
}