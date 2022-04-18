/*
Dania Nasereddin
5-5-21
This program prompts the user to enter the number of values to be summed.
Then it creates a dynamic array of that size and repeatedly prompt the user
to enter values until the array is full. Then it will print the sum of the values.
You will then ask the user for 3 numbers and for each value it will say whether
it is in the array or not. If the value is not in the array append it to the array.
In the end it will delete the dynamic array before terminating the program.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *sumNums = NULL;
  int num, value;
  printf("Enter the number of values to be summed: ");
  scanf("%d",&num);//user inputs the size of array and stored in num
  //dynamically create an array of size num
  sumNums = (int*)malloc(sizeof(int)*num);
  //for loop to input integers into the array until its full
  for(int i = 0; i < num; i++)
  {
    printf("Enter a value for %d: ", i + 1);
    scanf("%d",&sumNums[i]);
  }
  int sum = 0;
  //compute sum of all entered values
  for(int i = 0; i < num; i++)
  {
    sum += sumNums[i];
  }
  printf("Sum: %d\n",sum);//displays the sum
  //searchs for 3 values in the array
  for(int j = 0;j < 3; j++)
  {
    printf("Enter the value to search for in the array: ");
    scanf("%d",&value);//user input for what number to look for in the array
    int inArray = 0;
    // loop over the array to search for value
    for(int i = 0;i < num; i++)
    {
      if(sumNums[j] == value) //if value found, set inArray to true(1)
      {
        inArray = 1;
        break; //leave loop
      }
    }
    if(inArray) //if value found
    {
      printf("%d was found in the array\n",value);
    }
    else //if value not found, insert the value at the end of array
    {
      printf("%d was not found in the array\n",value);
      //create a temporary array of size 1 more than original
      int* temp = (int*)malloc(sizeof(int)*(num + 1));
      //loop to copy the elements from numbers into temp
      for(int i = 0; i < num; i++)
      {
        temp[i] = sumNums[i];
      }
      temp[num] = value; //insert value at the end of array
      num++; //increment num by 1
      free(sumNums); //release the memory allocated to sumNums
      sumNums = temp; //update numbers to point to temp
    }
  }
  free(sumNums); //frees the memory allocated to sunNums
  return 0;
}
