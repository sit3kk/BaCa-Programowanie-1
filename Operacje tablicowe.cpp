//Konrad Sitek
#include <iostream>


using namespace std;


int main()
{
    int Sessions = 0, CurrentSession = 0, Size = 0;


    cin >> Sessions;
    while (CurrentSession < Sessions)
    {


        cin >> Size;
        int tab[Size];


        int CurrentElement = 0;
        while (CurrentElement < Size) cin >> tab[CurrentElement++];


        CurrentElement = 0;
        while (CurrentElement < Size) cout << tab[CurrentElement++] << " ";

        cout << "\n";

        char TypeOfOperation='X';
        while (TypeOfOperation != 'F')
        {

            cin >> TypeOfOperation;

            if (TypeOfOperation == 'R')
            {
                int Index = 0, Lenght = 0;
                cin >> Index >> Lenght;


                if (Index >= 0 && Index < Size) {}
                else
                {
                    while (Index < 0) Index += Size;
                    while (Index >= Size) Index -= Size;
                }


                int PartOfArray = 0,
                    StartIndex = Index,
                    IndexA = Index,
                    IndexB = Index + Lenght - 1,
                    Parts = 0, Iteration = 0;

                if (Lenght != 0) Parts = Size / Lenght;
                if (Parts < 0) Parts /= -1;
                if (IndexB >= Size) IndexB -= Size;


                while (Iteration < Parts)
                {
                    int a = IndexA, b = IndexB;


                    if (Lenght % 2 == 1)
                    {
                        while (a != b)
                        {

                            int pom = tab[a];
                            tab[a] = tab[b];
                            tab[b] = pom;

                            a++;
                            b--;

                            if (a >= Size) a -= Size;
                            if (a < 0) a += Size;
                            if (b >= Size) b -= Size;
                            if (b < 0) b += Size;
                        }
                    }
                    else
                    {
                        int i = Lenght / 2;
                        while (i--)
                        {
                            int pom = tab[a];
                            tab[a] = tab[b];
                            tab[b] = pom;

                            a++;
                            b--;

                            if (a >= Size) a -= Size;
                            if (b < 0) b += Size;
                        }
                    }


                    IndexA = IndexB + 1;
                    IndexB = IndexA + Lenght - 1;


                    if (IndexA >= Size) IndexA -= Size;
                    if (IndexA < 0) IndexA += Size;
                    if (IndexB >= Size) IndexB -= Size;
                    if (IndexB < 0) IndexB += Size;


                    Iteration++;


                }

            }
            else if (TypeOfOperation == 'C')
            {
                int Index = 0, Lenght = 0, Shift = 0;
                cin >> Index >> Lenght >> Shift;

                if (Lenght > Size) Lenght = Size;




                if (Shift != 0 && Lenght != 0)
                {
                    if (Index >= 0 && Index < Size) {}
                    else
                    {
                        while (Index < 0) Index += Size;
                        while (Index >= Size) Index -= Size;
                    }

                    int IndexA = Index;
                    int StartIndex = Index;
                    int IndexB = Index + Lenght - 1;
                    int Parts = Size/Lenght;
                    int Iteration=0;
                    int Shift_c = Shift;

                    while(IndexB >= Size) IndexB -= Size;
                    while (Shift < 0) Shift += Lenght;
                    while (Shift >= Size) Shift -= Lenght;

                    while (Iteration < Parts)
                    {
                        int CurrentShift = 0;


                        while (CurrentShift < Shift)
                        {
                            int a = IndexB,
                                b = 0,
                                pom = tab[a];


                            while (a != IndexA)
                            {
                                b = a - 1;
                                if (b < 0) b += Size;
                                tab[a] = tab[b];
                                a--;
                                if (a < 0) a += Size;
                            }
                            tab[IndexA] = pom;
                            CurrentShift++;
                        }

                        if (Iteration + 1 != Parts)
                        {
                            IndexA = IndexB + 1;
                            IndexB = IndexA + Lenght - 1;
                            while (IndexA >= Size) IndexA -= Size;
                            while (IndexB >= Size) IndexB -= Size;
                        }
                        Iteration++;
                    }



                    if (Size % Lenght != 0)
                    {
                        IndexA = IndexB + 1;
                        IndexB = Index - 1;

                        if (IndexA >= Size) IndexA -= Size;
                        if (IndexB < 0) IndexB += Size;


                        while (Shift_c < 0) Shift_c += (Size % Lenght);
                        while (Shift_c >= Size) Shift_c -= (Size % Lenght);
                        int CurrentShift = 0;

                        while (CurrentShift < Shift_c)
                        {

                            int a = IndexB,
                                b = 0,
                                pom = tab[a];

                            while (a != IndexA)
                            {
                                b = a - 1;
                                if (b < 0) b += Size;
                                tab[a] = tab[b];
                                a--;
                                if (a < 0) a += Size;
                            }
                            tab[IndexA] = pom;
                            CurrentShift++;
                        }

                    }

                }





            }
            else if (TypeOfOperation == 'S')
            {
                int Index = 0, Lenght = 0, Shift = 0;
                cin >> Index >> Lenght;


                if (Index >= 0 && Index < Size) {}
                else
                {
                    while (Index < 0) Index += Size;
                    while (Index >= Size) Index -= Size;

                }




                int A1 = Index,
                B1 = Index + Lenght - 1,
                A2 = B1 + 1,
                B2 = A2 + Lenght - 1,
                Parts=0,
                CurrentPart=0;

                if (Lenght != 0) Parts = Size / (Lenght*2);

                if (A1 >= Size) A1 -= Size;
                if (B1 >= Size) B1 -= Size;
                if (A2 >= Size) A2 -= Size;
                if (B2 >= Size) B2 -= Size;


                while (CurrentPart < Parts)
                {


                    int i = 0, a = A1, b = A2;
                    if (Lenght <= Size && Lenght > 0)
                    {
                        while (i < Lenght)
                        {
                            int pom = tab[b];
                            tab[b] = tab[a];
                            tab[a] = pom;

                            a++;
                            b++;

                            if (a >= Size) a -= Size;
                            if (b >= Size) b -= Size;

                            i++;

                        }

                    }
                    A1 = B2 + 1;
                    B1 = A1 + Lenght - 1;
                    A2 = B1 + 1;
                    B2 = A2 + Lenght - 1;


                    if (A1 >= Size) A1 -= Size;
                    if (B1 >= Size) B1 -= Size;
                    if (A2 >= Size) A2 -= Size;
                    if (B2 >= Size) B2 -= Size;



                    CurrentPart++;
                }


            }

        }



        CurrentElement = 0;
        while (CurrentElement < Size)
        {
            cout << tab[CurrentElement++] << " ";
        }
        cout << "\n";
        CurrentSession++;
    }


    return 0;



}