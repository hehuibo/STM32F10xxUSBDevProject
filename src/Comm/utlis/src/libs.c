/*
 ============================================================================
 Name        : utilslib.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "libs.h"

void StringToIp(const char *cp,unsigned int *ip){
	unsigned long val;
	unsigned char base;
	unsigned long parts[4];
	unsigned long *pp = parts;
	char c = *cp;
	
	for(;;){
		val = 0;
		base = 10;
		if(c == '0'){
			c = *++cp;
			base = 8;
		}
		
		for(;;){
			if((c>='0')&&(c<='9')){
				val= (val * base) + (int)(c-'0');
				c = *++cp;
			}
			else
				break;
		}
		
		if(c == '.'){
			*pp++ = val;
			c = *++cp;
		}
		else
			break;

	}
	val |= (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
     *ip =  val;
}
