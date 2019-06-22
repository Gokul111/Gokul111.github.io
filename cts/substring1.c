#include<stdio.h>
#include<string.h>

int substr(char* str, char* sub , int start, int len){
    memcpy(sub, &str[start], len);
    sub[len] = '\0';
}

int substring(int length , char source[] ,  char destination[][100]){

int looper = 0 ,j,i;

for (i= 0 ; i < length ; i++ ){

    for(j =1 ; j <= (length - i) ; j++ ){
        substr(source , destination[looper] , i , j);
        looper+=1;
    }

}
return looper ;
}


int unique(char destination[][100] , char source[][100] , int count){

    int looper = 0 ,i,j ,flag = 0;

    for(i = 0 ; i < count ; i++){

            flag = 0;
            for (j = 0 ; j < looper ; j ++){
                if(strcmp(source[i] , destination[j]) == 0 ){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                    strcpy(destination[looper] , source[i]);
                    looper++;
            }
    }
 // For Printing Unique Values
 /*
    for(int i=0;i<looper;i++){
        printf("%s \n" , destination[i]);
    } */
    return looper;
}

int count(char string[] , char source[][100] , int count ){
    int ans = 0,i;
    for(i = 0 ; i < count ; i++){
        if(strcmp(source[i] , string) == 0){
            ans++;
            }
    } 
    return ans;
}

int fact(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}


int ncr(int total , int selection){
      	return (fact(total)/fact(selection)/fact(total-selection)) ;

}

int main(){

int length , subcount , unqcount ,queries ,ans , limit;

char word[20] , substrings[100][100], uniquestr[100][100];

scanf("%d %d",&length ,&queries);

scanf("%s" , word);


subcount = substring(length ,word ,substrings);
unqcount = unique(uniquestr , substrings , subcount);

for(int j = 0 ; j< queries ; j++){

ans = 0;

scanf("%d" , &limit);

for(int i = 0 ; i < unqcount ; i++){
    int total = count(uniquestr[i] , substrings , subcount ) ;
    if(total >= limit ){
        ans += ncr(total , limit);
    }
}
printf("%d\n" , ans);

}
return 0;
}