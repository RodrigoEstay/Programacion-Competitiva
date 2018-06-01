#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lineScan(char *name);

int main(){
	
}


int lineScan(char *name){
	char c, line[300], pos=0, type=0;
	while(1){
		c=getc(stdin);
		if(c=='\n' || c==EOF){
			line[pos]='\0';
			break;
		}
		if((c>='a' || c<='z') && !type)
			type=1;
		else if((c>='A' || c<='Z') && !type)
			type=2;
		line[pos]=c;
		++pos;
	}
	if(!strcmp(line,"0"))
		return 0;
	if(!strcmp(line,"1"))
		return 1;
	if(type==1){
		strcpy(line,name);
		return 2;
	}
	if(type==2){
		strcpy(line,name);
		return 3;
	}
	return -1;
}

