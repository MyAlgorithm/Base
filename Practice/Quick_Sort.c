#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap( int *__lift, int *__right )
{
	int __tmp = *__lift;
	*__lift = *__right;
	*__right = __tmp;
}


int partition( int array[], int l, int r )
{
	int pivot = array[r];
	int curpos = l;
	int j;

	for( j = l; j<r; j++ )
	{
		if( array[j] < pivot )
		{
			swap( &array[j], &array[curpos] );
			curpos++;
		}
	}

	swap( &array[r], &array[curpos] );
	return curpos;
    
    
}

void quicksort( int array[], int l, int r )
{
    int interval;
    if( l < r )
    {
		interval = partition( array, l, r );
		quicksort( array, l, interval-1 );
		quicksort( array, interval+1, r );
	}
}


int test_quicksort()
{
	int number = 19;
	int *array = malloc( number*sizeof( int ) );
    if( array == NULL )
    {
        printf( "malloc failed\n" );
        return -1;
    }
    int i;

    printf( "----------------------------------------before quick sort--------------\n" );
    srand( time( NULL ) );
    for( i = 0; i < number; i++ )
    {
        array[i] = rand()%1000;
        printf( "\tarray[%d] = %d\n", i, array[i] );
    }

    printf( "----------------------------------------after quick sort-----------------\n" );
    
    quicksort( array, 0, number-1 );
    for( i = 0; i < number; i++ )
    {
        printf( "\tarray[%d] = %d\n", i, array[i] );
    }
    return 0;
}
int main()
{
	test_quicksort();
}
