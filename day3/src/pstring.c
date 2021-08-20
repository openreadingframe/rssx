#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#include "../pstring.h"

//	create an object of PString with its content as s
PString* psCreate(const char* s)
{
    PString *p;
    

    p = (PString*)malloc(sizeof(int)+strlen(s));

    p->length = strlen(s);
    int i;

    for (i=0; i<strlen(s); i++){
        p->content[i] = s[i];
    }

    

    return p;

}

//	release the object ps
void psFree(PString *ps)
{
    free(ps);

}

//	returns the number of characters in the PString object, i.e. the length of the string
int psLength(const PString* ps)
{
    return ps->length;

}

//----------------------------------------------------

//	print ps
void psPrint(const PString* ps)
{

    int i;
    for (i=0; i<ps->length; i++){
        printf("%c",ps->content[i]);
    }
    //printf("\n");

}

//	read a word, which is seperated by space
PString* psReadWord()
{
    char temp[1000];
    char c;
    int len = 0;
    while ((c = getchar()) != ' ' &&  c!='\n' && c!=EOF){
        temp[len++] = c;
        if (c==' ' || c=='\n')
            break;
    }

    temp[len] = '\0';

    PString *ps = psCreate(temp);

    return ps;
}

PString* psReadLine()
{
    char temp[1000];
    char c;
    int len = 0;
    while ((c = getchar()) != '\n' && c!=EOF){
        temp[len++] = c;
        if ('\n' == c)
            break;
    }

    temp[len] = '\0';

    PString *ps = psCreate(temp);

    return ps;

}

//	compare two PString objects
//	returns -1 if ps1 is < ps2; 0 if ps1 == ps2; 1 if ps1 > ps2
int psCompare(const PString* ps1, const PString* ps2)
{
    int ret = 0;
    //cnt is the min of the two lengths
    int cnt = ps1->length < ps2->length ? ps1->length : ps2->length;
    int i;
    for (i=0; i<cnt; i++){
        if (ps1->content[i] < ps2->content[i]){

            ret = -1;
            return ret;

        }else if (ps1->content[i] > ps2->content[i]){

            ret = 1;
            return ret;

        }
        //else
    }

    if (ps1->length < ps2->length){
        ret = -1;
    }else if (ps1->length > ps2->length){
        ret = 1;
    }else{
        ret = 0;
    }


    return ret;

}

//--------------------------------------------------
//	clone a PString object
//	return the new one
PString* psClone(const PString *ps)
{

    PString *p;

    p = (PString*)malloc(sizeof(int)+ps->length);

    p->length = ps->length;
    int i;

    for (i=0; i<p->length; i++){
        p->content[i] = ps->content[i];
    }

    return p;


}

//-----------------------------------
//	concat two PString into a new one
//	return the new one
PString* psConcat(const PString* ps1, const PString* ps2)
{

    PString *p;
    
    p = (PString*)malloc(sizeof(int)+ps1->length+ps2->length);

    p->length = ps1->length + ps2->length;
    int i;

    for (i=0; i<ps1->length; i++){

        p->content[i] = ps1->content[i];

    }
    for (i=0; i<ps2->length; i++){

        p->content[i+ps1->length] = ps2->content[i];

    }

    return p;

}

//-------------------------------------
//	find the location of ch in the ps
//	return the location of the first ch in ps, -1 if ch is not in ps
int psFindChar(const PString* ps, char ch)
{
    int idx = -1;
    int i;
    for (i=0; i<ps->length; i++){
        
        if (ps->content[i] == ch){
            idx = i;
            break;
        }
    }

    return idx;
}

//-------------------------
//	find the first location of ps2 in ps1
//	return the location, NULL is not found
int psFindString(const PString* ps1, const PString* ps2)
{
    int idx = -1;

    if (ps2->length==0 || ps1==NULL || ps2==NULL){
        return 0;
    }
    int i,j;
    for (i=0; i<ps1->length; i++){
        
        if (ps1->content[i] == ps2->content[0]){
            for (j=1; j<ps2->length && (i+j)<ps1->length; j++){
                if (ps1->content[i+j] != ps2->content[j]){
                    break;
                }else{

                }
            }
            if (j==ps2->length){
                idx = i;
                break;
            }else{

            }
            
        }
    }

    return idx;
}

//--------------------------
//	get rid of the space at both end
//	return the new created string
PString* psTrim(const PString* ps)
{
    int i;
    int left, right;
    left  = 0;
    right = ps->length-1;
    for (i=0; i<ps->length; i++){
        if (ps->content[i]==' '){
            left++;
        }else{
            break;
        }
    }

    for (i=ps->length-1; i>=0; i--){
        if (ps->content[i]==' '){
            right--;
        }else{
            break;
        }
    }


    //create
    PString *p;
    if (right < left){
        p = (PString*)malloc(sizeof(int));
        p->length = 0;
        
    }else{
        p = (PString*)malloc(sizeof(int)+right-left+1);

        p->length = right-left+1;

        for (i=0; i<p->length; i++){
            p->content[i] = ps->content[i+left];
        }
    }
    

    return p;
}

//----------------------
//	turn every character in ps into lower case
//	return the new lowered string
PString* psLower(const PString* ps)
{
    //like the clone
    PString *p;

    p = (PString*)malloc(sizeof(int)+ps->length);

    p->length = ps->length;
    int i;

    for (i=0; i<p->length; i++){
        if (ps->content[i] >= 'A' && ps->content[i] <= 'Z')
            p->content[i] = ps->content[i] - 'A' + 'a';
        else
            p->content[i] = ps->content[i];
    }

    return p;

}

//	turn every character in ps into upper case
//	return the new uppered string
PString* psUpper(const PString* ps)
{
    PString *p;

    p = (PString*)malloc(sizeof(int)+ps->length);

    p->length = ps->length;
    int i;

    for (i=0; i<p->length; i++){
        if (ps->content[i] >= 'a' && ps->content[i] <= 'z')
            p->content[i] = ps->content[i] - 'a' + 'A';
        else
            p->content[i] = ps->content[i];
    }

    return p;
}

//----------------------------
//	take a subset of the string ps. The subset is from begin to end.
//	For example, psSubstring(psCreate(“0123456789”), 3,5) returns a PString as “345”
//	return the new extracted string
PString* psSubstring(const PString* ps, int begin, int end)
{

    //create
    PString *p;

    p = (PString*)malloc(sizeof(int)+end-begin);

    p->length = end-begin;
    int i;
    for (i=0; i<p->length; i++){
        p->content[i] = ps->content[i+begin];
    }

    return p;
}

//--------------------------
//	replace every ch1 in ps with ch2
//	return the replaced string
PString* psReplace(const PString* ps, char ch1, char ch2)
{

    PString *p;

    p = (PString*)malloc(sizeof(int)+ps->length);

    p->length = ps->length;
    int i;

    for (i=0; i<p->length; i++){
        if (ps->content[i] == ch1)
            p->content[i] = ch2;
        else
            p->content[i] = ps->content[i];
    }

    return p;
}


//	return the char at the index
char psChar(const PString* ps, int index)
{

    return ps->content[index];
}

//	return 1 if the ps1 begins with ps2, 0 otherwise
int psBeginWith(const PString* ps1, const PString* ps2)
{
    int ret = psFindString(ps1, ps2)==0 ? 1 : 0;
    return ret;

}

