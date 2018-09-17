#include <iostream>
#include <memory>
int main ()
{
	int un;
	// Это русский текст std::unique_ptr<int> uptr1(&un); // segfault!! Äåñòðóêòîð uptr1 âûçîâåò äåñòðóêòîð int, à î. ñî ñòýêà ñàìîìó óäàëÿòü íåëüçÿ!(ïåðåìåííàÿ un ëåæèò íà ñòåêå)
	std::unique_ptr<int> uptr1(new int(1));	
	std::unique_ptr<int> uptr2(new int(2));

	std::unique_ptr<int> uptr3;
	//uptr3 = uptr2; 		// îøèáêà êîìïèëÿöèè!
	uptr3 = std::move(uptr2);	// òåïåðü uptr3 ññûëàåòñÿ òóäà æå êóäà è ññûëàëñÿ uptr2, à uptr2 íà null

	std::cout<<"uptr1--> "<<*uptr1<<std::endl;
	//std::cout<<"uptr2--> "<<*uptr2<<std::endl; // segfault!!
	std::cout<<"uptr3--> "<<*uptr3<<std::endl;

	uptr1.reset(); // òàê æå óäàëèòü î. ìîæíî ñ ïîìîùüþ ýòîé ôóíêöèè, à uptr1 ññûëàåòñÿ íà null
	uptr2.reset();
	uptr3.reset();

	std::shared_ptr<int> sptr1(new int(1000));
	std::shared_ptr<int> sptr2 = sptr1;

	std::cout<<"sptr1--> "<<*sptr1<<std::endl; // Äåñòðóêòîð ýòîãî êëàññà íå óäàëèò î. íà êîòîðûé ññûëàåòñÿ, è ëèøü óìåíüøèò ñ÷åò÷èê ññûëîê íà íåãî. Òàê æå ïîñòóïèò è ìåòîä reset.
	std::cout<<"sptr2--> "<<*sptr2<<std::endl;

	std::weak_ptr<int> wptr(new int(2000));
	sptr1.reset();
	sptr1 = wptr.lock(); 	// âîçâðàùàåò î. êëàññà shared_ptr åñëè î. åùå ñóùåòñâóåò
				// è âîçâð-ò null åñëè î. óæå íåò

	sptr1.reset();	// Çäåñü óíè÷òîæèëè ïîñëåäíþþ ññûëêó íà î."2000"
			// åñëè çäåñü âûçâàòü wptr.lock(), òî òåïåðü îí âåðíåò null

	return 0;
}
