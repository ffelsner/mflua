/*1:*/
#line 58 "../../../texk/web2c/cwebdir/common.w"

/*5:*/
#line 102 "../../../texk/web2c/cwebdir/common.w"

#include <ctype.h> 

/*:5*//*8:*/
#line 165 "../../../texk/web2c/cwebdir/common.w"

#include <stdio.h> 

/*:8*//*22:*/
#line 471 "../../../texk/web2c/cwebdir/common.w"

#line 151 "../../../texk/web2c/cwebdir/comm-w2c.ch"
#include <stdlib.h>  
#define CWEB
#include "cpascal.h"
#include <kpathsea/kpathsea.h>  
#include "help.h"

/*:22*/
#line 59 "../../../texk/web2c/cwebdir/common.w"

#define ctangle 0
#define cweave 1 \

#define and_and 04
#define lt_lt 020
#define gt_gt 021
#define plus_plus 013
#define minus_minus 01
#define minus_gt 031
#define not_eq 032
#define lt_eq 034
#define gt_eq 035
#define eq_eq 036
#define or_or 037
#define dot_dot_dot 016
#define colon_colon 06
#define period_ast 026
#define minus_gt_ast 027 \

#define buf_size 1000
#define longest_name 1000
#define long_buf_size (buf_size+longest_name) 
#define xisspace(c) (isspace(c) &&((unsigned char) c<0200) ) 
#define xisupper(c) (isupper(c) &&((unsigned char) c<0200) )  \

#define max_include_depth 10 \

#define max_file_name_length 1024
#define cur_file file[include_depth]
#define cur_file_name file_name[include_depth]
#define cur_line line[include_depth]
#define web_file file[0]
#define web_file_name file_name[0] \

#define lines_dont_match (change_limit-change_buffer!=limit-buffer|| \
strncmp(buffer,change_buffer,limit-buffer) )  \

#define if_section_start_make_pending(b) {*limit= '!'; \
for(loc= buffer;xisspace(*loc) ;loc++) ; \
*limit= ' '; \
if(*loc=='@'&&(xisspace(*(loc+1) ) ||*(loc+1) =='*') ) change_pending= b; \
} \

#define max_sections 10239 \
 \

#define too_long() {include_depth--; \
err_print("! Include file name too long") ;goto restart;} \

#define kpse_find_cweb(name) kpse_find_file(name,kpse_cweb_format,true)  \

#define max_bytes 1000000 \

#define max_names 10239 \
 \

#define length(c) (c+1) ->byte_start-(c) ->byte_start
#define print_id(c) term_write((c) ->byte_start,length((c) ) )  \

#define hash_size 8501 \

#define llink link
#define rlink dummy.Rlink
#define root name_dir->rlink \
 \

#define first_chunk(p) ((p) ->byte_start+2) 
#define prefix_length(p) (int) ((unsigned char) *((p) ->byte_start) *256+ \
(unsigned char) *((p) ->byte_start+1) ) 
#define set_prefix_length(p,m) (*((p) ->byte_start) = (m) /256, \
*((p) ->byte_start+1) = (m) %256)  \

#define less 0
#define equal 1
#define greater 2
#define prefix 3
#define extension 4 \

#define bad_extension 5 \

#define spotless 0
#define harmless_message 1
#define error_message 2
#define fatal_message 3
#define mark_harmless {if(history==spotless) history= harmless_message;}
#define mark_error history= error_message \

#define confusion(s) fatal("! This can't happen: ",s)  \
 \

#define show_banner flags['b']
#define show_progress flags['p']
#define show_stats flags['s']
#define show_happiness flags['h']
#define show_kpathsea_debug flags['d'] \
 \

#define update_terminal fflush(stdout)  \

#define new_line putchar('\n') 
#define putxchar putchar
#define term_write(a,b) fflush(stdout) ,fwrite(a,sizeof(char) ,b,stdout) 
#define C_printf(c,a) fprintf(C_file,c,a) 
#define C_putc(c) putc(c,C_file)  \
 \

#define ctangle_banner "This is CTANGLE, Version 3.64"
#define cweave_banner "This is CWEAVE, Version 3.64" \


#line 60 "../../../texk/web2c/cwebdir/common.w"

/*2:*/
#line 73 "../../../texk/web2c/cwebdir/common.w"

#line 75 "../../../texk/web2c/cwebdir/common.w"
boolean program;

/*:2*//*7:*/
#line 159 "../../../texk/web2c/cwebdir/common.w"

char buffer[long_buf_size];
char*buffer_end= buffer+buf_size-2;
char*limit= buffer;
char*loc= buffer;

/*:7*//*10:*/
#line 214 "../../../texk/web2c/cwebdir/common.w"

int include_depth;
FILE*file[max_include_depth];
FILE*change_file;
char file_name[max_include_depth][max_file_name_length];

char change_file_name[max_file_name_length];
#line 222 "../../../texk/web2c/cwebdir/common.w"
int line[max_include_depth];
int change_line;
int change_depth;
boolean input_has_ended;
boolean changing;
boolean web_file_open= 0;

/*:10*//*20:*/
#line 418 "../../../texk/web2c/cwebdir/common.w"

typedef unsigned short sixteen_bits;
sixteen_bits section_count;
boolean changed_section[max_sections];
boolean change_pending;

boolean print_where= 0;

/*:20*//*29:*/
#line 594 "../../../texk/web2c/cwebdir/common.w"

typedef struct name_info{
char*byte_start;
/*33:*/
#line 631 "../../../texk/web2c/cwebdir/common.w"

struct name_info*link;

/*:33*//*42:*/
#line 730 "../../../texk/web2c/cwebdir/common.w"

union{
struct name_info*Rlink;

char Ilk;
}dummy;

/*:42*//*57:*/
#line 1062 "../../../texk/web2c/cwebdir/common.w"

char*equiv_or_xref;

/*:57*/
#line 597 "../../../texk/web2c/cwebdir/common.w"

}name_info;
typedef name_info*name_pointer;
char byte_mem[max_bytes];
char*byte_mem_end= byte_mem+max_bytes-1;
name_info name_dir[max_names];
name_pointer name_dir_end= name_dir+max_names-1;

/*:29*//*31:*/
#line 617 "../../../texk/web2c/cwebdir/common.w"

name_pointer name_ptr;
char*byte_ptr;

/*:31*//*34:*/
#line 644 "../../../texk/web2c/cwebdir/common.w"

typedef name_pointer*hash_pointer;
name_pointer hash[hash_size];
hash_pointer hash_end= hash+hash_size-1;
hash_pointer h;

/*:34*//*58:*/
#line 1082 "../../../texk/web2c/cwebdir/common.w"

int history= spotless;

/*:58*//*69:*/
#line 1220 "../../../texk/web2c/cwebdir/common.w"

int argc;
char**argv;
char C_file_name[max_file_name_length];
char tex_file_name[max_file_name_length];
char idx_file_name[max_file_name_length];
char scn_file_name[max_file_name_length];
boolean flags[128];

/*:69*//*79:*/
#line 1370 "../../../texk/web2c/cwebdir/common.w"

FILE*C_file;
FILE*tex_file;
FILE*idx_file;
FILE*scn_file;
#line 576 "../../../texk/web2c/cwebdir/comm-w2c.ch"
FILE*active_file;
char*found_filename;
#line 1376 "../../../texk/web2c/cwebdir/common.w"

/*:79*/
#line 61 "../../../texk/web2c/cwebdir/common.w"

/*3:*/
#line 83 "../../../texk/web2c/cwebdir/common.w"
int phase;

/*:3*//*11:*/
#line 240 "../../../texk/web2c/cwebdir/common.w"

char change_buffer[buf_size];
char*change_limit;

/*:11*/
#line 62 "../../../texk/web2c/cwebdir/common.w"

/*35:*/
#line 650 "../../../texk/web2c/cwebdir/common.w"

#line 260 "../../../texk/web2c/cwebdir/comm-w2c.ch"
extern int names_match P4H(name_pointer,char*,int,char);
#line 652 "../../../texk/web2c/cwebdir/common.w"

/*:35*//*40:*/
#line 703 "../../../texk/web2c/cwebdir/common.w"

#line 280 "../../../texk/web2c/cwebdir/comm-w2c.ch"
extern void init_p P2C(name_pointer,p,char,t);
#line 705 "../../../texk/web2c/cwebdir/common.w"

/*:40*//*48:*/
#line 852 "../../../texk/web2c/cwebdir/common.w"

#line 327 "../../../texk/web2c/cwebdir/comm-w2c.ch"
extern void init_node P1C(name_pointer,node);
#line 854 "../../../texk/web2c/cwebdir/common.w"

/*:48*//*55:*/
#line 1017 "../../../texk/web2c/cwebdir/common.w"

#line 373 "../../../texk/web2c/cwebdir/comm-w2c.ch"
int section_name_cmp P3H(char**,int,name_pointer);
#line 1019 "../../../texk/web2c/cwebdir/common.w"

/*:55*//*59:*/
#line 1092 "../../../texk/web2c/cwebdir/common.w"

#line 392 "../../../texk/web2c/cwebdir/comm-w2c.ch"
void err_print P1H(char*);
#line 1094 "../../../texk/web2c/cwebdir/common.w"

/*:59*//*62:*/
#line 1140 "../../../texk/web2c/cwebdir/common.w"

#line 410 "../../../texk/web2c/cwebdir/comm-w2c.ch"
int wrap_up P1H(void);
extern void print_stats P1H(void);
#line 1143 "../../../texk/web2c/cwebdir/common.w"

/*:62*//*65:*/
#line 1173 "../../../texk/web2c/cwebdir/common.w"

#line 427 "../../../texk/web2c/cwebdir/comm-w2c.ch"
void fatal P2H(char*,char*);
void overflow(char*);
#line 1175 "../../../texk/web2c/cwebdir/common.w"

/*:65*//*71:*/
#line 1251 "../../../texk/web2c/cwebdir/common.w"

#line 495 "../../../texk/web2c/cwebdir/comm-w2c.ch"
void scan_args P1H(void);
#line 1253 "../../../texk/web2c/cwebdir/common.w"

/*:71*/
#line 63 "../../../texk/web2c/cwebdir/common.w"


/*:1*//*4:*/
#line 89 "../../../texk/web2c/cwebdir/common.w"

void
#line 51 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 common_init P1H(void)
#line 92 "../../../texk/web2c/cwebdir/common.w"
{
#line 57 "../../../texk/web2c/cwebdir/comm-w2c.ch"
/*32:*/
#line 621 "../../../texk/web2c/cwebdir/common.w"

name_dir->byte_start= byte_ptr= byte_mem;
name_ptr= name_dir+1;
name_ptr->byte_start= byte_mem;

/*:32*//*36:*/
#line 655 "../../../texk/web2c/cwebdir/common.w"

for(h= hash;h<=hash_end;*h++= NULL);

/*:36*//*43:*/
#line 737 "../../../texk/web2c/cwebdir/common.w"

root= NULL;

/*:43*/
#line 57 "../../../texk/web2c/cwebdir/comm-w2c.ch"
;
/*24:*/
#line 188 "../../../texk/web2c/cwebdir/comm-w2c.ch"

kpse_set_program_name(argv[0],"cweb");
#line 473 "../../../texk/web2c/cwebdir/common.w"

/*:24*/
#line 58 "../../../texk/web2c/cwebdir/comm-w2c.ch"
;
#line 94 "../../../texk/web2c/cwebdir/common.w"
/*70:*/
#line 1233 "../../../texk/web2c/cwebdir/common.w"

#line 487 "../../../texk/web2c/cwebdir/comm-w2c.ch"
show_banner= show_happiness= show_progress= 1;
#line 1235 "../../../texk/web2c/cwebdir/common.w"

/*:70*/
#line 94 "../../../texk/web2c/cwebdir/common.w"
;
/*80:*/
#line 1377 "../../../texk/web2c/cwebdir/common.w"

scan_args();
if(program==ctangle){
if((C_file= fopen(C_file_name,"w"))==NULL)
fatal("! Cannot open output file ",C_file_name);

}
else{
if((tex_file= fopen(tex_file_name,"w"))==NULL)
fatal("! Cannot open output file ",tex_file_name);
}

/*:80*/
#line 95 "../../../texk/web2c/cwebdir/common.w"
;
}

/*:4*//*9:*/
#line 172 "../../../texk/web2c/cwebdir/common.w"

#line 67 "../../../texk/web2c/cwebdir/comm-w2c.ch"
int input_ln P1C(FILE*,fp)
#line 175 "../../../texk/web2c/cwebdir/common.w"
{
register int c= EOF;
register char*k;
if(feof(fp))return(0);
limit= k= buffer;
while(k<=buffer_end&&(c= getc(fp))!=EOF&&c!='\n')
if((*(k++)= c)!=' ')limit= k;
if(k> buffer_end)
if((c= getc(fp))!=EOF&&c!='\n'){
ungetc(c,fp);loc= buffer;err_print("! Input line too long");

}
if(c==EOF&&limit==buffer)return(0);

return(1);
}

/*:9*//*12:*/
#line 251 "../../../texk/web2c/cwebdir/common.w"

void
#line 88 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 prime_the_change_buffer P1H(void)
#line 254 "../../../texk/web2c/cwebdir/common.w"
{
change_limit= change_buffer;
/*13:*/
#line 265 "../../../texk/web2c/cwebdir/common.w"

while(1){
change_line++;
if(!input_ln(change_file))return;
if(limit<buffer+2)continue;
if(buffer[0]!='@')continue;
if(xisupper(buffer[1]))buffer[1]= tolower(buffer[1]);
if(buffer[1]=='x')break;
if(buffer[1]=='y'||buffer[1]=='z'||buffer[1]=='i'){
loc= buffer+2;
err_print("! Missing @x in change file");

}
}

/*:13*/
#line 256 "../../../texk/web2c/cwebdir/common.w"
;
/*14:*/
#line 282 "../../../texk/web2c/cwebdir/common.w"

do{
change_line++;
if(!input_ln(change_file)){
err_print("! Change file ended after @x");

return;
}
}while(limit==buffer);

/*:14*/
#line 257 "../../../texk/web2c/cwebdir/common.w"
;
/*15:*/
#line 292 "../../../texk/web2c/cwebdir/common.w"

{
change_limit= change_buffer+(limit-buffer);
strncpy(change_buffer,buffer,limit-buffer+1);
}

/*:15*/
#line 258 "../../../texk/web2c/cwebdir/common.w"
;
}

/*:12*//*16:*/
#line 320 "../../../texk/web2c/cwebdir/common.w"

void
#line 96 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 check_change P1H(void)
#line 323 "../../../texk/web2c/cwebdir/common.w"
{
int n= 0;
if(lines_dont_match)return;
change_pending= 0;
if(!changed_section[section_count]){
if_section_start_make_pending(1);
if(!change_pending)changed_section[section_count]= 1;
}
while(1){
changing= 1;print_where= 1;change_line++;
if(!input_ln(change_file)){
err_print("! Change file ended before @y");

change_limit= change_buffer;changing= 0;
return;
}
if(limit> buffer+1&&buffer[0]=='@'){
char xyz_code= xisupper(buffer[1])?tolower(buffer[1]):buffer[1];
/*17:*/
#line 358 "../../../texk/web2c/cwebdir/common.w"

if(xyz_code=='x'||xyz_code=='z'){
loc= buffer+2;err_print("! Where is the matching @y?");

}
else if(xyz_code=='y'){
if(n> 0){
loc= buffer+2;
printf("\n! Hmm... %d ",n);
err_print("of the preceding lines failed to match");

}
change_depth= include_depth;
return;
}

/*:17*/
#line 342 "../../../texk/web2c/cwebdir/common.w"
;
}
/*15:*/
#line 292 "../../../texk/web2c/cwebdir/common.w"

{
change_limit= change_buffer+(limit-buffer);
strncpy(change_buffer,buffer,limit-buffer+1);
}

/*:15*/
#line 344 "../../../texk/web2c/cwebdir/common.w"
;
changing= 0;cur_line++;
while(!input_ln(cur_file)){
if(include_depth==0){
err_print("! CWEB file ended during a change");

input_has_ended= 1;return;
}
include_depth--;cur_line++;
}
if(lines_dont_match)n++;
}
}

/*:16*//*18:*/
#line 378 "../../../texk/web2c/cwebdir/common.w"

void
#line 104 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 reset_input P1H(void)
#line 381 "../../../texk/web2c/cwebdir/common.w"
{
limit= buffer;loc= buffer+1;buffer[0]= ' ';
/*19:*/
#line 393 "../../../texk/web2c/cwebdir/common.w"

#line 116 "../../../texk/web2c/cwebdir/comm-w2c.ch"
if((found_filename= kpse_find_cweb(web_file_name))==NULL||
(web_file= fopen(found_filename,"r"))==NULL){
fatal("! Cannot open input file ",web_file_name);
}else if(strlen(found_filename)<max_file_name_length){
strcpy(web_file_name,found_filename);
free(found_filename);
}
#line 399 "../../../texk/web2c/cwebdir/common.w"


web_file_open= 1;
#line 129 "../../../texk/web2c/cwebdir/comm-w2c.ch"
if((found_filename= kpse_find_cweb(change_file_name))==NULL||
(change_file= fopen(found_filename,"r"))==NULL){
fatal("! Cannot open change file ",change_file_name);
}else if(strlen(found_filename)<max_file_name_length){
strcpy(change_file_name,found_filename);
free(found_filename);
}
#line 404 "../../../texk/web2c/cwebdir/common.w"

/*:19*/
#line 383 "../../../texk/web2c/cwebdir/common.w"
;
include_depth= 0;cur_line= 0;change_line= 0;
change_depth= include_depth;
changing= 1;prime_the_change_buffer();changing= !changing;
limit= buffer;loc= buffer+1;buffer[0]= ' ';input_has_ended= 0;
}

/*:18*//*21:*/
#line 426 "../../../texk/web2c/cwebdir/common.w"

#line 143 "../../../texk/web2c/cwebdir/comm-w2c.ch"
int get_line P1H(void)
#line 428 "../../../texk/web2c/cwebdir/common.w"
{
restart:
if(changing&&include_depth==change_depth)
/*27:*/
#line 537 "../../../texk/web2c/cwebdir/common.w"
{
change_line++;
if(!input_ln(change_file)){
err_print("! Change file ended without @z");

buffer[0]= '@';buffer[1]= 'z';limit= buffer+2;
}
if(limit> buffer){
if(change_pending){
if_section_start_make_pending(0);
if(change_pending){
changed_section[section_count]= 1;change_pending= 0;
}
}
*limit= ' ';
if(buffer[0]=='@'){
if(xisupper(buffer[1]))buffer[1]= tolower(buffer[1]);
if(buffer[1]=='x'||buffer[1]=='y'){
loc= buffer+2;
err_print("! Where is the matching @z?");

}
else if(buffer[1]=='z'){
prime_the_change_buffer();changing= !changing;print_where= 1;
}
}
}
}

/*:27*/
#line 431 "../../../texk/web2c/cwebdir/common.w"
;
if(!changing||include_depth> change_depth){
/*26:*/
#line 520 "../../../texk/web2c/cwebdir/common.w"
{
cur_line++;
while(!input_ln(cur_file)){
print_where= 1;
if(include_depth==0){input_has_ended= 1;break;}
else{
fclose(cur_file);include_depth--;
if(changing&&include_depth==change_depth)break;
cur_line++;
}
}
if(!changing&&!input_has_ended)
if(limit-buffer==change_limit-change_buffer)
if(buffer[0]==change_buffer[0])
if(change_limit> change_buffer)check_change();
}

/*:26*/
#line 433 "../../../texk/web2c/cwebdir/common.w"
;
if(changing&&include_depth==change_depth)goto restart;
}
if(input_has_ended)return 0;
loc= buffer;*limit= ' ';
if(buffer[0]=='@'&&(buffer[1]=='i'||buffer[1]=='I')){
loc= buffer+2;*limit= '"';
while(*loc==' '||*loc=='\t')loc++;
if(loc>=limit){
err_print("! Include file name not given");

goto restart;
}
if(include_depth>=max_include_depth-1){
err_print("! Too many nested includes");

goto restart;
}
include_depth++;
/*25:*/
#line 474 "../../../texk/web2c/cwebdir/common.w"
{
#line 201 "../../../texk/web2c/cwebdir/comm-w2c.ch"
char*cur_file_name_end= cur_file_name+max_file_name_length-1;
char*k= cur_file_name;
#line 479 "../../../texk/web2c/cwebdir/common.w"

if(*loc=='"'){
loc++;
while(*loc!='"'&&k<=cur_file_name_end)*k++= *loc++;
if(loc==limit)k= cur_file_name_end+1;
}else
while(*loc!=' '&&*loc!='\t'&&*loc!='"'&&k<=cur_file_name_end)*k++= *loc++;
if(k> cur_file_name_end)too_long();

*k= '\0';
#line 208 "../../../texk/web2c/cwebdir/comm-w2c.ch"
if((found_filename= kpse_find_cweb(cur_file_name))!=NULL&&
(cur_file= fopen(found_filename,"r"))!=NULL){

if(strlen(found_filename)<max_file_name_length){
strcpy(cur_file_name,found_filename);
free(found_filename);
}
#line 490 "../../../texk/web2c/cwebdir/common.w"
cur_line= 0;print_where= 1;
goto restart;
}
#line 517 "../../../texk/web2c/cwebdir/common.w"
include_depth--;err_print("! Cannot open include file");goto restart;
}

/*:25*/
#line 452 "../../../texk/web2c/cwebdir/common.w"
;
}
return 1;
}

/*:21*//*28:*/
#line 569 "../../../texk/web2c/cwebdir/common.w"

void
#line 252 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 check_complete P1H(void){
#line 572 "../../../texk/web2c/cwebdir/common.w"
if(change_limit!=change_buffer){
strncpy(buffer,change_buffer,change_limit-change_buffer+1);
limit= buffer+(int)(change_limit-change_buffer);
changing= 1;change_depth= include_depth;loc= buffer;
err_print("! Change file entry did not match");

}
}

/*:28*//*37:*/
#line 660 "../../../texk/web2c/cwebdir/common.w"

name_pointer
#line 271 "../../../texk/web2c/cwebdir/comm-w2c.ch"

id_lookup P3C(char*,first,char*,last,char,t)
#line 666 "../../../texk/web2c/cwebdir/common.w"
{
char*i= first;
int h;
int l;
name_pointer p;
if(last==NULL)for(last= first;*last!='\0';last++);
l= last-first;
/*38:*/
#line 683 "../../../texk/web2c/cwebdir/common.w"

h= (unsigned char)*i;
while(++i<last)h= (h+h+(int)((unsigned char)*i))%hash_size;


/*:38*/
#line 673 "../../../texk/web2c/cwebdir/common.w"
;
/*39:*/
#line 691 "../../../texk/web2c/cwebdir/common.w"

p= hash[h];
while(p&&!names_match(p,first,l,t))p= p->link;
if(p==NULL){
p= name_ptr;
p->link= hash[h];hash[h]= p;
}

/*:39*/
#line 674 "../../../texk/web2c/cwebdir/common.w"
;
if(p==name_ptr)/*41:*/
#line 706 "../../../texk/web2c/cwebdir/common.w"
{
if(byte_ptr+l> byte_mem_end)overflow("byte memory");
if(name_ptr>=name_dir_end)overflow("name");
strncpy(byte_ptr,first,l);
(++name_ptr)->byte_start= byte_ptr+= l;
if(program==cweave)init_p(p,t);
}

/*:41*/
#line 675 "../../../texk/web2c/cwebdir/common.w"
;
return(p);
}

/*:37*//*44:*/
#line 764 "../../../texk/web2c/cwebdir/common.w"

void
#line 289 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 print_section_name P1C(name_pointer,p)
#line 768 "../../../texk/web2c/cwebdir/common.w"
{
char*ss,*s= first_chunk(p);
name_pointer q= p+1;
while(p!=name_dir){
ss= (p+1)->byte_start-1;
if(*ss==' '&&ss>=s){
term_write(s,ss-s);p= q->link;q= p;
}else{
term_write(s,ss+1-s);p= name_dir;q= NULL;
}
s= p->byte_start;
}
if(q)term_write("...",3);
}

/*:44*//*45:*/
#line 783 "../../../texk/web2c/cwebdir/common.w"

void
#line 299 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 sprint_section_name P2C(char*,dest,name_pointer,p)
#line 788 "../../../texk/web2c/cwebdir/common.w"
{
char*ss,*s= first_chunk(p);
name_pointer q= p+1;
while(p!=name_dir){
ss= (p+1)->byte_start-1;
if(*ss==' '&&ss>=s){
p= q->link;q= p;
}else{
ss++;p= name_dir;
}
strncpy(dest,s,ss-s),dest+= ss-s;
s= p->byte_start;
}
*dest= '\0';
}

/*:45*//*46:*/
#line 804 "../../../texk/web2c/cwebdir/common.w"

void
#line 308 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 print_prefix_name P1C(name_pointer,p)
#line 808 "../../../texk/web2c/cwebdir/common.w"
{
char*s= first_chunk(p);
int l= prefix_length(p);
term_write(s,l);
if(s+l<(p+1)->byte_start)term_write("...",3);
}

/*:46*//*47:*/
#line 825 "../../../texk/web2c/cwebdir/common.w"

#line 318 "../../../texk/web2c/cwebdir/comm-w2c.ch"

int web_strcmp P4C(char*,j,int,j_len,char*,k,int,k_len)
#line 829 "../../../texk/web2c/cwebdir/common.w"
{
char*j1= j+j_len,*k1= k+k_len;
while(k<k1&&j<j1&&*j==*k)k++,j++;
if(k==k1)if(j==j1)return equal;
else return extension;
else if(j==j1)return prefix;
else if(*j<*k)return less;
else return greater;
}

/*:47*//*49:*/
#line 855 "../../../texk/web2c/cwebdir/common.w"

name_pointer
#line 340 "../../../texk/web2c/cwebdir/comm-w2c.ch"

add_section_name P5C(name_pointer,par,int,c,char*,first,char*,last,
int,ispref)
#line 863 "../../../texk/web2c/cwebdir/common.w"
{
name_pointer p= name_ptr;
char*s= first_chunk(p);
int name_len= last-first+ispref;
if(s+name_len> byte_mem_end)overflow("byte memory");
if(name_ptr+1>=name_dir_end)overflow("name");
(++name_ptr)->byte_start= byte_ptr= s+name_len;
if(ispref){
*(byte_ptr-1)= ' ';
name_len--;
name_ptr->link= name_dir;
(++name_ptr)->byte_start= byte_ptr;
}
set_prefix_length(p,name_len);
strncpy(s,first,name_len);
p->llink= NULL;
p->rlink= NULL;
init_node(p);
return par==NULL?(root= p):c==less?(par->llink= p):(par->rlink= p);
}

/*:49*//*50:*/
#line 884 "../../../texk/web2c/cwebdir/common.w"

void
#line 354 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 extend_section_name P4C(name_pointer,p,char*,first,char*,last,int,ispref)
#line 891 "../../../texk/web2c/cwebdir/common.w"
{
char*s;
name_pointer q= p+1;
int name_len= last-first+ispref;
if(name_ptr>=name_dir_end)overflow("name");
while(q->link!=name_dir)q= q->link;
q->link= name_ptr;
s= name_ptr->byte_start;
name_ptr->link= name_dir;
if(s+name_len> byte_mem_end)overflow("byte memory");
(++name_ptr)->byte_start= byte_ptr= s+name_len;
strncpy(s,first,name_len);
if(ispref)*(byte_ptr-1)= ' ';
}

/*:50*//*51:*/
#line 912 "../../../texk/web2c/cwebdir/common.w"

name_pointer
#line 364 "../../../texk/web2c/cwebdir/comm-w2c.ch"

section_lookup P3C(char*,first,char*,last,int,ispref)
#line 917 "../../../texk/web2c/cwebdir/common.w"
{
int c= 0;
name_pointer p= root;
name_pointer q= NULL;
name_pointer r= NULL;
name_pointer par= NULL;

int name_len= last-first+1;
/*52:*/
#line 936 "../../../texk/web2c/cwebdir/common.w"

while(p){
c= web_strcmp(first,name_len,first_chunk(p),prefix_length(p));
if(c==less||c==greater){
if(r==NULL)
par= p;
p= (c==less?p->llink:p->rlink);
}else{
if(r!=NULL){
printf("\n! Ambiguous prefix: matches <");

print_prefix_name(p);
printf(">\n and <");
print_prefix_name(r);
err_print(">");
return name_dir;
}
r= p;
p= p->llink;
q= r->rlink;
}
if(p==NULL)
p= q,q= NULL;
}

/*:52*/
#line 926 "../../../texk/web2c/cwebdir/common.w"
;
/*53:*/
#line 961 "../../../texk/web2c/cwebdir/common.w"

if(r==NULL)
return add_section_name(par,c,first,last+1,ispref);

/*:53*/
#line 927 "../../../texk/web2c/cwebdir/common.w"
;
/*54:*/
#line 969 "../../../texk/web2c/cwebdir/common.w"

switch(section_name_cmp(&first,name_len,r)){

case prefix:
if(!ispref){
printf("\n! New name is a prefix of <");

print_section_name(r);
err_print(">");
}
else if(name_len<prefix_length(r))set_prefix_length(r,name_len);

case equal:return r;
case extension:if(!ispref||first<=last)
extend_section_name(r,first,last+1,ispref);
return r;
case bad_extension:
printf("\n! New name extends <");

print_section_name(r);
err_print(">");
return r;
default:
printf("\n! Section name incompatible with <");

print_prefix_name(r);
printf(">,\n which abbreviates <");
print_section_name(r);
err_print(">");
return r;
}

/*:54*/
#line 928 "../../../texk/web2c/cwebdir/common.w"
;
}

/*:51*//*56:*/
#line 1020 "../../../texk/web2c/cwebdir/common.w"

#line 384 "../../../texk/web2c/cwebdir/comm-w2c.ch"
int section_name_cmp P3C(char**,pfirst,int,len,name_pointer,r)
#line 1025 "../../../texk/web2c/cwebdir/common.w"
{
char*first= *pfirst;
name_pointer q= r+1;
char*ss,*s= first_chunk(r);
int c;
int ispref;
while(1){
ss= (r+1)->byte_start-1;
if(*ss==' '&&ss>=r->byte_start)ispref= 1,q= q->link;
else ispref= 0,ss++,q= name_dir;
switch(c= web_strcmp(first,len,s,ss-s)){
case equal:if(q==name_dir)
if(ispref){
*pfirst= first+(ss-s);
return extension;
}else return equal;
else return(q->byte_start==(q+1)->byte_start)?equal:prefix;
case extension:
if(!ispref)return bad_extension;
first+= ss-s;
if(q!=name_dir){len-= ss-s;s= q->byte_start;r= q;continue;}
*pfirst= first;return extension;
default:return c;
}
}
}

/*:56*//*60:*/
#line 1095 "../../../texk/web2c/cwebdir/common.w"

void
#line 401 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 err_print P1C(char*,s)
#line 1099 "../../../texk/web2c/cwebdir/common.w"
{
char*k,*l;
printf(*s=='!'?"\n%s":"%s",s);
if(web_file_open)/*61:*/
#line 1115 "../../../texk/web2c/cwebdir/common.w"

{if(changing&&include_depth==change_depth)
printf(". (l. %d of change file)\n",change_line);
else if(include_depth==0)printf(". (l. %d)\n",cur_line);
else printf(". (l. %d of include file %s)\n",cur_line,cur_file_name);
l= (loc>=limit?limit:loc);
if(l> buffer){
for(k= buffer;k<l;k++)
if(*k=='\t')putchar(' ');
else putchar(*k);
putchar('\n');
for(k= buffer;k<l;k++)putchar(' ');
}
for(k= l;k<limit;k++)putchar(*k);
if(*limit=='|')putchar('|');
putchar(' ');
}

/*:61*/
#line 1102 "../../../texk/web2c/cwebdir/common.w"
;
update_terminal;mark_error;
}

/*:60*//*63:*/
#line 1150 "../../../texk/web2c/cwebdir/common.w"

#line 419 "../../../texk/web2c/cwebdir/comm-w2c.ch"
int wrap_up P1H(void){
#line 1152 "../../../texk/web2c/cwebdir/common.w"
putchar('\n');
if(show_stats)
print_stats();
/*64:*/
#line 1160 "../../../texk/web2c/cwebdir/common.w"

switch(history){
case spotless:if(show_happiness)printf("(No errors were found.)\n");break;
case harmless_message:
printf("(Did you see the warning message above?)\n");break;
case error_message:
printf("(Pardon me, but I think I spotted something wrong.)\n");break;
case fatal_message:printf("(That was a fatal error, my friend.)\n");
}

/*:64*/
#line 1155 "../../../texk/web2c/cwebdir/common.w"
;
if(history> harmless_message)return(1);
else return(0);
}

/*:63*//*66:*/
#line 1179 "../../../texk/web2c/cwebdir/common.w"
void
#line 437 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 fatal P2C(char*,s,char*,t)
#line 1182 "../../../texk/web2c/cwebdir/common.w"
{
if(*s)printf(s);
err_print(t);
history= fatal_message;exit(wrap_up());
}

/*:66*//*67:*/
#line 1190 "../../../texk/web2c/cwebdir/common.w"
void
#line 446 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 overflow P1C(char*,t)
#line 1193 "../../../texk/web2c/cwebdir/common.w"
{
printf("\n! Sorry, %s capacity exceeded",t);fatal("","");
}


/*:67*//*72:*/
#line 1254 "../../../texk/web2c/cwebdir/common.w"

void
#line 504 "../../../texk/web2c/cwebdir/comm-w2c.ch"
 scan_args P1H(void)
#line 1257 "../../../texk/web2c/cwebdir/common.w"
{
char*dot_pos;
char*name_pos;
register char*s;
boolean found_web= 0,found_change= 0,found_out= 0;

boolean flag_change;

while(--argc> 0){
if((**(++argv)=='-'||**argv=='+')&&*(*argv+1))/*76:*/
#line 528 "../../../texk/web2c/cwebdir/comm-w2c.ch"

{
if(strcmp("-help",*argv)==0||strcmp("--help",*argv)==0)
/*84:*/
#line 605 "../../../texk/web2c/cwebdir/comm-w2c.ch"

usagehelp(program==ctangle?CTANGLEHELP:CWEAVEHELP,NULL);


/*:84*/
#line 531 "../../../texk/web2c/cwebdir/comm-w2c.ch"
;
if(strcmp("-version",*argv)==0||strcmp("--version",*argv)==0)
/*85:*/
#line 614 "../../../texk/web2c/cwebdir/comm-w2c.ch"

printversionandexit((program==ctangle?ctangle_banner:cweave_banner),
"Silvio Levy and Donald E. Knuth",NULL,NULL);


/*:85*/
#line 533 "../../../texk/web2c/cwebdir/comm-w2c.ch"
;
#line 1346 "../../../texk/web2c/cwebdir/common.w"
if(**argv=='-')flag_change= 0;
#line 539 "../../../texk/web2c/cwebdir/comm-w2c.ch"
else flag_change= 1;
if(*(*argv+1)=='d')
if(sscanf(*argv+2,"%u",&kpathsea_debug)!=1)/*77:*/
#line 1352 "../../../texk/web2c/cwebdir/common.w"

{
#line 562 "../../../texk/web2c/cwebdir/comm-w2c.ch"
if(program==ctangle){
fprintf(stderr,"ctangle: Need one to three file arguments.\n");
usage("ctangle");
}else{
fprintf(stderr,"cweave: Need one to three file arguments.\n");
usage("cweave");
}
#line 1362 "../../../texk/web2c/cwebdir/common.w"
}

/*:77*/
#line 541 "../../../texk/web2c/cwebdir/comm-w2c.ch"
;
#line 1348 "../../../texk/web2c/cwebdir/common.w"
for(dot_pos= *argv+1;*dot_pos> '\0';dot_pos++)
#line 547 "../../../texk/web2c/cwebdir/comm-w2c.ch"
flags[(unsigned char)*dot_pos]= flag_change;
#line 1350 "../../../texk/web2c/cwebdir/common.w"
}

/*:76*/
#line 1266 "../../../texk/web2c/cwebdir/common.w"

else{
s= name_pos= *argv;dot_pos= NULL;
while(*s){
if(*s=='.')dot_pos= s++;
else if(*s=='/')dot_pos= NULL,name_pos= ++s;
else s++;
}
if(!found_web)/*73:*/
#line 1292 "../../../texk/web2c/cwebdir/common.w"

{
if(s-*argv> max_file_name_length-5)
/*78:*/
#line 1364 "../../../texk/web2c/cwebdir/common.w"
fatal("! Filename too long\n",*argv);


/*:78*/
#line 1295 "../../../texk/web2c/cwebdir/common.w"
;
if(dot_pos==NULL)
sprintf(web_file_name,"%s.w",*argv);
else{
strcpy(web_file_name,*argv);
*dot_pos= 0;
}
#line 1303 "../../../texk/web2c/cwebdir/common.w"
sprintf(tex_file_name,"%s.tex",name_pos);
sprintf(idx_file_name,"%s.idx",name_pos);
sprintf(scn_file_name,"%s.scn",name_pos);
sprintf(C_file_name,"%s.c",name_pos);
found_web= 1;
}

/*:73*/
#line 1275 "../../../texk/web2c/cwebdir/common.w"

else if(!found_change)/*74:*/
#line 1310 "../../../texk/web2c/cwebdir/common.w"

{
if(strcmp(*argv,"-")==0)found_change= -1;
else{
if(s-*argv> max_file_name_length-4)
/*78:*/
#line 1364 "../../../texk/web2c/cwebdir/common.w"
fatal("! Filename too long\n",*argv);


/*:78*/
#line 1315 "../../../texk/web2c/cwebdir/common.w"
;
if(dot_pos==NULL)
sprintf(change_file_name,"%s.ch",*argv);
else strcpy(change_file_name,*argv);
found_change= 1;
}
}

/*:74*/
#line 1276 "../../../texk/web2c/cwebdir/common.w"

else if(!found_out)/*75:*/
#line 1323 "../../../texk/web2c/cwebdir/common.w"

{
if(s-*argv> max_file_name_length-5)
/*78:*/
#line 1364 "../../../texk/web2c/cwebdir/common.w"
fatal("! Filename too long\n",*argv);


/*:78*/
#line 1326 "../../../texk/web2c/cwebdir/common.w"
;
if(dot_pos==NULL){
sprintf(tex_file_name,"%s.tex",*argv);
sprintf(idx_file_name,"%s.idx",*argv);
sprintf(scn_file_name,"%s.scn",*argv);
sprintf(C_file_name,"%s.c",*argv);
}else{
strcpy(tex_file_name,*argv);
strcpy(C_file_name,*argv);
if(flags['x']){
*dot_pos= 0;
sprintf(idx_file_name,"%s.idx",*argv);
sprintf(scn_file_name,"%s.scn",*argv);
}
}
found_out= 1;
}

#line 528 "../../../texk/web2c/cwebdir/comm-w2c.ch"
/*:75*/
#line 1277 "../../../texk/web2c/cwebdir/common.w"

else/*77:*/
#line 1352 "../../../texk/web2c/cwebdir/common.w"

{
#line 562 "../../../texk/web2c/cwebdir/comm-w2c.ch"
if(program==ctangle){
fprintf(stderr,"ctangle: Need one to three file arguments.\n");
usage("ctangle");
}else{
fprintf(stderr,"cweave: Need one to three file arguments.\n");
usage("cweave");
}
#line 1362 "../../../texk/web2c/cwebdir/common.w"
}

/*:77*/
#line 1278 "../../../texk/web2c/cwebdir/common.w"
;
}
}
if(!found_web)/*77:*/
#line 1352 "../../../texk/web2c/cwebdir/common.w"

{
#line 562 "../../../texk/web2c/cwebdir/comm-w2c.ch"
if(program==ctangle){
fprintf(stderr,"ctangle: Need one to three file arguments.\n");
usage("ctangle");
}else{
fprintf(stderr,"cweave: Need one to three file arguments.\n");
usage("cweave");
}
#line 1362 "../../../texk/web2c/cwebdir/common.w"
}

/*:77*/
#line 1281 "../../../texk/web2c/cwebdir/common.w"
;
#line 513 "../../../texk/web2c/cwebdir/comm-w2c.ch"
if(found_change<=0)strcpy(change_file_name,DEV_NULL);
#line 1283 "../../../texk/web2c/cwebdir/common.w"
}

/*:72*/
