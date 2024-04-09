#include<stdio.h>

int dropGadget(int floor,int n){
  if(floor<=n){
    return 1;
else
   return 0;
  }
}
int HighestFloor(int n){
  int low=1;
  int high=n;
  int result=-1;

  while (low<=high){
    mid =(low +(high-low))/2;
    if(dropGadget(mid,n)){
      result=mid;
      low=mid+1;
    }else{
      high=mid-1;
    }
  }
  return result;
}
int main()
{
  int n;
  printf("Enter the number of floors in the building");
  scanf("%d",&n);

  int hf=HighestFloor(n);
  printf("The highest floor from which the gadget can be dropped without breaking is: %d\n',hf);

  return 0;
}
