grammar swl;

program     : 	'begin' statement+ 'end';

statement   : 	assign | add | sub | mult | div | ask | print | ifthenelse | whiledo;

assign      :   'let' ID 'be' (NUMBER | ID) ;
print       :   'print' (NUMBER | ID) ;
ask         :   'ask' ID ;
add         :   'add' (NUMBER | ID) 'to' ID ;
sub         :   'sub' (NUMBER | ID) 'to' ID ;
mult        :   'mult' (NUMBER | ID) 'to' ID ;
div         :   'div' (NUMBER | ID) 'to' ID ;
whiledo     :   'while' boolean wdo statement+ 'end';
wdo         :   'do';
ifthenelse  :   'if' boolean ithen statement+ 'end'
			|   'if' boolean ithen statement+ ielse statement+ 'end' 
            ;
ithen       :   'then';
ielse       :   'else';
boolean     :	condition (LOGIC condition)* 
			|  	(condition LOGIC)* '(' condition (LOGIC condition)* ')' (LOGIC condition)*
			| 	NOT* '(' boolean ')'
			; 
condition   : 	NOT* (NUMBER|ID) 
			| 	NOT* '(' NOT* (NUMBER|ID) ')' 
			| 	NOT* (NUMBER|ID) OPCONF NOT* (NUMBER|ID)
			| 	NOT* '(' NOT* (NUMBER|ID) OPCONF NOT* (NUMBER|ID) ')'
			| 	NOT* '(' condition ')'
			;

ID          : 	[a-zA-Z]+ ;
NUMBER      : 	[0-9]+ ;
OPCONF	    : 	'>=' | '<=' | '>' | '<' | '!=' | '==' | ' ' OPCONF ' ' ;
LOGIC       : 	'&&' | '||' | ' ' LOGIC ' ' ;
NOT 	    : 	[!]+;
WS          : 	[ \r\n\t]+ -> skip;
ErrorChar   : 	. ;
