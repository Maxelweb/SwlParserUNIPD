grammar swl;

program     : 'begin' statement+ 'end';

statement   : assign | add | sub | mult | div | print | ifthenelse | whiledo;

assign      : 'let' ID 'be' (NUMBER | ID) ;
print       : 'print' (NUMBER | ID) ;
add         : 'add' (NUMBER | ID) 'to' ID ;
sub         : 'sub' (NUMBER | ID) 'to' ID ;
mult        : 'mult' (NUMBER | ID) 'to' ID ;
div         : 'div' (NUMBER | ID) 'to' ID ;
whiledo     : 'while' boolean wdo statement+ 'end';
wdo         : 'do';
ifthenelse  : 'if' boolean ithen statement+ 'end'
			| 'if' boolean ithen statement+ ielse statement+ 'end' ;
ithen       : 'then';
ielse       : 'else';
boolean     :	condition (LOGIC condition)* 
			|  	(condition LOGIC)* LEB condition (LOGIC condition)* RIB (LOGIC condition)*
			| 	NOTNOT* '(' boolean ')'
			; 

condition  : 
				NOTNOT* (NUMBER|ID) 
			| 	NOTNOT* '(' NOTNOT* (NUMBER|ID) ')' 
			| 	NOTNOT* (NUMBER|ID) CARATTERI NOTNOT* (NUMBER|ID)
			| 	NOTNOT* '(' NOTNOT* (NUMBER|ID) CARATTERI NOTNOT* (NUMBER|ID) ')'
			| 	NOTNOT* '(' condition ')'
			;

ID          : 	[a-zA-Z]+ ;
NUMBER      : 	[0-9]+ ;
CARATTERI   : 	'>=' | '<=' | '>' | '<' | '!=' | '==' ;
LOGIC       : 	' and '|' or ';
NOTNOT 	    : 	[!]+;
LEB 		:   '(';
RIB 		:   ')'; 
WS          : 	[ \r\n\t]+ -> skip;
ErrorChar   : 	. ;
			