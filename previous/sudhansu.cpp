#include<iostream>
int main(){
    int t ;
    printf("enter testcases");
    scanf("%d",&t) ; 

    for( int i = 0 ; i < t ; i++){
        int n ; 
     printf("enter the no of elements") ; 
      scanf("%d",&n) ; 

      int arr[n] ;

     for( int i = 0 ;i < n ; i++){
         printf("enter the element %d",i) ;
         scanf("%d",&arr[i]) ;  
         }

     for( int i = n-1 ; i >= 0 ; i--){
     printf("%d",arr[i]) ;
     }


     }



    }
