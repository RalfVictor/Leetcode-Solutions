void moveZeroes(int* nums, int n) {
    int move[n];
    int i,j=n-1,x=0;
    for(i=0;i<n;i++){
        if(*(nums+i)!=0){
            move[x]=*(nums+i);
            x++;
        }else{
            move[j]=0;
            j--;
        }
    }
    for(i=0;i<n;i++){
        *(nums+i)=move[i];
    }
}