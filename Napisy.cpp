//Konrad Sitek
#include <string>

std::string FormatujNapis(std::string FirstArgument, std::string Param1, std::string Param2, std::string Param3)
{
	if (FirstArgument.size() < 5) return FirstArgument;

	std::string Result = FirstArgument, array[3] = { Param1, Param2, Param3 }, Left = "", Right = "", ToAdd = "";

	for (int i = 0; i < Result.size(); i++)
	{
		if (Result[i] == '{')
		{
			int n = (int)(Result[i + 3]) - 48;
			if (Result[i + 1] == 'p')
			{
				for (int j = 0; j < i; j++) Left += Result[j];
				for (int j = 0; j < n; j++) ToAdd += Result[i + 5];
				for (int j = i + 7; j < Result.size(); j++) Right += Result[j];
				Result = Left + ToAdd + Right;


			}
			else if (Result[i + 1] == 'u')
			{
				for (int j = 0; j < i; j++) Left += Result[j];
				for (int j = i + 5 + n; j < Result.size(); j++) Right += Result[j];
				i = 0;
				Result = Left + Right;
			}
			else if (Result[i + 1] == 'U' )
			{

				for (int j = 0; j < i; j++) Left += Result[j];
				for (int j = i + 5; j < Result.size(); j++) Right += Result[j];
				if ((int)Left.size() - n > 0) Left.resize(Left.size() - n);
				else Left = "";
				i = 0;
				Result = Left + Right;

			}
			else if (Result[i + 1] == 'w')
			{
				for (int j = 0; j < i; j++) Left += Result[j];
				ToAdd = array[n - 1];
				for (int j = i + 5; j < Result.size(); j++) Right += Result[j];
				Result = Left + ToAdd + Right;

			}
			else if (Result[i + 1] == 'W')
			{
				int m = (int)(Result[i + 5]) - 48;
				for (int j = 0; j < i; j++) Left += Result[j];
				for (int j = i + 7; j < Result.size(); j++) Right += Result[j];
				ToAdd = array[n - 1];
				ToAdd.resize(m, ' ');
				Result = Left + ToAdd + Right;
				i = 0;

			}



			ToAdd = "";
			Left = "";
			Right = "";
		}
		if (Result[i] == '{') i--;


	}


	return Result;


}


std::string NormalizujNapis(std::string Argument)
{
    std::string Result = "", Left = "";

    short i = 0;
    while (Argument[i] == ' ') i++;


    for ( ; i < Argument.size(); ++i)
    {
        while (Argument[i] == ' ' && (Argument[i + 1] == ' ' || Argument[i + 1] == '.' || Argument[i + 1] == ',')) i++;
        Result += Argument[i];

    }
    for (short i = 0; i < Result.size(); i++)
    {
        if ((Result[i] == '.' || Result[i] == ',') && Result[i+1] != ' ') Left = Left + Result[i] + ' ';
        else Left += Result[i];
    }

    Result = Left;

    if (Result[Result.size() - 1] == ' ') Result.resize(Result.size() - 1);



    return Result;

}



std::string NajwiekszeSlowo(std::string Argument)
{


    std::string LongestWord = "", LongestWord_t;
    for (size_t i = 0; i < Argument.size(); i++)
    {
        if (Argument[i] != ' ') LongestWord_t += Argument[i];
        else
        {
            if (LongestWord_t > LongestWord) LongestWord = LongestWord_t;
            LongestWord_t = "";
        }

        if (i == Argument.size() - 1 && LongestWord_t > LongestWord) LongestWord = LongestWord_t;
    }


    return LongestWord;

}


std::string UsunSlowo(std::string Argument, int Word2Del)
{
    short WordNum = 0;
    std::string ResultWord;
    for (size_t i = 0; i < Argument.size(); i++)
    {
        if (Argument[i] != ' ')
        if(i == 0 || Argument[i - 1] == ' ')
            WordNum++;


        if (WordNum != Word2Del || Argument[i] == ' ') ResultWord += Argument[i];
    }

    return ResultWord;

}