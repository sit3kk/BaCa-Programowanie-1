//Konrad Sitek
#include <iostream>


 int pow(int base, int exponent)
{
    if (exponent == 0) return 1;
    else return base * pow(base, exponent - 1);
}


 int direction(int a, int size)
 {
     if (a >= size / 2) return -1;
     else return 1;
 }


 bool point(int x, int y, int z, int l, int v, int p, int h)
 {
     if ((pow((x - l), 2) + pow((y - v), 2) + pow((z - p), 2) <= pow((h - 1), 2))) return true;
     else return false;
 }

 bool IsCubeinclude(int x, int y, int z, int size)
 {
     if (x < size && y < size && z < size && x >= 0 && y >= 0 && z >= 0) return true; //Is the current point in?
     else return false;
 }


 bool same(long long tab[][32], int size)
 {
     //Searching for the same row
     for (int i = 0; i < size; i++)
     {
         for (int j = 0; j < size; j++)
         {
             int count = 0;
             for (int k = 0; k < size; k++) 
                 if (tab[i][k] == tab[j][k]  && i != j) count++;
            
             
             if (count == size) return true;

         }
     }

     return false;

 }


long long det(long long tab[32][32], int size)
{
    int q, w, e, i, j;
    long long result = 0;
    long long tab2[32][32];


    if (same(tab, size)) return 0;


    if (size == 3) return (tab[0][0] * tab[1][1] * tab[2][2] + tab[0][1] * tab[1][2] * tab[2][0] + tab[0][2] * tab[1][0] * tab[2][1]- tab[2][0] * tab[1][1] * tab[0][2] - tab[2][1] * tab[1][2] * tab[0][0] - tab[2][2] * tab[1][0] * tab[0][1]); //Saruss
    else if (size == 1) return tab[0][0]; //Matrix 1x1
    else if (size == 2) return (tab[0][0] * tab[1][1] - tab[0][1] * tab[1][0]); //Matrix 2x2
    else 
    {
        //Recusrion Laplace
        for (q = 0; q < size; q++) 
        {
            w = 0;
            e = 0;

            for (i = 1; i < size; i++) 
            {
                for (j = 0; j < size; j++) 
                {
                    if (j == q) continue;

                    tab2[w][e] = tab[i][j];
                    e++;

                    if (e == size - 1) 
                    {
                        w++;
                        e = 0;
                    }
                }
            }
            if(tab[0][q]!=0) result = result + tab[0][q] * pow(-1, q) * det(tab2, size - 1);
        }
        return result;
    }
  
}


long long calulateDet(long long tab[][32][32], int size, char k , int index)
{
    long long tab2D[32][32];

    //Convert to 2D array
    if (k == 'l') for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) tab2D[i][j] = tab[index][j][i];
    else if (k == 'v') for (int i = 0; i < size; i++) for(int j = 0; j < size; j++) tab2D[i][j] = tab[j][index][i];
    else if (k == 'p') for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) tab2D[i][j] = tab[j][i][index];
          
    //Calculate det
    return det(tab2D, size);
              
}



long long Csum(long long tab[][32][32], int size, int l, int v, int p, int h, int w, int d)
{
    long long sum = 0;
    int curr_x, curr_y, curr_z, x = 0, y, z;

   
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            for (int k = 0; k < d; k++)
            {
                curr_x = l + direction(l,size) * i;
                curr_y = v + direction(v,size) * j;
                curr_z = p + direction(p, size) * k;
                if(IsCubeinclude(curr_x, curr_y, curr_z, size)) sum += tab[curr_x][curr_y][curr_z];
            }

    return sum;

}

long long Tsum(long long tab[][32][32], int size, int l, int v, int p, int h, int w, int d)
{
    long long sum = 0;
    int curr_x, curr_y, curr_z, x, y, z;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w - i ; j++)
            for (int k = 0; k < d - i - j; k++)
            {
                curr_x = l + direction(l, size) * i;
                curr_y = v + direction(v, size) * j;
                curr_z = p + direction(p, size) * k;
                if (IsCubeinclude(curr_x, curr_y, curr_z, size)) sum += tab[curr_x][curr_y][curr_z];
            }
    return sum;

}


long long Osum(long long tab[][32][32], int size, int l, int v, int p, int h, int w, int d)
{
    long long sum = 0;
    int curr_x, curr_y, curr_z, x, y, z;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            for (int k = 0; k < d; k++)
            {
                curr_x = l + direction(l, size) * i;
                curr_y = v + direction(v, size) * j;
                curr_z = p + direction(p, size) * k;
                if (IsCubeinclude(curr_x, curr_y, curr_z, size)) sum += tab[curr_x][curr_y][curr_z] * point(curr_x, curr_y, curr_z, l, v, p, h);
            }
    return sum;

}

int main()
{
   
    
    int l, v, p, h, w, d,index,size;
    long long tab[32][32][32];
    char operation,k;

    std::cin >> size;

    for (int i = 0; i < size; ++i) 
        for (int j = 0; j < size; ++j) 
           for (int k = 0; k < size; ++k) 
               std::cin >> tab[j][k][i];
            
  
 
    while (std::cin>>operation)
    {
        if (operation == 'E') break;
        else if (operation == 'C')
        {
            std::cin >> l >> v >> p >> h >> w >> d;
            std::cout << Csum(tab, size, l, v, p, h+1, w+1, d+1) << '\n';
        }
        else if (operation == 'D')
        {
            std::cin >> k >> index;
            std::cout << calulateDet(tab, size, k, index) << '\n';
        }
        else if(operation == 'T')
        {
            std::cin >> l >> v >> p >> h;
            std::cout <<Tsum(tab, size, l, v, p, h + 1, h + 1,  h + 1) << '\n';
        }
        else if (operation == 'O')
        {
            std::cin >> l >> v >> p >> h;
            std::cout << Osum(tab, size, l, v, p, h + 1,  h + 1,  h + 1) << '\n';

        }
    }
 
    return 0;
}