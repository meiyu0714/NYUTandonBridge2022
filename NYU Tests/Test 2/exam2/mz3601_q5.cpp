int findIndex(int s[], int x, int left, int right){
    if(x < s[left] || x > s[right] )
      return -1;//x does not exist in s[]
    if(left == right){
        if(s[left] == x)
          return left;
        else 
          return -1;
        }
    else{
        int middle = (left+right)/2; 
        if(x == s[middle])
          return middle;
        else if(x < s[middle]){
            right = middle - 1;
            return findIndex(s,x,left, right);
        }
        else{
            left = middle +1;
            return findIndex(s,x,left,right);
        }  
    }  
}