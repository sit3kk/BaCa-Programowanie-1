#include <iostream>




const unsigned char MAX = 128;
const unsigned short MAXQ = 65535;

unsigned long long all_stuff = 0;

struct Place
{
	unsigned short quantity;
	unsigned char label;
	bool labeled;
	Place();
	void put(unsigned int a);
	void pop(unsigned short a);
	void showlabel();
	void setlabel(unsigned char dd);
	void move(Place* p2, unsigned short a);
	
	
};

void Place::move(Place* p2, unsigned short a)
{
	if (a > quantity) a = quantity;

	if (p2->quantity + a > MAXQ) a = MAXQ - p2->quantity;

	quantity -= a;
	p2->quantity += a;
}


void Place::pop(unsigned short a)
{
	if (quantity - a < 0)
	{
		all_stuff -= quantity;
		quantity = 0;
	}
	else
	{
		all_stuff -= a;
		quantity -= a;
		
	}
}

void Place::setlabel(unsigned char dd)
{

	labeled = true;
	label = dd;
}

void Place::showlabel()
{
	if (labeled == false) std::cout << "--" << '\n';
	else
	{
		if (label >= 10) std::cout << (int)label << '\n';
		else std::cout << "0" << (int)label << '\n';
	}
}


Place::Place()
{
	quantity = 0;
	label = '\0';
	labeled = false;
}

void Place::put(unsigned int a)
{

	if (quantity + a > MAXQ)
	{
		all_stuff += MAXQ - quantity;
		quantity = MAXQ;
	}
	else
	{
		quantity += a;
		all_stuff += a;
	}

}


struct Shelf
{
	unsigned char size;
	Place places[MAX];
	Shelf();

	void set(unsigned char p);
	int get();

};


int Shelf::get()
{
	unsigned int shelf_sum = 0;
	for (int i = 0; i < size; i++) shelf_sum += places[i].quantity;

	return shelf_sum;
}
Shelf::Shelf()
{
	size = 0;
}



void Shelf::set(unsigned char p)
{
	for (unsigned char i = size; i < p; i++)
	{
		all_stuff -= places[i].quantity;
		places[i].quantity = 0;
		places[i].labeled = false;
		places[i].label = '\0';
	}

	for (unsigned char i = p; i < size; i++)
	{
		all_stuff -= places[i].quantity;
		places[i].quantity = 0;
		places[i].labeled = false;
		places[i].label = '\0';
		
	}

	size = p;

}




struct Rack
{
	unsigned char size;
	Shelf shelfs[MAX];
	Rack();

	void set(unsigned char s, unsigned char p);
	int get();

};


int Rack::get()
{
	unsigned int rack_sum = 0;

	for (unsigned char i = 0; i < size; i++) rack_sum += shelfs[i].get();

	return rack_sum;
}

Rack::Rack()
{
	size = 0;

}

void Rack::set(unsigned char s, unsigned char p)
{
	for (unsigned char i = 0; i < s; i++) shelfs[i].set(p);
	for (unsigned char i = s; i < size; i++) shelfs[i].set(0);

	size = s;
}

struct Warehouse
{
	unsigned char size;
	Rack racks[MAX];
	Shelf handyshelf;

	Warehouse();

	void set(unsigned char r, unsigned char s, unsigned char p);
	unsigned long long get();


};

unsigned long long Warehouse::get()
{
	unsigned long long warehouse_sum = 0;

	warehouse_sum += handyshelf.get();

	for (unsigned char i = 0; i < size; i++) warehouse_sum += racks[i].get();

	return warehouse_sum;

}

Warehouse::Warehouse()
{
	size = 0;
}

void Warehouse::set(unsigned char r, unsigned char s, unsigned char p)
{
	for (unsigned char i = 0; i < r; i++) racks[i].set(s, p);

	for (unsigned char i = r; i < size; i++) racks[i].set(0, 0);

	size = r;
}

struct Storehouse
{
	unsigned char size;
	Warehouse warehouses[MAX];
	Storehouse();

	Rack handyrack;
	Shelf handyshelf;

	void set(unsigned char w, unsigned char r, unsigned char s, unsigned char p);
	void fill(unsigned char w, unsigned char r, unsigned char s, unsigned char p, unsigned short a);
	unsigned long long get();

};


unsigned long long Storehouse::get()
{
	return all_stuff;
}



Storehouse::Storehouse()
{
	size = 0;
}

void Storehouse::set(unsigned char w, unsigned char r, unsigned char s, unsigned char p)
{
	for (unsigned char i = 0; i < w; i++) warehouses[i].set(r, s, p);
	for (unsigned char i = w; i < size; i++) warehouses[i].set(0, 0, 0);

	size = w;


}



void Storehouse::fill(unsigned char w, unsigned char r, unsigned char s, unsigned char p, unsigned short a)
{
	all_stuff = 0;

	size = w;
	if (a > MAXQ) a = MAXQ;

	for (unsigned char i = 0; i < w; i++)
	{
		warehouses[i].size = r;

		warehouses[i].handyshelf.size = p;

		for (unsigned char j = 0; j < p; j++)
		{
			warehouses[i].handyshelf.places[j].label = '\0';
			warehouses[i].handyshelf.places[j].labeled = false;
			warehouses[i].handyshelf.places[j].quantity = a;
			all_stuff += a;
		}

		

		for (unsigned char j = 0; j < r; j++)
		{
			warehouses[i].racks[j].size = s;

			for (unsigned char k = 0; k < s; k++)
			{
				warehouses[i].racks[j].shelfs[k].size = p;

				for (unsigned char l = 0; l < p; l++)
				{
				
					warehouses[i].racks[j].shelfs[k].places[l].label = '\0';
					warehouses[i].racks[j].shelfs[k].places[l].labeled = false;
					warehouses[i].racks[j].shelfs[k].places[l].quantity = a;
					all_stuff += a;
				}
			}
		}
	}


	handyrack.size = s;
	for (unsigned char j = 0; j < s; j++)
	{
		handyrack.shelfs[j].size = p;
		for (unsigned char k = 0; k < p; k++)
		{
			handyrack.shelfs[j].places[k].label = '\n';
			handyrack.shelfs[j].places[k].labeled = false;
			handyrack.shelfs[j].places[k].quantity = a;
			all_stuff += a;
		}

	}

	handyshelf.size = p;
	for (unsigned char j = 0; j < p; j++)
	{
		handyshelf.places[j].label = '\0';
		handyshelf.places[j].labeled = false;
		handyshelf.places[j].quantity = a;
		all_stuff += a;
	}

}


int main()
{
	std::string command = "";
	static Storehouse storehouse;
	unsigned int w, r, s, p, a;
	unsigned short dd;



	while (std::cin >> command)
	{
		if (command.substr(0, 4) == "FILL")
		{
			std::cin >> w >> r >> s >> p >> a;
			if (w > MAX || r > MAX || s > MAX || p > MAX) std::cout << "error" << '\n';
			else storehouse.fill(w, r, s, p, a);
		}
		else if (command.substr(0, 4) == "SET-")
		{
			if (command[4] == 'A')
			{
				std::cin >> w >> r >> s >> p;
				if (w > MAX || r > MAX || s > MAX || p > MAX) std::cout << "error" << '\n';
				else
				{
					if (command[5] == 'P')
					{
						if (w >= storehouse.size || r >= storehouse.warehouses[w].size || s >= storehouse.warehouses[w].racks[r].size) std::cout << "error" << '\n';
						else storehouse.warehouses[w].racks[r].shelfs[s].set(p);

					}
					else if (command[5] == 'S')
					{
						if (w >= storehouse.size || r >= storehouse.warehouses[w].size) std::cout << "error" << '\n';
						else storehouse.warehouses[w].racks[r].set(s, p);

					}
					else if (command[5] == 'R')
					{
						if (w >= storehouse.size) std::cout << "error" << '\n';
						else storehouse.warehouses[w].set(r, s, p);

					}
					else if (command[5] == 'W')
					{
						storehouse.set(w, r, s, p);
					}

				}
			}
			else if (command[4] == 'H')
			{
				if (command[5] == 'W')
				{
					std::cin >> w >> p;
					if (w >= storehouse.size || p > MAX) std::cout << "error" << '\n';
					else storehouse.warehouses[w].handyshelf.set(p);
				}
				else if (command[5] == 'R')
				{
					std::cin >> s >> p;
					if (s > MAX || p > MAX) std::cout << "error" << '\n';
					else storehouse.handyrack.set(s, p);
				}
				else if (command[5] == 'S')
				{
					std::cin >> p;
					if (p > MAX) std::cout << "error" << '\n';
					else storehouse.handyshelf.set(p);
				}
			}
			else if (command[4] == 'L')
			{
				if (command[5] == 'W')
				{
					std::cin >> w >> r >> s >> p >> dd;
					if (w >= storehouse.size || r >= storehouse.warehouses[w].size || s >= storehouse.warehouses[w].racks[r].size || p >= storehouse.warehouses[w].racks[r].shelfs[s].size || dd > 99) std::cout << "error" << '\n';
					else storehouse.warehouses[w].racks[r].shelfs[s].places[p].setlabel(dd);

				}
				else if (command[5] == 'H')
				{
					std::cin >> w >> p >> dd;
					if (w >= storehouse.size || p >= storehouse.handyshelf.size || dd > 99) std::cout << "error" << '\n';
					else storehouse.warehouses[w].handyshelf.places[p].setlabel(dd);
				}
				else if (command[5] == 'R')
				{
					std::cin >> s >> p >> dd;
					if (s >= storehouse.handyrack.size || p >= storehouse.handyrack.shelfs[s].size || dd > 99) std::cout << "error" << '\n';
					else storehouse.handyrack.shelfs[s].places[p].setlabel(dd);
				}
				else if (command[5] == 'S')
				{
					std::cin >> p >> dd;
					if (p >= storehouse.handyshelf.size || dd > 99) std::cout << "error" << '\n';
					else storehouse.handyshelf.places[p].setlabel(dd);
				}
				

			}
		}
		else if (command.substr(0, 4) == "PUT-")
		{
			if (command[4] == 'W')
			{
				std::cin >> w >> r >> s >> p >> a;
				if (w >= MAX || r >= MAX || s >= MAX || p >= MAX) std::cout << "error" << '\n';
				else
				{
					if (w >= storehouse.size || r >= storehouse.warehouses[w].size || s >= storehouse.warehouses[w].racks[r].size || p >= storehouse.warehouses[w].racks[r].shelfs[s].size) std::cout << "error" << '\n';
					else storehouse.warehouses[w].racks[r].shelfs[s].places[p].put(a);

				}
				

			}
			else if (command[4] == 'H')
			{
				std::cin >> w >> p >> a;
				if (w >= MAX || p >= MAX) std::cout << "error" << '\n';
				else
				{
					if (w >= storehouse.size || p >= storehouse.warehouses[w].handyshelf.size) std::cout << "error" << '\n';
					else storehouse.warehouses[w].handyshelf.places[p].put(a);

				}
				

			}
			else if (command[4] == 'R')
			{
				std::cin >> s >> p >> a;
				if (s >= MAX || p >= MAX) std::cout << "error" << '\n';
				else
				{
					if (s >= storehouse.handyrack.size || p >= storehouse.handyrack.shelfs[s].size) std::cout << "error" << '\n';
					else storehouse.handyrack.shelfs[s].places[p].put(a);
				}
				
			}
			else if (command[4] == 'S')
			{
				std::cin >> p >> a;
				if (p >= MAX) std::cout << "error" << '\n';
				else
				{
					if (p >= storehouse.handyshelf.size) std::cout << "error" << '\n';
					else storehouse.handyshelf.places[p].put(a);
				}
				

			}
		}
		else if (command.substr(0, 4) == "GET-")
		{
			if (command == "GET-S")
			{
				std::cout << storehouse.handyshelf.get() << '\n';
			}
			else if (command == "GET-E")
			{
				std::cout << all_stuff << '\n';

			}
			else if (command == "GET-W")
			{
				std::cin >> w;
				if (w >= storehouse.size) std::cout << "error" << '\n';
				else std::cout << storehouse.warehouses[w].get() << '\n';

			}
			else if (command[4] == 'R')
			{
				if (command[5] == 'W')
				{
					std::cin >> w >> r;
					if (w >= storehouse.size || r >= storehouse.warehouses[w].size) std::cout << "error" << '\n';
					else std::cout << storehouse.warehouses[w].racks[r].get() << '\n';
				}
				else if (command[5] == 'H') std::cout << storehouse.handyrack.get() << '\n';


			}
			else if (command[4] == 'S')
			{
				if (command[5] == 'W')
				{
					std::cin >> w >> r >> s;
					if (w >= storehouse.size || r >= storehouse.warehouses[w].size || s >= storehouse.warehouses[w].racks[r].size) std::cout << "error" << '\n';
					else std::cout << storehouse.warehouses[w].racks[r].shelfs[s].get() << '\n';

				}
				else if (command[5] == 'H')
				{
					std::cin >> w;
					if (w >= storehouse.size) std::cout << "error" << '\n';
					else std::cout << storehouse.warehouses[w].handyshelf.get() << '\n';
				}
				else if (command[5] == 'R')
				{
					std::cin >> s;
					if (s >= storehouse.handyrack.size) std::cout << "error" << '\n';
					else std::cout << storehouse.handyrack.shelfs[s].get() << '\n';

				}
			}
			else if (command[4] == 'L') 
			{
				if (command[5] == 'W')
				{
					std::cin >> w >> r >> s >> p;
					if (w >= storehouse.size || r >= storehouse.warehouses[w].size || s >= storehouse.warehouses[w].racks[r].size || p >= storehouse.warehouses[w].racks[r].shelfs[s].size) std::cout << "error" << '\n';
					else storehouse.warehouses[w].racks[r].shelfs[s].places[p].showlabel();

				}
				else if (command[5] == 'H')
				{
					std::cin >> w >> p;
					if (w >= storehouse.size || p >= storehouse.warehouses[w].handyshelf.size) std::cout << "error" << '\n';
					else storehouse.warehouses[w].handyshelf.places[p].showlabel();
				}
				else if (command[5] == 'R')
				{
					std::cin >> s >> p;
					if (s >= storehouse.handyrack.size || p >= storehouse.handyrack.shelfs[s].size) std::cout << "error" << "\n";
					else storehouse.handyrack.shelfs[s].places[p].showlabel();
				}
				else if (command[5] == 'S')
				{
					std::cin >> p;
					if (p >= storehouse.handyshelf.size) std::cout << "error" << '\n';
					else storehouse.handyshelf.places[p].showlabel();
				}

			}

		}
		else if (command.substr(0, 4) == "POP-")
		{
			if (command[4] == 'W')
			{
				std::cin >> w >> r >> s >> p >> a;
				if (w >= storehouse.size || r >= storehouse.warehouses[w].size || s >= storehouse.warehouses[w].racks[r].size || p >= storehouse.warehouses[w].racks[r].shelfs[s].size) std::cout << "error" << '\n';
				else  storehouse.warehouses[w].racks[r].shelfs[s].places[p].pop(a);

			}
			else if (command[4] == 'H')
			{
				std::cin >> w >> p >> a;
				if (w >= storehouse.size || p >= storehouse.warehouses[w].handyshelf.size) std::cout << "error" << '\n';
				else storehouse.warehouses[w].handyshelf.places[p].pop(a);
			}
			else if (command[4] == 'R')
			{
				std::cin >> s >> p >> a;
				if (s >= storehouse.handyrack.size || p >= storehouse.handyrack.shelfs[s].size) std::cout << "error" << '\n';
				else storehouse.handyrack.shelfs[s].places[p].pop(a);
			}
			else if (command[4] == 'S')
			{
				std::cin >> p >> a;
				if (p >= storehouse.handyshelf.size) std::cout << "error" << '\n';
				else storehouse.handyshelf.places[p].pop(a);
			}

		}
		else if (command.substr(0, 4) == "MOV-")
		{
			if (command[4] == 'W')
			{
				int wb, rb, sb, we, re, se, p, a;
				std::cin >> wb >> rb >> sb >> we >> re >> se >> p >> a;
				if (wb >= storehouse.size || rb >= storehouse.warehouses[wb].size || sb >= storehouse.warehouses[wb].racks[rb].size || p >= storehouse.warehouses[wb].racks[rb].shelfs[sb].size || 
					we >= storehouse.size || re >= storehouse.warehouses[we].size || se >= storehouse.warehouses[we].racks[re].size || p >= storehouse.warehouses[we].racks[re].shelfs[se].size) std::cout << "error" << '\n';
				else storehouse.warehouses[wb].racks[rb].shelfs[sb].places[p].move(&storehouse.warehouses[we].racks[re].shelfs[se].places[p], a);

			}
			else if (command[4] == 'H')
			{
				std::cin >> w >> r >> s >> p >> a;
				if (w >= storehouse.size || r >= storehouse.warehouses[w].size || s >= storehouse.warehouses[w].racks[r].size || p >= storehouse.warehouses[w].racks[r].shelfs[s].size) std::cout << "error" << '\n';
				else storehouse.warehouses[w].racks[r].shelfs[s].places[p].move(&storehouse.warehouses[w].handyshelf.places[p], a);
			}
			else if (command[4] == 'R')
			{
				int w, r, sb, se, p, a;
				std::cin >> w >> r >> sb >> se >> p >> a;
				if (w >= storehouse.size || r >= storehouse.warehouses[w].size || sb >= storehouse.warehouses[w].racks[r].size || p >= storehouse.warehouses[w].racks[r].shelfs[sb].size ||
					se >= storehouse.handyrack.size || p >= storehouse.handyrack.shelfs[se].size) std::cout << "error" << '\n';
				else storehouse.warehouses[w].racks[r].shelfs[sb].places[p].move(&storehouse.handyrack.shelfs[se].places[p], a);

			}
			else if (command[4] == 'S')
			{
				std::cin >> s >> p >> a;
				if (s >= storehouse.handyrack.size || p >= storehouse.handyshelf.size) std::cout << "error" << '\n';
				else storehouse.handyrack.shelfs[s].places[p].move(&storehouse.handyshelf.places[p], a);
			}
		}
		else if (command == "END") break;




	}


}