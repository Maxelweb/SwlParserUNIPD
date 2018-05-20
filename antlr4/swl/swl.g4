grammar swl;

program   : 'begin' statement+ 'end';

statement : assign | add | sub | mult | div | print | ifthenelse | whiledo ;

assign     : 'let' ID 'be' (NUMBER | ID) ;
print      : 'print' (NUMBER | ID) ;
add        : 'add' (NUMBER | ID) 'to' ID ;
sub        : 'sub' (NUMBER | ID) 'to' ID ;
mult       : 'mult' (NUMBER | ID) 'to' ID ;
div        : 'div' (NUMBER | ID) 'to' ID ;
whiledo    : 'while' boolean wdo statement+ 'end';
wdo        : 'do';
ifthenelse : 'if' boolean ith statement+ 'end'
           | 'if' boolean ith statement+ iels statement+ 'end' ;
ith        : 'then';
iels       : 'else';

boolean    : lnot* lb var ((opconf|logic) var)* rb
           | lnot* lb boolean ((opconf|logic) boolean)* rb;


var        : (NUMBER|ID) | lnot+var;

logic      : 'and' | 'or';
lnot       : 'not';

lb         : '(';
rb         : ')';

opconf     : '>=' | '<=' | '>' | '<' | '!=' | '==' ;



ID         : [a-zA-Z]+ ;
NUMBER     : [0-9]+ ;
WS         : [ \r\n\t]+ -> skip;
ErrorChar  : . ;
