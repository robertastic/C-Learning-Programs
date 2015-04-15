/*
* Strings
 */


#include <stdio.h>
#define MAX 25
//Prototypes********************************************************
int length(char *str);
int replace (char *str1, int rep);
void copy(char *, char*);
void concatenate (char *, char *, char *);
int prefix(char *, char *);
int substring(char *, char *);
//Main**************************************************************
int main(void){

	char str1[MAX];
	char copy_str1[MAX];
	char str2[MAX];
	char con_str[MAX];
	char pre[MAX];
	char check_pre[MAX];
	char sub[MAX];
	char check_sub[MAX];
	int rep;
	
	//COPY
	printf("Enter the first string: ");
	scanf("%s",str1);
	printf("\nFirst string is %s ",str1);
	copy(str1,copy_str1);
	printf("\nCopy of first string is %s ",copy_str1);
	
	//REPLACE
	printf("\nEnter an index location: ");
	scanf("%d",&rep);
	replace(str1,rep);
	printf("\nString after replacement operation is %s ",str1);
	
	//CONCATENATE
	printf("\nEnter second string (concatenate operation): ");
	scanf("%s",str2);
	concatenate(str1,str2,con_str);
	printf("\nSecond string is %s ",str2);
	printf("\nMerged string is %s ",con_str);
	
	//PREFIX
	printf("\nEnter a string (prefix operation): ");
	scanf("%s",pre);
	printf("\nEnter a string to check for prefix: ");
	scanf("%s",check_pre);
	if(prefix(pre,check_pre)==1){
		printf("\nString %s has a prefix of %s",pre,check_pre);
	} else {
		printf("\nString %s does not have a prefix of %s",pre,check_pre);
	};

	//BONUS (Does not work properly)
	printf("\nEnter a string (substring operation): ");
	scanf("%s",sub);
	printf("\nEnter a tring to check for substring: ");
	scanf("%s",check_sub);

	if(substring(sub,check_sub)==1){
		printf("\nString %s has a substring of %s",sub,check_sub);
	} else {
		printf("\nString %s does not have a substring of %s",sub,check_sub);
	};

return 0;
};

//Functions*********************************************************
int length(char *str){
	char *temp = str;
	int i;
	for (i=0;*temp != '\0';i++)
	{
		temp++;
	}
	return i;
};

int replace(char *str1,int rep){
	int len=length(str1);
	if (rep>len||rep<0){
		return 0;
	} else {
		*(str1+rep)='#';
		return 1;
	};

};
void copy(char *str1, char *copy_str1){
	int i,len=length(str1);
	for (i=0;i<=len;++i){
		(*copy_str1)=(*str1);
		copy_str1++;
		str1++;
	};
	*copy_str1='\0';
};

void concatenate (char *str1, char *str2, char *con_str){
	int i;
	int str1_length=length(str1);
	int str2_length=length(str2);
	for(i=0;i<(str1_length);i++){
		*con_str=*str1;
		str1++;
		con_str++;
	};
	for(i=0;i<(str2_length);i++){
		*con_str=*str2;
		str2++;
		con_str++;
	};
	*con_str='\0';		
};

int prefix(char *pre, char *check_pre){
	int i,pre_length=length(pre),result=0;
	for(i=0;i<pre_length;i++){
		if(*check_pre=='\0'||*pre=='\0')
			break;
		if(*check_pre==*pre){
			pre++;
			check_pre++;
			result=1;
		}else{
			result=0;
			break;
		};
	};
	return result;
}

//Bonus doesn't work properly
int substring(char *sub, char *check_sub){
	int i,j,sub_length=length(sub),check_sub_length=length(check_sub),result=0;
	for(i=0;i<sub_length;i++){
		for(j=0;j<check_sub_length;j++){
			if(*check_sub=='\0'||*sub=='\0')
				break;
			if(*check_sub==*sub){
				result = 1;
			} else {
				result = 0;
			};
		};
	};
	return result;
}

