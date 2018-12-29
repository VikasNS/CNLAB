int four_bit_adder(char F[4],char S[4],char Sum[4])
{
    char carry='0';
    char f_bit;
    char s_bit;
    for(int i=3;i>=0;i--)
    {
        f_bit=F[i];
        s_bit=S[i];
        
        
        if(f_bit=='0' && s_bit=='0' && carry=='0')
        {
            Sum[i]='0';
            carry='0';
        }else if(f_bit=='0' && s_bit=='0' && carry=='1')
        {            

            Sum[i]='1';
            carry='0';
        }else if(f_bit=='0' && s_bit=='1' && carry=='0')
        {            

            Sum[i]='1';
            carry='0';
        }else if(f_bit=='0' && s_bit=='1' && carry=='1')
        {            

            Sum[i]='0';
            carry='1';
        }else if(f_bit=='1' && s_bit=='0' && carry=='0')
        {            

            Sum[i]='1';
            carry='0';
        }else if(f_bit=='1' && s_bit=='0' && carry=='1')
        {           

            Sum[i]='0';
            carry='1';
        }else if(f_bit=='1' && s_bit=='1' && carry=='0')
        {           

            Sum[i]='0';
            carry='1';
        }else if(f_bit=='1' && s_bit=='1' && carry=='1')
        {           

            Sum[i]='1';
            carry='1';
        }
    }
    
    printf("\n %s %s %s \n",F,S,Sum);
    return carry;
    
}

void copy1(char F[4], char Sum[4])
{
    for(int i=0;i<4;i++)
        F[i]=Sum[i];
}

void copy2(char S[4], char checksum[4])
{
    for(int i=0;i<4;i++)
        S[i]=checksum[i];
}


int main()
{
    char F[4];
    char S[4];
    char Sum[4];
    char carry;
    char checksum[4];
    
    int no_of_inputs=3;
    printf("Enter 4 bit Binary \n");
    scanf("%s",F);
    for(int i=0;i<no_of_inputs-1;i++)
    {
        printf("%d Enter 4 bit Binary \n",i+2);
        scanf("%s",S);
        
        carry=four_bit_adder(F,S,Sum);
        copy1(F,Sum);
        if(carry=='1')
            four_bit_adder(F,"0001",Sum);
        copy1(F,Sum);
    }
    
    int k=0;
    for(k=0;k<4;k++)
        if (Sum[k]=='0')
            checksum[k]='1';
        else 
            checksum[k]='0';
    
    printf("\n Check sum is %s ",checksum);
    printf("------------ on the reciver end -----------\n");
    copy1(F,Sum);
    copy2(S,checksum);
    
    carry=four_bit_adder(F,S,Sum);
    if(carry=='1')
        four_bit_adder(F,"0001",Sum);
    
    for(k=0;k<4;k++)
        if (Sum[k]=='0')
            checksum[k]='1';
        else 
            checksum[k]='0';
    printf("%s",checksum);
    
    
    
    return 1;

}
