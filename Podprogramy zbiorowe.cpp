//Konrad Sitek
#include <iostream>

using namespace std;

void sort(int tab[])
{
    int n = 0;
    while (tab[n] != -1) n++;

    n++;


    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (tab[j - 1] > tab[j])
            {
                int pom = tab[j - 1];
                tab[j - 1] = tab[j];
                tab[j] = pom;
            }
        }

    }

}

void Add(int value,int tab[])
{
    int i = 0;
    bool Exist = false;

    if (value >= 1 && value <= 4095)
    {
        while (tab[i] != -1)
        {

            if (tab[i] == value)
            {
                Exist = true;
                break;
            }
            i++;
        }

        if(Exist == false)
        {
            tab[i] = value;
            tab[i+1] = -1;
        }
        sort(tab);

    }

}


void Add2(int value,int tab[])
{
    int i = 0;
    bool Exist = false;

    if (value >= 1 && value <= 4095)
    {
        while (tab[i] != -1)
        {

            if (tab[i] == value)
            {
                Exist = true;
                break;
            }
            i++;
        }

        if(Exist == false)
        {
            tab[i] = value;
            tab[i+1] = -1;
        }

    }

}

void Create(int n, int tab1[], int tab2[])
{
    int x = 0;
    tab2[0] = -1;
    for(int i = 0 ; i < n; i++)
    {
        bool Exist = false;
        for(int j = 0 ; j < x ; j++)
        {
            if(tab2[x] == tab1[j])
            {
                Exist = true;
                break;
            }
        }

        if(Exist == false) Add(tab1[i],tab2);
    }

    sort(tab2);
}

void Union(int tab1[], int tab2[], int tab3[])
{
    tab3[0] = -1;


    int i_max = 0, j_max = 0;
    while (tab1[i_max] != -1) i_max++;
    while (tab2[j_max] != -1) j_max++;

    for(int i = 0 ; i < i_max ; i++) Add2(tab1[i],tab3);
    for(int j = 0 ; j < j_max ; j++) Add2(tab2[j],tab3);

    sort(tab3);


}


void Intersection(int tab1[], int tab2[], int tab3[])
{
    int max1 = 0,max2 = 0;
    tab3[0] = -1;
    while(tab1[max1]!=-1) max1++;
    while(tab2[max2]!=-1) max2++;

    for(int i = 0 ; i < max1 ; i++) for(int j = 0 ; j < max2; j++) if(tab1[i] == tab2[j]) Add2(tab1[i],tab3);


    sort(tab3);

}

void Difference(int tab1[], int tab2[], int tab3[])
{
    int max1 = 0,max2 = 0;
    tab3[0] = -1;
    while(tab1[max1]!=-1) max1++;
    while(tab2[max2]!=-1) max2++;

    for(int i = 0 ; i < max1 ; i++)
    {
        bool Exist = false;
        for(int j =0 ; j < max2 ; j++)
        {
            if(tab1[i] == tab2[j])
            {
                Exist = true;
                break;
            }

        }
        if(Exist == false) Add2(tab1[i],tab3);
    }

    sort(tab3);

}




void Symmetric(int tab1[], int tab2[], int tab3[])
{
    int max1 = 0,max2 = 0;
    tab3[0] = -1;
    while(tab1[max1]!=-1) max1++;
    while(tab2[max2]!=-1) max2++;

    for(int i = 0 ; i < max1 ; i++)
    {
        bool Exist = false;
        for(int j = 0 ; j < max2 ; j++)
        {
            if(tab1[i] == tab2[j])
            {

                Exist = true;
                break;
            }
        }

        if(Exist == false) Add2(tab1[i],tab3);
    }


    for(int j = 0 ; j < max2 ; j++)
    {

        bool Exist = false;
        for(int i = 0 ; i < max1 ; i++)
        {
            if(tab2[j] == tab1[i])
            {
                Exist = true;
                break;
            }
        }
        int n = 0;
        while(tab3[n]!=-1)
        {
            if(tab3[n] == tab2[j])
            {

                Exist =true;
                break;
            }
            n++;
        }
        if(Exist == false) Add2(tab2[j],tab3);

    }

    sort(tab3);
}

void Complement(int tab1[], int tab2[])
{


    int max1 = 0,num = 1;
    tab2[0] = -1;
    while(tab1[max1]!=-1) max1++;


    while(num!=4096)
    {
        bool Exist = false;
        for(int i = 0 ; i < max1 ; i++)
        {
            if(tab1[i] == num)
            {
                Exist = true;
                break;

            }
        }


        if(Exist == false) Add2(num,tab2);

        num++;
    }


    sort(tab2);

}


bool Subset(int tab1[], int tab2[])
{
    int i_max = 0, j_max = 0;
    while (tab1[i_max++] != -1);
    while (tab2[j_max++] != -1);


    for (int i = 0; i < i_max; i++)
    {
        bool Exist = false;
        for (int j = 0; j < j_max; j++)
        {
            if (tab1[i] == tab2[j])
            {
                Exist = true;
                break;
            }
        }

        if (Exist == false) return false;
    }

    return true;
}




bool Equal(int tab1[], int tab2[])
{
    int tab1_size = 0,tab2_size = 0;

    while(tab1[tab1_size]!=-1) tab1_size++;
    while(tab2[tab2_size]!=-1) tab2_size++;


    tab1_size++;
    tab2_size++;

    if (tab1_size != tab2_size) return false;


    for(int i = 0 ; i < tab1_size ; i++)
    {

        bool Equal = false;
        for(int j =0 ; j < tab2_size ; j++)
        {

            if(tab1[i]==tab2[j]) Equal = true;


        }
        if(Equal == false) return false;
    }

    return true;
}


bool Empty(int tab[])
{
    if (tab[0] == -1) return true;

    return false;
}


bool Nonempty(int tab[])
{

    if (tab[0] != -1) return true;
    else return false;
}


bool Element(int Element,int tab[])
{
    int tab_size = 0;
    while(tab[tab_size]!=-1) tab_size++;

    for(int i = 0 ; i < tab_size ; i++) if(tab[i] == Element) return true;

    return false;
}


double Arithmetic(int tab[])
{
    int size = 0;
    while(tab[size]!= -1) size++;


    double sum = 0, n =0;

    for(int i = 0 ; i < size ; i++)
    {
        sum+=tab[i];
        n++;
    }



    if(tab[0] == -1) return 0;
    else return sum/n;
}


double Harmonic(int tab[])
{
    double sum = 0, n = 0,x = 1;
    if (tab[0] == -1) return 1;
    else
    {

        int i = 0;
        while (tab[i] != -1)
        {


            sum += (x / tab[i]);


            n++;
            i++;
        }


    }
    return n / sum;
}



void MinMax(int tab[], int *min, int &max)
{

    if(tab[0] != -1)
    {
        *min = 4096;
        max = 0;
        int size = 0;
        while(tab[size]!= -1) size++;
        for(int i = 0 ; i < size ; i++)
        {

            if(tab[i]<*min) *min = tab[i];
            if (tab[i] > max) max = tab[i];
        }

    }



}

void Cardinality(int tab[], int* power)
{
    if (tab[0] == -1) *power = 0;
    else
    {
        int i = 0;
        while (tab[i] != -1)
        {
            i++;
            *power = i;


        }

    }

}

void Properties(int tab[], char marks[], double &arithmetic, double *harmonic,  int &min, int *max,int &power)
{
    int CurrentOperation = 0;

    while (marks[CurrentOperation] != '\0')
    {
        if (marks[CurrentOperation] == 'a')
        {
            arithmetic = Arithmetic(tab);
        }
        else if (marks[CurrentOperation] == 'h')
        {
            *harmonic = Harmonic(tab);
        }
        else if (marks[CurrentOperation] == 'm')
        {
            MinMax(tab, &min, *max);
        }
        else if (marks[CurrentOperation] == 'c')
        {
            Cardinality(tab, &power);
        }


        CurrentOperation++;
    }
}