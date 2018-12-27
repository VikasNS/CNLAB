void print_out(char is_dropped[20],int packet_size,int curr_size,int after_adding,int after_processing)
{
    printf("%s \t\t %d \t\t %d \t\t %d \t\t %d \n",is_dropped,packet_size,curr_size,after_adding,after_processing);
}

void leaky_bucket(int max_packet_count,int process_rate,int bucket_limit)
{
    int curr_bucket_size=0;
    int i=0;
    int random_packet_size;
    char is_dropped[20];
    int c1_pk_size;
    int c2_b4;
    int c3_after_adding;
    int c4_after_proccesing;
    
    printf("Packet Status \t Packet Size \t B4 Adding \t After Adding \t After Proccesing \n");
    
    while(i<max_packet_count)
    {
        strncpy(is_dropped, "not dropped", 20);
        random_packet_size=(rand()%bucket_limit)+10;
        
        c1_pk_size=random_packet_size;
        c2_b4=curr_bucket_size;
        
        if(bucket_limit-curr_bucket_size<random_packet_size)
            strncpy(is_dropped, "dropped", 20);
        else   
            curr_bucket_size+=random_packet_size;
        
        c3_after_adding=curr_bucket_size;
        
        if(curr_bucket_size<=process_rate)
            curr_bucket_size=0;
        else
            curr_bucket_size-=process_rate;
        
        c4_after_proccesing=curr_bucket_size;
           
       print_out(is_dropped,c1_pk_size,c2_b4,c3_after_adding,c4_after_proccesing); 
       i++;
    }
    
    c1_pk_size=0;
    
    while(curr_bucket_size!=0)
    {
        c3_after_adding=c2_b4=curr_bucket_size;
        if(curr_bucket_size<=process_rate)
            curr_bucket_size=0;
        else
            curr_bucket_size-=process_rate;
        c4_after_proccesing=curr_bucket_size;
        print_out("No packet",c1_pk_size,c2_b4,c3_after_adding,c4_after_proccesing);  
    }
    
    
}


int main()
{
    leaky_bucket(10,200,1000);

    return 0;
}
