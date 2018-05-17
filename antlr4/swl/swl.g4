grammar swl;

program   : 'begin' statement+ 'end';

statement : assign | add | sub | mult | div | print | ifthenelse | whiledo;

assign     : 'let' ID 'be' (NUMBER | ID) ;
print      : 'print' (NUMBER | ID) ;
add        : 'add' (NUMBER | ID) 'to' ID ;
sub        : 'sub' (NUMBER | ID) 'to' ID ;
mult       : 'mult' (NUMBER | ID) 'to' ID ;
div        : 'div' (NUMBER | ID) 'to' ID ;
whiledo    : 'while' boolean wdo statement+ 'end';
wdo        : 'do';
ifthenelse : 'if' boolean ithen statement+ 'end'| 'if' boolean ithen statement+ ielse statement+ 'end' ;
ithen      : 'then';
ielse      : 'else';
boolean    : NOTNOT* condition (LOGIC NOTNOT* condition)* | '(' boolean ')'; 
condition  : (NUMBER|ID) | '(' (NUMBER|ID) CARATTERI (NUMBER|ID) ')' | (NUMBER|ID) CARATTERI (NUMBER|ID);

ID        : [a-zA-Z]+ ;
NUMBER    : [0-9]+ ;
CARATTERI : [<>=!]+ ;
LOGIC     : ' and '|' or ';
NOTNOT 	  : ' not ' | 'not ';
WS        : [ \r\n\t]+ -> skip;
ErrorChar : . ;
			