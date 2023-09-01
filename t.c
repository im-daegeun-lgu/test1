#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char filter_date1[] = "2010";
char filter_date2[] = "2020"; 
//char chk_str[]="";
char chk_str[]="";
int gf_getContentID(char *strInput, int nPos, char* strReturn);
int IsDigitBuf(char *sBuf, int nLen);

char category_ids[] ="A001|A002|A003|A004|A005|A006" ;
int main () {

	char pass_yn='N';
	char tt[10];

	printf(" strcmp test : %d \n ", strcmp("2","3"));
	memset(tt , 0x00 , sizeof(tt));
	tt[0] = 0x00;

	printf("date 1:%s\n",filter_date1);
	printf("date 2:%s\n",filter_date2);

	printf("i30Date:%s\n",chk_str);

	int rtn1 = strncmp(filter_date1,chk_str,4);
	int rtn2 = strncmp(filter_date2,chk_str,4);

	int strncmpRtn = strncmp("",tt,3);

	printf(" strncmp result : %d\n",strncmpRtn);

	printf("comp 1 :%d\n",rtn1);
	printf("comp 2 :%d\n",rtn2);

	printf("comp3-1 :%d\n", (int)strncmp("","2010",4));
	printf("comp3-2 :%d\n", (int)strncmp("2010","",4));

	
	pass_yn='N';

	printf("------1\n");
	printf("------1\n");
	if(strncmp(filter_date1,chk_str,4) <= 0) {
	printf("------2\n");
		printf(" date 1 < i30Date\n");
			
		if(!(strncmp(chk_str ,filter_date2,4) < 0)) {
			printf("------3\n");
			pass_yn='Y';
			printf(" date 2 > i30Date\n");
		}
		printf("------4\n");
	} else {
		printf("------5\n");
		pass_yn='Y';
	}

	printf("pass_YN:%c\n",pass_yn);


	printf("0,org_cat_id] :%s\n",category_ids);

	char c_cat_id[50+1];
	int idx = 1;
	memset(c_cat_id , 0x00 , sizeof(c_cat_id));
	int testN = gf_getContentID(category_ids,idx, c_cat_id);
	printf("1, c_cat_id[%d] :%s - %s\n",idx , c_cat_id , category_ids);
	
	testN = gf_getContentID(category_ids,idx, c_cat_id);
	printf("2, c_cat_id[%d] :%s - %s\n",idx , c_cat_id , category_ids);

	testN = gf_getContentID(category_ids,idx, c_cat_id);
	printf("3, c_cat_id[%d] :%s - %s\n",idx , c_cat_id , category_ids);

	testN = gf_getContentID(category_ids,idx, c_cat_id);
	printf("4. c_cat_id[%d] :%s - %s\n",idx , c_cat_id , category_ids);

	testN = gf_getContentID(category_ids,idx, c_cat_id);
	printf("5. c_cat_id[%d] :%s - %s\n",idx , c_cat_id , category_ids);

	testN = gf_getContentID(category_ids,idx, c_cat_id);
	printf("6. c_cat_id[%d] :%s - %s\n",idx , c_cat_id , category_ids);

	testN = gf_getContentID(category_ids,idx, c_cat_id);
	printf("7. c_cat_id[%d] :%s - %s\n",idx , c_cat_id , category_ids);


	printf(" isDigit : [%d]\n",(int)IsDigitBuf("0",strlen("0"))); 

	return 0;
}


int gf_getContentID(char *strInput, int nPos, char* strReturn)
{
     int nReturn = -1;
     int nRoop = 0;
     char *ptr1 = strInput, *ptr2;
     
     if ( strlen(strInput) == 0 ) return nReturn;

     for ( nRoop = 0 ; nRoop < nPos ; nRoop++ ) {
          if ( NULL == ptr1  ) {
               break;
          }
          // 찾으면
          if( (nRoop+1) == nPos ) {
               ptr2 = strchr( ptr1, '|' );
               if( NULL != ptr2 )
               {
                    //ptr1++;
                    memcpy(strReturn, ptr1, ptr2 - ptr1 );
                    //printf("[strReturn=%s]\n", strReturn);
                    nReturn = 1;
               }
               break;
          }
          else
          {
               //memcpy(strReturn, 0x00, 1 );
          }
          ptr1++;
     }
     
     if ( NULL == ptr2 || strlen(ptr2) == 0 ) return -1;
     strcpy((char*)category_ids ,ptr2+1);
     return nReturn;
}


int IsDigitBuf(char *sBuf, int nLen)
{
	int  i;
	printf(" -- isDigit len  : %d \n",nLen);

	for(i=0; i<nLen; i++)
	{
		if(!isdigit((int)sBuf[i]))
		{
			return(0);
		}
	}
	return(1);
}

