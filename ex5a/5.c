/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void xor(char g[8],char r[8])
{
    for(int i=0;i<8;i++)
    {
        
        if(g[i]==r[i])
            r[i]='0';
        else
            r[i]='1';
        
            
    }
}

void crc(char g[8],char cw[23],char r[8])
{
    int i=0;
    int j=0;
    for(i;i<8;i++)
        r[i]=cw[i];
    
    do
    {
       if(cw[0]=='1')
            xor(g,r);
        
        
        for(j=0;j<7;j++)
            r[j]=r[j+1];
            
        
        r[j]=cw[i++];
        printf("\n");
    
        for(int h=0;h<7;h++)
             printf("%c",r[h]);
     
        
    }while(i<=(16+8-1));
    
}



int main()
{
    int i=0;
    int j=16;
    char d[16]="1110011111110010";
    char g[8]= "10101001";
    char cw[23];
    char r[8];
    
    for(i;i<16;i++)
        cw[i]=d[i];
    for(j;j<23;j++)
        cw[j]='0';
    
        
    crc(g,cw,r);
    
    for(i=0;i<7;i++)
        cw[16+i]=r[i];
        
    crc(g,cw,r);
    
    printf("\n");
    for(int h=0;h<7;h++)
        printf("%c",r[h]);
    
    

        
    
}
