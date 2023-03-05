//Konrad Sitek
#include <iostream>
#include <fstream>
#include <string>



struct Data
{
	int IntComponent;
	std::string StrComponent;
	std::string CharComponent;

	struct Set
	{
		bool BoolComponent;
		int UCharComponent;
		float FloatComponent;
	};

	Set set1;
	Set set2;
	Set set3;
	Set set4;


};



void SortDSC(std::string path1, std::string path2)
{
	bool swapped = true;
	std::ifstream input;
	std::ofstream helpfile;
	std::string f;
	Data data, data2;


	while (swapped)
	{

		swapped = false;
		input.open(path1.c_str());
		helpfile.open(path2.c_str());

		if (input >> data.IntComponent)
		{



			input.ignore(2, '\n');
			std::getline(input, data.StrComponent);
			std::getline(input, data.CharComponent);
			input >> data.set1.BoolComponent >> data.set1.UCharComponent >> data.set1.FloatComponent
				>> data.set2.BoolComponent >> data.set2.UCharComponent >> data.set2.FloatComponent
				>> data.set3.BoolComponent >> data.set3.UCharComponent >> data.set3.FloatComponent
				>> data.set4.BoolComponent >> data.set4.UCharComponent >> data.set4.FloatComponent;



			while (input >> data2.IntComponent)
			{


				input.ignore(2, '\n');
				std::getline(input, data2.StrComponent);
				std::getline(input, data2.CharComponent);
				input >> data2.set1.BoolComponent >> data2.set1.UCharComponent >> data2.set1.FloatComponent
					>> data2.set2.BoolComponent >> data2.set2.UCharComponent >> data2.set2.FloatComponent >>
					data2.set3.BoolComponent >> data2.set3.UCharComponent >> data2.set3.FloatComponent >>
					data2.set4.BoolComponent >> data2.set4.UCharComponent >> data2.set4.FloatComponent;



				if (data.IntComponent < data2.IntComponent)
				{
					helpfile << data2.IntComponent << '\n' << data2.StrComponent << '\n' << data2.CharComponent << '\n' <<
						data2.set1.BoolComponent << ' ' << data2.set1.UCharComponent << ' ' << data2.set1.FloatComponent << '\n' <<
						data2.set2.BoolComponent << ' ' << data2.set2.UCharComponent << ' ' << data2.set2.FloatComponent << '\n' <<
						data2.set3.BoolComponent << ' ' << data2.set3.UCharComponent << ' ' << data2.set3.FloatComponent << '\n' <<
						data2.set4.BoolComponent << ' ' << data2.set4.UCharComponent << ' ' << data2.set4.FloatComponent << '\n';
					swapped = true;

				}
				else
				{

					helpfile << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
						data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
						data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
						data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
						data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent << '\n';


					data = data2;


				}
			}

			helpfile << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
				data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
				data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
				data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
				data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent << '\n';

		}
		input.close();
		helpfile.close();


		if (swapped)
		{
			std::ifstream in(path2.c_str());
			std::ofstream out(path1.c_str());
			while (std::getline(in, f)) out << f << '\n';
			in.close();
			out.close();
		}
		if (swapped == false) break;

	}

}


struct Number
{
	int num;
	int count;
};



void sortDSCcounter(std::string path1, std::string path2)
{
	bool swapped = true;
	std::ifstream input;
	std::ofstream helpfile;
	std::string f;
	Number number, number2;


	while (swapped)
	{

		swapped = false;
		input.open(path1.c_str());
		helpfile.open(path2.c_str());

		if (input >> number.num)
		{

			input >> number.count;


			while (input >> number2.num)
			{
				input >> number2.count;

				if (number.count < number2.count)
				{
					helpfile << number2.num << ' ' << number2.count << '\n';
					swapped = true;

				}
				else
				{

					helpfile << number.num << ' ' << number.count << '\n';
					number = number2;


				}
			}

			helpfile << number.num << ' ' << number.count << '\n';

		}
		input.close();
		helpfile.close();


		if (swapped)
		{
			std::ifstream in(path2.c_str());
			std::ofstream out(path1.c_str());
			while (std::getline(in, f)) out << f << '\n';
			in.close();
			out.close();
		}
		if (swapped == false) break;

	}


}

void SortCount(std::string path1, std::string path2, std::string path3)
{
	std::fstream input;
	std::string f;
	Data data, data2;
	bool swapped = true;

	SortDSC(path1, path2); 

	input.open(path1.c_str(), std::ios::in);

	if (input >> data.IntComponent)
	{
		input.ignore(2, '\n');
		std::getline(input, data.StrComponent);
		std::getline(input, data.CharComponent);
		input >> data.set1.BoolComponent >> data.set1.UCharComponent >> data.set1.FloatComponent
			>> data.set2.BoolComponent >> data.set2.UCharComponent >> data.set2.FloatComponent
			>> data.set3.BoolComponent >> data.set3.UCharComponent >> data.set3.FloatComponent
			>> data.set4.BoolComponent >> data.set4.UCharComponent >> data.set4.FloatComponent; 


		std::fstream helpfile, helpfile2;

		helpfile2.open(path3.c_str(), std::ios::out | std::ios::trunc); 

		int counter = 1;
		int n = data.IntComponent;
		while (input >> data.IntComponent)
		{
			input.ignore(2, '\n');
			std::getline(input, data.StrComponent);
			std::getline(input, data.CharComponent);
			input >> data.set1.BoolComponent >> data.set1.UCharComponent >> data.set1.FloatComponent
				>> data.set2.BoolComponent >> data.set2.UCharComponent >> data.set2.FloatComponent
				>> data.set3.BoolComponent >> data.set3.UCharComponent >> data.set3.FloatComponent
				>> data.set4.BoolComponent >> data.set4.UCharComponent >> data.set4.FloatComponent;

			if (data.IntComponent == n) counter++; 
			else
			{
				helpfile2 << n << " " << counter << '\n';
				n = data.IntComponent;
				counter = 1;
			}

		}
		helpfile2 << n << " " << counter << '\n';
		helpfile2.close();
		input.close();


		sortDSCcounter(path3, path2);


		helpfile2.open(path3.c_str(), std::ios::in);
		helpfile.open(path2.c_str(), std::ios::out | std::ios::trunc);



		while (helpfile2 >> n >> counter) 
		{
			input.open(path1.c_str(), std::ios::in);
			while (input >> data.IntComponent)
			{
				input.ignore(2, '\n');
				std::getline(input, data.StrComponent);
				std::getline(input, data.CharComponent);
				input >> data.set1.BoolComponent >> data.set1.UCharComponent >> data.set1.FloatComponent
					>> data.set2.BoolComponent >> data.set2.UCharComponent >> data.set2.FloatComponent
					>> data.set3.BoolComponent >> data.set3.UCharComponent >> data.set3.FloatComponent
					>> data.set4.BoolComponent >> data.set4.UCharComponent >> data.set4.FloatComponent;


				if (data.IntComponent == n) 
				{
					helpfile << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
						data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
						data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
						data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
						data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent << '\n';
				}

			}
			input.close();
		}
		helpfile.close();
		helpfile2.close();


		std::ifstream in(path2.c_str());
		std::ofstream out(path1.c_str());
		while (std::getline(in, f)) out << f << '\n';
		in.close();
		out.close();


		while (swapped)
		{
			swapped = false;


			input.open(path1.c_str(), std::ios::in);
			helpfile.open(path2.c_str(), std::ios::out | std::ios::trunc);


			if (input >> data.IntComponent)
			{
				input.ignore(2, '\n');
				std::getline(input, data.StrComponent);
				std::getline(input, data.CharComponent);
				input >> data.set1.BoolComponent >> data.set1.UCharComponent >> data.set1.FloatComponent
					>> data.set2.BoolComponent >> data.set2.UCharComponent >> data.set2.FloatComponent
					>> data.set3.BoolComponent >> data.set3.UCharComponent >> data.set3.FloatComponent
					>> data.set4.BoolComponent >> data.set4.UCharComponent >> data.set4.FloatComponent;


				while (input >> data2.IntComponent)
				{
					input.ignore(2, '\n');
					std::getline(input, data2.StrComponent);
					std::getline(input, data2.CharComponent);
					input >> data2.set1.BoolComponent >> data2.set1.UCharComponent >> data2.set1.FloatComponent
						>> data2.set2.BoolComponent >> data2.set2.UCharComponent >> data2.set2.FloatComponent
						>> data2.set3.BoolComponent >> data2.set3.UCharComponent >> data2.set3.FloatComponent
						>> data2.set4.BoolComponent >> data2.set4.UCharComponent >> data2.set4.FloatComponent;

					if (data.IntComponent == data2.IntComponent &&
						(data.set1.UCharComponent + data.set2.UCharComponent + data.set3.UCharComponent + data.set4.UCharComponent)%256  <
						(data2.set1.UCharComponent + data2.set2.UCharComponent + data2.set3.UCharComponent + data2.set4.UCharComponent)%256)
					{
						helpfile << data2.IntComponent << '\n' << data2.StrComponent << '\n' << data2.CharComponent << '\n' <<
							data2.set1.BoolComponent << ' ' << data2.set1.UCharComponent << ' ' << data2.set1.FloatComponent << '\n' <<
							data2.set2.BoolComponent << ' ' << data2.set2.UCharComponent << ' ' << data2.set2.FloatComponent << '\n' <<
							data2.set3.BoolComponent << ' ' << data2.set3.UCharComponent << ' ' << data2.set3.FloatComponent << '\n' <<
							data2.set4.BoolComponent << ' ' << data2.set4.UCharComponent << ' ' << data2.set4.FloatComponent << '\n';
						swapped = true;
					}
					else
					{
						helpfile << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
							data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
							data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
							data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
							data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent << '\n';
						data = data2;
					}
				}
				helpfile << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
					data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
					data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
					data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
					data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent << '\n';

			}
			input.close();
			helpfile.close();


			if (swapped)
			{
				std::ifstream in(path2.c_str());
				std::ofstream out(path1.c_str());
				while (std::getline(in, f)) out << f << '\n'; 
				in.close();
				out.close();
			}
			if (swapped == false) break;
		}
	}
	else input.close();


}


void SymmetricDifference(std::string path1, std::string path2, std::string path3)
{
	std::fstream input1, input2, helpfile;




	input2.open(path2.c_str(), std::ios::in | std::ios::ate);
	if (input2.tellg() == 0) 
	{
		input2.close();
		return;
	}
	input2.close();


	input2.open(path2.c_str(), std::ios::out | std::ios::in); 
	helpfile.open(path3.c_str(), std::ios::out | std::ios::in | std::ios::ate);
	Data data, data2;


	bool transfer = false;
	do
	{



		if (input2 >> data.IntComponent)
		{

			input2.ignore(2, '\n');
			std::getline(input2, data.StrComponent);
			std::getline(input2, data.CharComponent);
			input2 >> data.set1.BoolComponent >> data.set1.UCharComponent >> data.set1.FloatComponent
				>> data.set2.BoolComponent >> data.set2.UCharComponent >> data.set2.FloatComponent
				>> data.set3.BoolComponent >> data.set3.UCharComponent >> data.set3.FloatComponent
				>> data.set4.BoolComponent >> data.set4.UCharComponent >> data.set4.FloatComponent;

		}
		else break;


		transfer = true;
		input1.open(path1.c_str(), std::ios::in);



		while (1)
		{


			if (input1 >> data2.IntComponent)
			{
				input1.ignore(2, '\n');
				std::getline(input1, data2.StrComponent);
				std::getline(input1, data2.CharComponent);
				input1 >> data2.set1.BoolComponent >> data2.set1.UCharComponent >> data2.set1.FloatComponent
					>> data2.set2.BoolComponent >> data2.set2.UCharComponent >> data2.set2.FloatComponent
					>> data2.set3.BoolComponent >> data2.set3.UCharComponent >> data2.set3.FloatComponent
					>> data2.set4.BoolComponent >> data2.set4.UCharComponent >> data2.set4.FloatComponent;


			}
			else break;




			if (data.IntComponent == data2.IntComponent && data.StrComponent == data2.StrComponent && data.CharComponent == data2.CharComponent &&
				data.set1.BoolComponent == data2.set1.BoolComponent && data.set1.FloatComponent == data2.set1.FloatComponent && data.set1.UCharComponent == data2.set1.UCharComponent &&
				data.set2.BoolComponent == data2.set2.BoolComponent && data.set2.FloatComponent == data2.set2.FloatComponent && data.set2.UCharComponent == data2.set2.UCharComponent &&
				data.set3.BoolComponent == data2.set3.BoolComponent && data.set3.FloatComponent == data2.set3.FloatComponent && data.set3.UCharComponent == data2.set3.UCharComponent &&
				data.set4.BoolComponent == data2.set4.BoolComponent && data.set4.FloatComponent == data2.set4.FloatComponent && data.set4.UCharComponent == data2.set4.UCharComponent)
			{

				transfer = false;
				break;
			}
		}
		input1.close();



		if (transfer)
		{
			input1.open(path1.c_str(), std::ios::out | std::ios::app);


			input1 << '\n' << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
				data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
				data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
				data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
				data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent;
			input1.close();

		}
		else
		{


			helpfile << '\n' << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
				data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
				data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
				data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
				data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent;

		}


	} while (1);


	input2.close();
	helpfile.close();



	helpfile.open(path3.c_str(), std::ios::in);
	input2.open(path2.c_str(), std::ios::out | std::ios::ate);

	do
	{


		if (helpfile >> data.IntComponent)
		{

			helpfile.ignore(2, '\n');
			std::getline(helpfile, data.StrComponent);
			std::getline(helpfile, data.CharComponent);
			helpfile >> data.set1.BoolComponent >> data.set1.UCharComponent >> data.set1.FloatComponent
				>> data.set2.BoolComponent >> data.set2.UCharComponent >> data.set2.FloatComponent
				>> data.set3.BoolComponent >> data.set3.UCharComponent >> data.set3.FloatComponent
				>> data.set4.BoolComponent >> data.set4.UCharComponent >> data.set4.FloatComponent;

		}
		else break;






		input2 << '\n' << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
			data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
			data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
			data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
			data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent;



	} while (1);


	input2.close();
	helpfile.close();


}




void SortInt(std::string path1, std::string path2, std::string path3)
{

	bool swapped;
	std::ifstream input;
	std::ofstream helpfile;
	std::string f;
	
	Data data,data2; 


	while (1)
	{

		swapped = false;
		input.open(path1.c_str());
		helpfile.open(path2.c_str());

		if (input >> data.IntComponent)
		{



			input.ignore(2, '\n'); 
			std::getline(input, data.StrComponent);
			std::getline(input, data.CharComponent);
			input >> data.set1.BoolComponent >> data.set1.UCharComponent >> data.set1.FloatComponent
				>> data.set2.BoolComponent >> data.set2.UCharComponent >> data.set2.FloatComponent
				>> data.set3.BoolComponent >> data.set3.UCharComponent >> data.set3.FloatComponent
				>> data.set4.BoolComponent >> data.set4.UCharComponent >> data.set4.FloatComponent;



			while (input >> data2.IntComponent)
			{


				input.ignore(2, '\n'); 
				std::getline(input, data2.StrComponent);
				std::getline(input, data2.CharComponent);
				input >> data2.set1.BoolComponent >> data2.set1.UCharComponent >> data2.set1.FloatComponent
					>> data2.set2.BoolComponent >> data2.set2.UCharComponent >> data2.set2.FloatComponent >>
					data2.set3.BoolComponent >> data2.set3.UCharComponent >> data2.set3.FloatComponent >>
					data2.set4.BoolComponent >> data2.set4.UCharComponent >> data2.set4.FloatComponent;



				if (data.IntComponent > data2.IntComponent) 
				{
					


					helpfile << data2.IntComponent << '\n' << data2.CharComponent << '\n' << data2.StrComponent << '\n' <<
						data2.set1.BoolComponent << ' ' << data2.set1.UCharComponent << ' ' << data2.set1.FloatComponent << '\n' <<
						data2.set2.BoolComponent << ' ' << data2.set2.UCharComponent << ' ' << data2.set2.FloatComponent << '\n' <<
						data2.set3.BoolComponent << ' ' << data2.set3.UCharComponent << ' ' << data2.set3.FloatComponent << '\n' <<
						data2.set4.BoolComponent << ' ' << data2.set4.UCharComponent << ' ' << data2.set4.FloatComponent << '\n';
					swapped = true;

				}
				else
				{

					helpfile << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
						data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
						data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
						data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
						data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent << '\n';

					
					data = data2;
					

				}
			}

			helpfile << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
				data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
				data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
				data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
				data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent << '\n';

		}
		input.close();
		helpfile.close();


		if (swapped)
		{
			std::ifstream in(path2.c_str());
			std::ofstream out(path1.c_str());
			while (std::getline(in, f)) out << f << '\n'; 
			in.close();
			out.close();
		}
		if (swapped == false) break;

	}

	
}

void SortString(std::string path1, std::string path2, std::string path3)
{
	bool swapped;
	std::ifstream input;
	std::ofstream helpfile;
	std::string f;



	Data data, data2;


	while (1)
	{

		swapped = false;
		input.open(path1.c_str());
		helpfile.open(path2.c_str());

		if (input >> data.IntComponent)
		{



			input.ignore(2, '\n');
			std::getline(input, data.StrComponent);
			std::getline(input, data.CharComponent);
			input >> data.set1.BoolComponent >> data.set1.UCharComponent >> data.set1.FloatComponent
				>> data.set2.BoolComponent >> data.set2.UCharComponent >> data.set2.FloatComponent
				>> data.set3.BoolComponent >> data.set3.UCharComponent >> data.set3.FloatComponent
				>> data.set4.BoolComponent >> data.set4.UCharComponent >> data.set4.FloatComponent;



			while (input >> data2.IntComponent)
			{



				input.ignore(2, '\n');
				std::getline(input, data2.StrComponent);
				std::getline(input, data2.CharComponent);
				input >> data2.set1.BoolComponent >> data2.set1.UCharComponent >> data2.set1.FloatComponent
					>> data2.set2.BoolComponent >> data2.set2.UCharComponent >> data2.set2.FloatComponent >>
					data2.set3.BoolComponent >> data2.set3.UCharComponent >> data2.set3.FloatComponent >>
					data2.set4.BoolComponent >> data2.set4.UCharComponent >> data2.set4.FloatComponent;




				if (data.StrComponent > data2.StrComponent) 
				{


					helpfile << data2.IntComponent << '\n' << data2.StrComponent << '\n' << data2.CharComponent << '\n' <<
						data2.set1.BoolComponent << ' ' << data2.set1.UCharComponent << ' ' << data2.set1.FloatComponent << '\n' <<
						data2.set2.BoolComponent << ' ' << data2.set2.UCharComponent << ' ' << data2.set2.FloatComponent << '\n' <<
						data2.set3.BoolComponent << ' ' << data2.set3.UCharComponent << ' ' << data2.set3.FloatComponent << '\n' <<
						data2.set4.BoolComponent << ' ' << data2.set4.UCharComponent << ' ' << data2.set4.FloatComponent << '\n';
					swapped = true;



				}
				else
				{

					helpfile << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
						data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
						data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
						data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
						data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent << '\n';


					data = data2;


				}
			}

			helpfile << data.IntComponent << '\n' << data.StrComponent << '\n' << data.CharComponent << '\n' <<
				data.set1.BoolComponent << ' ' << data.set1.UCharComponent << ' ' << data.set1.FloatComponent << '\n' <<
				data.set2.BoolComponent << ' ' << data.set2.UCharComponent << ' ' << data.set2.FloatComponent << '\n' <<
				data.set3.BoolComponent << ' ' << data.set3.UCharComponent << ' ' << data.set3.FloatComponent << '\n' <<
				data.set4.BoolComponent << ' ' << data.set4.UCharComponent << ' ' << data.set4.FloatComponent << '\n';

		}
		input.close();
		helpfile.close();


		if (swapped)
		{
			std::ifstream in(path2.c_str());
			std::ofstream out(path1.c_str());
			while (std::getline(in, f)) out << f << '\n'; 
			in.close();
			out.close();
		}

		if (swapped == false) break;

	}

}