#include <iostream>

int main (int argc, char* argv[])
{// section below dedicated to dirty hack to modify character in string value
/****************************************************************************/
	std::string s = "Haaay, maaaan!";
	std::cout<<" s :" << s << std::endl;
	s[0]++;
	std::cout<<" s  modif :" << s << std::endl;
	s[0]++;
	std::cout<<" s  modif :" << s << std::endl;
	s[0]++;
	std::cout<<" s  modif :" << s << std::endl;
	const std::string f("Hey!");
	const std::string fa(&++(std::string(f)[0]));
	std::cout<<"  fa :" << fa << std::endl;
	std::cout<<"  f[0] :" << f[0] << std::endl;
/****************************************************************************/
	std::cout<<"**********************************************************************************"<< std::endl;
	std::cout<<" Hello, this is test function"<< std::endl;
	std::cout<<" argc adress :" << &argc << std::endl;
	std::cout<<" argv adress :" << &argv << std::endl;
	std::cout<<"**********************************************************************************" << std::endl;	
	std::string hxstr("01234567890A0B0C0D0E0F9");
	std::cout<<" hxstr          :"<< hxstr << std::endl;
	
	for (int i = 0; i <= hxstr.length(); i++)
	{
		//std::cout<<std::hex<<" i :" << i%50 << std::endl;
		hxstr[i]=='9' || hxstr[i]=='F'? hxstr[i] =--hxstr[i]:1;
	}
	std::cout<<" hxstr modified :" << hxstr << std::endl;
	return 0;
}
