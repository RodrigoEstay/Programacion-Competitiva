#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lineScan(char *name);

int main(){
	int namesCount, proyectsCount, type, signedUp[100], i, repeat;
	char names[10000][300], proyects[100][300], tempName[300];
	while(1){
		namesCount=0, proyectsCount=0, proyectsCount=-1;
		while(1){
			type=lineScan(tempName);
			if(type==-1)
				continue;
			if(type==0)
				return 0;
			if(type==1)
				break;
			if(type==2){
				strcpy(tempName,names[namesCount]);
				++namesCount;
				for(i=namesCount-signedUp[proyectsCount], repeat=0;i<namesCount;++i){
					if(!strcmp(names[i],names[namesCount])){
						repeat=1;
						--namesCount;
						break;
					}
				}
				if(!repeat){
					++signedUp[proyectsCount];
				}
			}
			else if(type==3){
				strcpy(tempName,proyects[proyectsCount]);
				++proyectsCount;
				signedUp[proyectsCount]=0;
			}
		}
		for(i=0;i<=proyectsCount;++i){
			printf("%s %d\n", proyects[i], signedUp[i]);
		}
	}
	return 0;
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

