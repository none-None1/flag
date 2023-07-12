#include<cstdio>
#include<cstdlib>
#define gets Gets
char line[1000000];
char cell[1000000];
int p;
int Gets(char *str){ // Implement the insecure gets function so it can be used correctly in C++.
	char c;
	int i=0;
	while(1){
		c=getchar();
		if(c==EOF||c=='\n') str[i]='\0';
		if(c==EOF) return EOF;
		if(c=='\n') return 0;
		str[i]=c;
		i++;
	}
	return 0;
}
void error(){
	puts("Bad character");
	exit(1);
}
void run(char *line){
	for(int i=0;line[i];i++){
		switch(line[i]){
			case '\0':{
				
				break;
			}
			case '\t':{
				error();
				break;
			}
			case '\v':{
				error();
				break;
			}
			case '?':{
				cell[p]=getchar();
				if(cell[p]=='\t') error();
				if(cell[p]=='\v') error();
				break;
			}
			case '!':{
				if(cell[p]=='\t') error();
				if(cell[p]=='\v') error();
				putchar(cell[p]);
				break;
			}
			case '*':{
				cell[p]++;
				break;
			}
			case ':':{
				p--;
				break;
			}
			case ';':{
				p++;
				break;
			}
			case '_':{
				char c='\n';
				if(line[i+1]) c=line[i+1];
				if(c=='\t') error();
				putchar(c);
				i++;
				break;
			}
			default:{
				putchar(line[i]);
				break;
			}
		}
	}
}
int main(int argc,char *argv[]){
	if(argc>2){
		puts("Must run only one file");
		return 2;
	}
	if(argc==2) freopen(argv[1],"r",stdin);
	if(argc<2) printf("Flag REPL, see https://esolangs.org/wiki/Flag for more details\n> ");
	while(gets(line)!=EOF){
		int i=0;
		for(;line[i]==' ';i++) ;
		if(i==0) run(line+i);
		else if(i==1){
			while(1) run(line+i);
		}else if(i==2){
			while(cell[p]) run(line+i);
		}else{
			for(int I=1;I<i;I++) run(line+i);
		}
		if(argc<2) printf("> ");
	}
	return 0;
}

