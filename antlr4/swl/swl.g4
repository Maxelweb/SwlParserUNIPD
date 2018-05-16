grammar swl;

program   : 'begin' statement+ 'end';

statement : assign | add | sub | mult | div | print | ifthenelse | whiledo ;

assign     : 'let' ID 'be' (NUMBER | ID) ;
print      : 'print' (NUMBER | ID) ;
add        : 'add' (NUMBER | ID) 'to' ID ;
sub        : 'sub' (NUMBER | ID) 'to' ID ;
mult       : 'mult' (NUMBER | ID) 'to' ID ;
div        : 'div' (NUMBER | ID) 'to' ID ;
whiledo    : 'while' boolean 'do' statement+ 'end';
ifthenelse : 'if' boolean 'then' statement+ 'end'| 'if' boolean 'then' statement+ 'else' statement+ 'end' ;
boolean    : condition | condition LOGIC condition | condition LOGIC boolean | boolean LOGIC condition | boolean LOGIC boolean | '(' boolean+ ')' | 'not (' boolean+ ')';
condition  : var | '(' var CARATTERI var ')' | var CARATTERI var;
var        : (NUMBER|ID) | 'not' (NUMBER|ID);

ID        : [a-zA-Z]+ ;
NUMBER    : [0-9]+ ;
CARATTERI : [<>=!]+ ;
LOGIC     : ' and '|' or '|' not ';
WS        : [ \r\n\t]+ -> skip;
ErrorChar : . ;
