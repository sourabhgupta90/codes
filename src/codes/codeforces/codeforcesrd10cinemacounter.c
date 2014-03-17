#include<stdio.h>
int min_val_fn(int x,int y,k)
{
	int center_pos = k/2;
	return abs(center_pos - x) + abs(center_pos - y ) ;
}
int seats[][];

int max_seats_in_row[]; 
int min_seat_allocation_function(int threater_size, int company_size )
{  
    //use calloc for the allocation of the memory
    /*
    4
    2
    0
    1
    3
    5
    */
    for(int row = 0 ; row < threater_size ; row++){
        if (company_size <= max_seats_in_row[row] ){
        }
    }
}
int main ()
{
	
	int numberofrequest;
	int threater_size;
	int company_size[1000];

	scanf("%d",numberofrequest);
	scanf("%d",threater_size);

	for(int request_index = 0 ;  request_index < numberofrequest ; request_index++ ){
		int member_in_company;
		scanf ("%d",member_in_company);
		company_size[request_index] = member_in_company;
	    seat_function()
	}  
	return 0;
}
