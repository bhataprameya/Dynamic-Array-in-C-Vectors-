#include "vector.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Vector * initVector()
{
  Vector *new_vector = malloc(sizeof(Vector));
      new_vector->current_size=0;
      new_vector->max_size=0;
      new_vector->data=NULL;
      return new_vector;
}

void vectorInsert(Vector * array, int index, Data value)
{
   if(array->max_size<= index)
     {
       array->max_size=index * 2 + 1;
       Data *new_array= malloc(sizeof(Data)*(array->max_size));
       memset(new_array,0,(sizeof(Data) * (array->max_size)));
       memcpy(new_array,array->data,(sizeof(Data)*(array->current_size)));
       free(array->data);
       array->data=new_array;
     }
array->data[index]=value;
if(index >= array->current_size)
array->current_size=index+1;
}




Data * vectorRead(Vector * array, int index)
{
	if(index < array->current_size && index>=0)
 {  if (array->data[index].value !=NULL)
    return &array->data[index];
    else
    {
	array->data[index].value = -1;
  	return &array->data[index];
   }
 }
	else return NULL;
}


void vectorRemove(Vector * array, int index)
{

if(index<array->current_size)
	{
		Data *new_array = malloc(sizeof(int)* array->current_size - 1);
		memcpy(new_array,array->data,sizeof(int) *(index));
		memcpy(new_array+index, array->data+index+1,sizeof(int)*(array->current_size-index-1));
       free(array->data);
       array->data=new_array;
       array->current_size-=1;
		
	}
return;
}

void * deleteVector(Vector *array)
{
free(array->data);
free(array);
array=NULL;
return array;
}
   
void vectorInsertIncremental(Vector * array, int index, Data value)
{
	if(array->max_size<= index)
	{

		   while(array->max_size<= index)
			{
       				array->max_size=array->max_size + 1;
			}
       Data *new_array= malloc(sizeof(Data)*(array->max_size));
       memset(new_array,0,(sizeof(Data) * (array->max_size)));
       memcpy(new_array,array->data,(sizeof(Data)*(array->current_size)));
       free(array->data);
       array->data=new_array;
     }
array->data[index]=value;
if(index >= array->current_size)
array->current_size=index+1;
}
void vectorInsertMine(Vector * array, int index, Data value)
{
   if(array->max_size<= index)
     {
       array->max_size=index + array->current_size+ 1;
       Data *new_array= malloc(sizeof(Data)*(array->max_size));
       memset(new_array,0,(sizeof(Data) * (array->max_size)));
       memcpy(new_array,array->data,(sizeof(Data)*(array->current_size)));
       free(array->data);
       array->data=new_array;
     }
array->data[index]=value;
if(index >= array->current_size)
array->current_size=index+1;
}

